#include<iostream>
#include<fstream>
#include<cstdlib>
#include"cpp1.h"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cerr << "Please input the name of input file and output file." << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "We can't open the input file." << endl;
		return -1;
	}
	ofstream out(argv[2]);
	if (!out) {
		cerr << "We can't open the output file." << endl;
	}

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(out, total) << endl;
				total = trans;
			}
		}
		print(out, total) << endl;
	}
	else {
		cerr << "No data." << endl;
	}
	system("pause");
	return 0;
}