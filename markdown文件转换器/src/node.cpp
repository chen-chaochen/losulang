struct Node {
	//语法类型
	int _type;
	//孩子节点
	vector<Node*> _child;
	//内容
	//elem[0]:保存需要显示的内容
	//elem[1]:保存网址/路径
	string elem[2];

	Node(int type)
	{
		_type = type;//赋值
	}
};
