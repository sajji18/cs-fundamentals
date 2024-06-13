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
    Using BFS:
    From a Given Src, go to its adjacent Neighbours and So on. 
    Now if let's say I go from A to B and then B to C, And C is already visited because i first went from A to D and then D to C
    This means a cycle is present, because i started from A in different Paths and somehow the paths converge to C. Thus Cycle is there
    TC => O(N + 2 * E), SC => O(N)
    Using DFS:
    Start DFS from Say Node N, Continue Calling DFS for its adjacents and whenever we find a node visited and it is not the parent of the current node, we found a cycle
    Do some dry runs for better clarity
    TC => O(N + 2 * E), SC => O(N)
*/
// BFS
bool detect (int src, vector <int> adj[], int vis[]) {
    vis[src] = 1;
    queue <pair<int, int>> q;
    q.push({ src, -1 });
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;        
        q.pop();
        for (auto child : adj[node]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push({ child, node });
            }
            else if (parent != child) return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis)) return true;
        }
    }
    return false;
}
// DFS
bool dfsCycleDetector (int node, int parent, int vis[], vector <int> adj[]) {
    vis[node] = 1;
    for (auto adjacentNode : adj[node]) {
        if (!vis[adjacentNode]) {
            if (dfsCycleDetector(adjacentNode, node, vis, adj) == true) return true;
        }
        else if (adjacentNode != parent) return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCycleDetector(i, -1, vis, adj) == true) return true;
        }
    }
    return false;
}

/*
0/1 Matrix Problem:
Given A Matrix with 0s and 1s, return a new Matrix dist, where dist[i][j] is the manhattan distance of the closest one
Logic:
    Create a Queue Data Structure, Push into it all the {{x, y}, 0} (where x and y are the coordinates of 1)
    From All these 1s, Do A BFS Traversal One at a time, increasing the step by 1, consequently updating it when popping these out of the queue
    Maintain a Visited Matrix to keep track of visited coordinates
    TC => O(N * M), SC => O(N * M)
*/
vector <vector <int>> nearest (vector <vector <int>> grid) {
    int n = grid.size();
    int m = grid.front().size();
    vector <vector <int>> vis(n, vector <int> (m, 0));
    vector <vector <int>> dist(n, vector <int> (m, 0));
    queue <pair <pair <int, int>, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({ { i, j }, 0 });
                vis[i][j] = 1;
            }
            else vis[i][j] = 0;
        }
    }
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                q.push({ { nrow, ncol }, steps + 1 });
                vis[nrow][ncol] = 1;
            }
        }
    }
    return dist;
}

/*
Surround Regions:
Replace All Os with Xs if the region of Os is surrounded by Xs from all 4 Sides (Diagonal does not count)
Logic:
    We Observe That Only Those regions which contain Os at the boundary of the grid cannot be completely surrounded by Xs and therefore can not be replaced
    There from all the boundary Os, perform DFS Traversal and mark the Os in these regions visited
    Now All the Os still unvisited shall be replaced by Xs
    One can also solve using BFS Traversal (My personal favourite)
    TC => O(N * M), SC => O(N * M)
*/
void dfsMarkZero(int row, int col, vector<vector<char>>& board, vector <vector <int>> &vis, int dx[], int dy[]) {
    vis[row][col] = 1;
    int n = board.size();
    int m = board.front().size();
    for (int i = 0; i < 4; i++) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
            dfsMarkZero(nrow, ncol, board, vis, dx, dy);
        }
    }
}
void surroundRegion(vector<vector<char>>& board) {
    int n = board.size(), m = board.front().size();
    vector <vector <int>> vis(n, vector <int> (m, 0));
    int dx[] = {0, +1, 0, -1};
    int dy[] = {-1, 0, +1, 0};
    for (int col = 0; col < m; col++) {
        // First Row
        if (!vis[0][col] && board[0][col] == 'O') {
            dfsMarkZero(0, col, board, vis, dx, dy);
        }
        // Last Row
        if (!vis[n - 1][col] && board[n - 1][col] == 'O') {
            dfsMarkZero(n - 1, col, board, vis, dx, dy);
        }
    }
    for (int row = 0; row < n; row++) {
        // First Row
        if (!vis[row][0] && board[row][0] == 'O') {
            dfsMarkZero(row, 0, board, vis, dx, dy);
        }
        // Last Row
        if (!vis[row][m - 1] && board[row][m - 1] == 'O') {
            dfsMarkZero(row, m - 1, board, vis, dx, dy);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

/*
Number of Enclaves:
Given A Grid of 0s and 1s, find Number of 1s through which one cannot go to the boundary
Logic:
    Same as that of Above Ques, Perform BFS or DFS from the boundary 1s and mark all those visited
    Now Count of All the 1s left unvisited is the answer
    TC => O(N * M), SC => O(N * M) 
*/
void dfsMarkOne (int row, int col, vector <vector <int>> &vis, vector <vector <int>> &grid, int dx[], int dy[]) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid.front().size();
    for (int i = 0; i < 4; i++) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
            dfsMarkOne(nrow, ncol, vis, grid, dx, dy);
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid.front().size();
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};
    vector <vector <int>> vis(n, vector <int> (m, 0));
    for (int col = 0; col < m; col++) {
        if (!vis[0][col] && grid[0][col] == 1) {
            dfsMarkOne(0, col, vis, grid, dx, dy);
        }
        if (!vis[n - 1][col] && grid[n - 1][col] == 1) {
            dfsMarkOne(n - 1, col, vis, grid, dx, dy);
        }
    }
    for (int row = 0; row < n; row++) {
        if (!vis[row][0] && grid[row][0] == 1) {
            dfsMarkOne(row, 0, vis, grid, dx, dy);
        }
        if (!vis[row][m - 1] && grid[row][m - 1] == 1) {
            dfsMarkOne(row, m - 1, vis, grid, dx, dy);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) count++;
        }
    }
    return count;
}

/*
Word Ladder - 1 (Very Hard)
Given A Starting Word, Target Word and A Dictionary
Find the Shortest Path to Go from starting word to target word using only the words of the dictionary
Remember All Adjacent Words should differ by 1 Character at max
Logic:
    For A Given Starting Word, Try All Possible 1 Character Changes, if found in the dictionary, push into a Queue Data Structure along with the steps taken variable
    When the front of queue becomes equal to the {endword, steps}, return the steps
    If Not found, return 0 (Not Possible to Perform this conversion)
*/
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    queue <pair <string, int>> q;
    q.push({ startWord, 1 });
    unordered_set <string> s(wordList.begin(), wordList.end());
    s.erase(startWord);
    while (!q.empty()) {
        auto word = q.front().first;
        auto steps = q.front().second;
        q.pop();
        if (word == targetWord) return steps;
        for (int i = 0; i < word.length(); i++) {
            auto original = word[i];
            for (int ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (s.find(word) != s.end()) {
                    q.push({ word, steps + 1 });
                    s.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

/*
Word Ladder - 2 (Too Much)
An Extension of Word Ladder 1, Here We Do not need to Return The Min Length Sequence to convert startWord to endWord using wordList
But All such possible minimum length sequences :(
Logic:  
    We Again Maintain a Queue DS with the initial Word
    Now, BFS!!!! Check Level Wise, and maintain a vector list (Representing the sequence till now) for each level
    To get List for the next level, just take the last word of the current level list (Any list), and try out all possible 1 Character Variation Combinations over its length
    If any of these combinations possible (Present in a Set of Available Words), push_back in the list and push this list in queue. AND POP BACK AGAIN, Why ? So other combinations can also be created of this words
    More Clarity Can be Achieved using dry run and also checking the implementation below
    TC => O(N * N * M) {Not Really Possible to Compute, Just an Estimate}, SC => {Queue, Set, Vector}
*/
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // Set To store available words from wordList
    unordered_set <string> s(wordList.begin(), wordList.end());
    // Q for Usual BFS
    queue <vector <string>> q;
    q.push({ beginWord });
    // Keep Track of When to Delete Elements (Delete only when a Level is Completely traversed)
    int level = 0;
    vector <vector <string>> ans;
    vector <string> wordOnLevel;
    wordOnLevel.push_back(beginWord);
    while (!q.empty()) {
        auto list = q.front();
        q.pop();
        // Means We are on A Greater Level, So Previous Level Elements should not be used
        if (list.size() > level) {
            level++;
            for (auto word : wordOnLevel) {
                s.erase(word);
            }
            wordOnLevel.clear();
        }
        auto lastWord = list.back();
        // If Target Word Found, Push the Smallest Length Vector Sequence into the Answer
        if (lastWord == endWord) {
            if (ans.size() == 0) {
                ans.push_back(list);
            }
            else if (ans.front().size() == list.size()) {
                ans.push_back(list);
            }
        }
        // Try All Combinations and check if it is present in Available Wordsa
        for (int i = 0; i < lastWord.length(); i++) {
            auto original = lastWord[i];
            for (int ch = 'a'; ch <= 'z'; ch++) {
                lastWord[i] = ch;
                if (s.find(lastWord) != s.end()) {
                    // If word transformation possible, push in list, push the list in queue, and pop back from list for other combinations
                    list.push_back(lastWord);
                    q.push(list);
                    list.pop_back();
                    wordOnLevel.push_back(lastWord);
                }
            }
            lastWord[i] = original;
        }
    }
    return ans;
}

/*
Number of Islands:
Given A Matrix with 1s and 0s, we need to find number of islands/connected components of 1s
1s can be connected in all 8 directions
Logic:
    Very Simple Problem, Iterate Over the Matrix, Whenever an unvisited 1 is found, do bfs or dfs and increase count by 1
    TC => O(N * M), SC => O(N * M) {If BFS, then Queue Space. If DFS, Then Auxiliary Recursive Stack Space}
*/
void bfsIsland (int row, int col, vector <vector <int>> &vis, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid.front().size();
    queue <pair <int, int>> q;
    q.push({ row, col });
    while (!q.empty()) {
        auto x = q.front().first;
        auto y = q.front().second;
        q.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nrow = x + i;
                int ncol = y + j;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({ nrow, ncol });
                }
            }
        }
    }
}
void dfsIsland (int row, int col, vector <vector <int>> &vis, vector<vector<char>>& grid) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid.front().size();
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nrow = row + i;
            int ncol = col + j;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfsIsland(nrow, ncol, vis, grid);
            }
        }
    }
}
int numIslands (vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid.front().size();
    vector <vector <int>> vis(n, vector <int> (m, 0));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                count++;
                // bfsIsland(i, j, vis, grid);
                dfsIsland(i, j, vis, grid);
            }
        }
    }
    return count;
}

/*
Biphartite Graph:
Given 2 Colors and A Graph, The Graph is Bipartite if we can color it using these 2 colors in such a way that all adjacent vertices are of different color
=> Graph with cycles of Odd Length are NOT Bipartite
=> Graph with cycles of Even Length ARE Bipartite
=> Graphs with no cyces ARE Bipartite
Logic:
    For a Connected Component, start from a Source (DFS), give it a specific color and call DFS for its neighbours with a different color
    While traversing, if we come across a neighbour who is colored same as the node, return false
    TC => O(V + 2 * E), SC => O(V)
*/
bool dfsBipartite (int node, int clr, int color[], vector <int> adj[]) {
    color[node] = clr;
    for (auto &neighbour : adj[node]) {
        if (color[neighbour] == -1) {
            return dfsBipartite(neighbour, !clr, color, adj);
        }
        else if (color[neighbour] == clr) return false;
    }
    return true;
}
bool isBipartite (int V, vector <int> adj[]) {
    int color[V];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (dfsBipartite(i, 0, color, adj) == false) {
                return false;
            }
        }
    }
    return true;
}

/*
Check Cycle in a Directed Graph
Logic:
    Maintain 2 Arrays : Visited and PathVisited (If the node is already visited on the current path)
    If we Go from 1 Node to its neighbour and it is visited as well as PathVisited, return true (Cycle Present)
    TC => O(V + E), SC => O(N)
*/
bool dfsCyclic (int node, vector <int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto neighbour : adj[node]) {
        if (!vis[neighbour]) {
            if (dfsCyclic(neighbour, adj, vis, pathVis) == true) return true;
        }
        else if (pathVis[neighbour] == 1) return true;
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic (int V, vector <int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCyclic(i, adj, vis, pathVis) == true) return true;
        }
    }
    return false;
}

/*
Topological Sorting Using DFS:
This type of sorting only exist on DAG (Directed Acyclic Graphs)
This is a linear ordering such that if there is an edge from u to v, u appears before v (in the linear order)
Logic:
    DO Normal DFS Traversal from Any Node, And for a Node when the dfs for its neighbours is complete, push it into the stack
    Why do we push into stack only when the neighbours dfs is over ? Because At the end only the nodes who have edges to other nodes will remain, which is what we need
    Thus it will stack up and give a nice topological order
    Dry runs for better clarity
    TC =>? O(N + E), SC => O(N + N)
*/
void dfsTopoSort (int node, int vis[], vector <int> adj[], stack <int> &stk) {
    vis[node] = 1;
    for (auto neighbour : adj[node]) {
        if (!vis[neighbour]) {
            dfsTopoSort(neighbour, vis, adj, stk);
        }
    }
    stk.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V] = {0};
    stack <int> stk;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsTopoSort(i, vis, adj, stk);
        }
    }
    vector <int> ans;
    while (!stk.empty()) {
        int top = stk.top();
        ans.push_back(top);
        stk.pop();
    }
    return ans;
}

/*
Kahn's Algorithm / BFS - For Topological Sorting
Logic:
    Create an Indegree vector which represents the incoming edges for each node
    Create a Queue Data Structure which initially contains all the nodes with 0 indegrees
    Now Take elements of queue one by one (Storing in some list), and reducing the indegree of all the neighbours this element is connected to
    If the indegree of any of the neighbour become 0, insert this neighbour into the queue
    Keep doing until the queue is not empty
    TC => O(N + E), SC +> O(N + N)
*/
vector<int> topoSort(int V, vector<int> adj[]) {
    int inDegree[V] = {0};
    for (int i = 0; i < V; i++) {
        for (auto neighbour : adj[i]) {
            inDegree[neighbour]++;
        }
    }
    queue <int> q;
    for (int i = 0; i < V; i++) {
        if (!inDegree[i]) q.push(i);
    }
    vector <int> topo;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        topo.push_back(front);
        for (auto &neighbour : adj[front]) {
            inDegree[neighbour]--;
            if (!inDegree[neighbour]) q.push(neighbour);
        }
    }
    return topo;
}

/*
Detection of Cycle in a Directed Graph Using Kahn's Algorith for Topological Sorting:
Logic:
    Perform the usual Kahn's Algorith, if the length of toposort found is == N, cycle not present, else cycle present
    TC => O(N + E), SC => O(N + N)
*/
bool cycleDetectKahnsAlgorithm(int V, vector<int> adj[]) {
    int inDegree[V] = {0};
    for (int i = 0; i < V; i++) {
        for (auto neighbour : adj[i]) {
            inDegree[neighbour]++;
        }
    }
    queue <int> q;
    for (int i = 0; i < V; i++) {
        if (!inDegree[i]) q.push(i);
    }
    int count = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        count++;
        for (auto &neighbour : adj[front]) {
            inDegree[neighbour]--;
            if (!inDegree[neighbour]) q.push(neighbour);
        }
    }
    return !(count == V);
}

/*
Course Schedule:
This Problem Gives PreRequisite for tasks, for ex - Task 0 should be performed before Task 1, Task 1 before Task 2 and so on
Poblem 1 : We need to determine if it is possible to complete all tasks, starting from any one task
Problem 2 : Give any such valid ordering of tasks
Logic:
    Problem 1: 
    When is it not possible ? Only when there is a cyclic dependency, Like 0 before 1, 1 before 2 and 2 before 0 (Impossible to Complete)
    So we need to detected if the sequence forms a cycle, and since 0 before 1 means an edge from 0 to 1. We need to find whether cycle exists in Directed Graph
    Use Kahns Algorithm for this Problem, return true if topological sequence is possible
    Problem 2:
    Return the topological sequence of this graph (DAG)
*/


/*
Find Eventual Safe States:
We need to find All the nodes, through which all their paths end at a terminal node (Node with 0 indegrees)
Logic:
    First Reverse All the Edges of the graph
    Push All the Nodes with 0 indegrees in a Queue Data Structure
    Iterate through Queue, Storing the front element, now reduce the indegrees of the neighbours (If indegree == 0, push again into the queue)
    Basically using Kahns Algorithm
    TC => O(N + E), SC => O(N + N)
*/
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    int indegree[V];
    vector <int> adj[V];
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < V; i++) {
        for (auto neighbour : graph[i]) {
            adj[neighbour].push_back(i);
            indegree[i]++;
        }
    }
    queue <int> q;
    for (int i = 0; i < V; i++) {
        if (!indegree[i]) q.push(i);
    }
    vector <int> safe;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        safe.push_back(front);
        for (auto &neighbour : adj[front]) {
            indegree[neighbour]--;
            if (!indegree[neighbour]) q.push(neighbour);
        }
    }
    sort(safe.begin(), safe.end());
    return safe;
}

/*
Alien Dictionary:
Given A List of Alien Alphatically Ordered List of Words
We Need to Find the Aplhabetical Order (Like 'a', 'b', 'c', ..)
Logic:

*/
string findOrder(string dict[], int N, int K) {
    vector <int> adj[K];
    // Generate Directed Graph
    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                // Using Mapped Numbers instead of characters
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    // Find the Topological Order
    int indegrees[K] = {0};
    for (int i = 0; i < K; i++) {
        for (auto neighbour : adj[i]) {
            indegrees[neighbour]++;
        }
    }
    // // Kahns Algorithm
    queue <int> q;
    for (int i = 0; i < K; i++) {
        if (!indegrees[i]) q.push(i);
    }
    vector <int> order;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        order.push_back(front);
        for (auto neighbour : adj[front]) {
            indegrees[neighbour]--;
            if (!indegrees[neighbour]) q.push(neighbour);
        }
    }
    // // Mapping the Numbers back to characters
    string ans = "";
    for (auto val : order) {
        ans.push_back(char('a' + val));
    }
    return ans;
}

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