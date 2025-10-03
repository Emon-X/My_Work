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
void dfs(ll i,ll j,ll &sz,vector<vector<bool>>&vis,const vector<string>&s){
    vis[i][j] = true;
    sz = sz + 1;
    for(int k=0;k<4;k++){
        ll nx = i + dx[k], ny = j + dy[k];
        if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && s[nx][ny]=='#'){
            dfs(nx,ny,sz,vis,s);
        }
    }
}

void domain_expension()
{
    cin >> n >> m;
    vector<string>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    vector<vector<bool>>vis(n,vector<bool>(m,false));
    ll sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && s[i][j]=='#'){
                ll sz = 0;
                dfs(i,j,sz,vis,s);
                sum+=(sz*sz);
            }
        }
    }
    if(sum==0){
        cout << 0 << endl;
        return;
    }
    ll d = 1LL*n*m;
    ll g = __gcd(sum,d);

    ll p = sum/g;
    ll q = d/g;
    if(q == 1) cout << p << endl;
    else cout << p << " / " << q << endl;
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