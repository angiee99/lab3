#include "evaluator.h" 
using namespace std; 

Evaluator::Evaluator(string input){
    this->input =  input; 
    this->qu = new Queue(input.length()); 
    this->st = new Stack(input.length());
}
Evaluator::Evaluator(const Evaluator& another){
    this->input = another.input; 
    this->qu = new Queue(input.length()); 
    this->st = new Stack(input.length());
    
    for(int i = 0; i< this->qu->getSize(); i++){
        this->qu[i] = another.qu[i]; 
    }
    for(int i = 0; i< this->st->getSize(); i++){
        this->st[i] = another.st[i]; 
    }
}

void Evaluator::toPostfix(){
    _prepareInput(); 

    // cout << input.length() << endl; 
    // cout<< "queue size: " << qu->getSize()<< endl; 

    for (size_t i = 0; i < input.length(); ++i) {
        string current;
        // Check if the character is a digit
        if (isdigit(input[i])) {
            if(input[i-1] == 'u') current += "-"; // unary minus
            // If it's a number with more than 1 digit 
            while (i < input.length() && (isdigit(input[i]))) {
                current += input[i];
                ++i;
            }
            //for the non-digit character in the next iteration
            --i;
        }
        else if(input[i]=='u') continue; //skipping unary minus to reunite it later
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
      
    // cout<< "queue size: " << qu->getSize()<< endl; 
    // cout<<"\nQueue: "; 
    // qu->print();
    // cout<<"\nStack: "; 
    // st->print();  
}

void Evaluator::_prepareInput(){

  string newinput;
  if(input.find(' ')!= string::npos){ // delete Spaces
    stringstream ss(this->input); 
    string temp; 
    while(ss >> temp) newinput+= temp; 
    
  } else newinput = this->input; 

    for(int i = 0; i < newinput.length(); i++){
        if (newinput[i] == '-'){
            if( (i == 0) || (!isdigit(newinput[i-1])) && newinput[i-1]!= ')'){
                newinput.replace(i, 1, "u"); // replacing unary minus heh
            }
        }
    }
    //cout << newinput<< endl; 
    this->input = newinput; 
};

void Evaluator:: _decideAndPut(const string& value){
    if (_ifNumber(value)){
        qu->enqueue(value); 
    }
    else{        
        //cout << "notNum: " << value << endl; 
        Operator op(value);

        while( !st->isEmpty() && st->peek() != "(" ){
            Operator last(st->peek());

            bool action = ( last.getPrec() > op.getPrec() 
            || (last.getPrec() == op.getPrec()  && op.isLeft() ) ); 
                // if equal and left assotiative
            
            if (!action) break;
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

bool Evaluator::_ifNumber(const string& s){
    string operators = "+-/*%()^";
    if (operators.find(s) == string::npos){
        return true;
    }
    else if (s.length() > 1 && s[0] == '-') return true;
    else return false; 
}

int Evaluator::PostfixEval(){
    while(!qu->isEmpty()){
        string token = qu->dequeue(); 
        if(_ifNumber(token)){
            st->push(token); 
        }
        else st->push(_countRes(token));
    }
    return stoi(st->pop());
}

string Evaluator::_countRes(string& token){
    int b = stoi(st->pop()); // ckeck for exception 
    int a = stoi(st->pop());
    if (token == "+") return to_string(a+b); 
    if (token == "-") return to_string(a-b); 
    if (token == "*") return to_string(a*b); 
    if (token == "/") return to_string(a/b); 
    if (token == "%") return to_string(a%b); 
    if (token == "^") return to_string(pow(a, b));
    throw invalid_argument("(Parser::_countRes) Unable to calculate with operand "
                             + token);
}



const string Operator::operator_list = "+-*/%^()";

Operator::Operator(string value){

    if (operator_list.find(value) == string::npos){
        throw invalid_argument("Operator " + value+ " cannot be created," + 
        "as it is probably not an operator. Accepting operator: " + operator_list);
    }
    this->o = value; 
    this->precedence = -1; 
    this->left = (value != "^"); 
}

void Operator::countPrec(){
    if (o == ")") this->precedence = 0; 
    if (o == "+" || o == "-") this->precedence = 1;
    if (o == "*" || o == "/" || o == "% ") this->precedence =  2; 
    if (o == "^") this->precedence =  3;
    if (o == "(") this->precedence =  4; 
}

int Operator::getPrec(){
    if (precedence == -1) countPrec();
    return this->precedence; 
}
