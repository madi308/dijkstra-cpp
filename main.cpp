#include <iostream>

#include "Node.hpp"
#include "Dijkstra.hpp"

int main() {
    std::string fileName;
    std::cout << "Enter file name:";
    std::cin >> fileName;
    const auto graph = Dijkstra::readGraph(fileName);

    std::cout << "All edges:\n";
    for (const auto& node : graph) {
        std::cout << *node;
    }

    std::cout << "---------------------------\n";
    std::cout << "Shortest paths from " << graph.at(0)->info << '\n';
    for (auto dijkstra = Dijkstra::dijkstra(graph.at(0), graph);
        const auto&[fst, snd] : dijkstra) {
        std::cout << "to " << fst << " " << snd << '\n';
    }
}
