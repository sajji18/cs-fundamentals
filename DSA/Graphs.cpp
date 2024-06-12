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
Graphs
These are Data Structure with consist of Nodes/Vertex connected to each other using edges
There are Broadly two Types of Graphs:
1. Undirected Graphs:
    In these All the edges are Bidirectional, means if one can go from u to v, then one can also go from v to u
2. Directed Graphs:
    In these, edges can be unidirectional or bidirectional, in the former case one can only go from u to v, but in latter u to v as well as v to u

=> Trees are a Subset Of Graphs, These are Acyclic Undirected Graphs

Cycle:
    It mainly refers to starting at one node, there exists a path which ends at this node
If a Cycle is present in an Undirected graph, it is called cyclic undirected Graph
Else it is called Acyclic Undirected Graph
If a Cycle is present in a Directed Graph, it is called cyclic directed graph
Else it is called Acyclic Directed Graph (DAG)

Path:
    Contains a lot of Nodes and Vertices and Each of them are Reachable

In Unidirected Graph:
    Degree of a Node/Vertex:
        It is the number of edges attached to that Node/Vertex
    Total Degree:
        It is the Sum of Degrees of all Vertices of the graph, It is equal to 2 * E (Number of Edges)
        This is because each edge is connected to 2 Nodes

In Directed Graph:
    InDegree of a Node/Vertex:
        It is the number of edges Coming in to that vertex
    OutDegree of a Node/Vertex
        It is the number of edges coming out of that vertex

Edge Weights:
    We can assign Weight/Values to edges, by default we assume edge weights to be 1
*/

/*
Graph Representation:
    UnDirected Graphs:
    There are two ways to store undirected graphs : Adjacency Matrix and Adjacency List
    Adjacency Matrix:
        In this way, we create a matrix adj[N + 1][N + 1], where N => Number of Nodes
        If there is an Edge between U and V, perform : adj[U][V] = 1 and adj[V][U] = 1
        If there is an Edge between U and V, and graph is weighted with Weight of this edge W, perform : adj[U][V] = W and adj[V][U] = W
    Adjacency List:
        In this way, we create an Array of List/Vector as vector <int> adj[N + 1], N => Number of Nodes
        If there is an Edge between U and V, perform : adj[U].push_back(V) and adj[V].push_back(U)
        If there is an Edge between U and V, and graph is weighted (Create vector <pair<int, int>> adj[N + 1]) with Weight of this edge W, perform : adj[U].push_back({V, W}) and adj[V].push_back({U, W})

    Directed Graphs:
    There are two ways to store directed graphs : Adjacency Matrix and Adjacency List
    Adjacency Matrix:
        In this way, we create a matrix adj[N + 1][N + 1], where N => Number of Nodes
        If there is an Edge from U To V, perform : adj[U][V] (Not Reverse unless Given Edge from V to U)
        If there is an Edge from U To V, and graph is weighted with Weight of this edge W, perform : adj[U][V] = W
    Adjacency List:
        In this way, we create an Array of List/Vector as vector <int> adj[N + 1], N => Number of Nodes
        If there is an Edge from U To V, perform : adj[U].push_back(V)
        If there is an Edge from U To V, and graph is weighted (Create vector <pair<int, int>> adj[N + 1]) with Weight of this edge W, perform : adj[U].push_back({V, W})
*/
void representation () {
    int n, m; // nodes, edges
    // Undirected Graph Using Adjacency Matrix
    int adj1[n + 1][n + 1];
    for (int i = 0; i < m; i++) {
        // Unweighted
        int u, v; cin >> u >> v;
        adj1[u][v] = 1;
        adj1[v][u] = 1;
        // Weighted
        int u, v, w; cin >> u >> v >> w;
        adj1[u][v] = w;
        adj1[v][u] = w;
    }

    // Undirected Graph Using Adjacency List
    vector <int> adj2[n + 1]; // unweighted
    vector <pair <int, int>> adj3[n + 1]; // weighted
    for (int i = 0; i < m; i++) {
        // Unweighted
        int u, v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(v);
        // Weighted
        int u, v, w; cin >> u >> v >> w;
        adj3[u].push_back({ v, w });
        adj3[v].push_back({ u, w });
    }

    /*
    For Directed We just create the edge which is given, not both
    Means if edge from u to v is given, only create from u to v and not from v to u
    */
}

/*
Components in a Graph:
=> It is possible that all the nodes of a graph do not exists in a COMPONENT, such that there always exist a path between the 2
=> In this case, the graph is basically broken into pieces called components
*/

/*
Breadth First Search in a Graph (BFS):
Logic:
    So Similar to Trees
    Only Change in trees we also do it from root, (if we do from somewhere else, we markParents and use visited array)
    Since there is no problem of parents in this Data Structure, we just use a visited array and move from one node to all its children
    TC => O(2 * E), SC => O(N) {Queue Data Structure}
*/
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector <int> bfs;
    int vis[V] = {0};
    queue <int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        auto front = q.front();
        bfs.push_back(front);
        q.pop();
        for (auto child : adj[front]) {
            if (vis[child]) continue;
            vis[child] = 1;
            q.push(child);
        }
    }
    return bfs;
}

/*
Depth First Search in a Graph (DFS):
Logic:
    Since we need to go to the depths, we use recursion
    Start at a node, from this node, go to its children one by one (Recursively on at a time)
    Maintain a visited array to keep track of visited nodes and avoid reducdant calls which can cause stack overflow
    TC => O(N) + O(2 * E) {For Every Node we call once, and then call for its degrees}, SC => O(N) + O(N) + O(N) {Visited array, adjacency list, recursion stack space}
*/
void dfs (int node, bool vis[], vector <int> adj[], vector <int> &res) {
    if (vis[node]) return;
    vis[node] = true;
    res.push_back(node);
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, vis, adj, res);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    bool vis[V] = {0};
    vector <int> res;
    dfs(0, vis, adj, res);
    return res;
}

/*
Number of Provinces/Connected Components in a Graph
Logic:
    Iterate from 1 to N, And call dfs for each node which is not visited (Maintain a Visted Array)
    The number of times dfs call occur from this 1 - N Nodes (In Loop) = Number of Provinces or Connected Component
    Why ? Because say if 1, 2, 3 are in one component, when we call dfs(1), all 1, 2, 3 are visited. So no dfs calls for 2 and 3
    TC => O(N) + O(V + 2 * E), SC => O(N) {Recursive Stack Space}
*/
void dfs1 (int node, vector <int> adj[], vector <bool> &vis) {
    if (vis[node]) return;
    vis[node] = 1;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs1(child, adj, vis);
        }
    }
}
int connectedComponents(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector <int> adj[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j and isConnected[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto child : adj[i]) cout << child << " ";
        cout << endl;
    }
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs1(i, adj, vis);
        }
    }
    return count;
}

/*
Rotten Oranges
A Rotten Orange in a grid Rottens all fresh oranges adjacent to it in every 1 second, which in turn rotten their neighbours. Find Minimum time for all to be rotten.
Logic:
    Since we need the Minimum time, we use BFS Traversal, i.e, All rotten oranges rot fresh oranges simultaneously in their breadth
    TC => O(N * M), SC => O(N * M) {Queue + Visited Array}
*/
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid.front().size();
    queue <pair <pair<int, int>, int>> q;
    vector <vector <int>> vis(n, vector <int> (m, 0));
    int freshCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({ {i, j}, 0 });
                vis[i][j] = 1;
            }
            if (grid[i][j] == 1) freshCount++;
        }
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int res = 0, count = 0;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        res = max(res, t);
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xcor = x + dx[i];
            int ycor = y + dy[i];
            if (xcor < n && xcor >= 0 && ycor < m && ycor >= 0 && grid[xcor][ycor] == 1 and !vis[xcor][ycor]) {
                q.push({ {xcor, ycor}, t + 1 });
                vis[xcor][ycor] = 1;
                count++;
            }
        }
    }
    if (count != freshCount) return -1;
    else return res;
}

/*
Flood Fill:
Given A Cell in a grid and a color.
Starting from this cell, all its adjacent members who have the same color (original color) as this cell will acquire the given color (Including the parent cell as well) 
And So On this continues
Logic:
    BFS Solution:
    We Start A BFS Traversal from the given cell, moving in all 4 directions at a time
    We Maintain the original color of this cell, to check which adjacent cells can be colored
    This is done with the help of a Queue and done till the queue is not empty
    TC => O(N * M), SC => O(N * M)
    DFS Solution:
    Since It is not given in the problem to do this process in minimum time or anything like that
    We can use a DFS Solution as well
    TC => O(N * M), SC => O(N * M)
*/
// BFS
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size(), m = image.front().size();
    queue <pair <pair <int, int>, int>> q;
    vector <vector <int>> vis(n, vector <int> (m, 0));
    q.push({ {sr, sc}, image[sr][sc] });
    image[sr][sc] = color;
    vis[sr][sc] = 1;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int clr = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xrow = x + dx[i];
            int ycol = y + dy[i];
            if (xrow >= 0 && xrow < n && ycol >= 0 and ycol < m && (image[xrow][ycol] == clr) && !vis[xrow][ycol]) {
                q.push({ { xrow, ycol }, image[xrow][ycol] });
                image[xrow][ycol] = color;
                vis[xrow][ycol] = 1;
            }
        }
    }
    return image;
}

// DFS
void dfsFloodFill (int row, int col, vector <vector <int>> &ans, vector <vector <int>> &image, int newColor, int delRow[], int delCol[], int iniColor) {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image.front().size();
    for (int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfsFloodFill(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

/*
Detection of Cycle in an Undirected Graph
Logic:
    
*/

ll M = 1e9 + 7;
ll n, m, k, x, y, z, p, q;

void solve() {
    cin >> n;
    vll a(n);
    input(a, n);
}

signed main() {
    sajji;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}