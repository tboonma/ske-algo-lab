#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, fire_required=1;
    long r;
    cin >> n >> r;
    long arr[n];
    vector< pair<long, long> > fire;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        fire.push_back(make_pair(arr[i]-r, arr[i]+r));
    }
    sort(fire.begin(), fire.end());
    long edge_pos = fire.begin()->second;
    for (auto i=fire.begin(); i!=fire.end(); i++) {
        if (edge_pos - i->first < 0) {
            fire_required++;
            edge_pos = i->second;
        }
    }
    cout << fire_required;
}