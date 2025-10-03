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

vector<ll>f1,f2;

void dfs(ll node,ll par,const vector<ll>&s,const vector<vector<ll>>&g)
{
    if(node==1){
        f1[node] = f2[node] = s[node];
    }
    else{
        f1[node] = max(s[node],s[node]-f2[par]);
        f2[node] = min(s[node],s[node]-f1[par]);
    }
    for(auto c:g[node]){
        if(c==par) continue;

        dfs(c,node,s,g);
    }
}

void domain_expension()
{
    ll n;
    cin >> n;
    vector<ll>s(n+1);
    vector<vector<ll>>g(n+1);
    for(int i=1;i<=n;i++) cin >> s[i];

    
    f1.resize(n+1),f2.resize(n+1);
    for(int i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0,s,g);
    for(int i=1;i<=n;i++) cout << f1[i] << " ";cout << endl;
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