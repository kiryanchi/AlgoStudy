// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i = 1, m;
    stack<int> S;
    cin >> n;

    string ans = "";
    while (n--) {
        cin >> m;

        for (; i < m + 1; i++) {
            S.push(i);
            ans += "+\n";
        }

        if (S.top() == m) {
            S.pop();
            ans += "-\n";
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << ans;
}