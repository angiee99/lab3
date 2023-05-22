#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std; 

class Queue{
    string* queue; 
    int startInd, endInd; 
    int size, capacity; 
public: 
    Queue(){}; 
    Queue(int capacity);
    //copy cnstr
    ~Queue(){
        delete[] queue; 
    }
    int getSize() const {
        return size;
    }
    void enqueue(const string value);
    string dequeue();
    void print(){
        for(int i = startInd; i <= this->size; i++){
            cout << queue[i] << " ";
        }
        cout<< endl;
    }
    // ???? 
    void resize();
    bool isEmpty(){
        return this->size==0;
    }
    // bool isFull
};

class Stack{
    string* stack; 
    int size, capacity; 
    int top; 
public: 
    Stack(){}; 
    Stack(int capacity);
    ~Stack(){
        delete[] stack; 
    };
    void push(string value);
    string pop(); 
    string peek(); 
    void print(){
        for(int i = 0; i <= top; i++){
            cout << stack[i] << " "; 
        }
        cout << endl; 
    }
    bool isEmpty(){
        return this->size==0;
    }
    bool isFull(){
        return size==capacity;
    }
};