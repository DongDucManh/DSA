#ifndef GRAPH_CPP
#define GRAPH_CPP
#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;
#define elif else if
template<class data>
class Graph{
    private:
        int soDinh;
        linked_list<data>* graph;
        int getEdgeCount(){
            int count = 0;
            for (int i = 1; i <= soDinh; i++){
                count += graph[i].size();
            }
            return count/2;
        }
    public:
        Graph(int n){
            soDinh = n;
            graph = new linked_list<data>[n+1];
        }
        Graph(){
            soDinh = 0;
            graph = NULL;
        }
        ~Graph(){
            delete[] graph;
        }
        Graph* operator&(){
            return this;
        }
        void addEdge(data u, data v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        void readFile(string filename){
            ifstream file(filename);
            int n, m;
            file >> n >> m;
            Graph g(n);
            for (int i = 0; i < m; i++){
                int u, v;
                file >> u >> v;
                g.addEdge(u, v);
            }
            *this = g;
            file.close();
        }
        void writeFile(string filename){
            ofstream file(filename);
            file << soDinh << " " << getEdgeCount() << endl;
            for (int i = 1; i <= soDinh; i++){
                for (data j : graph[i]){
                    if (i < j){
                        file << i << " " << j << endl;
                    }
                }
            }
            file.close();
        }
        int dfs(){//Dem so thanh phan lien thong
            bool* visited = new bool[soDinh];
            memset(visited, false, sizeof(visited));
            stack<data> S;
            int count = 0;
            for (int v = 1; v <= soDinh; v++){
                if (!visited[v]){
                    count++;
                    S.push(v);
                    visited[v] = true;
                    while (!S.empty()){
                        data u = S.top();
                        S.pop();
                        for (data i : graph[u]){
                            if (!visited[i]){
                                visited[i] = true;
                                S.push(i);
                            }
                        }
                    }
                }
            }
            delete[] visited;
            return count;
        }
        //BFS de kiem tra duong di giua hai dinh
        bool checkPath(data start, data end){
            if (start == end) return true;
            bool* visited = new bool[soDinh];
            memset(visited, false, sizeof(visited));
            queue<data> q;
            q.push(start);
            visited[start] = true;
            while (!q.empty()){
                data current = q.front();
                q.pop();
                for (data i : graph[current]){
                    if (i == end){
                        delete[] visited;
                        return true;
                    }
                    if (!visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            delete[] visited;
            return false;
        }
        void printGraph(){
            for (int i = 0; i < soDinh; i++){
                cout << i << ": ";
                for (data j : graph[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
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