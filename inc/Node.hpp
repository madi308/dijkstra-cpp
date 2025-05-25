#pragma once

#include <Edge.hpp>
#include <string>
#include <utility>
#include <vector>

struct Node {
    std::string info;
    std::vector<Edge> edges{}; // Edges that originate from this node.

    explicit Node(std::string info) : info(std::move(info)) {}
};

std::ostream & operator<<(std::ostream &os, const Node &obj);