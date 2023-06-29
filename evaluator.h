#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "structs.h" 
using namespace std; 

class Operator{
    int precedence;
        //if operator is left assosiative
    bool left; 
    string o; 
    static const string operator_list;
        //count precedence
    void countPrec(); 
public: 
    Operator(string value); 
        //get value
    string value(); 
        //get precedence
    int getPrec(); 
        // if operator is left assosiavite
    bool isLeft(); 
};

/*
realizatiot of Shunting Yard
    turns a math infix expression to postfix
    evaluates postfix expression 
    utilizes queue ans stack
*/

class Evaluator{ 
    Queue *qu; 
    Stack *st; 
    string input; 
protected: 
    /// @brief deletes spaces and replaces unary minus with 'u'
    void _prepareInput();

    /// @brief Puts token either to queue (if number) or to stack (if operator) 
    /// when turning to postfix, takes operator precedence into account
    /// @param  string value - token to put
    void _decideAndPut(const string&);   

    /// @brief determines if a token is a number
    /// @param  string value
    /// @return true if value is a number
    bool _ifNumber(const string&); 

    /// @brief based on operator, pop two operands from stack, count and return the result
    /// @param token 
    /// @return result
    string _countRes(string& token); 
public: 
    Evaluator(string input); 
    ~Evaluator();
    Evaluator(const Evaluator& another);

    /// @brief turns math expression from infix to postfix expression
    void toPostfix(); 

    /// @brief evaluates posfix expression
    /// @return result
    int PostfixEval(); 
};