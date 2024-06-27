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


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */


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


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */


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

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/*
Shortest Path From Source to All Nodes in a Weighted Directed Acyclic Graph (DAG):
This problem can be solved by a normal bfs of the topological sorted order of the nodes
This only works if in the topological sorted order, source node appears at the beginning (Top of Stack (LIFO))
Logic:
    Construct Graph with Weights
    Find the TopoSort Order using BFS (Kahn's Indegree Algorithm) or DFS (Push a Node in Stack after DFS of its neighbour is complete)
    Maintain a distance array to store the minimum distance
    Iterate over stack, take top element and pop
    Iterate over this elements neighbours: If the shortestDistance[element] + weight[edge b/w element & neighbour] < shortestDistance[neighbour], then update
    Keep doing this until stack is not empty
    Intution: Basically Shortest Distance for a Node = Shortest Distance of its parents + min(weights of all edge b/w this node and its parents)
    TC => O(N + E), SC => O(N) + O(N) + O(N) + O(N) {visited array, recursive auxiliary stack, stack, dist array}
*/
void dfs (int node, vector <pair<int, int>> adj[], int vis[], stack <int> &stk) {
    // Entering Node
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it.first]) {
            dfs(it.first, adj, vis, stk);
        }
    }
    // Exiting Node
    stk.push(node);
}
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // Shortest Path in DAG using Topological sort works only if the source is cannot be reached via any other node
    // Create Graph
    vector <pair<int, int>> adj[N];
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({ v, wt });
    }
    // Store TopoSort order in stack
    int vis[N] = {0};
    stack <int> stk;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, stk);
        }
    }
    // Store Distances using TopoSort Stack
    // Assuming the source is not child of any node
    vector <int> dist(N, 1e9);
    dist[0] = 0;
    while (!stk.empty()) {
        int top = stk.top();
        stk.pop();
        for (auto it : adj[top]) {
            if (dist[top] + it.second < dist[it.first]) {
                dist[it.first] = dist[top] + it.second;
            }
        }
    }
    for (auto &it : dist) {
        if (it == 1e9) it = -1;
    }
    return dist;
}

/*
Shortest Path in Undirected Graph with Unit Weights
Given A Source, find the shortest distance of this source to all the points in a vector (-1 if not reachable)
Logic:
    Normal BFS Algorithm, start from source: As we go to neighbours distance increase by 1.
    Maintain a Distance Array which keeps track of the Minimum distance
    TC => O(N + 2 * E), SC => O(N)
*/
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector <int> adj[N];
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int dist[N];
    for (int i = 0; i < N; i++) dist[i] = 1e9;
    dist[src] = 0;
    queue <int> q;
    q.push(src);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto it : adj[front]) {
            if (dist[it] > 1 + dist[front]) {
                dist[it] = 1 + dist[front];
                q.push(it);
            }
        }
    }
    vector <int> ans(N, -1);
    for (int i = 0; i < N; i++) {
        if (dist[i] != 1e9) ans[i] = dist[i];
    }
    return ans;
}


/*
Dijkstra Algorithm:
Function to find the shortest distance of all the vertices from the source vertex S
Only Types of Graph where it does not work is graphs with negative weights
TC => O(N * log(V)) {Very Important}
*/
// Using Priority Queue
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Store {distance, node} in priority queue
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    vector <int> dist(V, 1e9);
    // Distance to source S is 0
    dist[S] = 0;
    pq.push({ 0, S });
    // BFS
    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // Checking Shortest Distance for neighbours
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if (distance + edgeWeight < dist[adjNode]) {
                dist[adjNode] = distance + edgeWeight;
                pq.push({ dist[adjNode], adjNode });
            }
        }
    }
    return dist;
}
// Using Set, Only Benefit is that If someone visited a Node earlier and Gave a Worse distance
// We can erase that distance once we visit that node again with a better distance
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Store {distance, node} in set
    set <pair <int, int>> st;
    vector <int> dist(V, 1e9);
    // Distance to source S is 0
    st.insert({ 0, S });
    dist[S] = 0;
    // BFS Like Traversal
    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        // Finding shortest Path to neighbours
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            
            if (dis + edgeWeight < dist[adjNode]) {
                // If Worse Distance already present
                if (dist[adjNode] != 1e9) {
                    // erase it since we found better
                    st.erase({ dist[adjNode], adjNode });
                }
                // Update this better distance
                dist[adjNode] = dis + edgeWeight;
                st.insert({ dist[adjNode], adjNode });
            }
        }
    }
    return dist;
}

/*
In Dijkstra's Algorithm
Question) Why do we consider Priority Queue / Set instead of a Queue ?
Answer => If we use queue, it is brute force (Using dry runs we find out, using queues will lead us to explore all possible paths)
        But when we use priority queue or set, we are greedily first only exploring the minimum distance paths and then proceed

Time Complexity Derivation:
TC = O(V * (Pop Vertex from Min Heap + No. of edges on each vertex * Pust into Min Heap))
TC = O(V * (log(Heap Size) + ne * log(Heap Size)))
TC = O(V * (log(Heap Size) * (1 + ne))) {But ne = V - 1 (In the worst case, all vertex connected to every other vertex)}
TC = O(V * V * log(Heap Size))
TC = O(V^2 * log(Heap Size)) {Worse case Heap size = V^2}
TC = O(V^2 * 2 * log(V)) {V^2 ~= Edges E}
TC = O(E * 2 * log(V)) = O(E * log(V))
*/

/*
Print the Shortest Path from 1 to N in a Weighted Graph:
Logic:
    Use the standard Dijkstra's Algorithm
    Maintain a parent array to keep track of the parents of the nodes (From where did we come from to reach Node N)
    Finally Backtrack to find the given path
    TC => O(N) + O(E * log(V))
*/
vector <int> printShortestPath (int n, int m, vector <vector <int>> &edges) {
    // Construct weighted graph
    vector <pair<int, int>> adj[n + 1];
    for (auto it : edges) {
        adj[it[0]].push_back({ it[1], it[2] });
        adj[it[1]].push_back({ it[0], it[2] });
    }
    // Mark Parents
    int parent[n + 1];
    for (int i = 1; i <= n; i++) parent[i] = i;
    // Dijkstra (Create Priority Queue with {distance, node})
    vector <int> dist(n + 1, 1e9);
    priority_queue <pair<int, int>, vector<pair <int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });
    dist[1] = 0;
    while (!pq.empty()) {
        auto node = pq.top().second;
        auto dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node]) {
            auto adjNode = it.first;
            auto edgeWeight = it.second;
            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({ dist[adjNode], adjNode });
                parent[adjNode] = node;
            }
        }
    }
    // Path Not Found
    if (dist[n] == 1e9) return {-1};
    // Backtrack to get Path
    vector <int> ans;
    int node = n;
    while (parent[node] != node) {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}

/*
Path with Minimum Effort:
Return the minimum effort of all of the paths from (0, 0) to (n - 1, m - 1) of a grid of heights
Effort is the maximum absolute difference of adjacent heights in a path
Logic:
    This problem can be solved using Dijkstra or BFS
    When Using dijkstra, we sort of keep a dp array (Memoization) to keep track of minimum efforts of all paths at a point (x, y
    Means dp[x, y] = min(dp[x, y], max(dp[x + i, y + j], abs(heights[x + i][y + j] - heights[x][y]))) for all i = {-1, 0, +1, 0} and j = {0, +1, 0, -1} corresponding pairs
*/
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights.front().size();
    // Maintaining a Queue Data Structure
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    vector <vector <int>> dp(n, vector <int> (m, 1e9));
    q.push({ 0, { 0, 0 } });
    dp[0][0] = 0;
    int dr[] = {-1, 0, +1, 0};
    int dc[] = {0, +1, 0 , -1};
    while (!q.empty()) {
        auto curr = q.top().first;
        auto r = q.top().second.first;
        auto c = q.top().second.second;
        q.pop();
        if (r == n - 1 && c == m - 1) return curr;
        for (int i = 0; i < 4; i++) {
            int newr = r + dr[i];
            int newc = c + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && dp[newr][newc] > max(curr, abs(heights[r][c] - heights[newr][newc]))) {
                dp[newr][newc] = min(dp[newr][newc], max(dp[r][c], abs(heights[r][c] - heights[newr][newc])));
                q.push({ dp[newr][newc], {newr, newc} });
            }
        }
    }
    return dp[n - 1][m - 1];
}

/*
Cheapest Flight with At most K stops
Reach from source S to destination D, using minimum cost as well as within stop limit (Number of times vertex change)
Logic:
    One Might think this can be solved with Dijkstra... Game Over (No it cannot)
    The thing is Dijkstra always uses a Priority Queue, So we will always find the shortest Path. But it is not manadatory that it will be within the stop limit
    And Dijkstra will not even allow a costlier path to store itself even if it is within the stop limit, and cheaper path is out of stop limit
    Therefore we maintain a Queue with {stops, {node, cost}} and do a level order traversal (Based on stops)
    And push nodes min path nodes into the queue (ONLY IF THEY ARE WITHIN STOP LIMIT)
    TC => O(N) {Normal BFS}
*/ 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Creating Graph
    vector <pair <int, int>> adj[n];
    for (auto it : flights) {
        adj[it[0]].push_back({ it[1], it[2] });
    }
    // Dp Array to Store Min Cost to Reach that Node
    vector <int> dp(n, 1e9);
    dp[src] = 0;
    // Dijkstra's Algorith
    queue <pair<int, pair<int, int>>> pq;
    pq.push({ 0, { src, 0 }});
    // Heres the catch, we need to store {stops, {node, distance}} and Not {distance, {node, stops}} since stops are more important than this problem. Rest same
    while (!pq.empty()) {
        auto node = pq.front().second.first;
        auto cost = pq.front().second.second;
        auto stops = pq.front().first;
        pq.pop();
        if (stops > k) break;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (dp[adjNode] > cost + edgeWeight && stops <= k) {
                dp[adjNode] = cost + edgeWeight;
                pq.push({ stops + 1, {adjNode, cost + edgeWeight} });
            }
        }
    }
    if (dp[dst] == 1e9) return -1;
    else return dp[dst];
}

/*
Network Delay Time:
Given A Directed Graph with Weights equal to Time
Find the minimum time to reach signal from source node to all nodes
Logic:
    Find the Shortest Path / Time for each node from the given source
    The maximum of these shortest times will be time when all nodes will get notified of the messafe
*/
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Create Graph
    vector <pair <int, int>> adj[n + 1];
    for (auto it : times) {
        adj[it[0]].push_back({it[1], it[2]});
    }
    // Maintain a dp array, dp[i] = Minimum time to receive Message from source k
    vector <int> dp(n + 1, 1e9);
    dp[k] = 0;
    // Dijkstra to find the shortest path to all the nodes (time, node)
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, k });
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        auto time = it.first;
        auto node = it.second;
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeW = it.second;
            if (time + edgeW < dp[adjNode]) {
                dp[adjNode] = time + edgeW;
                pq.push({ dp[adjNode], adjNode });
            }
        }
    }
    int res = INT_MIN;
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    if (res == 1e9) return -1;
    else return res;
}

/*
Minimum Multiplications to reach End:
Given Start Number, End Number and Array of Multipliers
Return the minimum number of steps to reach from start number to end number using multiplications from the array multipliers any number of time
Logic:
    We observe that this is like a graph, and we need to find the shortest number of steps (BFS OFcourse!!!!!!!!!)
    TC => O(100000 * N) {Very Unlikely, Expected to be much lower than this}
*/
int minimumMultiplications(vector<int>& arr, int start, int end) {
    // Edge Case
    if (start == end) return 0;
    // Store {value, steps}
    queue <pair<int, int>> q;
    vector <int> dp(100000, 1e9);
    q.push({ start, 0 });
    dp[start] = 0;
    while (!q.empty()) {
        auto node = q.front().first;
        auto steps = q.front().second;
        q.pop();
        for (auto it : arr) {
            int num = (node * it) % 100000;
            if (dp[num] > steps + 1) {
                q.push({ num, steps + 1 });
                if (num == end) return steps + 1;
                dp[num] = steps + 1;
            }
        }
    }
    return -1;
}

/*
Number of shortest paths to arrive at destination
Logic:
    Dijkstra + DP (Storing the number of ways)
    lets say if all weights of paths are same then: dp[node] = dp[child1] + dp[child2] + ...
    Else if a new path with less weight is found: dp[node] = dp[child]
    TC => O(E * log(V)), SC => O(N)
*/
int countPaths(int n, vector<vector<int>>& roads) {
    // Create Graph
    vector <pair<long long, long long>> adj[n];
    for (auto it : roads) {
        adj[it[0]].push_back({ it[1], it[2] });
        adj[it[1]].push_back({ it[0], it[2] });
    }
    // Dp Array to store ways and distance array to keep track of minimum distance
    vector <long long> dp(n, 0);
    vector <long long> dist(n, LONG_MAX);
    dp[0] = 1;
    dist[0] = 0;
    // Dijkstra
    priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        long long node = pq.top().second;
        long long dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node]) {
            long long adjNode = it.first;
            long long edgeW = it.second;
            // This is the first time i am coming to this node with a shorter distance
            if (dis + edgeW < dist[adjNode]) {
                pq.push({ dis + edgeW, adjNode });
                dist[adjNode] = dis + edgeW;
                dp[adjNode] = (dp[node]) % 1000000007;
            }
            else if (dis + edgeW == dist[adjNode]) {
                dp[adjNode] = (dp[adjNode] + dp[node]) % 1000000007;
            }
        }
    }
    return dp[n - 1] % 1000000007;
}

/*
BELLMAN FORD ALGORITHM:
=> Similar to Dijkstra, it is also an Algorithm for finding the shortest path from source to all nodes
=> Only Difference - It works for graphs with negative weights as well
=> It only works for directed graph (If graph if undirected, make it double directed
=> TC => O(V * E)
Algorithm:
    Relax all the edges, N - 1 times (Assuming N Vertex)
    Relaxation of Edge:
        If there is an edge from u to v
        Relaxation means if (dist[u] + edgeWeight < dist[v]) dist[v] = dist[u] + edgeWeight
    To Check if graph contains a Negative Cycle:
        Relax all the edges the Nth time (1 More Relaxation)
        If any distance still update, then negative cycle is Present
        Proof : Basically, for any graph, we require at Most N - 1 Relaxations to find shortest distance for all the nodes
                The only case of distance updating the Nth time, will be if negative cycles are present
*/
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector <int> dist(V, 1e8);
    dist[S] = 0;
    // Relaxing Edges V - 1 Times
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth Relaxation to Check Negative Cycle
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};
        }
    }
    // If No Negative Cycle found, return the shortest distance array
    return dist;
}

/*
FLOYD MARSHALL ALGORITHM:
=> It is used to find the the shortest Path from every node to every other node (Baap of Dijkstra and Bellman Ford)
=> TC => O(N * N * N)
=> Can be used to detect negative cycle as well
Algorithm:
    Solved using Dynamic Programming
    State: dp[i][j] = shortest distance to reach from i to j
    Initialization: Same as Adjacency Matrix of Graph (Replace -1 with 1e9 (For {i, j} whose edges are not given))
    Transition: dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]) (To Reach from i to j, we go from i to k then k to j {for all k = 1 to N})
*/
void shortest_distance(vector<vector<int>>&dp){
    int n = dp.size();
    // Initialize dp array from adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) dp[i][j] = 1e9;
        }
    }
    // Compute Shortest distance for dp[i][j] using Dynamic Programming
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            } 
    }
    // If distance is 1e9, path does not exist
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 1e9) dp[i][j] = -1;
        }
    }
    // Check Presence of Negative Cycle
    for (int i = 0; i < n; i++) {
        if (dp[i][i] < 0) cout << "Negative Cycle is There\n";
    }
}

/*
Minimum Spanning Tree (MST):
=> It is for a graph, out of all possible Spanning Trees, the one having minimum sum of edge weights
=> Can be found using:
    Prims Algorithm of MST
    Kruskal Algorith (Disjoint Set)
Spanning Tree:
    A tree in with N nodes and N - 1 edges, and all nodes are reachable from each other
*/

/*
Prim's Algorithm (Minimum Spanning Tree):
Intution:
    We solve this problem using a GREEDY Approach
    Initially push 0 into the priority queue (Since At least one edge will be connected to 0 in the MST)
    Now we Push all its adjNodes 
    But everytime we greedily pick out the smallest weight nodes from the MIN-HEAP (Thus we find MST)
    We maintain a visited array and make nodes visited the first time they are picked out of the heap (Then ignore them afterwards)
    TC => O(E * log(E))
*/
int spanningTree(int V, vector<vector<int>> adj[]) {
    // Create a Min-Heap to store {weight, node} (If MST was also asked, store {weight, {node, parent}})
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector <int> vis(V, 0);
    pq.push({ 0, 0 });
    int sum = 0;
    while (!pq.empty()) {
        auto node = pq.top().second;
        auto wt = pq.top().first;
        pq.pop();
        // If Visited, Continue. Else Take Value
        if (vis[node]) continue;
        vis[node] = 1;
        sum += wt;
        // Check adjacent Neighbours
        for (auto it : adj[node]) {
            auto adjNode = it[0];
            auto edgeW = it[1];
            if (!vis[adjNode]) {
                pq.push({ edgeW, adjNode });
            }
        }
    }
    return sum;
}

/*
BRIDGES IN A GRAPH:
It is an Edge, on removal of which, the graph breaks into 2 or more components.
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