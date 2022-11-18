#include <bits/stdc++.h>

using namespace std;


int N, X;
int arr[10000];


void solve() {
    for (int i = 0; i < N; i++) {
        if (arr[i] < X) {
            cout << arr[i] << " ";
        }
    }
}

void init() {
    
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}