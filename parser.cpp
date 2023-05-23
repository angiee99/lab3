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
    _parseMePls(input); 

    cout << input.length() << endl; 
    // for future with chars in Queue and Stack
    // if input.at(i)!= " "
    //  _decideAndPut(input.at(i));

    for (size_t i = 0; i < input.length(); ++i) {
        string current;
        // Check if the character is a digit
        if (isdigit(input[i])) {
            if(input[i-1] == 'u')current += "-";
            // If it's a digit, continue appending characters until a non-digit is encountered
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                current += input[i];
                ++i;
            }
            // Decrement i to handle the non-digit character in the next iteration
            --i;
        }
        else if(input[i]=='u') continue; 
        else current = input[i]; 

        _decideAndPut(current);
        // qu->print(); 
        // st->print();
    }

    while(! st->isEmpty()){
        if(st->peek() != "(" && st->peek() != ")"){
            qu->enqueue(st->pop()); 
        }  
        else{
            st->pop();
        }
    }

    cout<<"\nQueue: "; 
    qu->print();
    cout<<"\nStack: "; 
    st->print();  

}

void Parser::_parseMePls(string& str){
// delete Spaces
    stringstream ss(str); 
    string input, temp; 
    while(ss >> temp) input+= temp; 
    cout << input << endl;
// delete Spaces
    for(int i = 0; i < input.length(); i++){
        if (input[i] == '-'){
            if( (i == 0) || (!isdigit(input[i-1])) && input[i-1]!= ')'){
                input.replace(i, 1, "u");
            }
        }
    }
    cout << input<< endl; 
    str = input; 
};

void Parser:: _decideAndPut(const string value){
    if (_ifNumber(value)){
        cout<< value<< endl; 
        qu->enqueue(value); 
    }
    else{        
        cout << "notNum: " << value << endl; 
            // string o2 = st->peek(); 
            // if value == ")"
        while( !(st->isEmpty()) && st->peek() != "(" 
                &&( (getPrecedence(st->peek()) > getPrecedence(value) 
                || (getPrecedence(st->peek()) == getPrecedence(value) && value != "^")) )){
                // if equal and left assotiative
            if(st->peek() != "(" && st->peek() != ")"){
                qu->enqueue(st->pop()); 
            }     
                       
        }
        if (value == ")") {
            if(st->peek() == ")") st->pop();
            if(st->peek() == "(") st->pop();
        }
        else st->push(value); 
    }
}

int  Parser::getPrecedence(const string o){
    if (o == ")") return 0; 
    if (o == "+" || o == "-") return 1;
    if (o == "*" || o == "/" || o == "% ") return 2; 
    if (o == "^") return 3;
    if (o == "(") return 4; // ? 
    else return -1;
}

bool Parser::_ifNumber(const string s){
    string operators = "+-/*%()^";// змахує на атрибут
    if (operators.find(s) == string::npos){
        return true;
    }
    else if (s.length() > 1 && s[0] == '-') return true;
    else return false; 
}