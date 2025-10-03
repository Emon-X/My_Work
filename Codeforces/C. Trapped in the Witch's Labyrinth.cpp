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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i],s[i]="-"+s[i];

    // reverse adjacency list
    vector<vector<vector<pair<int,int>>>> jda(n+2, vector<vector<pair<int,int>>>(m+2));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='U') jda[i-1][j].push_back({i,j});
            if(s[i][j]=='D') jda[i+1][j].push_back({i,j});
            if(s[i][j]=='L') jda[i][j-1].push_back({i,j});
            if(s[i][j]=='R') jda[i][j+1].push_back({i,j});
        }
    }

    vector<vector<int>> vis(n+2, vector<int>(m+2,0));
    queue<pair<int,int>> q;

    // border কে source ধরলাম
    for(int j=0;j<=m+1;j++) vis[0][j]=1, q.push({0,j});
    for(int i=1;i<=n+1;i++) vis[i][0]=1, q.push({i,0});
    for(int j=1;j<=m+1;j++) vis[n+1][j]=1, q.push({n+1,j});
    for(int i=1;i<=n;i++) vis[i][m+1]=1, q.push({i,m+1});

    // BFS on reverse graph
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(auto [a,b]: jda[x][y]){
            if(vis[a+1][b+1]==0){ // adjust indexing
                vis[a+1][b+1]=1;
                q.push({a+1,b+1});
            }
        }
    }

    // এখন '?' চেক করতে হবে
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1][j-1]=='?' and vis[i-1][j] and vis[i+1][j] and vis[i][j-1] and vis[i][j+1]){
                vis[i][j]=1;
            }
        }
    }

    ll ans = n*m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]) ans--;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) domain_expension();
    return 0;
}
