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
Object Pointer:
=> A Pointer containing the address of an object is called Object Pointer

This Pointer:
=> this is a keyword
=> this is a local object pointer in every instance member function containing address of the caller object
=> this pointer can not be modified
=> It is used to REFER CALLER OBJECT in member function
*/
class Box {
    private:
        int l, b, h;
    public:
        void setDimensions (int l, int b, int h) {
            // l = l; b = b; h = h; This can cause naming conflicts.

            // This is resolved using this pointer
            // this always points to the address of the caller object (It is basically created when a caller object calls a member function)
            // Now the naming is resolved, this -> l == Instance Member Variable and l == local function variable / Parameter
            this -> l = l;
            this -> b = b;
            this -> h = h;
        }
        void showDimensions () {
            cout << "x = " << l << " y = " << b << " z = " << h << "\n";
        }
};

int main () {
    // use * to declare a Pointer to object of mentioned data type
    Box *p;
    Box smallBox;

    // Set Pointers value to the address of an Object of the same data type as the pointer is expected to point to
    p = &smallBox;

    // Pointer can call Member functions for this Object (The Address it is storing) with -> 
    p->setDimensions(12, 10, 5);
    p->showDimensions();

    // When smallBox calls an instance member function, a this pointer is created which points to smallBox (caller object) and is available inside that instance member function
    smallBox.setDimensions(12, 10, 5);
    smallBox.showDimensions();
}