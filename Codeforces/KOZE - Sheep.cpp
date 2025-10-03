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

ll n,m;
void dfs(ll i,ll j,ll &sheep,ll &wolves,vector<vector<bool>>&vis,const vector<string>&s){
    vis[i][j] = true;
    if(s[i][j]=='k') sheep++;
    else if(s[i][j]=='v') wolves++;

    for(int k=0;k<4;k++){
        ll nx = i + dx[k], ny = j + dy[k];
        if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && s[nx][ny]!='#'){
            dfs(nx,ny,sheep,wolves,vis,s);
        }
    }
}

void domain_expension()
{
    cin >> n >> m;
    vector<string>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    vector<vector<bool>>vis(n,vector<bool>(m,false));
    ll c1 = 0, c2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(s[i][j]=='#' or vis[i][j]) continue;

            ll sheep=0,wolves =0;
            dfs(i,j,sheep,wolves,vis,s);
            
            if(sheep>wolves) c1+=sheep;
            else c2+=wolves;
            
        }
    }
    cout << c1 << " " << c2 << endl;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    domain_expension();
    return 0;
}