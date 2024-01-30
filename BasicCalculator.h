
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#ifndef MAIN_CPP_BASICCALCULATOR_H
#define MAIN_CPP_BASICCALCULATOR_H


bool isdigit(char c );
void eval(stack<int> &num,stack<char>& op);
int calculate(string s);

#endif //MAIN_CPP_BASICCALCULATOR_H
