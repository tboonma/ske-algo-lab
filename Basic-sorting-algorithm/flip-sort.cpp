#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == EOF)
            break;
        int arr[n];
        for (int i=0; i<n; i++)
            cin >> arr[i];
        int min_flip = 0;
        // Selection Sort
        // for (int i=0; i<n-1; i++) {
        //     int min_idx = i;
        //     int min_val = arr[i];
        //     for (int j=i+1; j<n; j++) {
        //         if (arr[j] < min_val) {
        //             min_idx = j;
        //             min_val = arr[j];
        //         }
        //     }
        //     if (min_val < arr[i]) {
        //         int temp = arr[i];
        //         arr[i] = arr[min_idx];
        //         arr[min_idx] = temp;
        //         min_flip++;
        //         cout << temp << endl;
        //     }
        // }

        // Bubble sort
        while(true) {
            bool changed = false;
            for(int i=0; i <n-1; i++) {
            // compares a[i] with a[i+1]
                if(arr[i] > arr[i+1]) {
                    // wrong order, swap them;  don't forget to update changed variable
                    
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    changed = true;
                    min_flip++;
                }
            }
            if(!changed)
            break;
        }
        cout << "Minimum exchange operations : " << min_flip << endl;

    }
}