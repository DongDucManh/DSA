#include "graph.cpp"
#include "linked_list.cpp"
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Tạo đồ thị mới với 5 đỉnh
    // Graph<int> g(5);
    
    // // Thêm các cạnh
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // for (auto i: g[2]){
    //     cout<<i<<" ";
    // }
    // In đồ thị
    // cout << "Do thi ban dau:" << endl;
    // g.printGraph();
    
    // // Test các chức năng
    // cout << "\nSo thanh phan lien thong: " << g.dfs() << endl;
    // cout << "Co duong di tu 1 den 4: " << (g.checkPath(1, 4) ? "Co" : "Khong") << endl;
    
    // // Ghi và đọc file
    // g.writeFile("graph.txt");
    linked_list<int> a;
    a.push_front(3);
    a.push_front(4);
    a.push_front(5);
    a.push_front(6);
    a.push_front(7);
    cout<<a.back()<<endl;
    cout<<a.front()<<endl;
    cout<<a.size()<<endl;
    for (linked_list<int>::iterator i = a.begin(); i != a.end(); ++i){
        cout<<1<<" ";
    }
    return 0;
}