#include<bits/stdc++.h>
#define inf 1e9
#define ll long long
using namespace std;
struct item {
	int wt;
	int val;
};
ll solve(vector<item>ar, int n, int W) {
	ll dp[n + 1][W + 1];
	for (int w = 0; w <= W; w++)dp[1][w] = 0;

	dp[1][ar[1].wt] = ar[1].val;
	for (int i = 2; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			dp[i][w] = dp[i - 1][w];
			if (ar[i].wt > w)continue;
			dp[i][w] = max(dp[i][w], ar[i].val + dp[i - 1][w - ar[i].wt]);
		}
	}
	return *max_element(dp[n], dp[n] + W + 1);
}
int main() {
	int n, w;
	cin >> n >> w;
	vector<item>arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].wt >> arr[i].val;
	}
	cout << solve(arr, n, w);
}