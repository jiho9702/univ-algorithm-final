#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

/*
1
7
51 883 + -83 21 + -

1
9
1 2 3 * + 4 5 / -

1
3
- - -

1
7
5 8 + 8 2 + -

1
4
5 4 + -

*/


//param
int t;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int result = 0;
		stack<int> st;
		stack<string> sv;

		int acnt = 0;
		int bcnt = 0;

		while (n--) {
			string s;
			cin >> s;
			if (s == "+" || s == "-" || s == "*" || s == "/") {
				bcnt++;
				sv.push(s);
				if (acnt >= 2) {
					if (s == "+") {
						int second;
						int first;
						second = st.top();
						st.pop();
						first = st.top();
						st.pop();
						st.push(first + second);
						acnt--;
						sv.pop();
						continue;
					}
					if (s == "-") {
						int second;
						int first;
						second = st.top();
						st.pop();
						first = st.top();
						st.pop();
						st.push(first - second);
						acnt--;
						sv.pop();
						continue;
					}
					if (s == "/") {
						int second;
						int first;
						second = st.top();
						st.pop();
						first = st.top();
						st.pop();
						st.push(first / second);
						acnt--;
						sv.pop();
						continue;
					}
					if (s == "*") {
						int second;
						int first;
						second = st.top();
						st.pop();
						first = st.top();
						st.pop();
						st.push(first * second);
						acnt--;
						sv.pop();
						continue;
					}
				}
			}
			else {
				st.push(stoi(s));
				acnt++;
			}
		}
		if (st.size() == 1 && sv.empty()) {
			cout << st.top() << endl;
		}
		else if (!sv.empty() || st.size() > 1) {
			cout << "Incorrect Expression!" << endl;
		}
	}
}