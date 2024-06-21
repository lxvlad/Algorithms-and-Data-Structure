//
// Created by Vladyslav Lishchynskyi on 21.06.2024.
//

#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

int priority(char c);
bool isDigital(char c);
bool isOperand(char c);
double applyOperator(double op1, double op2, char op);
string toPostfix(string infix);
int calculate(string expr);
string toInfix(string postfix);
void choice();
