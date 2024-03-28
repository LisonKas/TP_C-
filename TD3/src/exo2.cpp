#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

//Question 1
Token make_token(float value){
    Token new_token {};
    new_token.type = TokenType::OPERAND;
    new_token.value = value;
    new_token.op = Operator::ADD; //Par défaut
    return new_token;
}

Token make_token(Operator o){
    Token new_token {};
    new_token.type = TokenType::OPERATOR;
    new_token.value = 0.0f;  //Par défaut
    new_token.op = o; 
    return new_token;
}

//Question 2
std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens;
    for(std::string element : words){
        bool is_digit {true};
        for(int i {0}; i<element.size(); i++){
            if(!isdigit(element[i]) && element[i]!='.'){
                is_digit = false;
            }
        }
        if(is_digit){
            tokens.push_back(make_token(stod(element)));
        }
        else{
            if(element == "+"){
                tokens.push_back(make_token(Operator::ADD));
            } else if(element == "-"){
                tokens.push_back(make_token(Operator::SUB));
            } else if(element == "*"){
                tokens.push_back(make_token(Operator::MUL));
            } else if(element == "/"){
                tokens.push_back(make_token(Operator::DIV));
            }
        }
    }
}

//Question 3
float npi_evaluate(std::vector<Token> const& tokens){
    float calcul {0};
    std::stack<float> pile;
    for(Token element: tokens){
        if(element.type == TokenType::OPERAND){
            pile.push(element.value);
        }
        else {
            float nb1 {pile.top()};
            pile.pop();
            float nb2 {pile.top()};
            pile.pop();

            if(element.op == Operator::ADD){
                calcul = nb1 + nb2;
                pile.push(calcul);
            }
            else if(element.op == Operator::SUB){
                calcul = nb1 - nb2;
                pile.push(calcul);
            }
            else if(element.op == Operator::MUL){
                calcul = nb1 * nb2;
                pile.push(calcul);
            }
            else if(element.op == Operator::DIV){
                calcul = nb1 / nb2;
                pile.push(calcul);
            }
        }
    }
    return calcul;
}

int main(){

    std::vector<std::string> exemple1 {"3.0", "4.0", "+"};
    std::vector<Token> tokens {tokenize(exemple1)};
    std::cout << "Le résultat du calcul 3.0 4.0 + est : " << npi_evaluate(tokens) << std::endl;

    return 0;
}