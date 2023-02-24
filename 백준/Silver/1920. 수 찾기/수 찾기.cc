#include <bits/stdc++.h>
using namespace std;

int n, m, num;
int l, r, mid;
int A[100005];

bool found(int x) {
    l = 0, r = n - 1;

    bool is_found = false;
    while (l <= r) {
        mid = (l + r) / 2;
        if (A[mid] == x) {
            is_found = true;
            break;
        }
        else if (A[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return is_found;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A, A+n);

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> num;

        cout << found(num) << '\n';
    }
}