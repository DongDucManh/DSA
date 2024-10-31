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
void insertsort(int data[],int n){
    for (int i = 1; i < n; i++) {
    // Tìm vị trí phù hợp cho i
        int j = i;
        while (j > 0 && data[i] < data[j-1]) --j;

        // Đưa i về đúng vị trí
        int tmp = data[i];
        for (int k = i; k > j; k--)
            data[k] = data[k-1];
        data[j] = tmp;
    }

}
main(){
  cin.tie(0)->sync_with_stdio(0);
  int a[]={16,3,5,52,5,3,5,7,1,4};
  insertsort(a,10);
  for (int i=0;i<10;i++ )cout<<a[i]<<" ";
  return 0;
}