#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

//Question 1
bool is_NPI_spaces(std::string const& chaine){
    bool valid {true};
    for(char element : chaine){
        if(!isdigit(element) && element!='+' && element!='-' && element!='*' && element!='/' && element!=' ' && element!='.'){
            valid = false;
            break;
        }
    }
    return valid;
}

//Question 3
bool is_floating(std::string const& chaine){
    bool point_exist {false};
    for(char element : chaine){
        if(isdigit(element)){
            continue;
        }
        else if(element == '.'){
            if(point_exist){
                point_exist = false;
                break;
            }
            else {
                point_exist = true;
            }
        }
        else {
            point_exist = false;
            break;
        }
    }
    return point_exist;
}

//Question 4
float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> pile;
    float calcul {0};
    for(std::string token : tokens){
        if(!token.empty()){
            if(is_floating(token)){
                pile.push(stod(token));
            }
            else {
                float nb1 {pile.top()};
                pile.pop();
                float nb2 {pile.top()};
                pile.pop();

                if(token == "+"){
                    calcul = nb1 + nb2;
                    pile.push(calcul);
                } else if(token == "-"){
                    calcul = nb1 - nb2;
                    pile.push(calcul);
                } else if(token == "*"){
                    calcul = nb1 * nb2;
                    pile.push(calcul);
                } else if(token == "/"){
                    calcul = nb1 / nb2;
                    pile.push(calcul);
                }
            }
        }
        else {
            std::cout << "Error, token empty" << std::endl;
            return -1.0;
        }
    }
    return calcul;
}

int main(){

    //Question 1
    std::string expression_NPI;
    std::cout << "Entrez une expression NPI (Séparée par des espaces) : ";
    getline(std::cin, expression_NPI);
    while(!is_NPI_spaces(expression_NPI)){
        std::cin.clear(); 
        std::cin.ignore(255, '\n'); 
        std::cout << "Erreur ! Entrez une expression NPI (Séparée par des espaces) : ";
        getline(std::cin, expression_NPI);
    }
    // std::cout << expression_NPI << std::endl;

    std::vector<std::string> expression_seperated {split_string(expression_NPI)}; //Question 2
    // for(int i {0}; i<expression_seperated.size(); i++){ //Question 3
    //     if(expression_seperated[i]!="+" && expression_seperated[i]!="-" && expression_seperated[i]!="*" && expression_seperated[i]!="/"){
    //         bool is_float {is_floating(expression_seperated[i])};
    //         if(is_float){
    //             std::cout << "Tout est bon..." << std::endl;
    //         }
    //         else {
    //             std::cout << "L'un de vos nombre n'est pas un float !" << std::endl;
    //             break;
    //         }
    //     }
    // //     std::cout << expression_seperated[i] << ", ";
    // }
    // std::cout << std::endl;

    std::cout << "Le resultat de votre expression est : " << npi_evaluate(expression_seperated) << std::endl; //Question 4

    //Question 5
    //J'ai tester chacune des expressions données

    return 0;
}