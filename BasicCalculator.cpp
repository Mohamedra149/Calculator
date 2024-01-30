#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isdigit(char c )
{
    if(c >='0' && c<='9')
        return true;
    return false;
}
void eval(stack<int> &num,stack<char>& op) {
    auto c = op.top();  op.pop();
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto r = 0;
    if (c == '+') r = a + b;
    else if (c == '-') r = a - b;
    else if (c == '*') r = a * b;
    else if (c == '/') r = a / b;
    num.push(r);
}

int calculate(string s) {
    stack<int> num; // maintain numbers
    stack<char> op; // maintian operators
    unordered_map<char, int> map; // maintian operators priority
    map['+'] = map['-'] = 0;
    map['*'] = map['/'] = 1;

    // remove empty space if exists
    string str = "";
    for (auto c: s)
        if (c != ' ') str += c;

    // calculate
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        auto c = str[i];
        // 1）c is a integer, get the entire number if mutiple-digit number
        if (isdigit(c)) {
            int j = i, x = 0;
            while (j < n && isdigit(str[j]))
                x = x * 10 + (str[j ++] - '0');
            i = j - 1;
            num.push(x);
        }
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(')
                eval(num,op);
            op.pop();
        }
        else {

            while (op.size() > 0 && op.top() != '(' && map[op.top()] >= map[c])
                eval(num,op);
            op.push(c);
        }
    }
    while (op.size() > 0) eval(num,op);
    return num.top();
}

