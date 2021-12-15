#include <iostream>
using namespace std;

typedef int ValueType;
struct ListNode {
  ValueType val;
  ListNode* next;

  ListNode(ValueType v, ListNode* nxt=0)
    : val(v), next(nxt) {}
};

ListNode* front = nullptr;
ListNode* rear = nullptr;

void append(ListNode*& front, ListNode*& rear, ValueType x)
{
  ListNode* n = new ListNode(x);
  if (rear != nullptr) {
    rear->next = n;
    rear = n;
  } else {
    front = rear = n;
  }
}

ValueType extract(ListNode*& front, ListNode*& rear)
{
  ValueType v = front->val;

  ListNode* new_front = front->next;
  delete front;
  front = new_front;
  if (front == nullptr) {
    rear = nullptr;
  }
  return v;
}

int main()
{
  int m, id, served, remaining=0;

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int t;

    cin >> t;
    if (t == 1) {
      int n;
      cin >> n;
      // your code here
        for (int j=0; j<n; j++) {
            cin >> id;
            append(front, rear, id);
        }
    } else {
      // here, t = 2.  Call someone to the queue.
        served = extract(front, rear);
        cout << served << endl;
    }
  }

  // you have to print the number of remaining customers as well.
  // iterate the rest of the list here...
  while (true){
      remaining++;
      front = front->next;
        if (front == rear) {
            remaining++;
            break;
        }  
  }
  cout << remaining << endl;
}