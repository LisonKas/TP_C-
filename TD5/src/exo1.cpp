#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <ctime>
#include <numeric>
#include <string>
#include <math.h>

size_t folding_string_hash(std::string const& s, size_t max){
    int somme {0};
    for(char element : s){
        somme += static_cast<int>(element);
    }
    size_t hashing {somme % max};
    return hashing;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    int somme {0};
    for(int i {0}; i<s.size(); i++){
        somme += static_cast<int>(s[i]) * i;  //pow(10, s.size()-i)
    }
    size_t hashing {somme % max};
    return hashing;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    int somme {0};
    for(int i {0}; i<s.size(); i++){
        int power {1};
        for(int j {1}; j<i; j++){
            power *= p;
        }
        somme += (static_cast<int>(s[i]) * power) % m; 
    }
    size_t hashing {somme};
    return hashing;
}

int main(){
    std::string chaine {"coucou"};
    std::cout << "Hash de " << chaine << " = " << folding_string_hash(chaine, 1024) << std::endl;

    std::cout << "Hash de 'yolo' : " << folding_string_ordered_hash("yolo", 1024) << " et hash de 'oloy' : " << folding_string_ordered_hash("oloy", 1024) << std::endl;

    std::cout << "Hash polynome yolo : " << polynomial_rolling_hash("yolo", 3, 1024) << std::endl;

    return 0;
}