#include <iostream>
using namespace std;

void remove_quotes(char* src, char *dest)
{
    char* str1 = src;
    char* str2 = dest;
    while (true) {
        if (*str1 == '\"' || *str1 == '\'') {
            str1++;
            continue;
        }
        *str2 = *str1;
        if (*str1 == '\0')
            break;
        str2++;
        str1++;
    }
}

int main()
{
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  remove_quotes(st,out);

  cout << out << endl;
}