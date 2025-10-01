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
vector<ll>g[N];

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=n;i++) sort(all(g[i]));

    vector<bool>vis(n+1,false);
    vector<ll>ans;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(1);
    vis[1] = true;
    while(!pq.empty()){
        ll u = pq.top(); pq.pop();
        ans.pb(u);
        for(auto v : g[u]){
            if(!vis[v]){
                vis[v] = true;
                pq.push(v);
            }
        }
    }
    for(auto u:ans) cout << u << " "; cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}