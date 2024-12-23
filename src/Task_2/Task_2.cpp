#include "../../include/Task_2.h"

void SignInterpretator(std::string& number)
{
  if (number[0] == 45)
    number[0] = 49;
  else if (number[0] == 43)
    number[0] = 48;
  else
    number.insert(0, 1, '0');
}

void ToDirect2(std::string& number)
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

void ToAdditional(std::string& number)
{
  if (number[0] == 49)
  {
    // П -> 0
    for (int i = 1; number[i] != '\0'; ++i)
    {
      if (number[i] == 49)
        number[i] = 48;
      else
        number[i] = 49;
    }
    // О -> Д
    for (int i = number.size() - 1; i != 0; --i)
    {
      if (number[i] == 48)
      {
        number[i] = 49;
        break;
      }
      number[i] = 48;
    }
  }
}

void ZeroAddition2(std::string& num1, std::string& num2)
{
  int zeroAddition = num1.size() - num2.size();
  // Добавляем нули, чтобы уравнять количество разрядов
  if (zeroAddition < 0)
    num1.insert(1, abs(zeroAddition), '0');
  else if (zeroAddition > 0)
    num2.insert(1, abs(zeroAddition), '0');
}

std::string SumBinaryNumbers(std::string num1, std::string num2)
{
  // Сложение чисел в дополнительном коде
  std::string result(num1.size(), '0');
  int sumAddition = 0;
  for (int i = num1.size() - 1; i >= 0; --i) // O(n)
  {
    int sum = 0;
    short digit1 = num1[i] - '0';
    short digit2 = num2[i] - '0';
    sum = (digit1 + digit2 + sumAddition) % 2;
    sumAddition = (digit1 + digit2 + sumAddition) / 2;
    result[i] = sum + '0';
  }

  ToDirect2(result);
  if (result[0] == 48)
    result[0] = '+';
  else
    result[0] = '-';
  result.erase(1, result.find_first_not_of('0'));
  if (result.empty())
  {
    return "0";
  }
  return result;
}

void Solve_2()
{
  std::cout << "Программа принимает числа в двоичной системе счисления в естественной форме, \n"
               "считает их сумму в дополнительном коде и выводит её в естественной форме.\n"
               "P.s. Примеры естественной формы: -10101110 (отрицательное число), 101010110 (положительное число)\n";
  std::cout << "Введите числа:\n";
  std::string number1, number2;
  std::cin >> number1 >> number2;
  SignInterpretator(number1);
  SignInterpretator(number2);
  ZeroAddition2(number1,number2);
  ToAdditional(number1);
  ToAdditional(number2);
  std::string result = SumBinaryNumbers(number1, number2);
  std::cout << number1 << "\n+\n" << number2 << "\n---------------\n" << result << '\n';
}