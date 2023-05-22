#include "parser.h" 
using namespace std; 
/*
    potential for
    class Token{
        bool ifOperand
            int precedence
            int opCount (how many operands need)
        chat value 
    }
*/
Parser::Parser(string input){
    this->input =  input; 
    this->qu = new Queue(input.length()); 
    this->st = new Stack(input.length());
}

void Parser::toPostfix(){
    stringstream inp(input); 
    string value; 
    cout << input.length() << endl; 
    // for future with chars in Queue and Stack
    // if input.at(i)!= " "
    //  _decideAndPut(input.at(i));
    
    while(inp >> value) {
        //check if it is one value or a few just stuck together
        if(value.length() > 1 && !(_ifNumber(value))){
            // cout << value << endl;
            for (int i = 0; i < value.length(); i++){
                _decideAndPut(value.substr(i, 1));
            }             
        }        
        else _decideAndPut(value); 
    }
    //when input is done, pop all the stack and queue it

    while(! st->isEmpty()){
        if(st->peek() != "(" && st->peek() != ")"){
            qu->enqueue(st->pop()); 
        }  
        else{
            st->pop();
        }
    }

    //empty input -> enqueue all left in stack it all token by token 
    cout<<"\nQueue: "; 
    qu->print();
    cout<<"\nStack: "; 
    st->print();  

}

void Parser:: _decideAndPut(const string value){
     if (_ifNumber(value)){
            cout<< value<< endl; 
            qu->enqueue(value); 
        }
        else{        
            cout << "notNum: " << value << endl; 
            // string o2 = st->peek(); 
            // if value == ")"
            while(! (st->isEmpty()) && st->peek() != "(" 
                    && getPrecedence(st->peek()) > getPrecedence(value)){
                
                if(st->peek() != "(" && st->peek() != ")"){
                    qu->enqueue(st->pop()); 
                }                   
            }
            st->push(value); 
        }
}

int  Parser::getPrecedence(const string o){
    if (o == ")") return 0; 
    if (o == "+" || o == "-") return 1;
    if (o == "*" || o == "/" || o == "% ") return 2; 
    if (o == "(") return 3; // ? 
    else return -1;
}

bool Parser::_ifNumber(const string s){
    for (int i = 0; i < s.length(); i++){
        if (!isdigit(s[i])){
            return false; 
        }
    }
    return true; 
}