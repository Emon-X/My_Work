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

vector<vector<ll>>g;
ll ans = 0;
bool ok;
void dfs(ll node,vector<bool>&vis,vector<ll>&subtree)
{
    vis[node]=true;

    for(auto c:g[node]){
        if(vis[c]) continue;
        dfs(c,vis,subtree);
        subtree[node]+=subtree[c];
    }
}

void domain_expension()
{
    ll n;
    cin >> n;
    g.resize(n+1);
    for(int i=1;i<n;i++)
    {
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<bool>vis(n+1,false);
    vector<ll>subtree_size(n+1,1);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i,vis,subtree_size);
        
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) if(subtree_size[i]%2==0) ans++;

    if(n%2) cout << -1 << endl;
    else cout << ans-1 << endl;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}