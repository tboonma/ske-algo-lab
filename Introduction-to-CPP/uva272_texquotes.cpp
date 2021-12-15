#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string st;
    bool first = true;
    while(getline(cin, st)) {
        // cout << endl;
        int len = st.length();
        char char_array[len + 1];
        strcpy(char_array, st.c_str());
        for (int i=0; i<len; i++) {
            if (char_array[i] == '"') {
                if (first)
                {
                    cout << "``";
                    first = false;
                }
                else
                {
                    cout << "''";
                    first = true;
                }
            }
            else
                cout << char_array[i];
        }
        cout << endl;
    }
    return 0;
}