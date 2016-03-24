#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	ifstream in("data");
	if (!in) {
		cerr << "We can't open this file." << endl;
		return -1;
	}
	string line;
	vector<string> words;
	while (getline(in, line)) {
		words.push_back(line);
	}
	in.close();

	vector<string>::const_iterator it = words.begin();
	//const_iterator���������ڵ�Ԫ�ز�������ЩԪ�ص�ֵ�����ɸ�
	while (it != words.end()) {
		cout << *it << endl;
		++it;
	}
	return 0;
}