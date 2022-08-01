class losumarkdown {
public:
	losumarkdown(const string &filename)
	{
		_root = new Node(nul);
		_filename = filename;
	}
	~losumarkdown() {
		if (_root) {
			destory(_root);
		}
	}
	void transferm();
	void dfs(Node* root);//语法树转换成HTML源代码//深度优先遍历 DFS
	const char* processStr(const char* str);//去除行首空格
	void insert(Node* curNode, const char* str);//逐字符内容插入
	pair<int, const char*> parseType(const char* str);//解析行首语法  返回子:语法类型 + 对应内容起始位置
	bool isCutLine(const char* str);//判断水平分割线 "---"
	void html();
	void destory(Node* root);//销毁
private:
	Node* _root;//语法树根节点
	string _filename;//文件名
	string _content;//存放HTML文档内容
};

