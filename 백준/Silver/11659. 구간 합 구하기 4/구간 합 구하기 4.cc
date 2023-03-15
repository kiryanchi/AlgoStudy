#include <bits/stdc++.h>
using namespace std;

int n, m, ii, jj, sum, num;
int dp[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> dp[1];

    for (int i = 2; i <= n; i++) {
        cin >> num;
        dp[i] = dp[i-1] + num;
    }

    for (int i = 0; i < m; i++) {
        cin >> ii >> jj;
        cout << dp[jj] - dp[ii-1] << '\n';
    }
}