#include <bits/stdc++.h>
using namespace std;

# define ll long long
# define FOR(i, a, b) for (int i = a; i < b; i++)
# define RFOR(i, a, b) for (int i = a; i >= b; i--)
# define all(x) (x).begin(), (x).end()
# define vi vector <int>
# define vll vector <long long>
# define vpi vector<pair<int,int>>
# define vpll vector <pair<long long, long long>>
# define mapi map<int,int>
# define mapll map<ll,ll>
# define endl "\n"
# define yes cout<<"YES\n"
# define no cout<<"NO\n"
# define sajji ios_base::sync_with_stdio(false); cin.tie(nullptr);
# define input(a, n) FOR(i, 0, n) cin >> a[i];

// Hashing Utilities

const int hashp1 = 31;
const int hashp2 = 53;
const int hashM = 1e9 + 9;
const int N = 1e5;
ll power[N];

void computePrefixHash (string &str, ll n, ll prefixHash[], ll power[]) {
    prefixHash[0] = 0;
    prefixHash[1] = str[0];
    for (int i = 2; i <= n; i++) {
        prefixHash[i] = (prefixHash[i - 1] % hashM + (str[i - 1] % hashM * 1LL * power[i - 1] % hashM) % hashM) % hashM;
    }
    return;
}

void computeSuffixHash (string &str, ll n, ll suffixHash[], ll power[]) {
    suffixHash[0] = 0;
    suffixHash[1] = str[n - 1];
    for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++) {
        suffixHash[j] = (suffixHash[j - 1] % hashM + (str[i] % hashM * 1LL * power[j - 1] % hashM) % hashM) % hashM;
    }
    return;
}

int computeHash (ll n, ll prefixHash[], ll power[], ll start, ll end) {
    ll val = (prefixHash[end] - prefixHash[start - 1] + hashM) % hashM;
    val = (val * 1LL * (power[n - start])) % hashM;
    return val;
}

int computeRevHash (ll n, ll suffixHash[], ll power[], ll end, ll start) {
    start = n + 1 - start;
    end = n + 1 - end;
    ll val = (suffixHash[end] - suffixHash[start - 1] + hashM) % hashM;
    val = (val * 1ll * power[n - start]) % hashM;
    return val;
}

// Disjoint Set Utilities

class DisjointSet {
public:
    vector <int> rank, parent, size;
    DisjointSet (int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent (int node) {
        if (node == parent[node]) 
            return node;
        return parent[node] = findUParent(parent[node]);
    }   

    void unionByRank (int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return; 
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize (int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Binary Exponentiation

int binpow (int a, int b, int M) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

void dfs(int row, int col, vector <vector <int>> &v, vector <vector <int>> &vis, ll &curr) {
    vis[row][col] = 1;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int adj = 0;
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr <= 3 && nr >= 0 && nc <= 2 && nc >= 0 && !vis[nr][nc]) {
            if (nr == 3) {
                if (nc == 1 || nc == 2) {
                    continue;
                }
                else {
                    adj++;
                }
            }
            else {
                adj++;
            }
            dfs(nr, nc, v, vis, curr);
        }
    }
    cout << curr << " " << adj << "\n";
    if (adj) curr = (curr * adj) % (int)(1e9 + 7);
}

int main () {
    // Precomputation of Powers for Max Possible String Size to be done Before Handling Test Cases
    power[0] = 1;
    for (int i = 1; i <= 1500; i++) {
        power[i] = power[i - 1] * hashp1 % hashM;
    }
    int MOD = 1e9 + 7;
    vector <vector <int>> v;
    v.push_back({ 9, 8, 7 });
    v.push_back({ 6, 5, 4 });
    v.push_back({ 3, 2, 1 });
    v.push_back({ 0 });
    ll x = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 3 && j == 1) continue;
            if (i == 3 && j == 2) continue;
            ll curr = 1;
            vector <vector <int>> vis(4, vector <int> (3, 0));
            dfs(i, j, v, vis, curr);
            x = (x + curr) % MOD;
        }
    }
    cout << x << "\n";
}