#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
pair<int, int> dp[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[1] = {0, 0};
    dp[2] = {1, 1};
    dp[3] = {1, 1};

    int i = 4;
    while (i <= n) {
        dp[i] = {dp[i-1].X + 1, i-1};

        if (i % 2 == 0 && dp[i/2].X < dp[i].X-1) {
            dp[i] = {dp[i/2].X + 1, i/2};
        }

        if (i % 3 == 0 && dp[i/3].X < dp[i].X-1) {
            dp[i] = {dp[i/3].X + 1, i/3};
        }

        i++;
    }

    cout << dp[n].X << '\n';
    cout << n << ' ';
    while (dp[n].Y > 0) {
        cout << dp[n].Y << ' ';
        n = dp[n].Y;
    }
}