#include <Dijkstra.hpp>
#include <Node.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <ranges>
#include <queue>
#include <unordered_map>

std::vector<std::shared_ptr<Node>> Dijkstra::readGraph(std::string &fileName) {
    std::fstream file(fileName, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("File not found: " + fileName);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::map<std::string, std::shared_ptr<Node>> nodes{};
    std::vector<std::shared_ptr<Node>> insertionOrder{};
    std::string line;
    while (getline(buffer, line)) {
        if (line.empty())
            continue;
        std::stringstream ss{line};
        std::string info;
        getline(ss, info, '\t');
        std::shared_ptr<Node> node;
        if (nodes.contains(info)) {
            node = nodes.at(info);
        } else {
            node = std::make_shared<Node>(info);
            insertionOrder.push_back(node);
        }
        nodes[info] = node;
    }
    buffer.clear();
    buffer.seekg(0, std::ios::beg);
    while (getline(buffer, line)) {
        if (line.empty())
            continue;
        std::stringstream ss{line};
        std::string firstInfo;
        getline(ss, firstInfo, '\t');
        auto node = nodes.at(firstInfo);
        std::string weightText;
        getline(ss, weightText, '\t');
        std::string otherNodeInfo;
        while (getline(ss, otherNodeInfo, '\t')) {
            node->edges.emplace_back(Edge{node, nodes[otherNodeInfo], stoi(weightText)});
        }
    }
    return insertionOrder;
}

// Some inspiration: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
std::unordered_map<std::string, int> Dijkstra::dijkstra(const std::shared_ptr<Node>& initial,
                                                        const std::vector<std::shared_ptr<Node>> &graph) {
    using Pair = std::pair<int, std::shared_ptr<Node>>;
    auto comparator = [](const Pair &a, const Pair &b) {
        return a.first > b.first;
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(comparator)> pq(comparator);
    std::unordered_map<std::string, int> dist;
    for (const auto& node : graph) {
        dist[node->info] = INT_MAX;
    }

    dist[initial->info] = 0;
    pq.emplace(0, initial);

    while (!pq.empty()) {
        const std::shared_ptr<Node> u = pq.top().second;
        pq.pop();

        for (const auto& edge : u->edges) {
            auto otherNode = edge.to;

            if (const int weight = edge.weight; dist[otherNode->info] > dist[u->info] + weight) {
                dist[otherNode->info] = dist[u->info] + weight;
                pq.emplace(dist[otherNode->info], otherNode);
            }
        }
    }
    return dist;
}

