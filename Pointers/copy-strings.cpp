#include <iostream>
using namespace std;

void copy_string(char* src, char* dest)
{
    char* str1 = src;
    char* str2 = dest;
    while (true) {
        *str2 = *str1;
        if (*str1 == '\0')
            break;
        str2++;
        str1++;
    }
}

int main()
{
  char st1[1000];
  char st2[1000];

  cin.getline(st1,1000);
  copy_string(st1,st2);

  cout << st2 << endl;
}