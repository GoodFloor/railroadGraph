#include <fstream>
#include <iostream>

#include "Graph.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: railroad_graph.exe <file>\n");
        return 2;
    }
    // Read data from file
    Graph railroad;
    std::ifstream in(argv[1]);
    if (!in.is_open())
    {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    printf("Reading from file %s\n", argv[1]);
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
    
    if (in.eof())
    {
        printf("The file contains invalid data (declared number of stations/tracks is greater than the actual number of entries).\n");
        return 4;
    }
    
    railroad.analyze_cargo(start_node);
    railroad.print_all_possible_cargo();
    
    in.close();
    return 0;
}
