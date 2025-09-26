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

void domain_expension()
{
    ll n;
    cin >> n;
    vector<ll>r;
    ll product = 1;
    for(ll i=1;i<n;i++){
        ll g = gcd(n,i);
        if(g==1){
            r.pb(i);
            product *=i;
            product%=n;
        }
    }
    vector<ll>res;
    if(product!=1){
        for(auto u:r) if(product!=u) res.pb(u);
    }
    else{
        for(auto u:r) res.pb(u);
    }

    cout << res.size() <<endl;
    for(auto u:res) cout << u << " ";cout <<endl;
    
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    domain_expension();
    return 0;
}