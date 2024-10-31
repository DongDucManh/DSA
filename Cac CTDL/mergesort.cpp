#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
void mergesort(int a[],int l,int r){
    if (l>=r) return;
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    int i=l,j=m+1;
    vector<int> tmp;
    while (i<=m && j<=r){
        if (a[i]<a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while (i<=m) tmp.push_back(a[i++]);
    while (j<=r) tmp.push_back(a[j++]);
    for (int i=l;i<=r;i++) a[i]=tmp[i-l];
}
main(){
  cin.tie(0)->sync_with_stdio(0);
  int a[]={2,4,1,4,5,2,3,6,3,7};
    mergesort(a,0,9);
    for (auto x:a) cout<<x<<" ";
  return 0;
}