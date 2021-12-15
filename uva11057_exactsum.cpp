#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, temp, money, price1, price2, total_price, new_idx, diff;
    while(cin >> n) {
        vector<int> price;
        for (int i=0; i<n; i++) {
            cin >> temp;
            price.push_back(temp);
        }
        cin >> money;
        int idx = price.size()-2, nearest = INT_MAX;
        sort(price.begin(), price.end());
        while (true) {
            for (int i=idx+1; i<price.size(); i++) {
                total_price = price[idx] + price[i];
                diff = money - total_price;
                if (total_price <= money) {
                    if (diff < nearest) {
                        nearest = diff;
                        price1 = price[idx];
                        price2 = price[i];
                    }
                } else {
                    break;
                }
            }
            idx--;
            if (idx < 0)
                break;
        }
        cout << "Peter should buy books whose prices are " << price1 << " and " << price2 << "." << endl << endl;
    }
}