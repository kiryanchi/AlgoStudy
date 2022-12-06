#include <bits/stdc++.h>
using namespace std;

int alphabets[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for (auto c : str) {
        c = tolower(c);
        alphabets[c - 'a']++;
    }

    // for (auto i : alphabets) cout << i << ' ';

    bool is_dup = false;
    int mx = 0;
    int idx = -1;

    for (int i = 0; i < 26; i++) {
        if (alphabets[i] > mx) {
            is_dup = false;
            mx = alphabets[i];
            idx = i;
        } else if (alphabets[i] == mx) {
            is_dup = true;
        }
    }
    char ch = 'a' + idx;
    ch = toupper(ch);
    if (is_dup) cout << '?';
    else cout << ch;
}