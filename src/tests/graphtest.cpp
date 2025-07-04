#include <iostream>
#include "../../include/Graph.h"
using namespace std;

void testUnweightedGraph(){
    Graph<int> g(false, false);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.print();

    cout<<"bfs from 1: "<<endl;
    for(int i : g.bfs(1)){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"dfs from 1: "<<endl;
    for(int i : g.dfs(1)){
        cout<<i<<" ";
    }
    cout<<endl;
}

void testWeightedDirectedGraph(){
    Graph<int> g(true, true);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    g.print();

    cout<<"topological sort: "<<endl;
    for(int i : g.topologicalSort()){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Dijkstra from 0: "<<endl;
    auto dist = g.dijkstra(0);
    for(const auto& pair : dist){
        cout<<"distance to "<<pair.first<<" = "<<pair.second<<endl;
    }
}

int main(){

    testUnweightedGraph();
    testWeightedDirectedGraph();

    return 0;
}