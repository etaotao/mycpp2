//I cannot complete it by myself, this is the answer of others and my note.

#include"cpp1.h"
#include<cstdlib>
using namespace std;

int main() {
	Sales_data item1;
	print(std::cout, item1) << std::endl;
	//Input empty item1 and output zero
	
	Sales_data item2("0-201-78345-X");
	print(std::cout, item2) << std::endl;

	Sales_data item3("0-201-78345-X", 3,
		20.00);
	print(std::cout, item3) << std::endl;

	Sales_data item4(std::cin);
	print(std::cout, item4) << std::endl;
	//Input ISBN,number of books and the unit price and output the ISBN,number of books and the amount price of book
	system("pause");
	//Avoid the black block flashing
	return 0;
	
}