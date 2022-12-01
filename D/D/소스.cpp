#include <iostream>
#include <string>
#include <queue>

using namespace std;

//param
int T;
int N;

int main() {

	cin >> T;
	while (T--) {
		cin >> N;
		queue<int> q;
		while (N--) {
			
			string s;
			int id;
			cin >> s;
			if (s == "In") {
				cin >> id;
				q.push(id);
			}
			else if (s == "Out") {
				if (!q.empty()) {
					cout << q.front() << "\n";
					q.pop();
				}
				else {
					cout << "Empty" << "\n";
				}
			}
		}
	}
}