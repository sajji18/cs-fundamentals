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
VIRTUAL DESTRUCTOR:
In some cases, we need the destructors to follow Late Binding instead of Early Binding
In such cases, we make the destructors virtual
*/
class A {
    int a;
    public:
        void f1 () {}
        virtual ~A () {}
};
class B : public A {
    int b;
    public:
        void f2 () {}
        virtual ~B () {}
};
int fun () {
    // new B returns address to an unnamed memory block of object of class B
    // Since A is the parent class, we can store Child Class B object's address in pointer of A
    A *p = new B;

    p->f1(); // Correct due to Early Binding
    // p->f2(); Error due to Late Binding

    // Releasing Memory
    // Now the problem is that we have defined destructors for both class A and B. And we need both of them to run for our purpose
    // But what happens is that, Early Binding occurs... Compiler on seeing delete, decides on which Destructor to run
    // And it decides it based on type of p, which is pointer of Class A. Thus it calls destructor of class A only (Parent Class)
    // So we fucked up
    // What we want is, that the destructor of B be called, so that it will also call destructor of A (Since B is Child of A). Thus both will get called in this case
    // Therefore we like everytime, make these destructors/functions to follow LATE BINDING, i.e VIRTUAL
    delete p;
}

int main () {
}