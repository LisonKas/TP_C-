#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> robot_and_fixes;

    for (const auto& robot_fix : robots_fixes) {
        auto it = robot_and_fixes.find(robot_fix.first);
        if (it != robot_and_fixes.end()) {
            it->second.push_back(robot_fix.second);
        } else {
            robot_and_fixes[robot_fix.first] = {robot_fix.second};
        }
    }

    return robot_and_fixes;
}

float tab_to_sum(std::vector<float> tab){
    float sum {0.0f};
    for(int i {0}; i<tab.size(); i++){
        sum += tab[i];
    }
    return sum;
}


int main(){
    std::vector<std::pair<std::string, float>> exemple_get_robot {get_robots_fix(10)};
    std::cout << "Exemple de tableau avec get_robots_fix : " << std::endl; 
    for(int i {0}; i<exemple_get_robot.size(); i++){
        std::cout << "First : " << exemple_get_robot[i].first << " et Second : " << exemple_get_robot[i].second << ", " << std::endl;
    }
    std::cout << std::endl;

    std::unordered_map<std::string, std::vector<float>> exemple_map {robots_fixes_map(exemple_get_robot)};
    std::cout << "Exemple de tableau avec robots_fixes_map à partir du tableau précédent : " << std::endl; 
    for(std::pair<const std::string, std::vector<float, std::allocator<float>>> pair : exemple_map){
        std::cout << "Pour " << pair.first << " et Second : [ ";
        for(int i {0}; i<pair.second.size(); i++){
            std::cout << pair.second[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    std::vector<float> exemple_tab {1.0f, 6.0f, 7.0f, 2.0f};
    std::cout << "exemple de tab_to_sum : " << tab_to_sum(exemple_tab) << std::endl;
    std::cout << std::endl;

    std::cout << "On reprends le tableau précédent de robots_fixes_map et on affiche leur somme de réparation : " << std::endl;
    for(auto& robot : exemple_map){
        std::cout << "Robot " << robot.first << " : " << tab_to_sum(robot.second) << " de coût total de réparations" << std::endl;
    }

    return 0;
}