#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;

    queue<int> Q;

    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }

    while (Q.size() != 1) {
        Q.pop();

        Q.push(Q.front());

        Q.pop();
    }

    cout << Q.front();
    
    return 0;
}