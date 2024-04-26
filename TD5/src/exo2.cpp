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

// std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){
//     std::unordered_map<std::string, std::vector<float>> robot_and_fixes;
//     std::vector<float> reparations;
//     for(int i {0}; i<robots_fixes.size(); i++){
//         auto number = robot_and_fixes.find(robots_fixes[i].first);
//         if(number != robot_and_fixes.end()){
//             for(int j {0}; j<robots_fixes.size(); j++){
//                 if(robots_fixes[j].first == robots_fixes[i].first){
//                     reparations.push_back(robots_fixes[j].second);
//                 }
//             }
//         }
//         robot_and_fixes.insert(std::make_pair(robots_fixes[i].first, reparations));

//     }
//     return robot_and_fixes;
// }


//Truc 
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> robot_and_fixes;

    for (const auto& robot_fix : robots_fixes) {
        // Vérifie si le robot existe déjà dans la map
        auto it = robot_and_fixes.find(robot_fix.first);
        if (it != robot_and_fixes.end()) {
            // Si le robot existe déjà, ajoute simplement le coût à son vecteur de réparations
            it->second.push_back(robot_fix.second);
        } else {
            // Si le robot n'existe pas, ajoute une nouvelle entrée dans la map
            robot_and_fixes[robot_fix.first] = {robot_fix.second};
        }
    }

    return robot_and_fixes;
}




int main(){
    std::vector<std::pair<std::string, float>> exemple_get_robot {get_robots_fix(10)};
    std::cout << "Exemple de tableau avec std::pair : " << std::endl; 
    for(int i {0}; i<exemple_get_robot.size(); i++){
        std::cout << "First : " << exemple_get_robot[i].first << " et Second : " << exemple_get_robot[i].second << ", " << std::endl;
    }
    std::cout << std::endl;
    std::unordered_map<std::string, std::vector<float>> exemple_map {robots_fixes_map(exemple_get_robot)};
    std::cout << "Exemple de tableau avec unordered_map : " << std::endl; 
    for(std::pair<const std::string, std::vector<float, std::allocator<float>>> pair : exemple_map){
        std::cout << "Pour " << pair.first << " et Second : [ ";
        for(int i {0}; i<pair.second.size(); i++){
            std::cout << pair.second[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}