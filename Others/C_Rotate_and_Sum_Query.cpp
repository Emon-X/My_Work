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

struct BIT {
    vector<ll> bit;
    ll n;
    BIT(int n) : n(n), bit(n+1, 0) {}


    void update(int i, ll val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }
    ll query(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
    ll range_sum(int l, int r) {
        return query(r) - query(l-1);
    }
};

void domain_expension()
{
    ll n,q;
    cin >> n >> q;
    deque<ll>s(n);
    BIT prefix(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        prefix.update(i,s[i]);
    }
    ll shift = 0;
    ll ind = 1;
    while(q--)
    {
        ll type;
        cin >> type;
        if(type==2){
            ll l,r;
            cin >> l >> r;
            ll left = (l+shift-1)%n + 1;
            ll right = (r+shift-1)%n + 1;
            if(left<=right){
                cout << prefix.range_sum(left,right) << endl;
            }
            else{
                cout << prefix.range_sum(left,n) + prefix.range_sum(1,right) << endl;
            }
        }
        else{
            ll c;
            cin >> c;
            shift = (shift + c)%n;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}