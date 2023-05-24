#include "structs.h"
using namespace std; 

Queue::Queue(){
    this->capacity = 1; 
    this->queue = new string[capacity]; 
    this->size = 0; 
    this->startInd = -1; 
    this->endInd = -1; 
}

Queue::Queue(int capacity){
    this->capacity = capacity; 
    this->queue = new string[capacity]; 
    this->size = 0; 
    this->startInd = -1; 
    this->endInd = -1; 
}

Queue::Queue(Queue& another){
    this->capacity = another.capacity; 
    this->queue = new string[capacity]; 
   
    this->size = another.size; 
    this->startInd = another.startInd; 
    this->endInd = another.endInd;  
    if(size){
        for(int i = startInd; i <= this->endInd; i++){
            this->queue[i] = another.queue[i];
        }
    }
    
}

void Queue::enqueue(const string& value){
        if (size == capacity) resize(); 
        endInd++; 
        size++;
        queue[endInd] = value; 

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

void Queue::resize(){
    this->capacity *= 2; 
    string* newqueue =  new string[this->capacity]; 
    memcpy( newqueue, queue, size * sizeof(string) );
    delete[] queue; 
    this->queue = newqueue; 
}



Stack::Stack(){
    this->capacity = 1; 
    this->stack = new string[capacity]; 
    this->top = -1;
    this->size = 0; 
}

Stack::Stack(int capacity){
    this->capacity = capacity; 
    this->stack = new string[capacity]; 
    this->top = -1;
    this->size = 0; 
}
Stack::Stack(Stack& another){
    this->capacity = another.capacity; 
    this->stack = new string[capacity]; 
    this->top = another.top;
    this->size = another.size; 
    if(size){
        for(int i = 0; i <= top; i++){
            this->stack[i] = another.stack[i]; 
        }
    }
}
void Stack::resize(){
    this->capacity *= 2; 
    string* newstack =  new string[this->capacity]; 
    memcpy( newstack, stack, size * sizeof(string) );
    delete[] stack; 
    this->stack = newstack; 
}

void Stack::push(const string& value){
    if(isFull()) resize();

    top++;
    size++;
    stack[top] = value;
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
