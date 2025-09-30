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

bool perfectSquare(__int128 x)
{
    __int128 y = sqrtl(x);
    
    return (__int128)(y*y)==x;
}
void domain_expension()
{
    ll n;
    cin >> n;

    __int128 x1 = (__int128)5*n*n - 4;
    __int128 x2 = (__int128)5*n*n + 4;

    if(perfectSquare(x1) or perfectSquare(x2)) cout << "IsFibo\n";
    else cout << "IsNotFibo\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    domain_expension();
    return 0;
}