#include "graph.cpp"
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Tạo đồ thị mới với 5 đỉnh
    Graph<int> g(5);
    
    // Thêm các cạnh
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    //g.addEdge(2, 3);
    g.addEdge(4, 5);
    
    // In đồ thị
    cout << "Do thi ban dau:" << endl;
    g.printGraph();
    
    // Test các chức năng
    cout << "\nSo thanh phan lien thong: " << g.dfs() << endl;
    cout << "Co duong di tu 1 den 4: " << (g.checkPath(1, 4) ? "Co" : "Khong") << endl;
    
    // Ghi và đọc file
    g.writeFile("graph.txt");
    
    return 0;
}