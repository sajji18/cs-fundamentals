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
How Compiler Thinks:
=> When an instance of a Child Class calls a function say f
=> First the Compiler tries to find f in this Child Class, if found it DOES NOT GO TO PARENT CLASS AT ALL. It acts on this function only
=> Second, if the f is not found in the Child Class, the compiler THEN SEARCHES IN PARENT CLASS, and acts accordingly

Method Overloading:
=> When Multiple Method With Same Name, But different Parameters IN THE SAME CLASS !!!!

Method Overriding:
=> When Method with Same Name and Parameters is created in Child Class as in Parent Class

Method Hiding:
=> When Method with Same Name and different Parameter is present in Child Class and Parent Class
*/
class A {
    public:
        void f1 () {}
        void f2 () {}
};
class B : public A {
    public:
        void f1 () {} // Method Overriding
        void f2 (int x) {} // Method Hiding
};

int main () {
    B obj;
    obj.f1(); // B Class function will run
    // obj.f2(); // Error Because f2 is found in B, but parameters dont match (Compiler DOES NOT CARE about f2 in A, because f2 in B is found)
    obj.f2(4); // B Class function will run
}