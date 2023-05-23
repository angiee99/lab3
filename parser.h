#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "structs.h" 
using namespace std; 
// class Operator {
//     int precedence;
//     int opCount;//(how many operands need)
//     bool isLeft; 
//     char value; 
// public: 
//     Operator();
// };
class Parser{
    Queue *qu; //postfix 
    Stack *st; 
    string input; 
public: 
    Parser(string input); 
    void toPostfix(); 
    void _parseMePls(string& str);
    void _decideAndPut(const string); // internal method  
    bool _ifNumber(const string); // internal method (token method)
    int  getPrecedence(const string); // would go to be the method of a token 
};