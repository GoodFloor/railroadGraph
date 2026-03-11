#include "Graph.h"

#include <algorithm>
#include <iterator>
#include <stdexcept>

Graph::Node::Node(const int cargo_unload, const int cargo_load):    cargo_unload_(cargo_unload),
                                                                    cargo_load_(cargo_load)
{
    visited_ = false;
}

void Graph::Node::add_edge(Node* to)
{
    edges_.push_back(to);
}

void Graph::Node::print_possible_cargo() const
{
    bool first = true;
    for (const int cargo : possible_cargo_)
    {
        if (!first)
            printf(", ");
        else
            first = false;
        printf("[%d]", cargo);
    }
}

int Graph::Node::get_unloaded_cargo() const
{
    return cargo_unload_;
}

std::set<int> Graph::Node::get_possible_cargo()
{
    return possible_cargo_;
}

int Graph::Node::get_loaded_cargo() const
{
    return cargo_load_;
}

bool Graph::Node::was_visited() const
{
    return visited_;
}

void Graph::Node::add_possible_cargo(const int cargo)
{
    possible_cargo_.insert(cargo);
}

std::vector<Graph::Node*> Graph::Node::get_edges()
{
    return edges_;
}

void Graph::Node::visit()
{
    visited_ = true;
}

void Graph::analyze_station(Node* node, Node* predecessor)
{
    std::set<int> incoming_cargo =  predecessor->get_possible_cargo();
    std::set<int> current_cargo =  node->get_possible_cargo();
    incoming_cargo.erase(predecessor->get_unloaded_cargo());
    incoming_cargo.insert(predecessor->get_loaded_cargo());
    std::vector<int> difference;
    std::set_difference(incoming_cargo.begin(), incoming_cargo.end(), current_cargo.begin(), current_cargo.end(), std::back_inserter(difference));
    if (difference.empty() && node->was_visited())
        return;
    
    node->visit();
    for (const int cargo : difference)
    {
        node->add_possible_cargo(cargo);
    }
    for (const auto edge : node->get_edges())
    {
        analyze_station(edge, node);
    }
}

void Graph::add_node(const int id, const int cargo_unload, const int cargo_load)
{
    node_map_[id] = new Node(cargo_unload, cargo_load);
}

void Graph::add_edge(const int from, const int to)
{
    if (!node_map_.count(from))
    {
        printf("The station [%d] does not exist so a track cannot be added.", from);
        throw std::invalid_argument("Invalid 'from' station");
    }
    if (!node_map_.count(to))
    {
        printf("The station [%d] does not exist so a track cannot be added.", to);
        throw std::invalid_argument("Invalid 'to' station");
    }
    node_map_[from]->add_edge(node_map_[to]);
}

void Graph::print_all_possible_cargo() const
{
    for (const auto node : node_map_)
    {
        printf("Node [%d]:\n\t", node.first);
        node.second->print_possible_cargo();
        printf("\n");
    }
}

void Graph::analyze_cargo(const int start_node)
{
    if (!node_map_.count(start_node))
    {
        printf("The station [%d] does not exist so it cannot be a starting station.", start_node);
        throw std::invalid_argument("Invalid starting station");
    }
    Node* node = node_map_[start_node];
    
    node->visit();
    for (const auto next_node : node->get_edges())
    {
        analyze_station(next_node, node);
    }
}

