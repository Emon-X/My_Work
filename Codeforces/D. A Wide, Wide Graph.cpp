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

void dfs(ll node,ll par,ll depth,const vector<vector<ll>>&g,vector<ll>&d1)
{
    d1[node] = depth;
    for(auto c:g[node]){
        if(c!=par) dfs(c,node,depth+1,g,d1);
    }
}

void domain_expension()
{
    ll n;
    cin >> n;
    vector<vector<ll>>g(n+1);
    for(int i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<ll>d1(n+1,0),d2(n+1,0);
    dfs(1,-1,0,g,d1);
    ll a = max_element(all(d1))-d1.begin();
    dfs(a,-1,0,g,d1);
    ll b = max_element(all(d1))-d1.begin();
    dfs(b,-1,0,g,d2);

    for(int i=1;i<=n;i++) d2[i] = max(d2[i],d1[i]);

    sort(all(d2));

    ll ans = 0;
    for(int k=1;k<=n;k++){
        while(ans<n && d2[ans]<k) ans++;

        cout << ans << " ";
    }
    cout << endl;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}