#include <iostream>
using namespace std;

struct CookieSlot {
    int id;
    CookieSlot* next;

    CookieSlot(int n, CookieSlot* c=0) 
       : id(n), next(c) {}
};

CookieSlot* front = nullptr;

void insert(CookieSlot*& front, int k, int num)
{
    if (k == 0) {
        CookieSlot* temp = new CookieSlot(num, front);
        front = temp;
        return;
    }
    if (front == nullptr) {
        CookieSlot* temp = new CookieSlot(num, front);
        front = temp;
        return;
    }
    CookieSlot* temp = front;
    while (k--) {
        if (k == 0) {
            CookieSlot* temp2 = new CookieSlot(num, temp->next);
            temp->next = temp2;
            return;
        }
        if (temp->next == nullptr) {
            CookieSlot* temp2 = new CookieSlot(num);
            temp->next = temp2;
            return;
        }
        temp = temp->next;
    }
}

void eat(CookieSlot*& front, int k)
{
    if (front == nullptr)
        return;
    if (k == 1) {
        CookieSlot* temp = front->next;
        delete front;
        front = temp;
        return;
    }
    CookieSlot* temp = front;
    CookieSlot* temp2 = front; 
    for (int i=1; i<k; i++) {
        temp2 = temp;
        temp = temp->next;
        if (temp == nullptr)
            return;
    }
    temp2->next = temp->next;
    delete temp;
    return;
}

int main() {
    int step, oper, k, num;
    cin >> step;
    while (step--) {
        cin >> oper >> k;
        if (oper == 1) {
            cin >> num;
            insert(front, k, num);
        } else {
            eat(front, k);
        }
    }
    while (front != nullptr) {
        cout << front->id << endl;
        front = front->next;
    }
    return 0;
}