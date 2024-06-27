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

/*
Disjoint Set (DSU):
Used in dynamic graphs (graphs which are constantly changing and we need to answer queries in log(N) or O(1) time)
It consists of 2 functions:
    1. findParent(): Find the parent/ultimate parent of the concerned node (The topmost guy in the ancestor chain)
    2. union(): Creates Link Between two nodes

Union can be created in 2 ways:
    1. By Rank: Rank is Similar to height of the tree (Only difference is it does not change in Path Compression - A method to Make DSU Operations in constant time)
    2. By Size:

Union By Rank (Pseudo Code):
=> Union (u, v)
=> Find Ultimate parent of u and v (Say pu and pv)
=> Find rank of pu and pv
=> Connect Smaller Rank to Larger Rank Always. If rank same, connect anyone to anyone and increase the rank of the parent

Time Complexity of DSU => O(4 * alpha), alpha ~= 1

Union By Size ()
*/
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
        if (node == parent[node]) // If No Parent is There, return the Node itself
            return node;
        // Storing Ultimate Parents along the way, this is Path Compression
        return parent[node] = findUParent(parent[node]); // If Parent is There, call recursively to find the topmost guy
    }   

    void unionByRank (int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return; // Already in the same component
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

    // Check if Size of ulp_u > ulp_v or vice versa and compute accordingly
    void unionBySize (int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return; // Already in the same component
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

/*
Kruskal's Algorithm of MST:
Logic:
    Create a vector of pair<int, pair<int, int>> storing {weight, {node1, node2}}
    Sort the vector based on weight
    Iterate through this vector, if node1 and node2 belong to same component ignore
    else add this edge weight and perform union(node1, node2)
*/
int spanningTree (int V, vector <vector <int>> adj[]) {
    vector <pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            int node = i;
            int adjNode = it[0];
            int edgeWeight = it[2];
            edges.push_back({edgeWeight, {node, adjNode}});
        }
    }
    DisjointSet ds(V);
    int mstWeight = 0;
    sort(all(edges));
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUParent(u) != ds.findUParent(v)) {
            mstWeight += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWeight;
}

/*
Number of Operations to make network connected:
Given a network of computers, connected via edges (Given in connections list)
Find the number of times, we have to remove any edge and insert a new one to convert the network into 1 connected component
Logic:
    Explained in Comments
*/
int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int f = 0, r = 0;
    // Check Number of Redundant Edges (Which are not really contributing to make the network connected) as f
    for (auto it : connections) {
        int u = it[0];
        int v = it[1];
        if (ds.findUParent(u) != ds.findUParent(v)) {
            ds.unionBySize(u, v);
        }
        else {
            f++;
        }
    }
    // Check Number of Required Edges (Edges which we need to insert) as r
    for (int i = 1; i < n; i++) {
        if (ds.findUParent(0) != ds.findUParent(i)) {
            r++;
            ds.unionBySize(0, i);
        }
    }
    // If Redundant >= Required, ans is possible, otherwise NO WAY (-1)
    return (f >= r) ? r : -1;
}

/*
Most Stones Removed with Same Row or Column:
Given a 2d grid, with n stones placed somewhere in it
Find the maximum number of stones that can be removed (Stone can be removed if it shares a row or a col with another stone)
Logic:
    If we observe, we can basically break the configurations of stones into some connected components (Each Stone in a component is connected to atleast 1 another stone in that component)
    No In every connected component, we can remove component_size - 1 stones
    Therefore if x1, x2, ..., xn components are there
    Answer = (x1 - 1) + (x2 - 1) + ... + (xn - 1)
    Answer = (x1 + x2 + ... xn) - (1 + 1 + 1 ... + 1)
    Answer = n - number_of_components
*/
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int u1 = stones[i][0];
            int v1 = stones[i][1];
            int u2 = stones[j][0];
            int v2 = stones[j][1];  
            if (u1 == u2 or v1 == v2) {
                if (ds.findUParent(i) != ds.findUParent(j)) {
                    ds.unionBySize(i, j);
                }
            }                  
        }
    }
    int rem = 0;
    for (int i = 0; i < n; i++) {
        rem += (ds.findUParent(i) == i);
    }
    return n - rem;
}

/*
Accounts Merge:
Given A List Accounts. Each elements consists of the accounts name, followed by list of emails of this account
Two Accounts are said to belong to the same person, if they have atleast 1 email in common and the same name
Find the final accounts list, after merging all such accounts
Logic:
    Whenever it is about merging, belonging to the same component. DISJOINT SET
    Create a Map = {email, account_it_was_found_in}
    Iterate through all the emails, if this email is not yet found, mark it found in the current account
    Else take union of current account and the account this email was found in
    Finally use this graph to return the required answer
*/
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet ds(n);
    map <int, set <string>> mp;
    map <string, int> acc;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (acc.find(accounts[i][j]) != acc.end()) {
                int parent = ds.findUParent(acc[accounts[i][j]]);
                ds.unionBySize(parent, i);
            }
            else acc[accounts[i][j]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int parentAccount = ds.findUParent(i);
        for (int j = 1; j < accounts[i].size(); j++) {
            mp[parentAccount].insert(accounts[i][j]);
        }
    }
    vector <vector <string>> ans;
    for (auto it : mp) {
        ans.push_back({accounts[it.first][0]});
        for (auto emails : it.second) {
            ans.back().push_back(emails);
        }
    }
    return ans;
}

/*
Number of Islands - II:
Given a grid of n * m size, intially filled with all 0s.
An array is giving containing points (x, y)
For Each Online query, insert a 1 at point (x, y) and return number of islands of 1
Logic:
    Disjoint Set, Since the graph is changing (Dynamic)
    Basically Whenever a new unvisited point is given, increase number of islands by 1
    Now Check its adjacents, and reduce number of islands by the number of (unique, using SET) ultimate parents
*/
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector <vector<int>> grid(n, vector <int> (m, 0));
    vector <int> islands;
    vector <vector <int>> vis(n, vector <int> (m, 0));
    DisjointSet ds(n * m);
    int ct = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for (auto it : operators) {
        int row = it[0];
        int col = it[1];
        if (vis[row][col]) {
            islands.push_back(ct);
            continue;
        }
        ct++;
        grid[row][col] = 1;
        vis[row][col] = 1;
        int currentCell = row * m + col;
        set <int> st;
        for (int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1) {
                st.insert(ds.findUParent(newr * m + newc));
            }
        }
        for (auto it : st) {
            ct--;
            ds.unionBySize(currentCell, it);
        }
        islands.push_back(ct);
    }
    return islands;
}

/*
Making a Large Island
Given a grid of 0s and 1s. You can convert at Max one 0 to a 1.
Return the size of maximum island of 1s thus formed.
An Island is 4 directional collection of same objects.
Logic:
    Assign Numbers to all Cell. First row will be 0, 1, 2, ... n - 1. Second Row n, n + 1, ... and so on.
    First Create the graph / DSU with the initial configuration. How ? Basically iterate over each cell, if it is 1, combine it with adjacent 1s
    Now After initial configuration, again iterate over grid and whenever a 0 is found : ans = max(ans, 1 + size of unique adjacent 1 islands) 
*/
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    // Initial Configuration
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (!grid[row][col]) continue;
            int currentCell = row * n + col;
            for (int k = 0; k < 4; k++) {
                int newr = row + dr[k];
                int newc = col + dc[k];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc]) {
                    ds.unionBySize(currentCell, newr * n + newc);
                }
            }
        }
    }
    int ans = 0;
    // Converting Each Zero to One and Checking maximum answer
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col]) continue;
            int currentCell = row * n + col;
            int current = 0;
            set <int> st;
            for (int k = 0; k < 4; k++) {
                int newr = row + dr[k];
                int newc = col + dc[k];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc]) {
                    st.insert(ds.findUParent(newr * n + newc));
                }
            }
            for (auto it : st) {
                current += ds.size[it];
            }
            current++;
            ans = max(ans, current);
        }
    }
    // Edge Case for all 1s
    return !ans ? n * n : ans;
}

ll M = 1e9 + 7;
ll n, m, k, x, y, z, p, q;

void solve() {
    cin >> n;
}

signed main() {
    sajji;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}