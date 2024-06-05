#include "graph.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

namespace Graph {
    bool WeightedGraphEdge::operator==(WeightedGraphEdge const& other) const {
        return to == other.to && weight == other.weight;
    }

    bool WeightedGraphEdge::operator!=(WeightedGraphEdge const& other) const {
        return !(*this == other);
    }

    bool WeightedGraph::operator==(WeightedGraph const& other) const {
        return adjacency_list == other.adjacency_list;
    }

    bool WeightedGraph::operator!=(WeightedGraph const& other) const {
        return !(*this == other);
    }

    //EXO 1 Question 1
    void WeightedGraph::add_vertex(int const id) {
        auto find_id = this->adjacency_list.find(id);
        if(find_id == this->adjacency_list.end()){
            this->adjacency_list[id]={};
        }
    }

    //EXO 1 Question 2
    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
        //etant donné que add_vertex vérifie que les sommets existent avant de les créer :
        this->add_vertex(from);
        this->add_vertex(to);
        //puis on ajoute le poids :
        this->adjacency_list[from].push_back({to, weight});
    }

    //EXO 1 Question 3
    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight) {
        this->add_directed_edge(from, to, weight);
        this->add_directed_edge(to, from, weight);
    }

    //EXO 2 Question 1
    void WeightedGraph::print_DFS(int const start) const {
        std::unordered_set<int> deja_visite;
        std::stack<int> a_visite; 

        a_visite.push(start);
        while (!a_visite.empty()) {
            int noeud = a_visite.top();
            a_visite.pop();

            if (deja_visite.find(noeud) == deja_visite.end()) {  // si le noeud n'a pas encore ete visite
                deja_visite.insert(noeud);
                std::cout << noeud << ", ";
                if (this->adjacency_list.find(noeud) != this->adjacency_list.end()) {  //S'il y a encore des noeuds dans la liste (soit qu'il a des voisins)
                    for (const auto& graph : this->adjacency_list.at(noeud)) {
                        if (deja_visite.find(graph.to) == deja_visite.end()) { //Si le noeud arrivee n'a pas ete visite
                            a_visite.push(graph.to);
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    //EXO 2 Question 2
    void WeightedGraph::print_BFS(int const start) const {
        std::unordered_set<int> deja_visite;
        std::queue<int> a_visite; 

        a_visite.push(start);
        deja_visite.insert(start);
        while (!a_visite.empty()) {
            int noeud = a_visite.front();
            a_visite.pop();
            std::cout << noeud << ", ";

            if (this->adjacency_list.find(noeud) != this->adjacency_list.end()) {  //S'il y a encore des noeuds dans la liste (soit qu'il a des voisins)
                for (const auto& graph : this->adjacency_list.at(noeud)) {
                    if (deja_visite.find(graph.to) == deja_visite.end()) { //Si le noeud arrivee n'a pas ete visite
                        a_visite.push(graph.to);
                        deja_visite.insert(graph.to);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

}