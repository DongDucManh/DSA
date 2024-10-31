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

void bublesort(int a[],int n){//O(N^2)
for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1; j++)
        if (a[j] > a[j+1]) {
            swap(a[j], a[j+1]);
        }
}
main(){
  cin.tie(0)->sync_with_stdio(0);
  int a[]={2,4,1,4,5,2,3,6,3,7};
  bublesort(a,10);
  for (auto x:a) cout<<x<<" ";
  return 0;
}