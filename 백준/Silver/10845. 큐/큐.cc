#include <iostream>
#include <queue>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string op;
    queue<int> Q;
    while (N--) {
        cin >> op;

        if (op == "push") {
            int item;
            cin >> item;

            Q.push(item);
        } else if (op == "pop") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (op =="size") {
            cout << Q.size() << '\n';
        } else if (op == "empty") {
            cout << (int)Q.empty() << '\n';
        } else if (op == "front") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
            }
        } else if (op == "back") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.back() << '\n';
            }
        }
    }
}