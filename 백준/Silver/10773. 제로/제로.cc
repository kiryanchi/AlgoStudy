// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;
    int n;
    int sum = 0;
    cin >> k;

    stack<int> S;

    while (k--) {
        cin >> n;

        if (n == 0) {
            S.pop();
        } else {
            S.push(n);
        }
    }

    for (; S.size() > 0; S.pop()) {
        sum += S.top();
    }

    // for (int i = 0; i < S.size(); i++) {
    //     sum += S.top();
    //     S.pop();
    // }

    cout << sum;
}