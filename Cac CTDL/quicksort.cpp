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
void quicksort(int a[],int l,int r)
{
    int key=a[l];
    int i=l,j=r;
    while (i<j){
        while (a[i]<key)i++;
        while (a[j]>key)j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l<j) quicksort(a,l,j);
    if (i<r) quicksort(a,i,r);
}
main(){
  cin.tie(0)->sync_with_stdio(0);
  int a[]={2,4,1,4,5,2,3,6,3,7};
    quicksort(a,0,9);
    for (auto x:a) cout<<x<<" ";
    
  return 0;
}