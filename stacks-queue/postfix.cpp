#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
typedef double ValueType;

struct ListNode {
  ValueType val;
  ListNode* next;

  ListNode(ValueType val, ListNode* next=nullptr)
    : val(val), next(next) {}
};

ValueType pop(ListNode*& head)
{ 
  ListNode* next = head->next;
  ValueType x = head->val;
  delete head;
  head = next;

  return x; 
}

void push(ListNode*& head, ValueType x)
{
  ListNode* new_node = new ListNode(x, head);
  head = new_node;
}


int main()
{
  string buffer;

  ListNode* head = nullptr;

  do {
    cin >> buffer;
    if(buffer.at(0) == '=') {
      break;
    } else if((buffer.at(0) >= '0') && (buffer.at(0) <= '9')) {
      double val = stod(buffer);
      // *****************************
      // insert val into the top of the stack
      ListNode* temp = new ListNode(val);
      if (head == nullptr) {
          head = temp;
      } else {
          temp->next = head;
          head = temp;
      }
      ListNode* temp2 = head;
    } else {
      // *****************************
      // buffer is an operator.
      // your code here
      if (buffer == "+") {
          head->val += head->next->val;
      } else if (buffer == "-") {
          head->val = head->next->val - head->val;
      } else if (buffer == "*") {
          head->val *= head->next->val;
      } else if (buffer == "/") {
          head->val = head->next->val / head->val;
      }
      if (head->next != nullptr) {
          ListNode* temp = head->next;
          head->next = head->next->next;
          delete temp;
      }
      else {
          head->next = nullptr;
      }
      ListNode* temp = head;
    }
  } while(true);
  cout << fixed << setprecision(4) << head->val << endl;
}