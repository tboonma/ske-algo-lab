#include <iostream>
using namespace std;

struct House {
    int height;
    House* back;
    House* next;

    House(int h, House* b=0, House* n=0)
        : height(h), back(b), next(n) {}
};

int main() {
    int n, h, consec=1, plateau=0, swamp=0;
    cin >> n;
    int house[n];
    for (int i=0; i<n; i++) {
        cin >> house[i];
    }
    int *p = &house[1], *last = &house[n-1];
    int *left, *right;
    while (true) {
        if (p >= last)
            break;
        consec = 1;
        while (true) {
            left = p-consec;
            right = p+1;
            if (right > last) {
                break;
            }
            else if (*p == *right) {
                consec++;
                p++;
                continue;
            }
            else if (*p < *left && *p < *right) {
                swamp += consec;
                break;
            }
            else if (*p > *left && *p > *right) {
                plateau += consec;
                break;
            }
            else
                break;
        }
        p++;
    }
    cout << plateau << " " << swamp;
}