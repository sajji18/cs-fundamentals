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
Binary Search Trees
=> These allow efficient search operations, due to their very specific properties
=> For a Node N, Left Child L, Right Child R in BST, We have L < N < R (Always)
=> All the Subtrees in a BST should also be BSTs
=> Height of BST is Generally Kept As Log(N) to Allow Efficient Search, Insert Operations
=> These types of trees are rarely Degenerate
*/
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

/*
Search in a Binary Search Tree
Logic:
    Since we know for any Node, L < N < R, we can sort of perform a binary search
    If Value to be found > Current Node Value, Search to the Right of this Node
    If the Value to be found < Current Node Value, Search to the Left of this Node
    If the Value to be found == Current Node Value OR Current Node is NULL, Return this Node
    If final Return Value of the function = NULL, then Value is Not Present, Else The Node is Returned
*/
// Recursive
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (val == root -> data) return root;
    if (val < root -> data) {
        return searchBST(root -> left, val);
    }
    else {
        return searchBST(root -> right, val);
    }
}

// Iterative
TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL && root -> data != val) {
        if (root -> data > val) root = root -> left;
        else root = root -> right;
    }
    return root;
}

/*
Find the Min / Max Value in a Binary Search Tree
Logic:
    For a Given Node, L < N < R
    Thus it can be inferred that the leftMost Node, whose left child is NULL, will be the Smallest
    Also it can be inferred that the rightMost Node, whose right child is NULL will be the Largest
*/
int minValue(TreeNode* root) {
    if (root == NULL) return -1;
    while (root -> left != NULL) root = root -> left;
    return root -> data;
}
int maxValue(TreeNode* root) {
    if (root == NULL) return -1;
    while (root -> left != NULL) root = root -> left;
    return root -> data;
}

/*
Find Ceil of A Number in A Binary Search Tree
Logic:
    We need to find the element x >= input
    If we find element == input, then return input
    Initialize ans as INT_MAX (If at the end answer is INT_MAX, then no such element exists, return -1)
    If curr element > x, store it in ans as ans = min(ans, curr) as this element can be possible answer, ans go to left
    If curr element < x, this element cannot be answer, go to right to search for a larger element
*/
int findCeil(TreeNode* root, int input) {
    int ans = INT_MAX;
    while (root != NULL) {
        if (root -> data == input) return input;
        if (root -> data > input) {
            ans = min(ans, root -> data);
            root = root -> left;
        }
        else root = root -> right;
    }
    return ans == INT_MAX ? -1 : ans;
}

/*
Find Floor of A Number in A Binary Search Tree
Logic:
    We need to find the element x <= input
    If we find element == input, then return input
    Initialize ans as INT_MIN (If at the end answer is INT_MIN, then no such element exists, return -1)
    If curr element < x, store it in ans as ans = max(ans, curr) as this element can be possible answer, ans go to right
    If curr element > x, this element cannot be answer, go to left to search for a smaller element
*/
int findFloor(TreeNode* root, int x) {
    int ans = INT_MIN;
    while (root != NULL) {
        if (root -> data == x) return x;
        else if (root -> data > x) root = root -> left;
        else {
            ans = max(ans, root -> data);
            root = root -> right;
        }
    }
    return ans == INT_MIN ? -1 : ans;
}

/*
Insert a New Node into A Binary Search Tree
Logic:
    Find the Leaf Node where the given Node can be Added, and add it there
    If current node > given node, if it is leaf : Attach the given to its left, Else Go to Left to Search for a smaller Node
    If current node < given node, if it is leaf : Attach the given to its right, Else Go to Right to Search for a larger Node
    TC => O(log2(N)), SC => O(1)
*/
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = new TreeNode(val);
    TreeNode* curr = root;
    if (root == NULL) return node;
    while (true) {
        if (curr -> data > val) {
            if (curr -> left == NULL) {
                curr -> left = node;
                break;
            }
            else curr = curr -> left;
        }
        else {
            if (curr -> right == NULL) {
                curr -> right = node;
                break;
            }
            else curr = curr -> right;
        }
    }
    return root;
}

/*
Delete a Given Node from a Binary Search Tree
Logic:
    We need to reach a position, say (P), such that we are at the parent of the given node to be deleted
    Now this Node N, has L and R
    Now Make P -> left = L and Attach R to the right child of the rightmost node of L (One can also do the vice versa)
    Do Sum Dry Run with trees for better Clarity
    TC => O(log2(N)), SC => O(1)
*/
TreeNode* findRight (TreeNode* root) {
    TreeNode* curr = root;
    while (curr -> right != NULL) curr = curr -> right;
    return curr;
}
TreeNode* helper(TreeNode* root) {
    if (root -> right == NULL) return root -> left;
    if (root -> left == NULL) return root -> right;
    TreeNode* left = root -> left;
    TreeNode* right = root -> right;
    TreeNode* rightMostOfLeft = findRight(left);
    cout << rightMostOfLeft -> data;
    rightMostOfLeft -> right = right;
    return left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (root -> data == key) return helper(root);
    TreeNode *curr = root;
    while (curr) {
        if (curr -> data > key) {
            if (curr -> left != NULL && curr -> left -> data == key) {
                curr -> left = helper(curr -> left);
                break;
            }
            else curr = curr -> left;
        }
        else {
            if (curr -> right != NULL && curr -> right -> data == key) {
                curr -> right = helper(curr -> right);
                break;
            }
            else curr = curr -> right;
        }
    }
    return root;
}

/*
Find the Kth Largest/Smallest Element in a BST
Logic:
    Brute Force:
    Traverse over the tree using any of the traversals, store the node values in any data structure
    Sort it and then return the kth smallest or kth largest element
    Optimized:
    Inorder Traversal of any BST always prints the nodes in sorted order of their values
    One can do recursive or iterative inorder traversal, store the nodes (already sorted), give the required answer
    Optimized(Space as well):
    Use Morris Traversal along with a counter, after visiting every node increament counter by 1
    When count == k, return the kth smallest

    => For the kth largest, this is same as the (n - k)th Smallest
    => First count the number of nodes using 1 traversal, then proceed similarly to the morris traversal
*/
int kthSmallest(TreeNode* root, int k) {
    if (root == NULL) return 0;
    TreeNode* curr = root;
    int counter = 0, ans = -1;
    // Morris Traversal
    while (curr != NULL) {
        // If no left child include curr element, then move right
        if (curr -> left == NULL) {
            counter++;
            if (counter == k) ans = curr -> data;
            curr = curr -> right;
        }
        else {
            TreeNode* prev = curr -> left;
            // Check if back link is created or not
            while (prev -> right != NULL && prev -> right != curr) prev = prev -> right;
            // If not created, create one and move left
            if (prev -> right == NULL) {
                prev -> right = curr;
                curr = curr -> left;
            }
            // If created, then it is the second time visiting this node, increase counter and update ans if needed
            else {
                prev -> right = NULL;
                counter++;
                if (counter == k) ans = curr -> data;
                curr = curr -> right;
            }
        }
        cout << counter << endl;
    }
    return ans;
}

/*
Check if a Given Binary Tree is Binary Search Tree (BST)
Logic:
    Brute Force:
    The inorder Traversal of any BST always gives a list in ascending sorted order (Duplicates not allowed)
    Perform the inorder traversal, and check if list is sorted without duplicates
    TC => O(N), SC => O(N)
    Optimized:
    Provide a Range of Values for Every Node which it can have
    Like, the Root Node can have Values from [-INT_MAX, INT_MAX], say this node has value 13
    Its left child can have range [-INT_MAX, 13] and right child can have range [13, INT_MAX]
    TC => O(N), SC => O(1)
*/
bool valid (TreeNode* root, long start, long end) {
    if (root == NULL) return true;
    if (root -> data <= start || root -> data >= end) return false;
    bool leftValid = valid(root -> left, start, min((long)(root -> data), end));
    bool rightValid = valid(root -> right, max(start, (long)(root -> data)), end);
    return leftValid && rightValid;
}
bool isValidBST(TreeNode* root) {
    long start = INT_MIN - (long)1, end = INT_MAX + (long)1;
    return valid(root, start, end);
}

/*
Lowest Common Ancestor (LCA) of Two Nodes X and Y in a Binary Search Tree
Logic:
    If we start from the root node, there are some possibilities
    If X < N and Y < N, both lie to the left, go left
    If X > N and Y > N, both lie to the right, go right
    If X < N and Y > N or X > N and Y < N, both lie on opposite sides, means this is the point of split, N => LCA
    In this process if we somehow land on X or Y, return X or Y respectively because this will be the LCA
    TC => O(Height of Tree), SC => O(1) or O(H) {Iterative V/s Recursive, Recursion Stack Space will be equal to Height of BST}
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        int curr = root -> data, pval = p -> data, qval = q -> data;
        if (pval < curr and qval < curr) root = root -> left;
        else if (pval > curr and qval > curr) root = root -> right;
        else return root;
    }
    return root;
}

/*
Construct a BST from a preorder traversal list given
Logic:
    Brute Force:
    Create another sorted copy of the preorder traversal list, this is the inorder traversal
    Now USing 1 Inorder and 1 Preorder, one can recursively build a unique tree, which in this case will be a BST
    TC => O(N * log(N)) {Due to Sorting} + O(N) {Actual}, SC => O(1)
    Optimized:
    Maintain an Upper Bound of Values for Current Node
    Check if Current Node value is greater than upper bound or i == list.size(), return NULL node
    Other wise create a root with the current list element value
    Create its left child recursively, with upper_bound as this new value
    Create its right child recursively, with upper bound as original value
    return this root
    TC => O(3 * N), SC => O(H) {Recursive Stack Space}
*/
TreeNode* Build (vector <int> &A, int &i, int ub) {
    if (i == A.size() || A[i] >= ub) return NULL;
    TreeNode* root = new TreeNode(A[i++]);
    root -> left = Build(A, i, root -> data);
    root -> right = Build(A, i, ub);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return Build (preorder, i, INT_MAX);
}

/*
Inorder Successor/Predecessor in a Binary Search Tree
Logic:
    Brute Force:
    Store the inorder traversal (Sorted By default in A BST), Then Return the Successor/Predecessor accordingly
    TC => O(N), SC => O(N)
    Optimized:
    Start with root, if root value > target value, this could be a possible answer, store it and move to left to search for smaller
    If root value <= target, this cannot be an answer, go to right for a larger value
    Keep doing this until root is null
    TC -> O(Height of Tree), SC => O(1)
*/
TreeNode* inorderSuccessor (TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;
    while (root) {
        if (root -> data <= p -> data) {
            root = root -> right;
        }
        else {
            successor = root;
            root = root -> left;
        }
    }
    return successor;
}

/*
Design a BST Iterator
=> hasNext() : Returns True if Current Node has a Successor
=> next() : Returns Successor of Current Node
Logic:
    Brute Force:
    Store the inorder traversal in a List, Initialize the pointer initially with -1
    If next() is called, return List[++pos], If hasNext() is called : Return true if pos + 1 < List.size()
    TC => O(N), SC => O(N)
    Optimized:
    Create a Stack Data Structure
    Start with root, pus it along with all left childrens along the successor path
    When Next() is called, return top element and remove it. If it has a right child, push all left child of this right child in the stack
    When hasNext() is called, return !stk.empty()
    TC => O(N), SC => O(Height of Tree) {Since we store elements equal to height of the tree at a time}
*/
class BSTIterator {
    stack <TreeNode*> stk;
    // reverse -> true -> before element
    // reverse -> false -> next element
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (!reverse) pushAll(node -> right);
        else pushAll(node -> left);
        return node -> data;
    }
    bool hasNext() {
        return !stk.empty();
    }
private:
    void pushAll (TreeNode* node) {
        while (node) {
            stk.push(node);
            if (reverse) {
                node = node -> right;
            }
            else node = node -> left;
        }
    }
};

/*
Check if there exists a pair with Sum K in a Binary Search Tree (Tough for Optimization)
Logic:
    Brute Force:
    Create a Map To Store node values
    Start with Root, if root == NULL, return false
    Increase count of Root -> val in map, and check if mp[K - root -> val] exists (root -> val != k - root -> val : Corner Case), if yes return true
    Else return The OR of recursive calls for left child and right child
    TC => O(N), SC => O(N)
    Optimized:
    Use the BST Iterator class to find the Required element of the inorder traversal list
    Say inorder traversal is this: 1, 2, 3, 4, 5, 6, 7, 8
    initially we have pointers l, r at 1, 8 respectively. If l + r < k, then l++, else r--
    In terms of BST Iterator Class, l++ means next(), r-- means before()
*/
// Brute Force
bool checkSumPairK (TreeNode* root, int k, map <int, int> &cnt) {
    if (root == NULL) return false;
    cnt[root -> data]++;
    if (cnt.find(k - root -> data) != cnt.end() && (root -> data != k - root -> data)) return true;
    bool checkLeft = checkSumPairK(root -> left, k, cnt);
    bool checkRight = checkSumPairK(root -> right, k, cnt);
    return checkLeft || checkRight;
}
// Optimization
bool checkSumPairKOptimiza (TreeNode* root, int k) {
    if (!root) return false;
    // next
    BSTIterator l(root, false);
    // before
    BSTIterator r(root, true);
    // Two Pointer Code
    int i = l.next();
    int j = r.next();
    while (i < j) {
        if (i + j == k) return true;
        else if (i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
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