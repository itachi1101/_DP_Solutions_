#include<bits/stdc++.h>
using namespace std;
#define inf 1e9;
int main() {
	int n;
	cin >> n;
	int k; cin >> k;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<int>dp(n + 1);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = inf;
		for (int j = i - 1; j >= 1 and (i - j) <= k; j--) {
			dp[i] = min(dp[i], abs(v[i] - v[j]) + dp[j]) ;

		}
	}
	cout << dp[n];
	return 0;
}