#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
  for(int i = 1; i < n; i++) {
    int j = i;  // try to insert a[i] in to the already sorted array a[0],...,a[i-1]
    while(j > 0) {
      // our current element is in a[j]

      // compares a[j] with a[j-1]
      if(a[j-1] > a[j]) {
        // need to swap a[j] with its preceding element
        int temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
      } else {
        break;
      }
      j--;
    }
  }
}

main()
{
  int a[1000];
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  insertion_sort(a, n);
  for(int i=0; i<n; i++)
    cout << a[i] << endl;
}