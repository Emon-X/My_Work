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
#define N 1000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<ll> lpf(N+1, 0);
ll prefix[N+1][11];

void pre()
{
    for (int i = 2; i < N; i++)
    {
        if (!lpf[i])
        {
            for (int j = i; j < N; j += i)
            {
                if (!lpf[j])
                    lpf[j] = i;
            }
        }
    }
    prefix[1][0]++;
    for (ll i = 2; i < N; i++) {
        ll y = i;
        ll cnt = 0;
        while (y > 1) {
            ll p = lpf[y];
            cnt++;
            while (y % p == 0) y /= p;
        }
        prefix[i][cnt]++;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=10;j++) prefix[i][j]+=prefix[i-1][j];
    }
}

void domain_expension()
{
    ll a,b,k;
    cin >> a >> b >> k;

    cout << prefix[b][k]-prefix[a-1][k] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= 10; j++)
        prefix[i][j] = 0;
    }
    pre();
    int t;
    cin >> t;
    while (t--)
        domain_expension();
    return 0;
}