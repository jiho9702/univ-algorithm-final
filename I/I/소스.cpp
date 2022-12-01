#include <iostream>
#include <vector>
using namespace std;

//param
int t;
vector<int> v;


int main() {

	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int money;
			cin >> money;
			v.push_back(money);
		}
	}
}