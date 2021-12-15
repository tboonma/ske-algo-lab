#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int arr[a];
    int k = a/b;
    for (int i=0; i<a; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+a);
    for (int i=1; i<=k; i++) {
        cout << arr[(b*i)-1] << endl;
    }
}