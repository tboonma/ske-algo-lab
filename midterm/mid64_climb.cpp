#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h=0, last_h, energy=0;
    int m = 0;
    bool is_upper = false;
    for (int i=0; i<n; i++) {
        last_h = h;
        cin >> h;
        if (h-last_h > 0) {
            if (is_upper)
                m++;
            else 
                is_upper = true;
            energy += h-last_h;
            energy += m;
        }
        else {
            m = 0;
            is_upper = false;
        }

    }
    cout << energy;
}