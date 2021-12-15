#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct myString {
    stack<char> s;
    int num;
    myString* next;

    myString(int number, myString* n=0)
      : num(number), next(n) {}
};

myString* start = nullptr;

void insert(int index, char c, myString* str)
{
    if (start == nullptr) {
        myString* temp = new myString(index);
        temp->s.push(c);
        start = temp;
        return;
    }
    for (int i=0; i<index; i++) {
        if (str->next == 0) {
            myString* temp = new myString(index);
            str->next = temp;
        }
        str = str->next;
    }
    str->s.push(c);
}

int main() {
    int g, swap_index, num;
    string c;
    while (true) {
        start = nullptr;
        cin >> g;
        if (g == 0)
            break;
        cin >> c;
        swap_index = c.length() / g;
        // start = new myString(num);
        for (int i=0; i<c.length(); i++) {
            num = i/swap_index;

            insert(num, c[i], start);
        }
        myString* temp = start;
        while (temp != 0) {
            while (!temp->s.empty()) {
                cout << temp->s.top();
                temp->s.pop();
            }
            temp = temp->next;
        }
        cout << endl;
    }
}