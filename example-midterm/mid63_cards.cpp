#include <iostream>
using namespace std;

int main() {
    int n, m, val;
    cin >> n >> m;
    int card[n];
    for (int i=0; i<n; i++) {
        cin >> card[i];
    }
    int *start = &card[0], *end = &card[n-1];
    int *p = start;
    for (int i=0; i<m; i++) {
        cin >> val;
        int summ = 0;
        while (true) {
            if (p == end+1)
                p = start;
            if (*p == -1) {
                p++;
                continue;
            }
            summ += *p;
            if (summ >= val) {
                *p = -1;
                p++;
                break;
            }
            p++;
        }
    }
    for (int i=0; i<n; i++) {
        if (card[i] != -1)
            cout << card[i] << endl;
    }
}