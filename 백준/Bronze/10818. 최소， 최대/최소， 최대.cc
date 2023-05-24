#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int max_number = -10000000;
    int min_number = 10000000;
    
    while (n--) {
        int tmp;
        scanf("%d", &tmp);
        
        if (tmp > max_number) {
            max_number = tmp;
        }
        
        if (tmp < min_number) {
            min_number = tmp;
        }
    }
    
    printf("%d %d\n", min_number, max_number);
}