//���������ϰ��Ŀ�������Լ���ɣ��ҵĴ�һ���з���

#include"cpp1.h"
#include<cstdlib>
using namespace std;

int main() {
	Sales_data item1;
	print(std::cout, item1) << std::endl;
	//����һ���յ�item1��������ֵ
	
	Sales_data item2("0-201-78345-X");
	print(std::cout, item2) << std::endl;

	Sales_data item3("0-201-78345-X", 3,
		20.00);
	print(std::cout, item3) << std::endl;

	Sales_data item4(std::cin);
	print(std::cout, item4) << std::endl;
	//�û�����isbn�������͵��ۣ�����isbn�������ͼ۸��ܺͣ���ctrl+z���Խ�������״̬��

	system("pause");
	//��ֹ�ڿ�һ������������Ҫ��catdlibͷ�ļ���
	return 0;
	
}