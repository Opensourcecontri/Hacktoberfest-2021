#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; //the number of vertices in the graph
    list<int> *l; //array of the list

    public:
    //constructor
    Graph(int v){
        V=v;
        l = new list<int>[V];
    }

    //for adding the edges between the vertices
    void addEdges(int u, int v, bool bidir=true){ //here we have already declared that the graph is bidirectional
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }

    //for printing the array of list ----- Not much useful in future
    void printGraph(){
        for(int i=0; i<V; i++){
            cout<<i<<"->";
            for(int vertex : l[i]){
                cout<<vertex<<", ";
            }
            cout<<"\n";
        }
    }

};

int main(){
    //graph has five vertices from 0 to 4
    Graph g(5);
    g.addEdges(0,1);
    g.addEdges(0,4);
    g.addEdges(4,3);
    g.addEdges(1,4);
    g.addEdges(1,2);
    g.addEdges(2,3);

    g.printGraph();

    return 0;
}