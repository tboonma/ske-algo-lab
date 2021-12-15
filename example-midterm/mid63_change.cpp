#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, x, y, maximum=0;
    cin >> n >> k;
    int summ[n];
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        summ[i] = x-y;
    }
    sort(summ, summ+n);
    int i = 0;
    while (k-- > 0) {
        if (summ[i] < 0)
            summ[i] = 0;
        i++;
    }
    for (int i=0; i<n; i++) {
        maximum += summ[i];
    }
    cout << maximum;
}