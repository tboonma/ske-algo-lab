#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int n, q, item, lottery, maximum_prize, reward_price;
    cin >> n >> q;
    long long arr[n+5];
    set< long long, greater<long long> > price;
    map<int, int> product;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        price.insert(arr[i]);
        product[arr[i]] = i;
    }
    for (int i=0; i<q; i++) {
        cin >> item >> lottery;
        maximum_prize = arr[item] + lottery;
        reward_price = *(price.lower_bound(maximum_prize));
        cout << product[reward_price] << "\n";
    }
}