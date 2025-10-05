#include <iostream>
using namespace std;

void showMenu(void);
unsigned getChoice(void);

int main() {
  while (true) {
    showMenu();
    unsigned choice = getChoice();

    switch (choice) {
    case 1:
      desplayTasks();
      break;
    case 2:
      addTask();
      break;
    case 3:
      removeTask();
      break;
    case 4:
      markCompleted();
      break;
    case 0:
      return 0;
    }
  }

  return 0;
}

void showMenu(void) {
  cout << "---Menu---" << endl;
  cout << "1. Show all tasks" << endl;
  cout << "2. Add task" << endl;
  cout << "3. Delete task" << endl;
  cout << "4. Mark as completed" << endl;
  cout << "0. Exit";
}

unsigned getChoice(void) {
  unsigned choice;

  while (true) {
    cout << "Enter your choice (0-4): ";
    cin >> choice;

    if (cin.fail() || choice < 0 || choice > 4) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid input! Please enter 0-4.\n";
    } else {
      cin.ignore(1000, '\n');
      return choice;
    }
  }
}
