#include "../../include/Task_4.h"

bool DividedOn_3(int number)
{
  int sum = 0;
  while (number)
  {
    sum += (number & 0xF);
    number >>= 4;
  }

  while (sum > 3)
  {
    int newSum = 0;
    while (sum)
    {
      newSum += sum & 0b11; // Используется 4-ричная система счисления
      sum >>= 2;
    }
    if (newSum == 3)
      break;
    sum = newSum;
  }
  return sum == 0;
}

bool DividedOn_23(int number)
{
  int divisor = 23;
  while (number >= divisor)
  {
    int r = number & 0b111;
    number >>= 3; // Используется 8-ричная система счисления
    number += ((r << 1) + r);
    if (number == 23)
      break;
  }
  return number == 0 || number == 23; 
}

bool DividedOn_107(int number)
{
  int divisor = 107; // 01101011
  int magicNumber = 27;
  while (number >= divisor) 
  {
    int r = number & 0b11;
    number >>= 2; // Используется 4-ичная система счисления
    number += ((r << 5) + (~((r << 2) + r) + 1)); 
    if (number == 107)
      break;
  }
  return number == 0 || number == 107; 
}

void Solve_4()
{
  std::cout << "Программа проверяет делимость числа на 3, 23, 107. Используются операция сложения и побитовые операции.\n";
  int number;
  std::cout << "Введите число: ";
  std::cin >> number;

  if (DividedOn_3(number))
    std::cout << number << " делится на 3\n";
  else
    std::cout << number << " не делится на 3\n";

  if (DividedOn_23(number))
    std::cout << number << " делится на 23\n";
  else
    std::cout << number << " не делится на 23\n";
    
  if (DividedOn_107(number))
    std::cout << number << " делится на 107\n";
  else
    std::cout << number << " не делится на 107\n";
}