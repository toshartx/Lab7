#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

int BaseInput();
std::string NumberInput(int base);
void ZeroAddition3(std::string &num1, std::string &num2);
std::string Sum(std::string num1, std::string num2, int base);
std::string Substraction(std::string num1, std::string num2, int base);
void Solve_3();