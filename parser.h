#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "structs.h" 
using namespace std; 

class Operator{
    int precedence;
    // int opCount;//(how many operands need, is 2 for all operators I've got)
    bool left; 
    string o; 
    static const string operator_list;
    void countPrec();
public: 
    Operator(string value);
    string value(){ return o; }; 
    int getPrec();
    bool isLeft(){ return left; }
};


class Parser{ //mb change name to Yard
    Queue *qu; 
    Stack *st; 
    string input; 
protected: 
    void _prepareInput();
    void _decideAndPut(const string&);   
    bool _ifNumber(const string&); 
    string _countRes(string& token); 
public: 
    Parser(string input); 
    ~Parser(){
        delete qu;
        delete st; 
    }
    Parser(const Parser& another);
    void toPostfix(); // +
    int PostfixEval(); //+
   
};