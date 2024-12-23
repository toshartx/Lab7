#include "../../include/Task_5.h"

// Пять рабов - 240 бочек, найти отравленную!
int NumberInput()
{
  int a;
  std::cout << "Пользователь травит бочку... ";
  while (!(std::cin >> a) || std::cin.peek() != '\n' || a < 1 || a > 240)
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Некорректный ввод, повторите попытку:\n";
  }
  return a;
}

void PlanDay1()
{
  std::cout << "Патриций привёз 240 бочек вина и некий Пользователь отравил одну из них\n"
               "У Патриция есть 5 рабов и с помощью них мы установим отравленную бочку\n"
               "План таков:\n"
               "------------------- День 1 ---------------------\n"
               "Рабы отпивают вино из бочек по следующему принципу:\n"
               "k-ый раб отпивает вино из тех бочек, k-ый разряд номера бочки которого в троичной системе счисления равен 0\n"
               "Сводная таблица:\n";
  std::cout << "-------------------------------------------------\n"
               "1 раб: 1-80\n";
  std::cout << "-------------------------------------------------\n"
               "2 раб: 1-26 ";
  for (int i = 81; i <= 240; i += 81)
  {
    std::cout << i << "-" << i+26 << " ";
  }
  std::cout << "\n-------------------------------------------------\n"
               "3 раб: 1-8 ";
  for (int i = 27; i <= 240; i += 27)
  {
    std::cout << i << "-" << i+8 << " ";
  }
  std::cout << "\n-------------------------------------------------\n"
               "4 раб: 1-2 ";
  for (int i = 9; i <= 240; i += 9)
  {
    std::cout << i << "-" << i+2 << " ";
  }
  std::cout << "\n-------------------------------------------------\n"
               "5 раб: каждую третью\n";
}

void PlanDay2()
{
  std::cout << "\n--------------------День 2-----------------------\n"
               "Выжившие рабы действуют по аналогичному принципу. Если раб мёртв, \nто k-ый разряд искомой отравленной бочки в троичной системе равен 1, иначе - 2\n"
               "Полученное 5-тиразрядное число в троичной системе счисления - это номер отравленной бочки\n";
}

void SearchPoisonedBarrel(int number, int poisonedBarrel)
{
  int editable = number;
  std::string numberIn3(5, '0');
  std::string poisonedIn3(5, '0');
  for (int i = 0; i <= 4; ++i)
  {
    numberIn3[4-i] = (editable % 3) + '0';
    editable /= 3;
  }
  bool slaves[5]{0};
  if (number == poisonedBarrel)
  {
    std::cout << "Ситуация после первого дня:\n";
    for (int i = 0; i <= 4; ++i)
    {
      if (numberIn3[i] == '0')
      {
        slaves[i] = 1;
        std::cout << "Раб " << i+1 << " мёртв\n";
      }
      else 
        std::cout << "Раб " << i+1 << " жив\n";
    }
    PlanDay2();
    std::cout << "Ситуация после второго дня:\n";
    for (int i = 0; i <= 4; ++i)
    {
      if (numberIn3[i] == '1' && slaves[i] == 0)
      {
        std::cout << "Раб " << i+1 << " мёртв\n";
        poisonedIn3[i] = '1';
      }
      else if (slaves[i] == 0)
      {
        std::cout << "Раб " << i+1 << " жив\n";
        poisonedIn3[i] = '2';
      }
    }
  }
  int ourPoisoned = 0;
  for (int i = 0; i <= 4; ++i)
  {
    ourPoisoned += pow(3, 4-i)*(poisonedIn3[i] - '0');
  }
  if (ourPoisoned != 0)
    std::cout << "Искомая бочка: " << ourPoisoned << '\n';
}

void Solve_5()
{
  int poisonedBarrel = NumberInput();
  PlanDay1();
  for (int i = 1; i <= 240; ++i)
  {
    SearchPoisonedBarrel(i, poisonedBarrel);
  }
}
          