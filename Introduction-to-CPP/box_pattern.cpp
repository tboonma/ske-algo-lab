#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int box[n];
    for (int i=1; i<=n; i++) {
        box[i-1] = i;
    }
    for (int i=0; i<n; i++) {
        int j=i, count=0;
        while (count < n) {
            cout << box[j];
            j++; count++;
            if (j >= n) {
                j = 0;
            }
        }
        cout << endl;
    }
}