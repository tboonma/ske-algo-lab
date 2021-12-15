#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;
    vector<int> arr4;
    int a, b, c, d, point, max_point=0, swap_point=4, swap_round=1;
    bool should_exit = false;
    for (int i=0; i<4; i++) {
        cin >> a >> b >> c >> d;
        arr1.push_back(a);
        arr2.push_back(b);
        arr3.push_back(c);
        arr4.push_back(d);
    }
    // while (true) {
    //     point = 0;
    //     for (int i=0; i<4; i++) {
    //         cout << arr1[i] << arr2[i] << arr3[i] << arr4[i] << endl;
    //     }
    //     cout << endl;
    //     for (int i=0; i<4; i++) {
    //         if (arr1[i] == arr2[i] && arr1[i] == arr3[i] && arr1[i] == arr4[i]) {
    //             cout << point << endl;
    //             point++;
    //         }
    //     }
    //     if (point == 4) {
    //         max_point = point;
    //         break;
    //     }
    //     if (point > max_point)
    //         max_point = point;
    for (int j=swap_point; j<=4; j++) {
        for (int i=0; i<swap_round; i++) {
            for (int i=0; i<4; i++) {
                cout << arr1[i] << arr2[i] << arr3[i] << arr4[i] << endl;
            }
            cout << endl;
            point = 0;
            for (int i=0; i<4; i++) {
                if (arr1[i] == arr2[i] && arr1[i] == arr3[i] && arr1[i] == arr4[i]) {
                    cout << point << endl;
                    point++;
                }
            }
            if (point == 4) {
                max_point = point;
                break;
            }
            if (point > max_point)
                max_point = point;
            if (j == 1) {
                arr1.insert(arr1.begin(), arr1.back());
                arr1.pop_back();
            }
            else if (j == 2) {
                arr2.insert(arr2.begin(), arr2.back());
                arr2.pop_back();
            }
            else if (j == 3) {
                arr3.insert(arr3.begin(), arr3.back());
                arr3.pop_back();
            }
            else if (j == 4) {
                arr4.insert(arr4.begin(), arr4.back());
                arr4.pop_back();
            }
            swap_round++;
            if (swap_point == 1 && swap_round == 4)
                should_exit = true;
            else if (swap_round > 4 && j == 4) {
                swap_round = 1;
                swap_point--;
            }
            else if (swap_round > 4) {
                swap_round = 1;
            }
        }
    }
    //     if (should_exit)
    //         break;
    // }
    cout << max_point;
}

/*
0 0 0 0
2 2 2 2
3 3 3 3
4 4 4 4

9 3 1 4
1 9 3 1
3 5 9 3
2 1 6 9
*/