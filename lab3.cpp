#include <iostream>
// #include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "structs.cpp" 


using namespace std; 


int main(int argc, char *argv[]){
    
    try{
        // if(argc != 2){
        //     cerr << "The command argument should include 2 arguments: \n-the name of the program \n-the directory name" << endl; 
        //     return 1;       
        // }
        for(int i = 0; i < argc; i ++){
            cout << argv[i] << endl; 
        }
        
        // Queue q(5); 
        // q.enqueue("1"); 
        // q.enqueue("2"); 
        // q.print();
        // cout << endl; 
        // cout << q.dequeue()<< endl;
        // q.print();

        Stack s(5); 
        s.push('1'); 
        s.push('2'); 
        s.push('3'); 
        s.print(); 
        cout << s.pop() << endl; 
        s.print();




    }
    catch(exception &e){
        cerr << "Default exception occured:\n" << e.what() << endl; 
    }

}