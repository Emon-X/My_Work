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
#define N 5000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll lpf[N+1];
ll cnt[N+1];

void pre()
{
    for(int i=2;i<=N;i++)
    {
        if(!lpf[i]){
            for(int j=i;j<=N;j+=i){
                if(!lpf[j]) lpf[j]=i;
            }
        }
    }
    for(int i=2;i<=N;i++){
        ll x = i;
        ll c = 0;
        while(x>1){
            ll d = lpf[x];
            x/=d;
            c++;
        }
        cnt[i] = c;
    }
    for(int i=1;i<=N;i++) cnt[i]+=cnt[i-1];
}

void domain_expension()
{
    ll a,b;
    cin >> a >> b;

    ll r = a, l = b + 1;
    ll ans = cnt[r] - cnt[l-1];
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--)
    domain_expension();
    return 0;
}