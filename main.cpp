#include <iostream>

#include "Node.hpp"
#include "Dijkstra.hpp"

int main() {
    std::string FILE_NAME = "../example_data.tsv";
    const auto graph = Dijkstra::readGraph(FILE_NAME);

    for (const auto node : graph) {
        std::cout << "Node: " << node->info << '\n';
        for (auto [from, to, weight] : node->edges) {
            std::cout << "From: " << from->info << ", ";
            std::cout << "to: " << to->info << ", ";
            std::cout << "weight: " << weight << '\n';
        }
    }

    auto dijkstra = Dijkstra::dijkstra(graph.at(0), graph);
    for (auto pair : dijkstra) {
        std::cout << pair.first << " " << pair.second << '\n';
    }
}
