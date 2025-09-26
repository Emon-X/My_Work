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

ll totient[N + 1];

void pre()
{
    for (int i = 0; i <= N; i++)
        totient[i] = i;

    for (int i = 2; i <= N; i++)
    {
        if (totient[i] == i)
        {
            for (int j = i; j <= N; j += i)
            {
                totient[j] -= totient[j] / i;
            }
        }
    }
    for(int i=1;i<=N;i++) totient[i]+=totient[i-1];
}

void domain_expension()
{
    ll n;
    cin >> n;

    ll total = n * (n + 1) / 2;

    cout << total - totient[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        domain_expension();
    }
    return 0;
}