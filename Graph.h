#pragma once
#include <map>
#include <set>
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
    };
    std::map<int, Node*> node_map_;
    static void analyze_station(Node* node, Node* predecessor);
public:
    void add_node(const int id, const int cargo_unload, const int cargo_load);
    void add_edge(const int from, const int to);
    void print_all_possible_cargo() const;
    void analyze_cargo(const int start_node);
};
