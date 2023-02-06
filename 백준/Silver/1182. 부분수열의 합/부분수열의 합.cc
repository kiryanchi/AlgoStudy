#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int nums[25];
int isUsed[25];

void solve(int sum, int idx) {
    if (idx == n) {
        if (sum == s) cnt++;
        return;
    }

    solve(sum + nums[idx], idx + 1);
    solve(sum, idx + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    solve(0, 0);
    
    if (s == 0) cnt--;

    cout << cnt;
}