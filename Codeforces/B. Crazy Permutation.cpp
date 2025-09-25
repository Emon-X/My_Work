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

    if (n % 4 == 3)
    {
        cout << -1 << endl;
        return;
    }
    set<ll> st;
    for (int i = 2; i <= n; i++)
    {
        st.insert(i);
    }
    vector<ll> r;
    r.pb(1);
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll xr = 1;
    while (st.size() > 0)
    {
        ll val = *st.begin();
        st.erase(st.begin());

        if ((val^ xr) != 0)
        {
            r.pb(val);
            xr ^=val;
        }
        else
        {

            if (st.size() == 0)
            {
                cout << -1 << endl;
                return;
            }
            auto it1 = st.begin();
            if ((*it1 ^ xr) != 0)
            {
                xr = xr ^*it1;
                r.pb(*it1);
                st.erase(it1);
                st.insert(val);
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto u : r)
        cout << u << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}