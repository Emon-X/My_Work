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


void solve(ll x)
{
    map<ll,ll>mp;
    while(x%2==0){
        mp[2]++;
        x/=2;
    }
    for(int i=3;i*i<=x;i+=2){
        while(x%i==0){
            mp[i]++;
            x/=i;
        }
    }
    if(x>1) mp[x]++;

    for(auto [n,f]:mp) cout << n << "^" << f << " ";
    cout << endl;
}

void domain_expension()
{
    ll n;
    while(cin >> n)
    {
        if(n==0) break;
        solve(n);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    domain_expension();
    return 0;
}