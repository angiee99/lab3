#include <iostream>
#include <stdio.h>
#include <string>
using namespace std; 

class Queue{
    string* queue; 
    int startInd, endInd; 
    int size, capacity; 
public: 
    Queue(int capacity){
        this->capacity = capacity; 
        this->queue = new string[capacity]; 
        this->size = 0; 
        this->startInd = -1; 
        this->endInd = -1; 
    }
    //copy cnstr
    ~Queue(){
        delete[] queue; 
    }
    int getSize() const {
        return size;
    }
    void enqueue(const string value){
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
    string dequeue(){
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
    void print(){
        for(int i = startInd; i <= size; i++){
            cout << queue[i] << " ";
        }
    }
    // ???? 
    void resize(){
        this->capacity *= 2; 
        string* newqueue =  new string[this->capacity]; 
        memcpy( newqueue, queue, size * sizeof(string) );
        delete[] queue; 
        this->queue = newqueue; 
    }
    // bool isEmpty
    // bool isFull
};

class Stack{
    string* stack; 
    int size, capacity; 
    int top; 
public: 
    Stack(int capacity){
        this->capacity = capacity; 
        this->stack = new string[capacity]; 
        this->top = -1;
        this->size = 0; 
    }
    ~Stack(){
        delete[] stack; 
    };
    void push(string value){
        if(size < capacity){
            top++;
            size++;
            stack[top] = value;
        }
        else {
            cout << "Stack is full" << endl;
        }
    };
    string pop(){
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
    string peek(){
        if(top > -1) {
            return stack[top]; 
        }
        return 0; 
    }; 
    void print(){
        for(int i = 0; i <= top; i++){
            cout << stack[i] << " "; 
        }
        cout << endl; 
    }
    // bool isEmpty
    // bool isFull
};