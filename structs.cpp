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

Queue::~Queue(){
    delete[] queue; 
}

void Queue::enqueue(const string& value){
    if (isLoaded()) resize(); 
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
            throw runtime_error("Queue is empty, not able to dequeue");
        }
        else{ 
            value = queue[startInd];
            startInd++; 
            size--; 
            
            if(size == 0){
                startInd= -1;
                endInd = -1;
            }
            return value; 
        }
    }

bool Queue::isLoaded(){
    float loaded = (float)size / capacity;
    return (loaded >= 0.75);
}
void Queue::resize(){
    this->capacity *= 2; 
    string* newqueue =  new string[this->capacity]; 
    memcpy( newqueue, queue, size * sizeof(string) );
    delete[] queue; 
    this->queue = newqueue; 
}
int Queue::getSize() const {
    return size;
}

void Queue::print(){
    for(int i = startInd; i <= this->endInd; i++){
        cout << queue[i] << " ";
    }
    cout << endl;
}
bool Queue::isEmpty(){
    return this->size==0;
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

Stack::~Stack(){
    delete[] stack; 
};

bool Stack::isLoaded(){ // load factor 
    float loaded = (float)size / capacity;
    return (loaded >= 0.75);
}
void Stack::resize(){
    this->capacity *= 2; 
    string* newstack =  new string[this->capacity]; 
    memcpy( newstack, stack, size * sizeof(string) );
    delete[] stack; 
    this->stack = newstack; 
}

void Stack::push(const string& value){
    if(isLoaded()) resize();

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
        throw  runtime_error("Stack is void, unable to pop."); 
    } 
}; 

string Stack::peek(){
    if(top > -1) {
        return stack[top]; 
    }
    throw runtime_error("Stack is void, nothing to peek here.");
}; 
void Stack::print(){
    for(int i = 0; i <= top; i++){
        cout << stack[i] << " "; 
    }
    cout << endl; 
}
int Stack::getSize() const {
    return this->size;
}
bool Stack::isEmpty() const{
    return this->size==0;
}
