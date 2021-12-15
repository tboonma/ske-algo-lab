#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;
    vector<int> arr4;
    int a, b, c, d, point, max_point=0;
    for (int i=0; i<4; i++) {
        cin >> a >> b >> c >> d;
        arr1.push_back(a);
        arr2.push_back(b);
        arr3.push_back(c);
        arr4.push_back(d);
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) {
                    point = 0;
                    for (int a=0; a<4; a++) {
                        if (arr1[a] == arr2[a] && arr1[a] == arr3[a] && arr1[a] == arr4[a]) {
                            point++;
                        }
                    }
                    if (point == 4) {
                        max_point = point;
                        break;
                    }
                    if (point > max_point)
                        max_point = point;
                    arr4.insert(arr4.begin(), arr4.back());
                    arr4.pop_back();
                }
                if (max_point == 4)
                    break;
                arr3.insert(arr3.begin(), arr3.back());
                arr3.pop_back();
            }
            if (max_point == 4)
                break;
            arr2.insert(arr2.begin(), arr2.back());
            arr2.pop_back();
        }
        if (max_point == 4)
            break;
        arr1.insert(arr1.begin(), arr1.back());
        arr1.pop_back();
    }
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