#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Hàm kiểm tra xem vị trí (x,y) có hợp lệ trên bàn cờ không
inline bool isValid(ll x, ll y, ll n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// Hàm tìm các vị trí mà một quân mã có thể tấn công
vector<vector<vector<pair<ll, ll>>>> getAttackPositions(ll n) {
    vector<vector<vector<pair<ll, ll>>>> attackPositions(n, vector<vector<pair<ll, ll>>>(n));
    for (ll x = 0; x < n; x++) {
        for (ll y = 0; y < n; y++) {
            for (int i = 0; i < 8; i++) {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if (isValid(nx, ny, n)) {
                    attackPositions[x][y].emplace_back(nx, ny);
                }
            }
        }
    }
    return attackPositions;
}

// Hàm giải bài toán cho n
ll solve(ll n) {
    ll ans = 0;
    ll total = n * n;
    auto attackPositions = getAttackPositions(n);

    for (ll pos1 = 0; pos1 < total; pos1++) {
        ll x1 = pos1 / n;
        ll y1 = pos1 % n;

        for (ll pos2 = pos1 + 1; pos2 < total; pos2++) {
            ll x2 = pos2 / n;
            ll y2 = pos2 % n;

            // Kiểm tra xem con mã thứ hai có bị tấn công bởi con thứ nhất
            bool attacked = false;
            for (const auto& p : attackPositions[x1][y1]) {
                if (p.first == x2 && p.second == y2) {
                    attacked = true;
                    break;
                }
            }
            if (attacked) continue;

            for (ll pos3 = pos2 + 1; pos3 < total; pos3++) {
                ll x3 = pos3 / n;
                ll y3 = pos3 % n;

                // Kiểm tra xem con mã thứ ba có bị tấn công bởi con thứ nhất hoặc thứ hai
                attacked = false;
                for (const auto& p : attackPositions[x1][y1]) {
                    if (p.first == x3 && p.second == y3) {
                        attacked = true;
                        break;
                    }
                }
                if (!attacked) {
                    for (const auto& p : attackPositions[x2][y2]) {
                        if (p.first == x3 && p.second == y3) {
                            attacked = true;
                            break;
                        }
                    }
                }
                if (attacked) continue;

                ans++;
                if (ans >= MOD) ans -= MOD;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    for (int i=0;i<=11;i++){
        
        cout << solve(i) << endl;
    }
    
    return 0;
}
