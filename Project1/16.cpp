#include<iostream>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include"cpp1.h"
#include<list>
#include<algorithm>
#include<string>

using namespace std;

string &trans(string &s) {
	for (int p = 0; p < s.size(); p++) {
		if (s[p] >= 'A'&&s[p] <= 'Z') {
			s[p] -= ('A' - 'a');
		}
		else if (s[p] == ',' || s[p] == '.') {
			s.erase(p, 1);
		}
		return s;
	}
}

int main() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		++word_count[trans(word)];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << (w.second>1 ? " times" : " time");
		cout << endl;
	}

	system("pause");
	return 0;
}