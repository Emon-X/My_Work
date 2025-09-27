#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    bool changed = true;
    while (changed) {
        changed = false;
        vector<pair<ll, ll>> black;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '.') continue;
                ll cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '#')
                        cnt++;
                }
                if (cnt == 1) black.push_back({i, j});
            }
        }
        for (auto [i, j] : black) {
            grid[i][j] = '#';
            changed = true;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#') ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}