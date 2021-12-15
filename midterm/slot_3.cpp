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
    for (int num_flip=1; num_flip<=4; num_flip++) {
        for (int i=0; i<num_flip; i++) {
            for (int j=0; j<4; j++) {
                point = 0;
                for (int k=0; k<4; k++) {
                    if (arr1[k] == arr2[k] && arr1[k] == arr3[k] && arr1[k] == arr4[k]) {
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
            }
        }
    }
}