#include <iostream>
using namespace std;

bool check_prime(int n)
{
    for (int i=2; i<=n/2; i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}

int get_pfactor(int n)
{
    int prime_factor = 0;
    for (int i=2; i<=n; i++) {
        if (n%i == 0) {
            if (check_prime(i))
                prime_factor++;
        }
    }
    return prime_factor;
}

int main() {
    int n;
    cin >> n;
    cout << get_pfactor(n);
}