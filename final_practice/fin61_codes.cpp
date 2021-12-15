#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], diff1, diff2;
    map<int, int> diffs;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++) {
        diff1 = abs(arr[i]-arr[i+1]);
        if (diffs.count(diff1)) {
            diffs[diff1]++;
        } else {
            diffs[diff1] = 1;
        }
        if (i < n-2) {
            diff2 = abs(arr[i]-arr[i+2]);
            if (diffs.count(diff2)) {
                diffs[diff2]++;
            } else {
                diffs[diff2] = 1;
            }
        }
    }
    int number, occur=-999;
    for (auto i=diffs.begin(); i!=diffs.end(); i++) {
        if (i->second > occur) {
            number = i->first;
            occur = i->second;
        }
    }
    cout << number;
}