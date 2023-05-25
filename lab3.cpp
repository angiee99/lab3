#include <iostream>
#include <stdio.h>
#include <string>

#include "structs.h"  
#include "evaluator.h" 

using namespace std; 


int main(int argc, char *argv[]){
    
    try{
        if(argc != 2){
            cerr << "The command argument should include 2 arguments:\n"
            << "-the name of the program \n-the math expresion inside the double quotes\n"; 
            return 1;       
        }   

        Evaluator p(argv[1]);  
        p.toPostfix(); 
        cout << "Result: " << p.PostfixEval()<< endl;

    }
    catch(invalid_argument &e){
        cerr << "Invalid argument exception occured:\n" << e.what() << endl; 
    }
    catch(runtime_error &e){
        cerr << "Runtime error occured:\n" << e.what() << endl; 
    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }
}
