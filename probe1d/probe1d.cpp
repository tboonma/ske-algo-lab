#include "probelib.h"
#include <iostream>
#include <math.h>
using namespace std;

int n;

int main()
{
  int n = probe_init();
  double running = n, i = 0, prev_running = n;
  while (true) {
      if (i == running) {
          probe_answer(i);
      } else if (probe_check(i, running-1)) {
          prev_running = running;
          running = running - ceil((running-i)/2);
          continue;
      } else {
          i = running;
          running = running + ceil((prev_running-running)/2);
          continue;
      }
  }
}