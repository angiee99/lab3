#include <iostream>
// #include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "structs.h"  // hpp later
#include "parser.h" 
/* 1) class Token 
    int precedence 
    char value
    + getPrecedence() 


*/
using namespace std; 
//just for test
void testStructs(); 


int main(int argc, char *argv[]){
    
    try{
        if(argc != 2){
            cerr << "The command argument should include 2 arguments: \n-the name of the program \n-the math expresion inside the quotes " << endl; 
            return 1;       
        }   

        Parser p(argv[1]);  //!
        p.toPostfix(); 
        cout << "Result: " << p.PostfixEval()<< endl;

    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }
}


void testStructs(){
    try{
        Queue q; 
        q.enqueue("1"); 
        q.enqueue("2"); 
        q.print();
        // Queue an(q);
        // cout << endl; 
        // cout << an.dequeue()<< endl;
        // an.print();

        Stack s; 
        s.push("1"); 
        s.push("2"); 
        s.push("3"); 
        s.print(); 
        Stack s2(s);
        cout << s2.pop() << endl; 
        s2.print();
    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }

}