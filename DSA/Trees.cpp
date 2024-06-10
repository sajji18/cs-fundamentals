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

// Tree Definition
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive Tree Traversals
vector <int> pre, in, post;
void recr_preorder (TreeNode* root) {
    if (root == nullptr) return;
    pre.push_back(root -> data);
    recr_preorder(root -> left);
    recr_preorder(root -> right);
}

void recr_inorder (TreeNode* root) {
    if (root == nullptr) return;
    recr_inorder(root -> left);
    in.push_back(root -> data);
    recr_inorder(root -> right);
}

void recr_postorder (TreeNode* root) {
    if (root == NULL) return;
    recr_postorder(root -> left);
    recr_postorder(root -> right);
    post.push_back(root -> data);
}

// Iterative Tree Traversals
vector <int> itr_preorder (TreeNode* root) {
    vector <int> pre; 
    if (root == NULL) return pre;
    stack <TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* top = stk.top();
        stk.pop();
        if (top -> right != nullptr) stk.push(top -> right);
        if (top -> left != nullptr) stk.push(top -> left);
        pre.push_back(top -> data);
    }
    return pre;
}

vector <int> itr_inorder (TreeNode* root) {
    vector <int> in;
    if (root == nullptr) return in;
    stack <TreeNode*> stk;
    while (true) {
        if (root != nullptr) {
            stk.push(root);
            root = root -> left;
        }
        else {
            if (stk.empty()) break;
            TreeNode* top = stk.top();
            stk.pop();
            in.push_back(top -> data);
            root = top -> right;
        }
    }
    return in;
}

vector <int> itr_postorder_stack1 (TreeNode* root) {

}

vector <int> itr_postorder_stack2 (TreeNode* root) {
    vector <int> post;
    if (root == nullptr) return post;
    stack <TreeNode*> stk1, stk2;
    stk1.push(root);
    while (!stk1.empty()) {
        TreeNode* top = stk1.top();
        stk1.pop();
        if (top -> left != nullptr) stk1.push(top -> left);
        if (top -> right != nullptr) stk1.push(top -> right);
        stk2.push(top);
    }
    while (!stk2.empty()) {
        TreeNode* top = stk2.top();
        stk2.pop();
        post.push_back(top -> data);
    }
    return post;
}

// All Depth First Search Traversals in one code
vector <vector <int>> itr_pre_in_post (TreeNode* root) {
    vector <vector <int>> pre_in_post;
    vector <int> pre, in, post;
    if (root == nullptr) return {pre, in, post};
    stack <pair <TreeNode*, int>> stk;
    stk.push({ root, 1 });
    while (!stk.empty()) {
        auto top = stk.top();
        stk.pop();
        if (top.second == 1) {
            top.second++;
            stk.push(top);
            pre.push_back(top.first -> data);
            if (top.first -> left != nullptr) stk.push({ top.first -> left, 1 });
        }
        else if (top.second == 2) {
            top.second++;
            stk.push(top);
            in.push_back(top.first -> data);
            if (top.first -> right != nullptr) stk.push({ top.first -> right, 1 });
        }
        else {
            post.push_back(top.first -> data);
        }
    }
    pre_in_post.push_back(pre);
    pre_in_post.push_back(in);
    pre_in_post.push_back(post);
    return pre_in_post;
}

// Breadth First Search in Trees
vector <vector <int>> itr_levelorder (TreeNode* root) {
    vector <vector <int>> bfs;
    if (root == nullptr) return bfs;
    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector <int> level;
        int currSize = q.size();
        for (int i = 0; i < currSize; i++) {
            TreeNode* front = q.front();
            q.pop();
            if (front -> left != nullptr) q.push(front -> left);
            if (front -> right != nullptr) q.push(front -> right);
            level.push_back(front -> data);
        }
        bfs.push_back(level);
    }
    return bfs;
}

// Depth / Height of a Tree 
int height (TreeNode* root) {
    if (root == nullptr) return 0;
    int leftSubTreeHeight = height(root -> left);
    /*  CHECK BALANCED TREE
        if (leftSubTreeHeight == -1) return -1;
    */
    int rightSubTreeHeight = height(root -> right);
    /*  CHECK BALANCED TREE
        if (rightSubTreeHeight == -1) return -1;
        if (abs(leftSubTreeHeight - rightSubTreeHeight) > 1) {
        return -1;
        }
    */
    return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
}

// Check If Tree is Balanced (leftSubTreeHeight - rightSubTreeHeight) <= 1 for all nodes
bool isBalanced (TreeNode* root) {
    return height(root) != -1;
}

// Find Diameter of Binary tree
int findHeight (TreeNode* root, int diameter) {
    if (root == NULL) return 0;
    int leftHeight = findHeight(root -> left, diameter);
    int rightHeight = findHeight(root -> right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

// Maximum Path Sum in a Binary Tree
int maxPathSum (TreeNode* root, int &maxSum) {
    if (root == nullptr) return 0;
    int leftMaxPathSum = maxPathSum(root -> left, maxSum);
    int rightMaxPathSum = maxPathSum(root -> right, maxSum);
    maxSum = max(maxSum, leftMaxPathSum + rightMaxPathSum + root -> data);
    return max(leftMaxPathSum, rightMaxPathSum) + root -> data;
}

// Check if Two Trees are Identical or Not
bool isIdentical (TreeNode* p, TreeNode* q) {
    if (p == nullptr and q == nullptr) return true;
    if (p == nullptr and q != nullptr) return false;
    if (p != nullptr and q == nullptr) return false;
    if (p -> data != q -> data) return false;
    bool leftSubTreeEqual = isIdentical(p -> left, q -> left);
    bool rightSubTreeEqual = isIdentical(p -> right, q -> right);
    return (leftSubTreeEqual && rightSubTreeEqual);
}

/* 
ZigZag Traversal => Extension of BFS / Level Order Traversal
Logic:
    Traverse the tree in Normal Level order fashion
    keep a flag variable, which if true insert in the level from front, else from back
*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector <vector <int>> bfs;
    if (root == nullptr) return bfs;
    queue <TreeNode*> q;
    q.push(root);
    bool leftToRight = false;
    while (!q.empty()) {
        vector <int> level;
        int currSize = q.size();
        for (int i = 0; i < currSize; i++) {
            TreeNode* front = q.front();
            q.pop();
            if (front -> left != nullptr) q.push(front -> left);
            if (front -> right != nullptr) q.push(front -> right);
            level.push_back(front -> data);
        }
        if (leftToRight) reverse(level.begin(), level.end());
        leftToRight = !leftToRight;
        bfs.push_back(level);
    }
    return bfs;
}

/*
Boundary Traversal fo a Tree in AnticlockWise Direction
Steps:
1. First Find the left Nodes in Order (Excluding Leaf Nodes)
2. Now Find the leaf Nodes in Order from left to right
3. Finally Find the right nodes in reverse order (excluding the leaf nodes)
*/
bool isLeaf(TreeNode* node) {
    bool left = (node -> left == NULL);
    bool right = (node -> right == NULL);
    return (left & right);
}

void leftBoundary (TreeNode* root, vector <int> &res) {
    root = root -> left;
    while (root) {
        if (!isLeaf(root)) res.push_back(root -> data);
        if (root -> left != NULL) root = root -> left;
        else root = root -> right;
    }
}

void leafNodes (TreeNode* root, vector <int> &res) {
    if (isLeaf(root)) {
        res.push_back(root -> data);
        return;
    }
    if (root -> left) leafNodes(root -> left, res);
    if (root -> right) leafNodes(root -> right, res);
}

void reverseRight (TreeNode* root, vector <int> &res) {
    root = root -> right;
    vector <int> rightBoundary;
    while (root) {
        if (!isLeaf(root)) rightBoundary.push_back(root -> data);
        if (root -> right != NULL) root = root -> right;
        else root = root -> left;
    }
    for (int i = rightBoundary.size() - 1; i >= 0; i--) {
        res.push_back(rightBoundary[i]);
    }
}

vector <int> boundaryTraversal (TreeNode* root) {
    vector <int> res;
    if (root == NULL) return res;
    if (!isLeaf(root)) res.push_back(root -> data);
    leftBoundary(root, res);
    leafNodes(root, res);
    reverseRight(root, res);
    return res;
}

/*
Vertical Order Traversal
Basically Store the results level wise, and vertical wise
From root, if we go to left child, level + 1, column - 1. Else if right child, level + 1, column + 1
Using Complex DS like map <int, map <int, multiset <int>>> to store (column, level, node values) final answer
A queue <pair <TreeNode*, pair <int, int>>> to traverse tree and keep track of (node, column, level)
*/
vector <vector <int>> verticalTraversal (TreeNode* root) {
    vector <vector <int>> verticle;
    if (root == nullptr) return verticle;
    map <int, map <int, multiset <int>>> nodes;
    queue <pair <TreeNode*, pair <int, int>>> q;
    q.push({ root, { 0, 0 } });
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int x = front.second.first, y = front.second.second;
        nodes[x][y].insert(node -> data);
        if (node -> left != nullptr) {
            q.push({ node -> left, { x - 1, y + 1 } });
        }
        if (node -> right != nullptr) {
            q.push({ node -> right, { x + 1, y + 1 } });
        }
    }
    for (auto &p : nodes) {
        vector <int> col;
        for (auto &q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        verticle.push_back(col);
    }
    return verticle;
}

/*
Top View of A Binary Tree
Logic : Basically if we divide the nodes with verticle lines
    then, the topmost node of each vertical line will be seen from top view
    Thus we use Level order Traversal to get the topmost nodes first and store it in map
*/
vector<int> topView(TreeNode *root){
    vector <int> res;
    if (root == nullptr) return res;
    map <int, int> nodes;
    queue <pair <TreeNode*, int>> q;
    q.push({ root, 0 });
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int x = front.second;
        if (nodes.find(x) == nodes.end()) nodes[x] = node -> data;
        if (node -> left != nullptr) {
            q.push({ node -> left, x - 1 });
        }
        if (node -> right != nullptr) {
            q.push({ node -> right, x + 1 });
        }
    }
    for (auto &p : nodes) {
        res.push_back(p.second);
    }
    return res;
}

/*
Bottom View of A Binary Tree
Logic : Just Maintain 2 DS, A Map to store (line, Node) and a queue to store (Node, line)
    As you take an element of queue, insert its left and right children in it and update map with this node value
    As you keep on traversing, and updating the map. Eventually, the map will contain values only due to the bottom most nodes
    This is because we are doing a level order traversal, so they come at the end
*/
vector <int> bottomView(TreeNode *root) {
    vector <int> bottom;
    if (root == nullptr) return bottom;
    map <int, int> nodes;
    queue <pair <TreeNode*, int>> q;
    q.push({ root, 0 });
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int line = front.second;
        nodes[line] = node -> data;
        if (node -> left != nullptr) {
            q.push({ node -> left, line - 1 });
        }
        if (node -> right != nullptr) {
            q.push({ node -> right, line + 1 });
        }
    }
    for (auto &p : nodes) {
        bottom.push_back(p.second);
    }
    return bottom;
}

/*
Right Side View
Logic: There are Two Approaches for this, recursive and iterative
Recursive:
    Really Short and Crisp Code, TC => O(N), SC => O(H)
    First Keep going to the right, then keep going to the left
    Maintain a data structure that accepts values, only when the size of that ds = the current level traversal is on
Iterative:
    Use the Level Order Traversal and basically store the last node appearing in each level from left to right
    Ends of taking lot of space
    TC => O(N), SC => O(N)

Left Side View of A Binary Tree
Logic: 
    In the recursion code, just swap the two function calls, i.e, first go left, then right
    In iterative code, store the first node encountered in each level
*/
vector <int> ds;
void rightSideViewRecr (TreeNode* root, int level) {
    if (root == nullptr) return;
    if (ds.size() == level) ds.push_back(root -> data);
    rightSideViewRecr(root -> right, level + 1);
    rightSideViewRecr(root -> left, level + 1);
}

vector<int> rightSideViewIterative(TreeNode* root) {
    vector <int> right;
    if (root == nullptr) return right;
    map <int, int> nodes;
    queue <TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();
            nodes[level] = front -> data;
            if (front -> left != nullptr) {
                q.push(front -> left);
            }
            if (front -> right != nullptr) {
                q.push(front -> right);
            }
        }
        level++;
    }
    for (auto &p : nodes) {
        right.push_back(p.second);
    }
    return right;
}

/*
Check if a Binary Tree is Symmetric
Logic:
    For any node to the left of root should be same as that to the right of root
    call function for left node of root and right node of root
    check if left of left == right of right and right of left == left of right for all nodes
*/
bool check (TreeNode* left, TreeNode* right) {
    if (left == nullptr or right == nullptr) return left == right;
    if (left -> data != right -> data) return false;
    return check(left -> left, right -> right) && check(left -> right, right -> left);
}

bool isSymmetric(TreeNode* root) {
    return root == nullptr || check(root -> left, root -> right);
}

/*
Find Path from the Root Node to Any Given Node
Logic:
    We follow an inorder traversal, If we arrive on a null node (return false, since given node not found)
    If we arrive on required node, return true.
    Else check if the given node is either on left subtree or right subtree, if not pop back curr node val and return false
*/
bool find(TreeNode* root, vector <int> &path, int val) {
    if (!root) return false;
    path.push_back(root -> data);
    if (root -> data == val) return true;
    if (find(root -> left, path, val) 
        || find(root -> right, path, val)) return true;
    path.pop_back();
    return false;
}

vector<int> Paths(TreeNode* root, int b) {
    vector <int> path;
    if (root == NULL) return path;
    find(root, path, b);
    return path;
}

/*
Find Path from the Root Node to All Leaf Nodes
Logic:
    if current node is null, return
    if current node is leaf, push it in the path, and store the path and return
    if Current node is not null and not leaf, push it in the path and call recursion for left and right child until leaf is found
*/
bool isLeaf(TreeNode* node) {
    return (node -> left == NULL && node -> right == NULL);
}
void recr (TreeNode* root, vector <int> curr, vector <vector <int>> &paths) {
    if (root == NULL) return;
    if (isLeaf(root)) {
        curr.push_back(root -> data);
        paths.push_back(curr);
        return;
    }
    curr.push_back(root -> data);
    recr(root -> left, curr, paths);
    recr(root -> right, curr, paths);
}
vector<vector<int>> Paths(TreeNode* root) {
    vector <vector <int>> paths;
    vector <int> curr;
    recr(root, curr, paths);
    return paths;
}

/*
Lowest Common Ancestor (LCA) of 2 Nodes x and y in a Binary Tree
Logic:
    Brute Force:
    Store the paths from root node to x and y respectively, the last common element in these paths is the LCA of x and y
    TC => O(N) + O(N) for separate path calculation for x and y, SC => O(N) + O(N) for storing both of their paths
    Optimization:
    If a node is null or x or y, return node
    If a node is neither x or y, check its left and right child trees
    If both left and right subtree return non null values, return this node (LCA has been found)
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL or root == p or root == q) {
        return root;
    }
    auto left = lowestCommonAncestor(root -> left, p, q);
    auto right = lowestCommonAncestor(root -> right, p, q);
    if (left == NULL and right != NULL) {
        return right;
    }
    else if (left != NULL and right == NULL) {
        return left;
    }
    else if (left == NULL and right == NULL) {
        return NULL;
    }
    else return root;
}

/*
Width of A Binary Tree
Logic:
    Using a level order traversal, and indexing each element of a level as 0, 1, 2, 3....
    Maximum width will be max of widths of all levels (last index - first index + 1)
    TC => O(N), SC => O(N)
*/
int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    queue <pair <TreeNode*, int>> q;
    q.push({ root, 0 });
    int width = 0;
    while (!q.empty()) {
        int size = q.size();
        int minIndex = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int index = front.second - minIndex;
            if (i == 0) first = index;
            if (i == size - 1) last = index;
            if (node -> left != nullptr) {
                q.push({ node -> left, 2 * 1ll * (index) + 1 });
            }
            if (node -> right != nullptr) {
                q.push({ node -> right, 2 * 1ll * (index) + 2 });
            }
        }
        width = max(width, last - first + 1);
    }
    return width;
}

/*
Check if Binary Tree Follows Children Sum Property
Logic:
    Do an Inorder Traversal
    Base condition - if a node is null or leaf, return true
    For any node else -> if its left subtree or right subtree return false, then this node should return false
    Else if both of them return true, check if this node is equal to the sum of its left and right child
    If yes return true, else return false
*/
bool isLeaf (TreeNode* node) {
    return node -> left == NULL && node -> right == NULL;
}
bool checkChildSum (TreeNode* root) {
    if (root == NULL or isLeaf(root)) return true;
    bool leftValid = checkChildSum(root -> left);
    bool rightValid = checkChildSum(root -> right);
    if (!leftValid or !rightValid) return false;
    int leftChild = 0, rightChild = 0;
    if (root -> left != nullptr) leftChild = root -> left -> data;
    if (root -> right != nullptr) rightChild = root -> right -> data;
    return (root -> data == leftChild + rightChild);
}

/*
Given A Binary Tree, Increment any Node Any number of times, such that it follow Child Sum Property
Logic:
    An Inorder Traversal
    If current node == null, return
    Start from the root node, if sum of left and right child > current node value, set current node = leftchild + rightchild
    if sum of left and right child < current node value, set left = right = current node value
    Call function for left subtree, then right subtree
    After function calls come back, again check the value of left + right, and set it to current nodes value
*/
void changeTree (TreeNode* root) {
    if (root == NULL) return;
    int child = 0;
    if(root -> left != NULL) child += root -> left -> data;
    if (root -> right != NULL) child += root -> right -> data;
    if (child >= root -> data) root -> data = child;
    else {
        if (root -> left != NULL) root -> left -> data = root -> data;
        if (root -> right != NULL) root -> right -> data = root -> data;
    }
    changeTree(root -> left);
    changeTree(root -> right);
    int newChild = 0;
    if(root -> left != NULL) newChild += root -> left -> data;
    if (root -> right != NULL) newChild += root -> right -> data;
    if (root -> left != NULL or root -> right != NULL) root -> data = newChild;
}

/*
Print All Nodes At a Distance of K from Target Node of a Binary Tree
Logic:
    Traverse through the tree and define parent for each node (use a map to store it)
    Now Find the target node and store in a node variable (If not given)
    Now from this node, go to the left child, right child and parent (Maintain a vis array to keep track of visited nodes)
    Increase the depth variable by 1 each time you go far off in breadth
    Keep doing bfs until the depth == K, then at this point return the queue current elements (They represent all required nodes)
    TC => O(2 * N), SC => O(3 * N)
*/
void inorder (TreeNode* root, map <TreeNode*, TreeNode*> &parent) {
    // One can also do this using a BFS Traversal
    if (root == NULL) return;
    if (root -> left) parent[root -> left] = root;
    if (root -> right) parent[root -> right] = root;
    inorder(root -> left, parent);
    inorder(root -> right, parent);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector <int> ans; // Store Nodes
    if (root == NULL) return ans;
    map <TreeNode*, TreeNode*> parent; // Store Parents
    parent[root] = NULL;
    inorder(root, parent);
    queue <TreeNode*> q; // For BFS
    q.push(target);
    map <TreeNode*, bool> vis; // Store visited Nodes (Prevent from revisiting)
    vis[target] = 1; // Marking Initial Node as Visited
    int depth = 0; // Keep Track of Distance
    while (depth < k) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* front = q.front();
            q.pop();
            // Store All Path Nodes
            TreeNode* leftChild = front -> left;
            TreeNode* rightChild = front -> right;
            TreeNode* par = parent[front];
            // Check if you can visit them, then visit (push it in queue)
            if (par && !vis[par]) {
                q.push(par);
                vis[par] = 1;
            }
            if (leftChild && !vis[leftChild]) {
                q.push(leftChild);
                vis[leftChild] = 1;
            }
            if (rightChild && !vis[rightChild]) {
                q.push(rightChild);
                vis[rightChild] = 1;
            }
        }
        depth = depth + 1;
    }
    while (!q.empty()) {
        ans.push_back(q.front() -> data);
        q.pop();
    }
    return ans;
}

/*
Time taken for Binary Tree to burn down completely starting from target Node (left, right and parent affected for a given node)
Logic:
    Similar Problem to All Node at a Distance of K from Given Node
    First Find the target Node Position
    Maintain Three Data Structure, a Queue (For BFS Traversal), a Visited hash map (store visited nodes) and a parent map (store parent for a node)
    From the target Node, perform bfs (keeping track of visited Nodes), until all Nodes are visited and queue is empty, and increment time by 1 each time
    TC => O(3 * N), SC => O(3 * N)
*/
void findNode (TreeNode* root, int target, TreeNode* &node) {
    if (root == NULL) return;
    if (root -> data == target) {
        node = root;
        return;
    }
    findNode(root -> left, target, node);
    findNode(root -> right, target, node);
}
void markParent (TreeNode* root, map <TreeNode*, TreeNode*> &parent) {
    if (root == NULL) return;
    if (root -> left != nullptr) parent[root -> left] = root;
    if (root -> right != nullptr) parent[root -> right] = root;
    markParent(root -> left, parent);
    markParent(root -> right, parent);
}
int minTime(TreeNode* root, int target) {
    TreeNode* node;
    findNode(root, target, node);
    int time = 0;
    queue <TreeNode*> q;
    q.push(node);
    map <TreeNode*, bool> vis;
    vis[node] = 1;
    map <TreeNode*, TreeNode*> parent;
    parent[root] = NULL;
    markParent(root, parent);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();
            TreeNode* left = front -> left;
            TreeNode* right = front -> right;
            TreeNode* par = parent[front];
            if (left && !vis[left]) {
                q.push(left); // Burn left
                vis[left] = 1;
            }
            if (right && !vis[right]) {
                q.push(right); // Burn right
                vis[right] = 1;
            }
            if (par && !vis[par]) {
                q.push(par); // Burn Parent
                vis[par] = 1;
            }
        }
        if (!q.empty()) time++; // If q is empty, then no nodes were burnt in this iteration
    }
    return time;
}

/*
Count The Total Number of Nodes in a Complete Binary Tree
Logic:
    Brute Force:
    Very Easy, just Do BFS or Inorder / Preorder / Postorder. TC => O(N), SC => O(N) and O(H) respectively
    Optimized:
    At a given node in a complete Binary Tree, if left height == right height == h, then num of nodes = 1 << h - 1;
    Else number of nodes = 1 + countForLeftTree + countForRightTree (Recurrence Relation)
*/
int leftH (TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node -> left;
    }
    return height;
}
int rightH (TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node -> right;
    }
    return height;
}
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    int lefth = leftH(root);
    int righth = rightH(root);
    if (lefth == righth) return (1 << lefth) - 1;
    else return 1 + countNodes(root -> left) + countNodes(root -> right);  
}

/*
Requirements to Contruct a Unique Binary Tree
Logic:
    Perform Dry Runs to find that requirements are Inorder (Absolute necessity) + PostOrder/PreOrder (Any One of them)
    1 - Preorder, 2 - Inorder, 3 - PostOrder
*/
bool isPossible(int a,int b) {
    return ((a == 2 or b == 2) && (a != b));
}

/*
Construct a Binary Tree using the Inorder and Preorder Traversal Given
Logic:
    Inorder = Left Root Right, Preorder = Root Left Right
    Call The Recursive Build Function
    Maintain 4 pointers, preorder start, preorder end, inorder start, inorder end
    The preorder start shows the root of the current tree, now find this in the inorder vector using a hash map
    The left of this root in inorder shows left subtree for this root, and right of it shows the right subtree
    call build recursivley to create root -> left and root -> right, with the modified parts of inorder and preorder vectors using the 4 pointers
    TC => O(N), SC => O(N) {Map} + O(N) {Auxiliary Recursive Stack Space}
*/
TreeNode* Build (vector <int> &preorder, int preStart, int preEnd, vector <int> &inorder, int inStart, int inEnd, map <int, int> &pos) {
    if (preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int position = pos[root -> data];
    int left = position - inStart;
    root -> left = Build(preorder, preStart + 1, preStart + left, inorder, inStart, position - 1, pos);
    root -> right = Build(preorder, preStart + left + 1, preEnd, inorder, position + 1, inEnd, pos);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map <int, int> position;
    for (int i = 0; i < inorder.size(); i++) {
        position[inorder[i]] = i;
    }
    int n = preorder.size();
    TreeNode* tree = Build(preorder, 0, n - 1, inorder, 0, n - 1, position);
    return tree;
}

/*
Construct a Binary Tree using the Inorder and Postorder Traversal Given
Logic:
    Similar thought process to that of inorder + preorder
*/
TreeNode* Build (vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map <int, int> &pos) {
    if (is > ie || ps > pe) return NULL;
    TreeNode* root = new TreeNode(postorder[pe]);
    int position = pos[root -> data];
    int leftNumbers = position - is;
    root -> left = Build(inorder, is, position - 1, postorder, ps, ps + leftNumbers - 1, pos);
    root -> right = Build(inorder, position + 1, ie, postorder, ps + leftNumbers, pe - 1, pos);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size()) return NULL;
    map <int, int> pos;
    for (int i = 0; i < inorder.size(); i++) {
        pos[inorder[i]] = i;
    }
    TreeNode* tree = Build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, pos);
    return tree;
}

/*
Serialize and Deserialize a Binary Tree
Logic:
    Serializer : Convert the Tree into a string like 1, 2, 3, #, #, 4, 5 Using A level Order Traversal
    DeSerializer : Iterate over this string as objects using stringstream
    Use a Level Order Traversal and if (the left child is not '#', then set it as left child)
    If the right child is not '#', set it as right child 
    Finally return the Root (All changes will be by reference, so pass a copy of root into the queue and set its children (of the copy))
    TC => O(N), SC => O(N)
*/
string serialize(TreeNode* root) {
    // Create String Like 1, 2, 3, #, #, 4, 5 Using A level Order Traversal
    if (root == NULL) return "";
    string s = "";
    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        if (front == NULL) s.append("#,");
        else s.append(to_string(front -> data) + ',');
        if (front != NULL) {
            q.push(front -> left);
            q.push(front -> right);
        }
    }
    return s;
}
TreeNode* deserialize(string &data) {
    if (!data.length()) return nullptr;
    // Read About this, very useful thing
    stringstream s(data); // Treats the given string as an iterable object

    string str;
    getline(s, str, ',');

    TreeNode* root = new TreeNode(stoi(str));
    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        // Current Node under Consideration
        auto front = q.front();        
        q.pop();
        getline(s, str, ','); // Left Child
        if (str == "#") {
            front -> left = NULL;
        }
        else {
            front -> left = new TreeNode(stoi(str));
            q.push(front -> left);
        }
        getline(s, str, ','); // Right Child
        if (str == "#") {
            front -> right = NULL;
        }
        else {
            front -> right = new TreeNode(stoi(str));
            q.push(front -> right);
        }
    }
    return root; // All changes were by Reference
}

/*
Morris Inorder Traversal of a Binary Tree
Logic:
    If the curr node's left child is null, print curr then move to right
    If the curr node's left child is non null, first find the rightmost node from the subtree with the left child as root
    If this rightmost node is null, set it as curr node as this will allow us to make to reverse path to move up the tree
    If this rightmost node is non null, means we came to the curr node via the reverse path, thus set that path as null, print curr node and move right
    TC => O(N + N), SC => O(1)
*/
vector<int> morrisInorderTraversal(TreeNode* root) {
    vector <int> ans;
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr -> left == NULL) {
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        else {
            TreeNode* prev = curr -> left;
            while (prev -> right != NULL && prev -> right != curr) {
                prev = prev -> right;
            }
            if (prev -> right == NULL) {
                prev -> right = curr;
                curr = curr -> left;
            }
            else {
                prev -> right = NULL;
                ans.push_back(curr -> data); // For InOrder Traversal
                curr = curr -> right;
            }
        }
    }
    return ans;           
}

vector<int> morrisPreorderTraversal(TreeNode* root) {
    vector <int> ans;
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr -> left == NULL) {
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        else {
            TreeNode* prev = curr -> left;
            while (prev -> right != NULL && prev -> right != curr) {
                prev = prev -> right;
            }
            if (prev -> right == NULL) {
                prev -> right = curr;
                ans.push_back(curr -> data); // For preOrder Traversal
                curr = curr -> left;
            }
            else {
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return ans;           
}

/*
Flatten Binary Tree to a Linked List
Logic:
    Approach 1:
    Recursive Traversal
    Approach 2:
    Iterative Traversal
    Since We are following the preorder traversal, create a data structure (preferably a Stack)
    While traversing through the stack, take top element / Node, insert first its right child and then left child
    Now If stack is not empty, set the right child of the curr node as the top element of stack and left child of curr node as null
    TC => O(N), SC => O(N)
    Approach 3:
    Morris Traversal
*/
void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack <TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            if (top -> right != nullptr) {
                stk.push(top -> right);
            }
            if (top -> left != nullptr) {
                stk.push(top -> left);
            }
            if (!stk.empty()) {
                top -> right = stk.top();
            }
            top -> left = nullptr;
        }
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