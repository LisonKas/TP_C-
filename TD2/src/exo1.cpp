#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

std::vector<float> generate_random_vector2(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }
bool is_sorted(std::vector<float> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

// EXO 1
void bubble_sort(std::vector<int> & vec){
    int tri = 0;
    while(tri!=vec.size() || !is_sorted(vec)){
        for(int i {0}; i<vec.size()-1; i++){
            if(vec[i]>vec[i+1]){
                std::swap(vec[i], vec[i+1]);
            }
        }
        tri++;
    }
}

// EXO 2
size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    float const valeur_pivot = vec[pivot];

    size_t first_bigger_element_index {left};

    std::swap(vec[pivot], vec[right]);

    for (size_t i {left}; i < right; ++i) {
        if (vec[i] < valeur_pivot) {
            std::swap(vec[i], vec[left]);

            first_bigger_element_index += 1;
        }
    }
    std::swap(vec[first_bigger_element_index], vec[right]);

    return first_bigger_element_index;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if(left>=right){
        return;       
    }
    size_t pivot {left + (right - left) /2};
    pivot = quick_sort_partition(vec, left, right, pivot);
    if(pivot > 0){
        quick_sort(vec, left, pivot - 1);
    }
    quick_sort(vec, pivot + 1, right); 
}

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

//EXO 4
int search(std::vector<int> tab, int value){
    int index {-1};
    int left {0}, right {static_cast<int>(tab.size())-1};
    int middle {};
    while(left<=right){
        middle = left + (right - left)/2;
        if(tab[middle]<value){
            left = middle + 1;
        }
        else if(tab[middle]>value){
            right = middle - 1;
        }
        else{
            index = middle;
            break;
        }
    }
    return index;
}

int main(){
    //EXO 1
    std::vector<int> array {8,4,5,7,2,1,10,9,6};
    std::vector<float> array2 {8,4,5,7,2,1,10,9,6};
    bubble_sort(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
        for(int i=0; i<array.size(); i++){
            std::cout << array[i] << ", ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    //EXO 2 ---------------------------------------------------------------------------------------------------
    quick_sort(array2);
    if (is_sorted(array2)) {
        std::cout << "Le tableau array2 est trié" << std::endl;
        for(int i=0; i<array2.size(); i++){
            std::cout << array2[i] << ", ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    

    //EXO 3 ----------------------------------------------------------------------------------------------------
    std::vector<float> data = generate_random_vector2(100);
    std::vector<int> tableau = generate_random_vector(100);
    std::vector<float> data2 = generate_random_vector2(100);
    {
        ScopedTimer timer("Tri rapide");
        quick_sort(data);
    }
    {
        ScopedTimer timer("Tri à bulles");
        bubble_sort(tableau);
    }
    {
        ScopedTimer timer("Le std::sort");
        std::sort(data2.begin(), data2.end());
    }
        /*Je peux en constater que le tri rapide est plus rapide (d'où son nom) que le tri à bulles. 
        Le tri récursif en séparant les parties du tableau est plus efficace. 
        Le std::sort est plus efficace que le tri à bulles, mais moins rapide que le tri récursif.
        Le tri récursif est donc le programme de tri le plus efficace.*/

    //EXO 4 -----------------------------------------------------------------------------------------------------
    int index1 {search({1, 2, 2, 3, 4, 8, 12}, 8)};  
    int index2 {search({1, 2, 3, 3, 6, 14, 12, 15}, 15)};
    int index3 {search({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16)};
    int index4 {search({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6)};
    int index5 {search({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10)};
    std::cout << "Dans l'ordre voici les index des valeurs recherchées pour chaque tableau exemple de l'énoncé : " << index1 << ", " << index2 << ", " << index3 << ", " << index4 << ", " << index5 << "." << std::endl;

    return 0;
}