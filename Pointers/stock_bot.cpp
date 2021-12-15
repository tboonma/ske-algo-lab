#include <iostream>
using namespace std;

int calculate(int* stock, int n, int min_diff)
{
    int diff = 0;
    bool hold = false;
    int summ = 0;
    int last_buy = 0;
    for (int i=0; i<n-1; i++,stock++) {
        diff = *(stock+1) - *stock;
        if (hold == false && diff >= min_diff) {
            hold = true;
            summ -= *(stock+1);
            last_buy = *(stock+1);
            // cout << "Buy on day" << i+2 << ": " << summ << endl;
        }
        else if (hold && diff <= -(min_diff)) {
            hold = false;
            summ += *(stock+1);
            // cout << "Sell on day" << i+2 << ": " << summ << endl;
        }
    }
    if (hold) {
        summ += last_buy;
    }
    return summ;
}


int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << calculate(a, n, k);
}