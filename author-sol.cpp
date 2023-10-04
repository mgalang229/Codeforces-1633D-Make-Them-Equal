#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1001;

int w[MAX_N];

void test_case(int& tc) {
	int n, k;
	cin >> n >> k;
	int b[n], c[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int sum = 0;
	for (int x : b)
		sum += w[x];
	k = min(k, sum);
	int dp[k+1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = k - w[b[i]]; j >= 0; j--)
			dp[j+w[b[i]]] = max(dp[j+w[b[i]]], dp[j] + c[i]);
	}
	cout << *max_element(dp, dp + k + 1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// precompute weights (min no. of operations)
	for (int i = 0; i < MAX_N; i++)
		w[i] = MAX_N;
	w[1] = 0;
	for (int i = 1; i < MAX_N; i++) {
		for (int x = 1; x <= i; x++) {
			int next = i + i / x;
			if (next < MAX_N)
				w[next] = min(w[next], w[i] + 1);
		}
	}
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
