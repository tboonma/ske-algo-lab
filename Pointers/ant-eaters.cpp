#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int all_ants = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        if (a[i] >= 1000)
        {
            all_ants += 1000;
            i++;
        }
        else
            all_ants += a[i];
    }
    cout << all_ants;
}
