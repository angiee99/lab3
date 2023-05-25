#pragma once
#include <iostream>
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
    ~Queue();
    int getSize() const;
    void enqueue(const string& value);
    string dequeue();
    void print();
    void resize();
    bool isEmpty();
    bool isLoaded();
};

class Stack{
    string* stack; 
    int size, capacity; 
    int top; 
public: 
    Stack(); 
    Stack(int capacity);
    Stack(Stack&);
    ~Stack();
    void push(const string& value);
    string pop(); 
    string peek(); 
    void print();
    int getSize() const;
    void resize();
    bool isEmpty() const;
    bool isLoaded(); // load factor 
};