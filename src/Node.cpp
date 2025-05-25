#include "Node.hpp"

std::ostream & operator<<(std::ostream &os, const Node &obj) {
    os << "Node: " << obj.info << '\n';

    for (const auto& [from, to, weight] : obj.edges) {
        os << "From: " << from->info << ", "
        << "to: " << to->info << ", "
        << "weight: " << weight << '\n';
    }
    return os;
}