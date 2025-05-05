#include <string>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

bool isSeparator(char c) {
	return c == ' ' || c == ',' || c == '?' || c == '!' || c == '.';
}

string transform(const string& s) {
	string t = "";
	for (char c : s)
		if (c >= 'A' && c <= 'Z')
			t += string(1, c - 'A' + 'a');
		else
			t += c;
	return t;
}

class Compare {
public:
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
		cout << "a ";
		if (a.second != b.second)
			return a.second > b.second;

		int mi = (int) a.first.length() < (int) b.first.length() ? (int) a.first.length() : (int) b.first.length();
		for (int i = 0; i < mi; i++)
			if (a.first[i] != b.first[i])
				return a.first[i] > b.first[i];

		return mi == (int) b.first.length();
	}
};

struct test {
	bool operator()(const int& a, const int& b) {
		return a < b;
	}
};

int main() {
	string s;
	ifstream f("input.txt");
	getline(f, s);
	f.close();

	priority_queue<int, vector<int>, test> a;
	a.push(1);
	a.push(3);
	a.push(2);

	while (!a.empty()) {
		cout << a.top() << ' ';
		a.pop();
	}

	return 0;

	vector<string> v;
	int i = 0;

	while (i < s.length()) {
		while (i < s.length() && isSeparator(s[i]))
			i++;
		if (i >= s.length())
			break;

		int l = i;
		while (i < s.length() && !isSeparator(s[i]))
			i++;

		v.push_back(s.substr(l, i - l));
	}

	map<string, int> fr;
	for (auto i : v)
		fr[transform(i)]++;

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> p;

	p.push({ "a", 1 });
	p.push({ "b", 2 });

	for (auto i : fr)
		p.push(make_pair(i.first, i.second));

	while (!p.empty()) {
		cout << p.top().first << " => " << p.top().second << endl;
		p.pop();
	}

	return 0;
}