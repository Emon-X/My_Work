#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
char dir[] = {'D','U','R','L'};

bool dfs(ll i, ll j, const vector<string>& s, vector<vector<int>>& state, vector<pair<ll,ll>>& path, vector<vector<bool>>& inCycle) {
    if (state[i][j] == 1) {
        // Found a cycle, mark all nodes in current path as in cycle
        for (auto [x, y] : path) inCycle[x][y] = true;
        inCycle[i][j] = true;
        return true;
    }
    if (state[i][j] == 2) return false;

    state[i][j] = 1;
    path.push_back({i, j});
    bool foundCycle = false;
    if (s[i][j] == '?') {
        for (int d = 0; d < 4; d++) {
            ll ni = i + dx[d];
            ll nj = j + dy[d];
            if (ni < 0 || ni >= s.size() || nj < 0 || nj >= s[0].size()) continue;
            if (dfs(ni, nj, s, state, path, inCycle)) foundCycle = true;
        }
    } else {
        int d;
        if (s[i][j] == 'D') d = 0;
        else if (s[i][j] == 'U') d = 1;
        else if (s[i][j] == 'R') d = 2;
        else d = 3;
        ll ni = i + dx[d];
        ll nj = j + dy[d];
        if (ni >= 0 && ni < s.size() && nj >= 0 && nj < s[0].size()) {
            if (dfs(ni, nj, s, state, path, inCycle)) foundCycle = true;
        }
    }
    path.pop_back();
    state[i][j] = 2;
    return foundCycle;
}

void domain_expension() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> state(n, vector<int>(m, 0));
    vector<vector<bool>> inCycle(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (state[i][j] == 0) {
                vector<pair<ll,ll>> path;
                dfs(i, j, s, state, path, inCycle);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (inCycle[i][j]) ans++;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        domain_expension();
    return 0;
}