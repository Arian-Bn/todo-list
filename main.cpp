#include <iostream>
using namespace std;

string tasks[100];
bool completed[100];
int taskCount = 0;

void showMenu();
unsigned getChoice();
void displayTasks();
void addTask();
void removeTask();
void markCompleted();

int main() {
  while (true) {
    showMenu();
    unsigned choice = getChoice();

    switch (choice) {
    case 1:
      displayTasks();
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

void showMenu() {
  cout << "---Menu---" << endl;
  cout << "1. Show all tasks" << endl;
  cout << "2. Add task" << endl;
  cout << "3. Delete task" << endl;
  cout << "4. Mark as completed" << endl;
  cout << "0. Exit" << endl;
}

unsigned getChoice() {
  unsigned choice;

  while (true) {
    cout << "\nEnter your choice (0-4): ";
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

void displayTasks() {
  cout << "\n--- TODO LIST ---\n";

  if (taskCount == 0) {
    cout << "No tasks found.\n";
    return;
  }

  for (unsigned i{}; i < taskCount; i++) {
    cout << i + 1 << ". " << (completed[i] ? "[X]" : "[ ]") << " " << tasks[i]
         << "\n";
  }
  cout << "---------------------------\n\n";
}

void addTask() {
  if (taskCount >= 100) {
    cout << "Error! Task list is full!\n";
    return;
  }

  string task;
  cout << "Enter new task: ";
  getline(cin, task);

  tasks[taskCount] = task;
  completed[taskCount] = false;
  taskCount++;

  cout << "Task added successfully!\n";
}

void removeTask() {
  if (taskCount == 0) {
    cout << "No task to delete.\n";
    return;
  }

  displayTasks();

  int taskNumber;
  cout << "Enter task number to delete: ";
  cin >> taskNumber;

  if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    return;
  }

  if (taskNumber < 1 || taskNumber > taskCount) {
    cout << "Invalid task number!\n";
    return;
  }

  for (unsigned i = taskNumber - 1; i < taskCount - 1; i++) {
    tasks[i] = tasks[i + 1];
    completed[i] = completed[i + 1];
  }

  taskCount--;
  cout << "Task deleted successfully!\n";
}

void markCompleted() {
  if (taskCount == 0) {
    cout << "No tasks available.\n";
    return;
  }

  displayTasks();

  int taskNumber;
  cout << "Enter task number to mark as completed: ";
  cin >> taskNumber;

  if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input! Please enter a number.\n";
    return;
  }

  if (taskNumber < 1 || taskNumber > taskCount) {
    cout << "Invalid task number!\n";
    return;
  }

  int index = taskNumber - 1;
  completed[index] = true;

  cout << "Task marked as completed!\n";
}
