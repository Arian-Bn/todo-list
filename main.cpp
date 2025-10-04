#include <iostream>
using namespace std;

struct Task {
  int id;
  string test;
  bool isDone;
}

Task[100];
int taskCount = 0;
int nextId = 1;
