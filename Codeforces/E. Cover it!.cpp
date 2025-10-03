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


void dfs(ll node,vector<ll>&d,ll height,vector<bool>&vis,const vector<vector<ll>>&g)
{
    vis[node] = true;
    d[node] = height;
    for(auto c:g[node]){
        if(vis[c]) continue;
        dfs(c,d,height+1,vis,g);
    }
}

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>>g(n+1);
    vector<bool>vis(n+1,false);
    vis.resize(n+1,false);
    for(int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<ll>d(n+1,0);
    dfs(1,d,0,vis,g);
    vector<ll>r1,r2;
    for(int i=1;i<=n;i++){
        if(d[i]%2) r1.pb(i);
        else r2.pb(i);
    }
    if(r1.size()>r2.size()){
        cout << r2.size() << endl;
        for(auto u:r2) cout << u << " ";
    }
    else {
        cout << r1.size() << endl;
        for(auto u:r1) cout << u << " ";
    }
    cout << endl;
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