#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int i = min(a, b);
    int normalized_a = a, normalized_b = b;
    while (i >= 0) {
        if (a%i==0 && b%i==0) {
            normalized_a = a/i;
            normalized_b = b/i;
            break;
        }
        i--;
    }
    cout << normalized_a << "/" << normalized_b;
}