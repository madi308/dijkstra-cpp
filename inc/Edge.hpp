#pragma once
#include <memory>

struct Node;

struct Edge {
    std::shared_ptr<Node> from;
    std::shared_ptr<Node> to;
    int weight{1};
};