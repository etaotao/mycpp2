#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Sales_data.h"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "Please input the name of file." << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "We can't open the file" << endl;
		return -1;
	}

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in,trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cerr << "No data." << endl;
	}
	system("pause");
	return 0;
}