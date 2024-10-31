#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
unordered_map<string,int> m;
void Try(string res,int d1,int d2){
    if (d1>n || d2>n) return;
    if (d2>d1) return;
    if (d2==n && d1==n){
        m[res]=1;
        return;
    }
    Try(res+'(',d1+1,d2);
    Try(res+')',d1,d2+1);
}
void Try1(string res,int d1,int d2){
    //freopen("sinh.out","w",stdout);
    if (d1>n || d2>n) return;
    if (d2<d1 and d1+d2<n) return;
    if (d2==n && d1==n){
        if( m.find(res) == m.end()){cout<<res<<"\n";}
        return;
    }
    Try1(res+'(',d1+1,d2);
    Try1(res+')',d1,d2+1);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    string s;
    //Try(s,0,0);
    Try1(s,0,0);
    return 0;
}
)((())
)(()()
)(())(
)()(()
)()()(
)())((
))(()(
))()((
)))(((
    
)((())
)(()()
)(())(
)()(()
)()()(
)())((
))((()
))(()(
))()((
)))(((