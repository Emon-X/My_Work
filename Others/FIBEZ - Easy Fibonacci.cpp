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
#define mod 100000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll fib(ll x)
{
    ll mask = 1LL << (63 - __builtin_clzll(x));
    ll res = 0, a = 0, b = 1;

    for (; mask; mask >>= 1)
    {
        ll na = (a * ((2 * b) % mod - a + mod)) % mod;
        ll nb = ((a * a) % mod + (b * b) % mod) % mod;

        if (x & mask)
        {
            a = nb;
            b = (na + nb) % mod;
        }
        else
        {
            a = na;
            b = nb;
        }
    }
    return a;
}

void domain_expension()
{
    ll n;
    cin >> n;

    cout << fib(n) << endl;
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