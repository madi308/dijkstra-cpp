#include <iostream>

#include "Node.hpp"
#include "Dijkstra.hpp"

int main() {
    std::string fileName;
    std::cout << "Enter file name:";
    std::cin >> fileName;
    const auto graph = Dijkstra::readGraph(fileName);

    for (const auto& node : graph) {
        std::cout << *node;
    }

    for (auto dijkstra = Dijkstra::dijkstra(graph.at(0), graph);
        const auto&[fst, snd] : dijkstra) {
        std::cout << fst << " " << snd << '\n';
    }
}
