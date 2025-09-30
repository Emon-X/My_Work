#include <bits/stdc++.h>
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
    map<ll, ll> mp;
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];

        mp[s[i]] = i;
    }
    if (is_sorted(all(s)))
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<ll, ll>> op;
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] == i)
            continue;

        if (gcd(s[i], i) == 1)
        {

            ll ind = mp[i];
            ll val = s[i];
            swap(s[ind], s[i]);
            op.pb({i, ind});
            mp[ind] = i;
            mp[val] = ind;
        }
    }
    if (is_sorted(all(s)))
    {
        cout << op.size() << endl;
        for (auto [u, f] : op)
            cout << u << " " << f << endl;
        return;
    }
    mp.clear();
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != i)
        {
            mp[s[i]] = i;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] == i)
            continue;

        if (gcd(s[i], i) == 1)
        {

            ll ind = mp[i];
            ll val = s[i];
            swap(s[ind], s[i]);
            op.pb({i, ind});
            mp[ind] = i;
            mp[val] = ind;
        }
    }
   // for(int i=1;i<=n;i++) cout << s[i] << " ";cout << endl;
    mp.clear();
    for (int i = 1; i <= n; i++)
    {
       mp[s[i]] = i;
    }
    for(int i=1;i<=n;i++){
        if(s[i]==i) continue;

      
            ll ind = mp[1];
            ll val = s[i];
            swap(s[ind],s[i]);
            op.pb({i,ind});
            mp[ind] = i;
            mp[val] = ind;

      

            ll ind1 = mp[i];
            ll val1 = s[i];
            swap(s[ind1],s[i]);
            op.pb({i,ind1});
            mp[ind1] = i;
            mp[val1] = ind1;
        
    }
    for(int i=1;i<=n;i++) cout << s[i] << " ";cout << endl;
    
   
    cout << op.size() << endl;
    for (auto [u, f] : op)
        cout << u << " " << f << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        domain_expension();
    return 0;
}