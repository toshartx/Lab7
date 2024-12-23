#include "../../include/Task_3.h"

int BaseInput()
{
  int a;
  while (!(std::cin >> a) || std::cin.peek() != '\n' || a <= 1 || a > 36)
  {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Некорректный ввод, повторите попытку:\n";
  }
  return a;
}

std::string NumberInput(int base)
{
  std::string number;
  bool correct = false;
  while (!correct)
  {
    std::cout << "Введите число с допустимой системой счисления: ";
    std::cin >> number;
    try
    {
      for (int i = 0; i < number.length(); ++i)
      {
        if (number[i] == '-')
          continue;
        std::string digit;
        digit.push_back(number[i]);
        std::stoi(digit, nullptr, base);
      }
      correct = true;
    }
    catch (const std::invalid_argument &)
    {
      std::cout << "Некорректный ввод, повторите попытку:\n";
    }
  }
  return number;
}

void ZeroAddition3(std::string &num1, std::string &num2)
{
  int zeroAdd = num1.length() - num2.length();
  if (zeroAdd > 0)
  {
    num2.insert(0, zeroAdd, '0');
  }
  else if (zeroAdd < 0)
  {
    num1.insert(0, -zeroAdd, '0');
  }
  else
  {
    num1.insert(0, 1, '0');
    num2.insert(0, 1, '0');
  }
}

std::string Sum(std::string num1, std::string num2, int base)
{
  bool isNegative = false;
  if (num1[0] == '-' && num2[0] != '-')
  {
    num1.erase(0, 1);
    return Substraction(num2, num1, base);
  }
  if (num1[0] != '-' && num2[0] == '-')
  {
    num2.erase(0, 1);
    return Substraction(num1, num2, base);
  }
  if (num1[0] == '-' && num2[0] == '-')
  {
    num1.erase(0, 1);
    num2.erase(0, 1);
    isNegative = true;
  }

  ZeroAddition3(num1, num2);
  size_t length = num1.length();
  std::string result(length, '0');
  int sum, remainder = 0;
  for (int i = length - 1; i >= 0; --i)
  {
    short digit1 = std::isdigit(num1[i]) ? num1[i] - '0' : num1[i] - 'A' + 10;
    short digit2 = std::isdigit(num2[i]) ? num2[i] - '0' : num2[i] - 'A' + 10;
    sum = (digit1 + digit2 + remainder) % base;
    remainder = (digit1 + digit2 + remainder) / base;
    result[i] = sum > 9 ? sum - 10 + 'A' : sum + '0';
  }

  result.erase(0, result.find_first_not_of('0'));
  if (result.empty())
  {
    return "0";
  }

  return isNegative ? "-" + result : result;
}

std::string Substraction(std::string num1, std::string num2, int base)
{
  bool isNegative = false;
  if (num1[0] == '-' && num2[0] != '-')
  {
    num1.erase(0, 1);
    return "-" + Sum(num1, num2, base);
  }
  if (num1[0] != '-' && num2[0] == '-')
  {
    num2.erase(0, 1);
    return Sum(num1, num2, base);
  }
  if (num1[0] == '-' && num2[0] == '-')
  {
    num1.erase(0, 1);
    num2.erase(0, 1);
    return Substraction(num2, num1, base);
  }

  if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2))
  {
    std::swap(num1, num2);
    isNegative = true;
  }

  ZeroAddition3(num1, num2);
  int length = num1.length();
  std::string result(length, '0');
  int difference, borrow = 0;
  for (int i = length - 1; i >= 0; --i)
  {
    short digit1 = std::isdigit(num1[i]) ? num1[i] - '0' : num1[i] - 'A' + 10;
    short digit2 = std::isdigit(num2[i]) ? num2[i] - '0' : num2[i] - 'A' + 10;
    difference = digit1 - digit2 - borrow;
    if (difference < 0)
    {
      difference += base;
      borrow = 1;
    }
    else
    {
      borrow = 0;
    }
    result[i] = difference > 9 ? difference - 10 + 'A' : difference + '0';
  }

  result.erase(0, result.find_first_not_of('0'));
  if (result.empty())
  {
    return "0";
  }

  return isNegative ? "-" + result : result;
}

void Solve_3()
{
  std::cout << "Вводится основание системы счисления (2-36), потом вводится два числа в этой системе счисления.\n"
               "Выводится сумма и разность чисел в исходной системе счисления.\n";
  int base;
  std::cout << "Введите основание системы счисления (2-36):\n";
  base = BaseInput();
  std::string number1 = NumberInput(base);
  std::string number2 = NumberInput(base);
  std::cout << "Сумма чисел: " << Sum(number1, number2, base) << '\n';
  std::cout << "Разность чисел: " << Substraction(number1, number2, base) << '\n';
}