#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<cstdlib>

using namespace std;
using namespace std::placeholders;

bool check_size(string::size_type sz,const string s) {
	return s.size() < sz;
}

void find_it(vector<int> v, string s) {
	auto t = find_if(v.begin(), v.end(), bind(check_size,_1,s));
	cout << *t << endl;
}

int main() {
	string s;
	vector<int> v;
	int i;
	cout << "Plesae input one string:" << endl;
	cin >> s;
	cout << "Plesae input some elements of v:" << endl;
	while (cin >> i) {
		v.push_back(i);
	}
	find_it(v, s);
	system("pause");
	return 0;
}