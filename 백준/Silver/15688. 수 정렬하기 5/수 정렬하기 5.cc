#include <bits/stdc++.h>
using namespace std;

int n;
int tmp[2000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        tmp[num + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++) {
        while (tmp[i]--) cout << i-1000000 << '\n';
    }
}