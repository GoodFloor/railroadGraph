#pragma once
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

class Graph
{
    class Node
    {
    public:
        Node(int cargo_unload, int cargo_load);
    private:
        std::set<int> possible_cargo_;
        std::vector<Node*> edges_;
        std::vector<Node*> changed_predecessors_;
        int cargo_unload_;
        int cargo_load_;
        bool visited_;
    public:
        std::vector<Node*> get_edges();
        void add_edge(Node* to);
        std::set<int> get_possible_cargo();
        void add_possible_cargo(const int cargo);
        int get_loaded_cargo() const;
        bool was_visited() const;
        void visit();
        void print_possible_cargo() const;
        int get_unloaded_cargo() const;
        void changed_predecessor(Node* predecessor);
        std::vector<Node*> get_changed_predecessors();
        void clear_changed_predecessors();
    };
    std::map<int, Node*> node_map_;
    std::unordered_set<Node*> to_be_visited_;
    void analyze_station(Node* node);
public:
    void add_node(const int id, const int cargo_unload, const int cargo_load);
    void add_edge(const int from, const int to);
    void print_all_possible_cargo() const;
    void analyze_cargo(const int start_node);
};
