enum Token {
	nul = 0,
	paragraph = 1,//段落
	href = 2,//超链接
	ul = 3,//无序集
	ol = 4,//有序集
	li = 5,//列表项目
	em = 6,//斜体，表示强调
	strong = 7,//加粗
	hr = 8,//标题
	image = 9,//图片
	quote = 10,//块引用

	//标题1-6
	h1 = 11,
	h2 = 12,
	h3 = 13,
	h4 = 14,
	h5 = 15,
	h6 = 16,

	blockcode = 17,//表示计算机源代码
	code = 18,//单行代码
};
