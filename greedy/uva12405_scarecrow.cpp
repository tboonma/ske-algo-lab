#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        int N, amount=0;
        cin >> N;
        char field[N];
        for (int j=0; j<N; j++) {
            cin >> field[j];
        }
        for (int j=0; j<N; j++) {
            if (field[j]=='.') {
                amount++;
                j += 2;
            }
        }
        cout << "Case " << i+1 << ": " << amount << endl;
    }
}