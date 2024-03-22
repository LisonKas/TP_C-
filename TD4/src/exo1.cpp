#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <ctime>
#include <numeric>

//EXO 2
auto const is_space = [](char letter){ return letter == ' '; };

int compte(std::string const& chaine){
    int nb_premier_mot {0};
    auto is_it_space = std::find(chaine.begin(), chaine.end(), ' ');
    nb_premier_mot += std::distance(chaine.begin(), is_it_space);
    return nb_premier_mot;
} //Question 1

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> string_casse {};
    auto debut {str.begin()};
    auto space = std::find(debut, str.end(), ' ');
    while(space!=str.end()){
        std::string new_str {};
        for(auto i {debut}; i!=space; i++){
            new_str += *i;
        }
        string_casse.push_back(new_str);
        debut = space+1;
        space = std::find(debut, str.end(), ' ');
    }
    return string_casse;
} //Question 2

int main(){
    std::srand(std::time(nullptr));

    //EXO 1
    std::vector<int> tab {};
    for(int i {0}; i<30; i++){
        tab.push_back(rand()%100 + 0);
    } //Question 1

    for(auto i {tab.begin()}; i!=tab.end(); i++){
        std::cout << *i << std::endl;
    } //Question 2

    int val_util {}, index_trouve {};
    std::cout << "Saisissez votre nombre : ";
    std::cin >> val_util;
    auto index = std::find(tab.begin(), tab.end(), val_util);
    if(index != tab.end()){
        for(int i {0}; i<tab.size(); i++){
            if(tab[i]==*index){
                index_trouve = i+1;
                break;
            }
        }
        std::cout << "Votre nombre " << *index << " a été trouvé à l'index " << index_trouve << " du tableau." << std::endl;
    }
    else {
        std::cout << "Votre nombre n'a pas été trouvé dans le tableau." << std::endl;
    } //Question 3

    int occur = std::count(tab.begin(), tab.end(), 69);
    std::cout << "Le numéro 69 apparait " << occur << " fois dans le tableau." << std::endl; //Question 4

    std::sort(tab.begin(), tab.end());
    for(auto i {tab.begin()}; i!=tab.end(); i++){
        std::cout << *i << std::endl;
    }  //Question 5

    int somme = std::accumulate(tab.begin(), tab.end(), 0, [](int acc, int current_element) { return acc + current_element; });
    std::cout << "La somme de tous les nombres du tableau est " << somme << "." << std::endl;  //Question 6


    //EXO 2
    std::string phrase {"Coucou c'est moi "};  //Question 1
    int nb_mot = compte(phrase);
    std::cout << "Le nombre de lettres du premier mot de la phrase '" << phrase << "' est " << nb_mot << "." << std::endl;

    std::vector<std::string> mots {split_string(phrase)};
    for(auto i {mots.begin()}; i!=mots.end(); i++){
        std::cout << *i << std::endl;
    }

    return 0;
}