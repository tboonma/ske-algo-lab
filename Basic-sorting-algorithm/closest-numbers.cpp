#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], diff;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int min_diff = abs(arr[0]-arr[1]);
    sort(arr, arr+n);
    for (int i=0; i<n-1; i++) {
        diff = abs(arr[i]-arr[i+1]);
        if (diff < min_diff) {
            min_diff = diff;
        }
        if (diff == 0)
            break;
    }
    cout << min_diff;
}