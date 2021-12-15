#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n, l, pairs=0;
    cin >> n >> l;
    int house[n];
    for (int i=0; i<n; i++) {
        cin >> house[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (abs(house[i]-house[j]) <= l) {
                pairs++;
            }
        }
    }
    cout << pairs;
}