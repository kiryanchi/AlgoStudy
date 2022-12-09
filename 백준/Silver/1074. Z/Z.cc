#include <bits/stdc++.h>
using namespace std;

int func(int n, int x, int y) {
    if (n == 0) return 0;
    int half = 1 << (n-1);
    if (x < half && y < half) return func(n-1, x, y);
    if (x < half && y >= half) return half*half + func(n-1,x, y-half);
    if (x >= half && y < half) return 2*half*half + func(n-1, x-half, y);
    return 3*half*half + func(n-1, x-half, y-half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;

    int result = func(n, r, c);
    cout << result;
}