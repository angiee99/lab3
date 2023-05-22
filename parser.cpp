#include "parser.h" 
using namespace std; 

Parser::Parser(string input){
    this->input =  input; 
    this->qu = new Queue(input.length()); 
    this->st = new Stack(input.length());
}

void Parser::toPostfix(){
    stringstream inp(input); 
    string value; 
    cout << input.length() << endl; 
    // int size = input.length();
    // Queue qu(input.length()); 
    // Stack st(input.length());

    while(inp >> value) {
        if(value.length() > 1){
            //check if it is one value or a few just stuck together 
        }
        
        if (_ifNumber(value)){
            cout<< value<< endl; 
            qu->enqueue(value); 
        }
        else{
            
            cout << "notNum" << value << endl; 
            // check if stack is empty 
            //check precedence 
            /*
            if prec value > prec before
                qu.enqueu(st.pop()); 
                st.push(value);
            else
                st.push(value);
            */
            st->push(value); 
        }
    }
    //empty stack -> enqueue it all token by token 
    cout<<"\nQueue: "; 
    qu->print();
    cout<<"\nStack: "; 
    st->print();  

}

bool Parser::_ifNumber(const string s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}