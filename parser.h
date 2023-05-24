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
//     getValue();
// };
class Parser{ //mb change name
    Queue *qu; //postfix 
    Stack *st; 
    string input; 
public: 
    Parser(string input); 
    ~Parser(){
        delete qu;
        delete st; 
    }
    Parser(const Parser& another);
    void toPostfix(); // +
    void _prepareInput();
    void _decideAndPut(const string&); // + internal method  
    bool _ifNumber(const string&); // internal method (token method)
    int  getPrecedence(const string&); // would go to be the method of a token 

    int PostfixEval(); //+
    string countRes(string& token); //+
};