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
Pure Virtual Function:
=> A do nothing function is pure virtual function

Rule 1: A object of a class in which a do nothing function is present (Abstract Class), CANNOT BE CREATED
Rule 2: In order to create object of a Class Inheriting an Abstract Class, we have to override the pure virtual functions 

Abstract Class:
=> A class containing pure virtual function is an Abstract Class 
=> We can not create Instance/Objects of an Abstract Class

Note: An Abstract Class Instance Member Functions can be only used via a Child Class Inheriting it (Provided that the Child Class Overrides the Pure Virtual Functions)

Why Abstract Class?
Example we create three classes: Person (Base Class), Student (Child Class) and Faculty (Child Class)
We want to store only the objects of student and faculty in our system and not of person.
What to do ? We prevent creation of objects of the person class by making it an Abstract Class
Furthermore, We Pressurize the Student and the Faculty Class to override/define the pure virtual functions again in them. Thus more control over methods
*/
class Person {
    public:
        virtual void fun () = 0; // Pure Virtual Function
        void f1 () {}
};
class Student : public Person {
    public:
        void fun () {}
};

int main () {
}