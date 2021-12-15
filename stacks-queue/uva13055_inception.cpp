#include <iostream>
#include <string>
#include <stack>
using namespace std;

string split_string(string st) {
    string name = "";
    for (int i=6; i<st.length(); i++) {
        name += st[i];
    }
    return name;
}

int main() {
    int n;
    string action;
    stack<string> dream;
    cin >> n;
    while(getline(cin, action)) {
        if (action[0] == 'S') {
            dream.push(split_string(action));
        }
        else if (action[0] == 'K') {
            if (!dream.empty())
                dream.pop();
        }
        else if (action[0] == 'T'){
            if (!dream.empty())
                cout << dream.top() << endl;
            else
                cout << "Not in a dream" << endl;
        }
        if (n-- <= 0)
            break;
    }
}