#include <iostream>

using namespace std;

int find_last(int* p, int n, int k)
{
    int* man = p;
    int* last_man = p+n-1;
    int count = 1;
    while (true) {
        if (man > last_man) {
            man = p;
        }
        if (n == 1) {
            if (*man == 0) {
                man++;
                continue;
            }
            return *man;
        }
        if (*man == 0) {
            man++;
            continue;
        }
        if (count == k) {
            *man = 0;
            count = 0;
            n--;
        }
        // cout << n << ndl;
        count++;
        man++;
    }
}

int main() 
{
    int n, k;
    cin >> n >> k;
    int person[n];
    for (int i=0; i<n; i++)
        person[i] = i+1;
    cout << find_last(person, n, k);
}
