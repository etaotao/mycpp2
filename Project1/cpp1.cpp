//关于类的练习项目，难以自己完成，找的答案一行行分析

#include"cpp1.h"
#include<cstdlib>
using namespace std;

int main() {
	Sales_data item1;
	print(std::cout, item1) << std::endl;
	//输入一个空的item1，返回零值
	
	Sales_data item2("0-201-78345-X");
	print(std::cout, item2) << std::endl;

	Sales_data item3("0-201-78345-X", 3,
		20.00);
	print(std::cout, item3) << std::endl;

	Sales_data item4(std::cin);
	print(std::cout, item4) << std::endl;
	//用户输入isbn，册数和单价，返回isbn，册数和价格总和（用ctrl+z可以结束输入状态）

	system("pause");
	//防止黑框一闪而过（上面要有catdlib头文件）
	return 0;
	
}