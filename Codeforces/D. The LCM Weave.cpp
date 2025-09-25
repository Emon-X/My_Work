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
#define N 1000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll lpf[N+1],Mobius[N+1];

void pre()
{
    for(int i=2;i<=N;i++)
    {
        if(!lpf[i]){
            for(int j=i;j<=N;j+=i){
                if(!lpf[j]) lpf[j] = i;
            }
        }
    }

    Mobius[1] = 1;
    for (int i = 2; i < N; i++) {
        if (lpf[i / lpf[i]] == lpf[i]) Mobius[i] = 0;
        else Mobius[i] = -Mobius[i / lpf[i]];
    }
}

void domain_expension()
{
    ll n;
    cin >> n;
    vector<ll>mp(N+1,0);
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    for(int i=1;i<=N;i++)
    {
        if(Mobius[i]==0) continue;

        ll d = 0;
        for(int j=i;j<=N;j+=i) d+=mp[j];

        ll total_pair = (d*(d-1))/2;

        ans+=(total_pair*Mobius[i]);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    domain_expension();
    return 0;
}