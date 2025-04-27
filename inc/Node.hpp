#pragma once

#include <Edge.hpp>
#include <string>
#include <vector>

struct Node {
    std::string info;
    std::vector<Edge> edges{}; // Edges that originate from this node.

    explicit Node(const std::string &info) : info(info) {}
};