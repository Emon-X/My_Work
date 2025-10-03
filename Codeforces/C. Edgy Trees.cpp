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

vector<ll> ft(N), inv_ft(N);

ll bin(ll base, ll p)
{
    ll res = 1;
    while (p > 0)
    {
        if (p % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return res;
}
ll n,k;
void dfs(ll node,const vector<pair<ll,ll>>g[],vector<bool>&vis ,ll &depth)
{
    vis[node] = true;
    depth++;
    for(auto [child,colour]:g[node]){
        if(vis[child] or colour == 1) continue;

        dfs(child,g,vis,depth);
    }
}

void domain_expension()
{
    cin >> n >> k;
    vector<pair<ll,ll>>g[n+1];
    for(int i=0;i<n-1;i++){
        ll u,v,c;
        cin >> u >> v >> c;
        g[u].pb({v,c});
        g[v].pb({u,c});
    }
    ll total = bin(n,k);
    ll bad = 0;
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        ll depth = 0;
        dfs(i,g,vis,depth);

        bad+=bin(depth,k);
        bad%=mod;
    }
    cout << (total - bad + mod)%mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}