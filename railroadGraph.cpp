#include <fstream>
#include <iostream>

#include "Graph.h"

int main(int argc, char* argv[])
{
    // Read data from file
    Graph railroad;
    std::ifstream in("Input1.txt");
    int num_nodes;
    int num_edges;
    in >> num_nodes >> num_edges;
    for (int i = 0; i < num_nodes; i++)
    {
        int id, unload, load;
        in >> id >> unload >> load;
        railroad.add_node(id, unload, load);
    }
    for (int i = 0; i < num_edges; i++)
    {
        int from, to;
        in >> from >> to;
        railroad.add_edge(from, to);        
    }
    int start_node;
    in >> start_node;
    
    railroad.analyze_cargo(start_node);
    railroad.print_all_possible_cargo();
    
    in.close();
    return 0;
}
