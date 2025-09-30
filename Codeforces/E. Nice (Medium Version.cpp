#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<ll> v;

ll getInt(const string& s) {
    ll x = 0;
    for (char c : s) {
        x = x * 10 + (c - '0');
    }
    return x;
}

void dfs(string &s) {
    if (!s.empty()) {
        v.pb(getInt(s));
    }
    if (s.size() == 18) return;

    s.pb('6');
    dfs(s);
    s.pop_back();

    s.pb('9');
    dfs(s);
    s.pop_back();
}

void pre() {
    string s = "";
    dfs(s);
    sort(all(v));
}

void domain_expansion() {
    ll l, r;
    cin >> l >> r;
    ll ans = upper_bound(all(v), r) - lower_bound(all(v), l);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    int t;
    cin >> t;
    while (t--) domain_expansion();
    return 0;
}
