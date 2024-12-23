#include "../include/Task_1.h"

void ToDirect1(std::string& number)
{
  if (number[0] == 49)
  {
    // Д -> О
    for (int i = number.size() - 1; i != 0; --i)
    {
      if (number[i] == 49)
      {
        --number[i];
        break;
      }
      number[i] = 49;
    }

    // O -> П
    for (int i = 1; number[i] != '\0'; ++i)
    {
      if (number[i] == 48)
        number[i] = 49;
      else
        number[i] = 48;
    }
  }
}

void Solve_1()
{
  std::cout << "Вводится двоичное число в доп. коде. Выводится число в прямом коде\n";
  std::string number = "";
  std::cout << "Введите число в доп. коде: ";
  std::cin >> number;
  ToDirect1(number);
  std::cout << number << '\n';
}
