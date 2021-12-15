#include <iostream>
using namespace std;

int count_char(char* st, char c)
{
    char* p = st;
    int count = 0;
    char want = c;
    while (true)
    {
        if (*p == want)
            count++;
        else if (*p == '\0')
            break;
        p++;
        c++;
    }
    return count;
}

int main()
{
  char st[1000];

  cin.getline(st,1000);

  cout << "space: " << count_char(st,' ') << endl;
  cout << "dot: " << count_char(st,'.') << endl;
  cout << "semi: " << count_char(st,';') << endl;
}