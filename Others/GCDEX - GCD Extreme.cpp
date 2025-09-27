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
ll phi[N+1],F[N+1];

void pre()
{
    //phi funtion
    for(int i=0;i<=N;i++) phi[i] = i;
    for(int i=2;i<=N;i++){
        if(phi[i]==i){
            for(int j=i;j<=N;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
    //contribution
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i){
            F[j] += 1LL*i*phi[j/i];
        }
    }
    for(int i=2;i<=N;i++) F[i]+=F[i-1];
}

void domain_expension()
{
    ll n;
    cin >> n;
    cout << F[n] - (n*(n+1)/2)<< endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    domain_expension();
    return 0;
}