#include "graph.cpp"
#include "linked_list.cpp"
#include <bits/stdc++.h>
using namespace std;
int main() {
    //Tạo đồ thị mới với 5 đỉnh
    Graph<int> g;
    g.readFile("Mzeno.inp");
    // Ghi và đọc file
    g.writeFile("Mzeno.out");
    cout<<"So thanh phan lien thong cua do thi: "<<g.sothanhphanlienthong()<<endl;
    //Kiểm tra đường đi giữa 2 đỉnh
    int s,f;
    cout<<"Nhap dinh bat dau va dinh ket thuc: ";
    cin >> s >> f;
    if (s > g.getVertices() || f > g.getVertices() || s < 1 || f < 1){
        cout << "Dinh khong hop le" << endl;
        return 0;
    }
    if (g.checkPath(s, f)){
        cout << "Co duong di giua " << s << " va " << f << endl;
    } else {
        cout << "Khong co duong di giua " << s << " va " << f << endl;
    }

    return 0;
}