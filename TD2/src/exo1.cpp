#include <iostream>
#include <vector>
#include <algorithm>
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
    float valeur_pivot = vec[pivot];

    std::swap(vec[pivot], vec[right]);

    for (size_t i {left}; i < right; ++i) {
        if (vec[i] < valeur_pivot) {
            std::swap(vec[i], vec[left]);

            left++;
        }
    }
    std::swap(vec[left], vec[right]);

    return left;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){

}

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

int main(){
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
    return 0;
}