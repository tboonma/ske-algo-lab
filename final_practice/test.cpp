#include <iostream>
using namespace std;

bool check_list(int l[], int n) {
    if (n > 6)
        return true;
    for (int i=0; i<n; i++) {
        cout << l[i] << endl;
    }
    l[n] = 6;
    return check_list(l, n+1);

}

int main() {
    int arr[6] = {1, 2, 3, 4, 5};
    int n = 5;
    check_list(arr, n);
}