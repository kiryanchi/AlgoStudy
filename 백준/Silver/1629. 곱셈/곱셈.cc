#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, m;

ll pow(ll a, ll b, ll m) {
    if (b == 1) return a % m;
    ll val = pow(a, b / 2, m);
    val = val * val % m;
    if (b % 2) return val * a % m;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> m;

    cout << pow(a, b, m);
}