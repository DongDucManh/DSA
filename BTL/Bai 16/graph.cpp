#ifdef Graph_cpp
#define Graph_cpp
#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;
#define elif else if
template<class data>
class Graph{
    private:
        unordered_map<data, linked_list<data>> graph;
    public:
        void addVertex(data vertex){
            if (graph.find(vertex) == graph.end()){
                graph[vertex] = linked_list<data>();
            }
        }
        void addEdge(data u, data v){
            addVertex(u);
            addVertex(v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }   
        void dfs(){
            stack<data> s;
            unordered_map<data, bool> visited;
            for(auto i: graph){
                visited[i.first] = false;
            }
        }
};
#endif