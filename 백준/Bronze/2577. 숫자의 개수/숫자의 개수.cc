// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int used[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    
    int number = a * b * c;
    
    while (number > 0) {
        used[number % 10]++;
        number /= 10;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << used[i] << '\n';
    }
}