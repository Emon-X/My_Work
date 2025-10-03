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

vector<ll> costs;
void dfs(ll node, ll par, vector<vector<pair<ll,ll>>>& g, ll depth, ll cost) {
    bool isLeaf = true;
    for (auto [child, w] : g[node]) {
        if (child == par) continue;
        isLeaf = false;
        ll newCost = cost + depth * w; 
        dfs(child, node, g, depth + 1, newCost);
    }
    if (isLeaf && node != 1) { 
       
        costs.push_back(cost);
    }
}

void domain_expension()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];

    vector<vector<pair<ll,ll>>> g(n + 1);
    for (int i = 0; i <n-1 ; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    costs.clear();
    dfs(1, -1, g, 1, 0);
    set<ll>st(all(p));

    ll ans = 0;
    for(int i=0;i<costs.size();i++){
        auto it = st.lower_bound(costs[i]);
        if(it!=st.end()){
            ans++;
            st.erase(it);
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    domain_expension();
    return 0;
}