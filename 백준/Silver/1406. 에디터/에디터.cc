#include <iostream>
#include <list>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n;
    list<char> editor;

    cin >> s;

    for (auto c : s) {
        editor.push_back(c);
    }

    auto cur = editor.end();

    cin >> n;

    while (n--) {
        char op;
        cin >> op;
        if (op == 'P') {
            char c;
            cin >> c;
            editor.insert(cur, c);
        }
        else if (op == 'L') {
            if (cur != editor.begin()) cur--;
        }
        else if (op == 'D') {
            if (cur != editor.end()) cur++;
        }
        else if (op == 'B') {
            if (cur != editor.begin()) {
                cur--;
                cur = editor.erase(cur);
            }
        }
    }

    for (auto c : editor) cout << c;

    return 0;
}