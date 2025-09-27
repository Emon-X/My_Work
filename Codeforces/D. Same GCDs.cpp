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

vector<ll> prime_count(N + 1, 0),primes;

void precompute() {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * 2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
        prime_count[i] = prime_count[i - 1] + is_prime[i];
    }
};

ll phi(ll n)
{
    if(n==1) return 1;
    ll ans = n;

    for(ll p:primes)
    {
        if(p*p>n) break;

        if(n%p==0){
            while(n%p==0) n/=p;
            ans -= ans/p;
        }
    }
    if(n>1) ans -=ans/n;

    return ans;

}

void domain_expension()
{
    ll a,m;
    cin >> a >> m;
    ll g = gcd(a,m);
    ll m1 = m/g;

    cout << phi(m1) << endl;
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