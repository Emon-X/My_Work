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
    map<ll,ll>mp;
    vector<ll>s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
        mp[s[i]]++;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        ll len = 0;
        for(auto [u,f]:mp){
            if(f >= i){
                len+=i;
            }
        }
        ans = max(ans,len);
    }
    cout << ans << endl;
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