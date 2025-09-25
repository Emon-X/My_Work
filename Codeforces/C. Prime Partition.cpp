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
#define N 1000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 modmul(u64 a, u64 b, u64 m) {
    return (u128)a * b % m;
}
u64 modpow(u64 a, u64 d, u64 m) {
    u64 r = 1;
    while (d) {
        if (d & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        d >>= 1;
    }
    return r;
}
bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n-1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }
    for (u64 a : {2,325,9375,28178,450775,9780504,1795265022}) {
        if (a % n == 0) continue;
        u64 x = modpow(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool comp = true;
        for (u64 r=1; r<s; r++) {
            x = modmul(x, x, n);
            if (x == n-1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}


void domain_expension() {
    ll n; cin >> n;

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }

    __int128 sum = (__int128)n * (n + 1) / 2;
    if (sum % 2 == 0) {
        cout << 2 << endl;
        return;
    }

    ll ans = -1;
    for (long long i = (long long)sum - 1; i >= (long long)sum - 2000; i--) {
        if (isPrime(i)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    domain_expension();
    return 0;
}