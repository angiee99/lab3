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
    bool _ifNumber(const string); // internal method
    void toPostfix(); 
};