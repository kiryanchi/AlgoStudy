#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cnt = 0;
    cin >> n >> m;

    deque<int> dq;

    for (int i=1; i <= n; i++) dq.push_back(i);

    while (m--) {
        int target;
        cin >> target;

        int pos = find(dq.begin(), dq.end(), target) - dq.begin();
        while (dq.front() != target) {
            if (pos < dq.size() - pos) {
                dq.push_back(dq.front());
                dq.pop_front();
            }

            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            cnt++;
        }

        dq.pop_front();
    }

    cout << cnt;

    return 0;
}