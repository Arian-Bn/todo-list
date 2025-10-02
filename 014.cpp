#include <iostream>

using namespace std;

/* LeetCode #136. Single Number

Условие:
В массиве все числа встречаются ровно два раза, кроме одного — оно встречается
один раз. Найди это число.

Пример:
Ввод: 4 1 2 1 2
Вывод: 4

Ограничения:

    Массив содержит нечётное число элементов (от 1 до 101)
    Все числа целые
*/

int main() {
  const int SIZE = 50;
  int a[SIZE];
  int number, i = 0;

  cout << "Enter numbers (404 to stop):" << endl;

  while (cin >> number && number != 404 && i < SIZE) {
    if (number % 2 == 1 && number >= 1 && number <= 101) {
      a[i++] = number;
    }
  }

  for (int j = 0; j < i; j++) {
    int h = 0;
    for (int k = 0; k < i; k++) {
      if (a[j] == a[k])
        h++;
    }

    if (h != 2) {
      cout << "Result: " << a[j] << endl;
      cout << "End!" << endl;
      break;
    }
  }
  return 0;
}
