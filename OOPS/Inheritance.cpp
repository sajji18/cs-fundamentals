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
Encapsulation:
It says, keep all information related to an entity in 1 class only.
For Example:
    If we have 2 classes, car and sportscar.
    Car has 5 basic properties, and sportscar has 3 add-on properties (But We do not add the basic properties again in this class)
    To represent a sportscar, we have to create 2 objects, one of car and one of sportscar to represent all 8 variables
    Thus this is against the rule of encapsulation and we need INHERITANCE TO SOLVE THIS PROBLEM.

Inheritance:
It is a provess of inheriting propertues and behaviours of existing class into a new class
Existing class = Old Class = Parent Class = Base Class
New Class = Child Class = Derived Class
=> Class is used to describe properties and behaviour of an object
=> Property : Names and Values
=> Behaviour : Actions

Syntax of Inheritance: (Visibility Mode is public, private or protected)
    class BASE_CLASS {};
    class DERIVED_CLASS : Visibility_Mode BASE_CLASS {};

Types of Inheritance:
1. Single Inheritance
2. Multilevel Inheritance
3. Multiple Inheritance
4. Hierarchical Inheritance
5. Hybrid Inheritance

Visibility Modes:
1. Private
2. Protected
3. Public 

Types of Users of A Class:
=> User 1 will create Object of your class
=> User 2 will create derived class from your class

Availability V/s Accessibility:
1. In Private Visibillity Mode: User 1 and User 2 cannot access private members of the base class, although they are available, but NOT accessible
2. In Protected Visibility Mode: User 1 cannot access, but User 2 can access private members
3. In Public Visibility Mode: User 1 and User 2 can access private members

Example:
      A
    / | \ 
   B  B  B
B is the Child Class and A is Parent Class
Based on what the visibility Mode is, ****B can access protected and public members of A****

So lets say we consider three cases, Private, Protected, Public
These visibility Mode determine, what the ****Child Class of B have in terms of access to members of A****

1. In Private Visibility of A : The protected and public will be considered as private members of B for User 1 and User 2 of Class B
2. In Protected Visibility of A : The protected and public will be considered as protected members of B for User 1 and User 2 of Class B
3. In Public Visibility of A : The protected and public will be considered protected and public members of B respectively for User 1 and User 2
*/ 
class A {
    private:
        int a;
    protected:
        void setValue (int k) {
            a = k;
        }
};
class B : public A {
    public:
        void setData (int x) {
            setValue(x);
        }
};

/*
Is a Relationship:
Example - Banana is a Fruit, Car Has a Engine, Rectangle is a Quadrilaterial

Association of Classes Can be in Different Forms:
- Aggregation
- Composition
- Inheritance

In Inheritance:
Example - Banana and Fruit => Banana will be Child (Less Generalized) and Fruit will be Parent (More Generalized)
        Every Banana is a Fruit, But Every Fruit is not a Banana

Public Inheritance:
=> ****Is a relationship is always implemented as a public inheritance****

- But Why ?
    For Example : If Animal class has a public member function Eating, then object of child class Cat should also be able to access it. And this can be only done if public inheritance is there.
- When When to use private and protected inheritance ?
    For Example : If we have two classes Array and Stack, Stack Inherits from Array Class
                We have a Public Utility in Array called insert, to insert element at any index
                We have a Public Utility in Stack called push, to insert only at the top of the stack
                Now if we create a public inheritance, the object of Stack class can use insert function of Array class (It will be public in stack as a result), and insert element anywhere. 
                This is bad since we can only insert at top in a stack. Thus we hide this utility from the OBJECT OF STACK
*/
// Example 1
class Car {
    private:
        int gear;
    public:
        void incrementGear () {
            if (gear < 5) gear++;
        }
};
class SportsCar : public Car {};
// Example 2
class Array {
    private:
        int a[10];
    public:
        void insert (int index, int value) {
            a[index] = value;
        }
};
class Stack : private Array {
    int top;
    public:
        Stack () {top = 0;}
        void push (int value) {
            insert(top, value);
            top++;
        }
};

/*
Constructor and Destructor in Inheritance:
Questions:
Q) We know that constructor is invoked implicitly when an object is created.
    In inheritance, when we create object of derived class, what will happen ?
Solution :
    Consider the below Example: Class C and D, D inherits from C
    When An Object of D is created, Constructor of D is called first, which first calls Constructor of C
    So first Constructor of C executes, then Constructor of D executes
    How is Constructor of C called ? 
        This is something, that the compiler writes code for itself
        But here's the catch : The Compiler writes code to call for only default constructor in the parent class
        So it works as long as, we do not create any Constructor or a Custom parameterized Constructor in Parent Class

        Once we have created a Parameterized Constructor in Parent Class, The Compiler does not create a default one 
        Thus we have to create a Custom Constructor in Child As well, which calls this Constructor in Parent Class

Q) We know that Destructor is invoked implicitly before an object is destroyed.
    In inheritance, when we create object of derived class, what will happen ?
Solution:
    Similar to Constructor:
    First the Child Class Destructor is called and then the Parent Class Destructor is called
    BUT THE EXECUTION ORDER IS DIFFERENT!!!!!!!!!!!!!!!!
    First the Child Class Destructor is executed and then the Parent Class Destructor is executed

Summing Up:
    First Child Class Constructor is Called and then Parent Class Constructor is Called
    First Parent Class Constructor is Executed and then Child Class Constructor is Executed

    First Child Class Destructor is Called and then Parent Class Destructor is Called
    First Child Class Destructor is Executed and then Parent Class Destructor is Executed
*/
class C {
    int c;
    public:
        // Constructor
        // Since we created a Parameterized Constructor, the Compiler is not creating any default one
        C (int k) {
            c = k;
        }

        // Destructor 
        ~C () {}
};
class D : public C {
    int d;
    public:
        // Constructor
        // We have to Explicitly Call that Parameterized Constructor in Parent Class, Since otherwise Compiler itself will Call Default One (Which does not exist since we created one ourself)
        D (int x, int y) : C (x) {
            d = y;
        }

        // Destructor
        ~D () {}
};

int main () {
    B obj;
    // obj.setValue(4); Gives Error Since User 1 cannot access private and protected Members
    obj.setData(4);

    D obj1(2, 3);
}