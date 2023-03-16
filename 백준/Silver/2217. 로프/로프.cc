#include <bits/stdc++.h>
using namespace std;

int n;
int ropes[100002];

bool compare(const int &a, const int &b) {
    return a > b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ropes[i];

    sort(ropes+1, ropes+n+1, compare);

    int weight = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = ropes[i] * i;
        if (tmp > weight) weight = tmp;
    }

    cout << weight;
}