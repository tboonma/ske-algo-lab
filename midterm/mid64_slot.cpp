#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[4][4], point = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        point = 0;
        for (int i=0; i<4; i++) {
            if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] == arr[i][3]) {
                point++;
            }
        }
        if (point == 4)
            break;
    }
    cout << point;
}

/*
0 0 0 0
2 2 2 2
3 3 3 3
4 4 4 4
*/