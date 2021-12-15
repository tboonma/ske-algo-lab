#include <iostream>
#include <algorithm>
using namespace std;

int answer[101];

int main() {
    int n, d, r;
    while (true) {
        int ot = 0;
        cin >> n >> d >> r;
        int morning[n], evening[n];
        if (n==0 && d==0 && r==0)
            break;
        for (int i=0; i<n; i++) {
            cin >> morning[i];
        }
        for (int i=0; i<n; i++) {
            cin >> evening[i];
        }
        sort(morning, morning+n);
        sort(evening, evening+n, greater<int>());
        for (int i=0; i<n; i++) {
            if (morning[i] + evening[i] > d) {
                ot += ((morning[i]+evening[i]) - d)*r;
            }
        }
        cout << ot << endl;
    }
}