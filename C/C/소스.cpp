#include <iostream>
#include <stack>
#include <string>
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string url = "http://www.acm.org/";
	stack<string>s, e; //foward, backward
 
	while (1)
	{
		string str;
		cin >> str;
		if (str == "QUIT") break;
		else if (str == "BACK") {
			if (e.empty()) {
				cout << "Ignored" << "\n";
				continue;
			}
			s.push(url);
			url = e.top();
			e.pop();
		}
		else if (str == "FORWARD") {
			if (s.empty()) {
				cout << "Ignored" << "\n";
				continue;
			}
			e.push(url);
			url = s.top();
			s.pop();
		}
		else if (str == "VISIT") {
			string tmp; 
			cin >> tmp;
			e.push(url);
			url = tmp;
			while (!s.empty()) s.pop();
		}
		cout << url << "\n";
	}
}