#include <iostream>
// #include <fstream>
using namespace std;

char arr[105][105];

void find_alive(int length, int x, int y) {
    arr[x][y] = '#';
    if (x < length && (arr[x+1][y] == 'x' or arr[x+1][y] == '@')) {
        find_alive(length, x+1, y);
    }
    if (x > 0 && (arr[x-1][y] == 'x' or arr[x-1][y] == '@')) {
        find_alive(length, x-1, y);
    }
    if (y < length && (arr[x][y+1] == 'x' or arr[x][y+1] == '@')) {
        find_alive(length, x, y+1);
    }
    if (y > 0 && (arr[x][y-1] == 'x' or arr[x][y-1] == '@')) {
        find_alive(length, x, y-1);
    }
}

int main() {
    int n, x;
    cin >> n;
    // ofstream myfile;
    // myfile.open("output.txt");
    for (int i=0; i<n; i++) {
        cin >> x;
        int alive = 0;
        for (int j=0; j<x; j++) {
            for (int k=0; k<x; k++) {
                cin >> arr[j][k];
            }
        }
        for (int j=0; j<x; j++) {
            for (int k=0; k<x; k++) {
                if (arr[j][k] == 'x') {
                    find_alive(x, j, k);
                    alive++;
                }
            }
        }
        cout << "Case " << i+1 << ": " << alive << endl;
    }
    // myfile.close();
}