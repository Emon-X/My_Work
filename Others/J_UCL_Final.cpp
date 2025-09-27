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
bool good(vector<ll>& a, ll k, ll mx) {
    
    ll sum = 0, players = 1; 
    for (ll x : a) {
        if (x > mx) return false;
        if (sum + x <= mx) {
            sum += x;
        } else {
            players++;
            sum = x;
        }
    }
    return players <= k;
}
void domain_expension()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k > n) {
        cout << -1 << "\n";
        return;
    }

    ll low = *max_element(all(a));
    ll high = accumulate(all(a), 0LL);
    ll ans = high;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (good(a, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}