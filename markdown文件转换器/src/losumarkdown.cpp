void losumarkdown::transferm()
{
	//打开文件
	ifstream fin(_filename);
	if (!fin.is_open()) {	//打开失败
		cerr << "打开文件失败" << endl;
		return;
	}

	bool inblock = false;
	//读取内容(按行读取)
	string rowStr;
	while (fin.peek() != EOF) 
	{
		//fin.eof()
		getline(fin, rowStr);

		//预处理:处理行首空格
		const char* start = processStr(rowStr.c_str());
		//忽略空内容
		if (!inblock && start == nullptr)	continue;

		//判断是否为水平分割线
		if (!inblock && isCutLine(start)) {
			_root->_child.push_back(new Node(hr));
			continue;
		}

		//语法解析//字典
		pair<int, const char*> typeRet = parseType(start);

		//创建语法结点

		//代码块结点
		if (typeRet.first == blockcode) {
			//判断代码块起始还是结束
			if (!inblock) {
				//代码块起始
				//创建代码块结点
				_root->_child.push_back(new Node(blockcode));
			}

			//如果是代码块结束位置,不需要创建新的代码块结点

			inblock = !inblock;
			continue;
		}

		//判断是否为代码块中代码
		if (inblock) {
			_root->_child.back()->elem[0] += rowStr;
			_root->_child.back()->elem[0] += '\n';
			continue;
		}

		//段落结点
		if (typeRet.first == paragraph) {
			//创建一个段落结点
			_root->_child.push_back(new Node(paragraph));
			//逐字符插入
			insert(_root->_child.back(), typeRet.second);
			continue;
		}

		//标题结点
		if (typeRet.first >= h1 && typeRet.first <= h6) {
			//创建标题结点
			_root->_child.push_back(new Node(typeRet.first));
			//插入标题内容
			_root->_child.back()->elem[0] = typeRet.second;
			continue;
		}

		//无序列表
		if (typeRet.first == ul) {
			//判断是否为无序列表的第一项
			//文档开始,或者语法书最后一个结点不是无序列表结点
			if (_root->_child.empty() || _root->_child.back()->_type != ul) {
				//创建无序列表
				_root->_child.push_back(new Node(ul));
			}
			//给无序列表加入列表子节点
			Node* uNode = _root->_child.back();
			uNode->_child.push_back(new Node(li));
			//给列表子节点插入内容
			insert(uNode->_child.back(), typeRet.second);
			continue;
		}

		//有序列表
		if (typeRet.first == ol) {
			if (_root->_child.empty() || _root->_child.back()->_type != ol) {
				_root->_child.push_back(new Node(ol));
			}
			Node* oNode = _root->_child.back();
			oNode->_child.push_back(new Node(li));
			insert(oNode->_child.back(), typeRet.second);
			continue;
		}

		//引用
		if (typeRet.first == quote) {
			//创建引用结点
			_root->_child.push_back(new Node(quote));
			insert(_root->_child.back(), typeRet.second);
		}
	}
	//展开语法树,生成HTML文档
	dfs(_root);
}

void losumarkdown::dfs(Node* root)
{
	//插入前置标签
	_content += frontTag[root->_type];

	//插入内容

	//网址
	if (root->_type == href) {
		_content += "<a href=\"";
		_content += root->elem[1];
		_content += "\">";
		_content += root->elem[0];
		_content += "</a>";
	}
	//图片
	else if (root->_type == image) {
		_content += "<img alt=\"";
		_content += root->elem[0];
		_content += "\" src=\"";
		_content += root->elem[1];
		_content += "\" />";
	}
	//其他
	else {
		_content += root->elem[0];
	}

	//处理孩子结点
	for (Node* ch : root->_child) {
		dfs(ch);
	}

	//插入后置标签
	_content += backTag[root->_type];
}

const char* losumarkdown::processStr(const char* str)
{
	while (*str) {
		if (*str == ' ' || *str == '\t')	++str;
		else break;
	}
	if (*str == '\0')	return nullptr;
	return str;
}

void losumarkdown::insert(Node* curNode, const char* str)
{
	bool incode = false;	//是否为行内代码
	bool instrong = false;	//粗体
	bool inem = false;		//斜体
	int len = strlen(str);
	//解析内容为纯文本,可以放入纯文本结点中
	//先创建一个纯文本孩子结点
	curNode->_child.push_back(new Node(nul));
	for (int i = 0; i < len; ++i) {
		//1.行内代码
		if (str[i] == '`') {
			if (incode) {
				//行内代码结束,则创建一个新的孩子结点,存放后序内容
				curNode->_child.push_back(new Node(nul));
			}
			else {
				//创建行内代码
				curNode->_child.push_back(new Node(code));
			}
			incode = !incode;
			continue;
		}

		//2.粗体: "**  **"
		//出现"**"且不在行内代码中
		if (str[i] == '*' && i + 1 < len && str[i + 1] == '*' && !incode) {
			if (instrong) {
				//粗体结束,创建新结点
				curNode->_child.push_back(new Node(nul));
			}
			else {
				//创建新的粗体结点
				curNode->_child.push_back(new Node(strong));
			}

			instrong = !instrong;
			//跳过粗体语法
			++i;
			continue;
		}

		//3.斜体:	"_   _"
		if (str[i] == '_' && !incode) {
			if (inem) {
				curNode->_child.push_back(new Node(nul));
			}
			else {
				curNode->_child.push_back(new Node(em));
			}
			inem = !inem;
			continue;
		}

		//4.图片:	![图片名称](图片地址)
		if (str[i] == '!' && i + 1 < len && str[i + 1] == '[') {
			//创建图片结点
			curNode->_child.push_back(new Node(image));
			Node* iNode = curNode->_child.back();
			i += 2;
			//存放图片名称在elem[0]
			for (; i < len && str[i] != ']'; ++i) {
				iNode->elem[0] += str[i];
			}
			//存放图片地址在elem[1]
			i += 2;
			for (; i < len && str[i] != ')'; ++i) {
				iNode->elem[1] += str[i];
			}

			//创建新结点处理后续内容
			curNode->_child.push_back(new Node(nul));
			continue;
		}

		//5.链接:[链接名](网址)
		//有左括号,且不在行内代码
		if (str[i] == '[' && !incode) {
			//创建链接结点
			curNode->_child.push_back(new Node(href));
			Node* hNode = curNode->_child.back();
			++i;
			//存放链接名在elem[0]
			for (; i < len && str[i] != ']'; ++i) {
				hNode->elem[0] += str[i];
			}
			//存放链接地址在elem[1]
			i += 2;
			for (; i < len && str[i] != ')'; ++i) {
				hNode->elem[1] += str[i];
			}

			//创建新结点处理后续内容
			curNode->_child.push_back(new Node(nul));
			continue;

		}

		//6.普通纯文本
		curNode->_child.back()->elem[0] += str[i];
	}

}

pair<int, const char*> losumarkdown::parseType(const char* str)
{
	//解析标题:# + 空格
	const char* ptr = str;
	int titleNum = 0;
	while (*ptr && *ptr == '#') {
		++ptr;
		++titleNum;
	}
	//1.标题
	if (*ptr == ' ' && titleNum > 0 && titleNum <= 6) {
		return make_pair(h1 + titleNum - 1, ptr + 1);
	}
	//不符合标题语法,需要重新解析
	ptr = str;

	//2.代码块:```代码内容```
	if (strncmp(ptr, "```", 3) == 0) {
		return make_pair(blockcode, ptr + 3);
	}

	//3.无序列表: - + 空格
	if (strncmp(ptr, "- ", 2) == 0) {
		return make_pair(ul, ptr + 2);
	}

	//4.有序列表:数字字符 + "." + 空格
	if (*ptr >= '0' && *ptr <= '9') {
		//遍历完数字
		while (*ptr && (*ptr >= '0' && *ptr <= '9'))	++ptr;
		if (*ptr && *ptr == '.') {
			++ptr;
			if (*ptr && *ptr == ' ')	return make_pair(ol, ptr + 1);
		}
	}
	//重置
	ptr = str;
	//5.引用:">" + 空格
	if (strncmp(ptr, "> ", 2) == 0) {
		return make_pair(quote, ptr + 2);
	}

	//其他语法统一解析为段落
	return make_pair(paragraph, str);
}

bool losumarkdown::isCutLine(const char* str)
{
	int cnt = 0;
	while (*str && *str == '-') {
		++str;
		++cnt;
	}
	return cnt >= 3;
}

void losumarkdown::html()
{
	std::string head =
		"<!DOCTYPE html><html><head>\
        <title>Losu·Markdown</title>\
        </head><body><article class=\"markdown-body\">";
	std::string end = "</article></body></html>";

	string m = _htmfile;
	ofstream fout(m);
	fout << head << _content << end;
}

void losumarkdown::destory(Node* root)
{
	if (root) {
		for (Node* ch : root->_child) {
			destory(ch);
		}

		delete root;
	}
}
