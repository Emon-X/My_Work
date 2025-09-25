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

vector<ll> prime_count(N + 1, 0);
vector<ll> primes;

void precompute() {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
        prime_count[i] = prime_count[i - 1] + is_prime[i];
    }
    for(int i=2;i<=N;i++) if(is_prime[i]) primes.pb(i);
};

ll search(ll x)
{
    ll l = 0,r = primes.size()-1;
    ll ans = -1;
    while(l<=r)
    {
        ll m = l + (r-l)/2;
        if((primes[m]*primes[m])<=x){
            ans = m;
            l = m+1;
        } 
        else r = m - 1;
    }
    return ans+1;
}

void domain_expension()
{
    ll n, K;
    cin >> n >> K;
    ll total = search(n);
    ll liked = total - search(K);
    cout << total << ' ' << max(0LL,liked) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precompute();
    int t;
    cin >> t;
    while(t--)
    domain_expension();
    return 0;
}