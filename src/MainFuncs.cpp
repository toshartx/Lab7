#include "../include/MainFuncs.h"

int Choose(int first, int last)
{
  int a;
  std::cout << "Введите номер задания: ";
  while (!(std::cin >> a) || std::cin.peek() != '\n' || (a < first || a > last))
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Не существует такого задания:\n";
  }
  std::cin.ignore(1000,'\n');
  return a;
}

bool Restart()
{
  std::cout << "Напишите " << "0 - чтобы завершить программу\n" 
                              "\t 1 - чтобы запустить программу\n";
  bool flag;
  while (!(std::cin >> flag) || std::cin.peek() != '\n')
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Команда не распознана. Повторите попытку:\n";
  }
  std::cin.ignore();
  return flag;
}

void Laba()
{
  switch (Choose(1,5))
  {
    case 1:
    {
      Solve_1();
      break;
    }
    case 2:
    {
      Solve_2();
      break;
    }
    case 3:
    {
      Solve_3();
      break;
    }
    case 4:
    {
      Solve_4();
      break;
    }
    case 5:
    {
      Solve_5();
      break;
    }
    default:
    {
      break;
    }
  }
}