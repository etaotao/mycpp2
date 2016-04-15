#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>

using namespace std;

void add(multimap<string, string>&love, pair<string, string> &name) {
	love.insert({ name.first,name.second });
}

void del(multimap<string, string> &love, pair<string,string> &name) {
	if (love.find(name.first) == love.end()) {
		cout << "Your name is wrong." << endl;
	}
	else {
		auto t1 = love.equal_range(name.first);
		if (t1.first == t1.second) {
			cout << "Your girlfriend's name is wrong." << endl;
		}
		for (; t1.first != t1.second; t1.first++) {
			if (t1.first->second == name.second) {
				love.erase(t1.first);
				break;
			}
		}
	}
}

void input(multimap<string, string> &love, string &name) {
	auto t1 = love.equal_range(name);
	if (t1.first == t1.second) {
		cout << "Your name is wrong or you don't have any girlfriends.";
	}
	else {
		cout << "All of your girlfriends are: " << endl;
		for (; t1.first != t1.second; t1.first++) {
			cout << t1.first->second << " ";
		}
	}

}

int main() {
	multimap<string, string> love;
	love.insert({ "xinmengtao","huxvejie" });
	love.insert({ "xinmengtao","renmengyu" });
	love.insert({ "xinmegntao","xiaoqimeng" });

	char ch;
	pair<string, string> name;
	string your_name;
	string line;

	cout << "Do you want to add your girlfriends?(y or n)" << endl;
	cin >> ch;
	if (ch == 'y'||ch == 'Y') {
		cout << "Please input your name and your girlfriends' name." << endl;
		cout << "You only can input two name in one line£¨your name and your girlfriend's name£©" << endl;
		while (getline(cin, line)) {
			istringstream in(line);
			while (cin >> name.first) {
				while (cin >> name.second) {
					add(love, name);
				}
			}
		}
	}

	cout << "Do you want to delete your girlfriends?(y or n)" << endl;
	cin >> ch;
	if (ch == 'y'||ch == 'Y') {
		cout << "Please input your name and your girlfriends' name." << endl;
		cout << "You only can input two name in one line£¨your name and your girlfriend's name£©" << endl;
		while (getline(cin, line)) {
			istringstream in(line);
			while (cin >> name.first) {
				while (cin >> name.second) {
					del(love, name);
				}
			}
		}
	}

	cout << "Do you want to input your girlfriends?(y or n)" << endl;
	cin >> ch;
	if (ch == 'y'||ch == 'Y') {
		cout << "Please input your name." << endl;
		while (cin >> your_name) {
			input(love, your_name);
		}
	}

	system("pause");
	return 0;
}