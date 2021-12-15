#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cases, n, P, Q, maximum, weight;
    cin >> cases;
    for (int i=0; i<cases; i++) {
        cin >> n >> P >> Q;
        int egg[n];
        for (int j=0; j<n; j++) {
            cin >> egg[j];
        }
        sort(egg, egg+n);
        maximum = 0;
        weight = 0;
        for (int j=0; j<n; j++) {
            if (weight+egg[j] > Q || maximum == P)
                break;
            weight += egg[j];
            maximum++;
        }
        cout << "Case " << i+1 << ": " << maximum << endl;
    }
}
