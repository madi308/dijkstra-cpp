#pragma once

#include "Node.hpp"
#include<string>
#include <unordered_map>

class Dijkstra {
public:
    static std::vector<std::shared_ptr<Node>> readGraph(std::string &fileName);

    static std::unordered_map<std::string, int> dijkstra(std::shared_ptr<Node> initial,
                                                         const std::vector<std::shared_ptr<Node> > &graph);
};
