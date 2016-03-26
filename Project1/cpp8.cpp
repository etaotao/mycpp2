#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<cstdlib>
using namespace std;

int main() {
	list<int> lst;
	int i1;
	while (cin >> i1) {
		lst.push_back(i1);
	}
	deque<int> lst1;
	deque<int> lst2;
	for (auto t1 = lst.begin(); t1 != lst.end(); t1++) {
		if (((*t1) / 2) * 2 == (*t1)) {
			lst1.push_back(*t1);
			continue;
		}
			lst2.push_back(*t1);
	}
	cout << "Even number is: ";
	for (auto t1 = lst1.begin(); t1 != lst1.end(); t1++) {
		cout << *t1 << " ";
	}
	cout << endl;
	cout << "Odd number is: ";
	for (auto t1 = lst2.begin(); t1 != lst2.end(); t1++) {
		cout << *t1 << " ";
	}
	cout << endl;
	system("pause");
	return 0;


}