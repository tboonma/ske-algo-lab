#include <iostream>
using namespace std;

int main() {
    int amount;
    cin >> amount;
    for (int i=0; i<amount; i++) {
        int pyramid[9][9];
        for (int j=0; j<9; j++)
            for (int k=0; k<9; k++)
                pyramid[j][k] = -1;
        for (int j=0; j<9; j+=2) {
            for (int k=0; k<=j; k+=2) {
                cin >> pyramid[j][k];
            }
        }
        for (int j=2; j<9; j+=2) {
            for (int k=1; k<j; k+=2) {
                pyramid[j][k] = (pyramid[j-2][k-1] - pyramid[j][k-1] - pyramid[j][k+1])/2;
                pyramid[j-1][k-1] = pyramid[j][k] + pyramid[j][k-1];
                pyramid[j-1][k] = pyramid[j][k] + pyramid[j][k+1];
            }
        }
        for (int j=0; j<9; j++, cout<<endl) {
            for (int k=0; k<=j; k++) {
                if (k)
                    cout << ' ';
                cout << pyramid[j][k];
            }
        }
    }
}

/*
2
255
54 67
10 18 13
3 3 5 2
2 1 2 1 1
256
64 64
16 16 16 
4 4 4 4
1 1 1 1 1
*/