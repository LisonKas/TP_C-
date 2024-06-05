#pragma once
#include <vector>
#include <unordered_map>
#include <utility>

namespace Graph {

    struct WeightedGraphEdge {
        int to {};
        float weight {1.0f};

        bool operator==(WeightedGraphEdge const& other) const;
        bool operator!=(WeightedGraphEdge const& other) const;
    };

    struct WeightedGraph {
        std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list {};

        void add_vertex(int const id);
        void add_directed_edge(int const from, int const to, float const weight = 1.0f);
        void add_undirected_edge(int const from, int const to, float const weight = 1.0f);
        bool operator==(WeightedGraph const& other) const;
        bool operator!=(WeightedGraph const& other) const;
        void print_DFS(int const start) const;
        void print_BFS(int const start) const;
    };

} // namespace Graph