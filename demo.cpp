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
main(){
    cin.tie(0)->sync_with_stdio(0);
    map<string,int> m;
    string s,s1;
    getline(cin,s);
    m[s]+=1;
    cin>>s1;
    m[s1]+=1;
    cout<<m[s1];
    return 0;
}