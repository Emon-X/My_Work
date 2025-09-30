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
ll cost[200][200];
vector<bool>vis(N,false);

ll sum1,last;

void dfs(ll node)
{
    vis[node] = true;
    last = node;
    for(auto child:g[node])
    {
        if(vis[child]) continue;

        sum1+=cost[node][child];
        dfs(child);
    }
}

void domain_expension()
{
    ll n;
    cin >> n;
    ll total = 0;
    for(int i=1;i<=n;i++)
    {
        ll u,v,c;
        cin >> u >> v >> c;
        g[u].pb(v);
        g[v].pb(u);
        cost[u][v] = 0;
        cost[v][u] = c;
        total+=c;
    }
    sum1=0;
    dfs(1);
    sum1+=cost[last][1];

    cout << min(sum1,total-sum1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}