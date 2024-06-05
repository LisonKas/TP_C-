#include <iostream>
#include <vector>
#include <array>
#include "graph.hpp"

//EXO 1 Question 4
Graph::WeightedGraph adjacency_list_from_adjacency_matrix(const std::vector<std::vector<int>>& matrice_adjacence) {
    Graph::WeightedGraph graphe;
    int taille = matrice_adjacence.size();

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (matrice_adjacence[i][j] != 0) {
                graphe.add_directed_edge(i, j, static_cast<float>(matrice_adjacence[i][j]));
            }
        }
    }

    return graphe;
}

void print_graph(Graph::WeightedGraph graph){
    for (const auto& paire : graph.adjacency_list) {
        int noeud = paire.first;
        const std::vector<Graph::WeightedGraphEdge>& weighted_graph = paire.second;
        std::cout << "Noeud n°" << noeud << " contient une arrête allant vers : ";
        for (const auto& graphe : weighted_graph) {
            std::cout << graphe.to << " de poids " << graphe.weight << ", ";
        }
        std::cout << std::endl;
    }
}

int main(){
    //EXO 1 Question 5
    std::vector<std::vector<int>> matrice_adjacence = {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };

    Graph::WeightedGraph graph = adjacency_list_from_adjacency_matrix(matrice_adjacence);
    print_graph(graph);

    std::cout << std::endl;
    std::cout << "Autre graphe en utilisant les premières méthodes : " << std::endl;
    Graph::WeightedGraph graph2;
    graph2.add_undirected_edge(1, 2, 2.0f);
    graph2.add_undirected_edge(2, 3, 3.0f);
    graph2.add_undirected_edge(3, 4, 4.0f);
    graph2.add_undirected_edge(1, 4, 7.0f);
    graph2.add_vertex(5);
    graph2.add_undirected_edge(2, 5, 1.0f);
    print_graph(graph2);
    std::cout << std::endl;
    //EXO 2 Question 1
    std::cout << "Le print_DFS du graph2 : ";
    graph2.print_DFS(1);
    std::cout << "Le print_DFS du graph : ";
    graph.print_DFS(0);
    std::cout << std::endl;
    //EXO 2 Question 2
    std::cout << "Le print_BFS du graph2 : ";
    graph2.print_BFS(1);
    std::cout << "Le print_BFS du graph : ";
    graph.print_BFS(0);

    return 0;
}

/* ETAPES POUR TROUVER LE PLUS COURT CHEMIN ENTRE LES SOMMETS A ET E DU GRAPHE DONNE (DIJKSTRA)
ETAPE 1
    On ajoute dans une file à_visiter le noeud A avec un poids de 0, A(0), car il est au départ du graphe.

ETAPE 2
    On parcourt les voisins de A. On observe B(1), D(2) et C(5). On les rajoute dans à_visiter, puis on les ajoutes dans un tableau associatif qu'on nommera Distances.
    Elles seront noté B(1, A), D(2, A) et C(5, A). Le poids est en premier, et la provenance est en dernier.

ETAPE 3
    On choisit le sommet B car son poids est le plus petit. On observe ses voisins qui sont (avec les poids additionné au poids de B) : C(5), qui ne change rien, et D(6).
    Etant donné que depuis B, le poids de D est plus grand que depuis A, on choisit de ne pas rajouter ce poids dans Distances. Cependant il faudra tout de même qu'il soit ajouté dans à_visiter.
    C(5) ne sera pas rajouté dans à_visiter car il a déjà été visité. Il ne sert à rien de changer sa provenance dans Distances car le poids est le même. 

ETAPE 4
    On va choisir C(5) car son poids est plus petit que D(6). Ses voisins sont E(8) et F(9) qu'on rajoutera dans à_visiter.
    De même on rajoutera E(8, C) et F(9, C) dans Distances.

ETAPE 5
    Cette fois-ci on regarde les voisins de E(8), plus petit que F(9). Il n'a qu'un seul voisin : F(11). On le rajoutera dans à_visiter, mais comme F(11) est plus grand que F(9), on ne le rajoutera pas dans Distances.

ETAPE 6
    Etant donné que F n'a pas de voisins, on retourne alors sur D(2), car on ignore D(6) qui est plus grand et donc ne nous intéresse pas.
    Ses voisins sont C(4) et E(7). On les rajoute dans à_visiter. Leur poids étant plus petit que ceux enregistré au préalables, on les remplacera donc dans Distances :
    C(5, A) deviendra C(4, D) et E(8, C) deviendra E(7, D) dans Distances.

ETAPE 7
    On choisit alors C(4) et on regarde à nouveau ses voisins. On retrouve E(7), qu'on ne changera donc pas. Et on a F(8), qui ne nous intéresse pas, mais qu'on rajoute tout de même dans les tableaux.

CONCLUSION
    On sait alors que le plus petit chemin pour aller de A à E a un poids de 7.
    En regardant Distances on a : B(1, A), D(2, A), C(4, D), E(7, D) et F(8, C). On peut en déduire que le plus court chemin est : A --> D --> E. 
*/