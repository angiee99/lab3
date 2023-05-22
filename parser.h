#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "structs.h" 
using namespace std; 

class Parser{
    Queue *qu; //postfix 
    Stack *st; 
    string input; 
public: 
    Parser(string input); 
    void toPostfix(); 
    void _decideAndPut(const string); // internal method  
    bool _ifNumber(const string); // internal method (token method)
    int  getPrecedence(const string); // would go to be the method of a token 
};