#ifndef GRAPH_CPP
#define GRAPH_CPP
#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;
#define elif else if
template<class data>
class Graph{
    private:
        int vertices;
        slist<data>* graph;
        int getEdgeCount(){
            int count = 0;
            for (int i = 1; i <= vertices; i++){
                count += graph[i].size();
            }
            return count/2;
        }
    public:
        Graph(int n){
            vertices = n;
            graph = new slist<data>[n+5];
        }
        Graph(){
            vertices = 0;
            graph = NULL;
        }
        ~Graph(){
            delete[] graph;
        }
        Graph* operator&(){
            return this;
        }
        slist<data>& operator[](int i){
            return graph[i];
        }
        void addEdge(data u, data v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int getVertices(){
            return vertices;
        }
        void readFile(string filename){
            ifstream file(filename);
            int n, m;
            file >> n >> m;
            vertices = n;
            graph = new slist<data>[n+1];
            for (int i = 0; i < m; i++){
                int u, v;
                file >> u >> v;
                addEdge(u, v);
            }
            
            file.close();
        }
        void writeFile(string filename){
            ofstream file(filename);
            file<<"So dinh: "<<vertices<<endl;
            file<<"So canh: "<<getEdgeCount()<<endl;
            file<<"Danh sach canh: "<<endl;
            for (int i = 1; i <= vertices; i++){
                for (typename slist<data>::iterator j = graph[i].begin(); j != graph[i].end(); j++){
                    if (i < *j){
                        file << i << " " << *j << endl;
                    }
                }
            }
        }
        //Dem so thanh phan lien thong voi DFS
        int sothanhphanlienthong(){
            bool *visited = new bool[vertices+1];
            for (int i = 1; i <= vertices; i++){
                visited[i] = false;
            }
            stack<data> S;
            int count = 0;
            for (int v = 1; v <= vertices; v++){
                if (!visited[v]){
                    count++;
                    S.push(v);
                    visited[v] = true;
                    while (!S.empty()){
                        data u = S.top();
                        S.pop();
                        for (typename slist<data>::iterator i = graph[u].begin(); i != graph[u].end(); i++){
                            if (!visited[*i]){
                                visited[*i] = true;
                                S.push(*i);
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
            bool* visited = new bool[vertices];
            memset(visited, false, sizeof(visited));
            queue<data> q;
            q.push(start);
            visited[start] = true;
            while (!q.empty()){
                data current = q.front();
                q.pop();
                for (typename slist<data>::iterator i = graph[current].begin(); i != graph[current].end(); i++){
                    if (*i == end){
                        delete[] visited;
                        return true;
                    }
                    if (!visited[*i]){
                        visited[*i] = true;
                        q.push(*i);
                    }
                }
            }
            delete[] visited;
            return false;
        }
        void printGraph(){
            for (int i = 1; i <= vertices; i++){
                cout << i << ": ";
                for (typename slist<data>::iterator j = graph[i].begin(); j != graph[i].end(); j++){
                    cout << *j << " ";
                }
                cout << endl;
            }
        }
};
#endif
