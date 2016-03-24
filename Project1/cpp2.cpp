#include<iostream>
#include<stdexcept>
using namespace std;

istream& f(istream & in) {
	int v;
	while (in >> v, !in.eof()) {
		if (in.bad()) {
			throw runtime_error("IO error");
		}
		if (in.fail()) {
			cerr << "Wrong data!Plesae try it again.";
			in.clear();
			in.ignore(100, '/n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}

int main() {
	cout << "Please input some integers:" << endl;
	f(cin);
	return 0;
}