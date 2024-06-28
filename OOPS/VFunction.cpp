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
Base Class Pointer:
=> Base Class Pointer can point to the object of any of its descendant class
=> But the converse is not true
=> Example: Class A is Base and Class B is Child. If we create a pointer - A *ptr, technically it should only point to objects of A. But it can point to objects of any of its children classes

Early Binding:
=> By Default all class methods adhere to early binding
=> During Compile Time, Based on Caller Objects Data TYPE, the compiler will decide which class to search the instance member function in.

Late Binding:
=> The Class where the instance member function is searched, depends NOT ON the DATA TYPE of caller object. BUT it depends on the Content of the caller object

Conversion of a function from early binding to late binding can be done by making that function VIRTUAL
*/
class A {
    public:
        virtual void f1 () {} // Now this function is Virtual (Late Binding Will Occur)
};
class B : public A {
    public:
        void f1 () {} // Method Overriding
};

/*
Virtual Function Working:
If we create even a single virtual function inside a class
A *_vptr pointer is created as a member variable
And This class and all its children are given a static vtable array, which stores pointers to the virtual function to call during late binding

*_vptr is common to all classes (Since Children will inherit the parent, and parent has _vptr, so technically all get access to _vptr)
But Array vtable is static (So everyone is allocated a separate vtable array)
*/

int main () {
    A *ptr, o1;
    B o2;
    ptr = &o2;

    // When f1 is called, compiler decides based on o2 (caller object's) data type to decide which class to find f1 in
    o2.f1(); // B

    // When f1 is called, compiler decides based on ptr (caller object's) data type to decide which class to find f1 in
    // But there is a problem, ptr is a pointer of class A.
    // Even though it is storing address of B, which means we want the compiler to search for f1 in Class B, but it searches for f1 in Class A (Due to Early Binding)
    // Thus it FAILS, runs a different function than what we wanted
    // To prevent this, and to make compiler decide based on the caller pointers content that it is storing
    // We make the function f1 virtual in the parent class (It becomes virtual for all decendant classes as well if declared later on as well)
    // Now Since it became virtual, it adheres to LATE BINDING, that is decide based on content storing (Address in this case) to decide which class to search f1 in. Therefore it searches in Class B (What we Wanted :D)
    ptr->f1(); // A
}