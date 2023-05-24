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
    Queue(); 
    Queue(int capacity);
    Queue(Queue&);
    ~Queue(){
        delete[] queue; 
    }
    int getSize() const {
        return size;
    }
    void enqueue(const string& value);
    string dequeue();
    void print(){
        for(int i = startInd; i <= this->endInd; i++){
            cout << queue[i] << " ";
        }
        fflush(stdin); 
        cout << endl;
    }

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
    Stack(); 
    Stack(int capacity);
    Stack(Stack&);
    ~Stack(){
        delete[] stack; 
    };
    void push(const string& value);
    string pop(); 
    string peek(); 
    void print(){
        for(int i = 0; i <= top; i++){
            cout << stack[i] << " "; 
        }
        cout << endl; 
    }
    int getSize(){
        return this->size;
    }
    void resize();
    bool isEmpty(){
        return this->size==0;
    }
    bool isFull(){
        return size==capacity;
    }
};