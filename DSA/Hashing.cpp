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
Hashing:
It Used to Solve the Problems of Comparing Strings Efficiently
Since the Brute Force to Compare Letters of Two Strings, yield a Time Complexity of O(min(n1, n2)), where n1 and n2 are string lengths

The Idea behind String Hashing is :
    We Map each String into an Integer and Compare those Integers instead of Strings
    This allows to reduce Execution Time of String Comparison to O(1)

For Strings with only Lowercase Letters:
int hashp1 = 31
int hashM = 1e9 + 9
Hash For a String S, Hash(S) = (s[0] + s[1] * hashp1 + s[2] * hashp1^2 + ....... + s[n - 1] * hashp1^(n - 1)) % hashM

For Strings with both Lowercase and Uppercase Letters
int hashp2 = 53
int hashM = 1e9 + 9
Hash For a String S, Hash(S) = (s[0] + s[1] * hashp2 + s[2] * hashp2^2 + ....... + s[n - 1] * hashp2^(n - 1)) % hashM

Computation of Hash of Substring of S from i to j, i.e Hash(s[i.....j])
Derivation:
    Hash(s[i...j]) = Summation k = i to j (s[k] * hashp1 ^ (k - i)) % hashM
    Hash(s[i...j]) * hashp1 ^ i = Summation k = i to j (s[k] * hashp1 ^ k) % ahshM  // Multiplying by hashp1 ^ i on Both Sides
    Hash(s[i...j]) * hashp1 ^ i = Hash(s[0...j]) - hash(s[0...i - 1]) % hashM
    Hash(s[i...j]) * hashp1 ^ i = prefixHash(s[j]) - prefixHash(s[i - 1]) % hashM

    Since We are in our utility Functions, already calculation prefixHash Arrays, It is quite Convenient
Problem:
    Only Problem is We need to Divide the RHS by hashp1 ^ i, therefore need to compute the modular inverse of hashp1 ^ i
Alternate:
    Suppose we need to compare two substrings
    We calculate hash(s[i....x]) * hashp1 ^ i and hash(s[j....y]) ^ hashp1 ^ j
    Now to Compare the two hash Values, we do not necessarity need to eliminate the hashp1 element, Instead we can try to make it equal on both sides
    
    if i < j, multiply the left side by hashp1 ^ (j - i), therefore we compare hash(s[i....x]) * hashp1 ^ j and hash(s[j....y]) ^ hashp1 ^ j.... So the hashp1 cancels out
    If j > i, multiply the right side by hashp1 ^ (i - j), therefore we compare hash(s[i....x]) * hashp1 ^ i and hash(s[j....y]) ^ hashp1 ^ i.... So the hashp1 cancels out

Collisions:
=> The Mentioned Polynomial Hash is Good Enough in Most Cases and No Collisions will occur During Tests
=> The probability that collision happens is only (1 / hashM), where hashM = 1e9 + 9, thus probability is 1e-9
=> But Notice that this probability is only for 1 Comparison
=> Lets say we did 1e6 Comparisons, The Probability now becomes 1e-3
=> And Bruhhh, if we compare 1e6 strings with each other (To find Unique), Probability ~= 1 (Damnnnnn), Pretty Much guaranted to give wrong answer
=> Thus either try using hashM = 1e18 or compute two hashes with hashM = 1e9 + 9 for a given string
*/

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

/*
Example Problem 1:
1. Problem : Given a list of N strings Si, each no longer than N characters, find all the duplicate strings and divide them into groups.
Solution : 
    Brute Force:
        The Obvious Algorithm is to Sort the Strings, and proceed.
        Time Complexity = O(N * M * log(N)) {Explanation: N * Log(N) for Sorting and AtMax M Comparisons For Each Pair}
    Hashing Algorithm:
        We Calculate Hash for each String in the List, Sort these Hashes together with indices, and group these indices by identical hashes
        Using Hashing, we reduce the comparison time to O(1), thus overall time complexity becomes : O(N * M + N * log(N))
*/
vector <vector <int>> group_identical_strings (vector <string> &s) {
    int n = s.size();
    int prefixHash[n + 1];
    vector <pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++) {
        int m = s[i].length();
        computePrefixHash(s[i], m, prefixHash, power);
        ll hashValue = computeHash(m, prefixHash, power, 1, m);
        hashes[i] = {hashValue, i};
    }
    sort(hashes.begin(), hashes.end());
    vector <vector <int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i - 1].first) {
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

/*
Example Problem 2:
2. Problem : Given a String of Length N, find the number of different substrings in the string
Solution : 
    Brute Force:
        Iterate Over All Substring Lengths
        For Each Substring Length, Store All Possible Substrings in a Set
        Increment Answer by Size of the Set for each Length
        This is Not Optimized Since We are storing Strings in Set, Also Set will Take O(M * Log(N)) time to store these strings in sorted order
        O(M) for comparing two substrings
    Hashing Algorithm:
        What we will do is the same thing. But STORE INTEGERS REPRESENTING SUBSTRING IN THE SET
        THUS COMPARISON WILL ONLY TAKE O(LOG(N)) TIME
        Time Complexity = O(N * N) ======> {Note that this is not the best time complexity, We can solve in O(N * Log(N)) or Even O(N) Using Suffix Arrays, Suffix Trees or Suffix Automation}

Important Insights:
hash(s[i....j]) * power[i] = (prefixHash(s[0....j]) - prefixHash(s[0....i])) % hashM
Now we would basically need to divide the RHS by power[i], thus there will be problems of modular inverse and all to calculate the hash of any subtring.

So we Multiply Both Sides by power[n - i - 1], 
which makes the LHS: hash(s[i.....j]) * power[i] * power[n - i - 1] = hash(s[i.....j]) * power[n - 1], Thus leaving only power[n - 1] (A Constant Factor)

So ALL the HashValues we calculate are just multiplied with a constant factor power[n - 1]
Therefore we can compare them directly, since all are multiplied with the same constant factor which will just cancel out
*/
int count_unique_substrings(string &s) {
    int n = s.size();
    int prefixHash[n + 1];
    computePrefixHash(s, n, prefixHash, power);
    int count = 0;
    for (int l = 1; l <= n; l++) {
        unordered_set <ll> hashSet;
        for (int i = 0; i <= n - l; i++) {
            ll currHash = (prefixHash[i + l] - prefixHash[i] + hashM) % hashM;
            // Very Important Step power[n - i] or power[n - i - 1], Does not matter much which one you chose... But the Idea is Crazy
            currHash = currHash * power[n - i - 1] % hashM;
            hashSet.insert(currHash);
        }
        count += hashSet.size();
    }
    return count;
}


int main () {
    // Precomputation of Powers for Max Possible String Size to be done Before Handling Test Cases
    power[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        power[i] = power[i - 1] * hashp1 % hashM;
    }

    // Testing Of Example 1
    vector <string> s;
    s.push_back("aaa");
    s.push_back("aba");
    s.push_back("acc");
    s.push_back("aaa");
    s.push_back("aba");
    vector <vector <int>> groups = group_identical_strings(s);
    for (auto it : groups) {
        for (auto val : it) {
            cout << val << " ";
        }
        cout << "\n";
    }

    // Testing of Example 2
    string str = "abab";
    cout << count_unique_substrings(str) << "\n";
}