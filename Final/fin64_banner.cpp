#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, largest_size=-1;
    cin >> n;
    long long pole[n+5];
    for (int i=1; i<=n; i++) {
        cin >> pole[i];
    }
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (pole[i] == pole[j] && abs(j - i) >= largest_size) {
                largest_size = abs(j - i);
                break;
            } else if (pole[i] == pole[j]) {
                break;
            }
        }
    }
    cout << largest_size;
}

/*
10
10
1
10
3
2
2
10
7
3
9
*/