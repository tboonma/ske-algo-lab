#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int number[n];
    int taller[n];
    for (int i=0; i<n; i++) {
        cin >> number[i];
        taller[i] = 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j == i) continue;
            if (number[i] < number[j]) taller[i]++;
        }
    }
    for (int i=0; i<n; i++) {
        cout << taller[i] << endl;
    }
}