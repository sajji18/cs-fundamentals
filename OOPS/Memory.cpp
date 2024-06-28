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
Note:
=> When a Program Runs, it comes in RAM of the system and the variables are allocated memory inside the RAM only

SMA:
Static Memory Allocation
=> Memory Required for the program is DECIDED in Compile time only (Please Note that memory is only decided in compile time, it is NOT ALLOTED. It is ALLOTED DURING EXECUTION ONLY)
=> No change in life of variables in SMA is possible, as everything is fixed, how much life is and how much memory it will take.
=> Further changes/increase in memory during EXECUTION is NOT POSSIBLE
=> Example : If we declare arr[100], then we cannot increase or decrease the number of elements in this array
=> Use Case : It is useful when WE KNOW HOW MUCH MEMORY we need, like average of 100 students. (This prevents taking excess or less memory)

DMA:
Dynamic Memory Allocation 
=> Their memory is throughout the program, does not affect by function blocks and shit like these.
=> We cannot create DMA using declaration statements, since these statements are understood by COMPILER
=> Variables made through DMA are not known to compiler. They are decided and created only on RUNTIME
=> new keyword is used to create these types of variables

Example : int *p = new int; {We create a Pointer pointing to a memory block}
               p
            ------          ------
           | 1000 | -----> |      |
            ------          ------
        float *q = new float[5]; {Dynamic Array}

=> delete keyword is used to release the memory of DMA variables ONLY
=> Since DMA variables stay throughout the program in memory, so delete comes in handy
=> for normal variables : delete p; ---- for dynamic array : delete []p (delete basically releases the memory block that p is pointing to)
=> If Pointer address is Manipulated, then the Dynamic Memory Block cannot be released from memory using delete
*/

int main () {
}