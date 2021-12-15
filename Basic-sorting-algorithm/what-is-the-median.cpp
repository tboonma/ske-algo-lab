#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned int a;
    int arr[10000];
    int idx = 0;
    while (cin >> a) {
        if (a == EOF)
            break;
        arr[idx] = a;
        idx++;
        sort(arr, arr+idx);
        int med = (idx/2);
        int med_ans = arr[med];
        if (idx%2==0) {
            int temp = (idx/2)-1;
            med_ans = (med_ans+(arr[temp]))/2;
        }
        cout << med_ans << endl;
    }
    
}