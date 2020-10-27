# include<bits/stdc++.h>
#define inf 1e9
using namespace std;
struct activity {
	int a, b, c;
};
int solve(vector<activity>v, int n) {
	int dp[n + 1][3];
	dp[1][0] = v[1].a;
	dp[1][1] = v[1].b;
	dp[1][2] = v[1].c;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = v[i].a + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = v[i].b + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = v[i].c + max(dp[i - 1][0], dp[i - 1][1]);

	}
	return max(dp[n][0], max(dp[n][1], dp[n][2]));
}
int main() {
	int n; cin >> n;
	vector<activity>ar(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].a;
		cin >> ar[i].b;
		cin >> ar[i].c;
	}
	cout << solve(ar, n);
	return 0;
}