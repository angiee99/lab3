#include "structs.h"
using namespace std; 


Queue::Queue(int capacity){
    this->capacity = capacity; 
    this->queue = new string[capacity]; 
    this->size = 0; 
    this->startInd = -1; 
    this->endInd = -1; 
}

void Queue::enqueue(const string value){
        if (size == capacity){
            cout << "Queue full" << endl; 
            // resize(); 
        }
        else{
            endInd++; 
            size++;
            queue[endInd] = value; 
        }
        if(size == 1){
            startInd = 0; 
        }
    }

string Queue::dequeue(){
        string value; 
        if(size == 0){
            // throw exception("Queue is empty, not able to dequeue");
            cout << "Queue is empty, not able to dequeue" << endl;
            return "";
        }
        else{ 
            value = queue[startInd];
            startInd++; 
            size--; 
            return value; 
        }
        if(size == 0){
            startInd= -1;
            endInd = -1;
            return "";
        }
        
    }

    // ???? 

void Queue::resize(){
        this->capacity *= 2; 
        string* newqueue =  new string[this->capacity]; 
        memcpy( newqueue, queue, size * sizeof(string) );
        delete[] queue; 
        this->queue = newqueue; 
    }
    // bool isEmpty
    // bool isFull


// Stack::Stack(){}; 

Stack::Stack(int capacity){
        this->capacity = capacity; 
        this->stack = new string[capacity]; 
        this->top = -1;
        this->size = 0; 
    }

void Stack::push(string value){
        if(size < capacity){
            top++;
            size++;
            stack[top] = value;
        }
        else {
            cout << "Stack is full" << endl;
        }
    };

string Stack::pop(){
        if(size > 0){
            string value = stack[top];
            top--; 
            size--; 
            return value; 
        }
        else{
           cout << "Stack is void" << endl;
           return 0;  
        } 
    }; 

string Stack::peek(){
        if(top > -1) {
            return stack[top]; 
        }
        return 0; 
    }; 
