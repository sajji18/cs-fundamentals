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
int power[100001];

void computePrefixHash (string &str, int n, int prefixHash[], int power[]) {
    prefixHash[0] = 0;
    prefixHash[1] = str[0];
    for (int i = 2; i <= n; i++) {
        prefixHash[i] = (prefixHash[i - 1] % hashM + (str[i - 1] % hashM * power[i - 1] % hashM) % hashM) % hashM;
    }
    return;
}

void computeSuffixHash (string &str, int n, int suffixHash[], int power[]) {
    suffixHash[0] = 0;
    suffixHash[1] = str[n - 1];
    for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++) {
        suffixHash[j] = (suffixHash[j - 1] % hashM + (str[i] % hashM * power[j - 1] % hashM) % hashM) % hashM;
    }
    return;
}

int computeHash (int n, int prefixHash[], int power[], int start, int end) {
    ll val = (prefixHash[end] - prefixHash[start - 1] + hashM) % hashM;
    val = (val * (power[n - start])) % hashM;
    return val;
}

int computeRevHash (int n, int suffixHash[], int power[], int end, int start) {
    start = n + 1 - start;
    end = n + 1 - end;
    ll val = (suffixHash[end] - suffixHash[start - 1] + hashM) % hashM;
    val = (val * power[n - start]) % hashM;
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

int main () {
    // Precomputation of Powers for Max Possible String Size to be done Before Handling Test Cases
    power[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        power[i] = power[i - 1] * hashp1 % hashM;
    }
}