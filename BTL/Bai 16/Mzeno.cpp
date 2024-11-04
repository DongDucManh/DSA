#include "graph.cpp"
#include "linked_list.cpp"
#include <bits/stdc++.h>
using namespace std;
int main() {
    //Tạo đồ thị mới với 5 đỉnh
    Graph<int> g;
    g.readFile("Mzeno.inp");
    g.printGraph();
    // // Ghi và đọc file
    // g.writeFile("graph.txt");

    return 0;
}