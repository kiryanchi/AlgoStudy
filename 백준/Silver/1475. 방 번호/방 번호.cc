#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n > 0) {
        int num = n % 10;
        
        // solve
        arr[num]++;
        // solve done
        
        n /= 10;
    }
    
    int sum_of_69 = (arr[6] + arr[9]);
    
    arr[6] = sum_of_69 / 2;
    if (sum_of_69 % 2) {
        arr[6]++;
    }
    arr[9] = arr[6];
    
    int tmp = -1;
    for (auto i : arr) {
        if (tmp < i) {
            tmp = i;
        }
    }
    
    cout << tmp;
    return 0;
}