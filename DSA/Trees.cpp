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

// ZigZag Traversal => Extension of BFS / Level Order Traversal
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