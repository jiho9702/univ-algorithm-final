#include <iostream>
#include <algorithm>

using namespace std;

int sack[4] = { 1, 3, 7, 12 };
int dp[10001] = { 0, };
int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 

		for (int i = 1; i <= n; i++) dp[i] = 10001;

		for (int i = 0; i < 4; i++) { 
			for (int j = sack[i]; j <= n; j++) { 
				dp[j] = min(dp[j], dp[j - sack[i]] + 1);
			}
		}

		cout << dp[n] << '\n';
	}
}