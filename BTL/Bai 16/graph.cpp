#ifdef GRAPH_CPP
#define GRAPH_CPP
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
            
        }
};
#endif
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m,u,v,k=0,res=0,dem;
//     cin>>n>>m;
//     int d[n+5]={};
//     vector<int> A[n+5];
//     while(m--)
//     {
//         cin>>u>>v;
//         A[u].push_back(v);A[v].push_back(u);
//     }
//     for(int i=1;i<=n;i++)
//     if(d[i]==0)
//     {
//         k++;
//         dem=1;
//         d[i]=1;
//         stack<int> S;
//         S.push(i);
//         while(S.size())
//         {
//             u=S.top();S.pop();
//             for(int v:A[u])
//             if(d[v]==0)
//             {
//                 d[v]=1;
//                 dem++;
//                 S.push(v);
//             }
//         }
//         if(res<dem) res=dem;
//     }
//     cout<<k<<" \n"<<res;
// }