#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, temp;
    cin >> n >> k;
    vector<int> order;
    for (int i=0; i<n; i++) {
        bool consec = true;
        cin >> temp;
        order.push_back(temp);
        for (int j=0; j<k && i>=k-1; j++) {
            if (order.size() < k || order.at(order.size()-j-1) != temp) {
                consec = false;
                break;
            }
        }
        if (consec && i>=k-1) {
            order.erase(order.end()-k, order.end());
        }
    }
    cout << order.size();
}
