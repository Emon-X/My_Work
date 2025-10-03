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

bool ok;

void dfs(ll node,vector<ll>&colour,ll c,vector<bool>&vis,const vector<vector<ll>>&g)
{
    vis[node] = true;
    colour[node] = c;
    for(auto child:g[node]){
        if(!vis[child])
        dfs(child,colour,c^1,vis,g);
        else if(colour[node]==colour[child]){
            ok = true;
            return;
        }
    }
}

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>>g(n+1);
    vector<pair<ll,ll>>mp(m+1);
    for(int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        mp[i] = {u,v};
    }
    vector<ll>colour(n+1,-1);
    vector<bool>vis(n+1,false);
    ok = false;
    dfs(1,colour,0,vis,g);
    if(ok) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i=0;i<m;i++){
            cout << colour[mp[i].first];
        }
        cout<<"\n";
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}