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

vector<ll> ft(N), inv_ft(N);

ll bin(ll base, ll p)
{
    ll res = 1;
    while (p > 0)
    {
        if (p % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return res;
}

void domain_expension()
{
    ll n;
    cin >> n;

    ll total = bin(2, n);
    ll prob = (total - 2 + mod) % mod; 
    
    ll inv = bin(total, mod - 2); 
    cout << (prob * inv) % mod << endl;
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