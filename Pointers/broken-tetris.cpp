#include <iostream>
using namespace std;

int main() {
    int n, p;
    char a;
    cin >> n;
    bool t[100000][11];
    for (int i=0; i<100000; i++) {
        for (int j=0; j<=10; j++) {
            t[i][j] = 0;
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> a >> p;
        if (a == '-') 
            for (int j=1; j<=n*4; j++) {
                if (t[j][p] == 0 && t[j][p+1] == 0 && t[j][p+2] == 0 && t[j][p+3] == 0) {
                    t[j][p] = t[j][p+1] = t[j][p+2] = t[j][p+3] = 1;
                    break;
                }
            }
        else if (a == 'i') {
            for (int j=1; j<=n*4; j++) {
                if (t[j][p] == 0 && t[j+1][p] == 0 && t[j+2][p] == 0 && t[j+3][p] == 0) {
                    t[j][p] = t[j+1][p] = t[j+2][p] = t[j+3][p] = 1;
                    break;
                }
            }
        }
        else if (a == 'o') {
            for (int j=1; j<=n*4; j++) {
                if (t[j][p] == 0 && t[j+1][p] == 0 && t[j][p+1] == 0 && t[j+1][p+1] == 0) {
                    t[j][p] = t[j+1][p] = t[j][p+1] = t[j+1][p+1] = 1;
                    break;
                }
            }
        }
    }
    int maximum = 0;
    for (int i=1; i<=n*4; i++) {
        for (int j=1; j<=10; j++) {
            if (t[i][j] == 1) {
                maximum = i;
                break;
            }
        }
        if (maximum < i)
            break;
    }
    cout << maximum << endl;
    for (int i=1; i<=n*4; i++) {
        for (int j=1; j<=10; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

// testcases
/*
5
i 1
- 2
i 3
- 2
o 3
*/