#include <iostream>
using namespace std;

struct Dog {
  int age;
  double weight;
  double speed;
};

bool heavier(Dog d1, Dog d2) {
    return d1.weight > d2.weight;
}

Dog read_dog()
{
  Dog d;
  cin >> d.age >> d.weight >> d.speed;
  return d;
}

int main()
{
  Dog dang = read_dog();
  Dog dum = read_dog();
  if(heavier(dang, dum)) {
    cout << "Dang is heavier" << endl;
  } else {
    cout << "Dang is not heavier" << endl;
  }
}