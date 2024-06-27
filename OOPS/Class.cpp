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
Classes and Structures:
Only Difference is that - 
=> The members of Structures are by default public
=> The members of class are by default private
Thus all concepts equally applicable to both

=> Whenever we are creating a class or struct, we create a non primitive data type

=> Class is a description of an object
=> Object is an instance of a class

State of an Object is the collection of the instance member variables for that object
If we change any variable of the object, the state is said to be changed
OOPS says that the objects state should be changed only through the object functions

The instance member functions of an object are collectively called behaviour of the object

Thus,
Instance Member Variables - Attributes, Data Members, Fields, Properties
Instance Member Functions - Methods, Procedures, Actions, Operations, Services
*/
class Complex {
    private:
    // Cannot be directly accessed in main since private
    // Can be accessed only through public methods
    // These are instance member variables, since these are allotted memory only when instance is created
        int a, b;
    public:
        // These are also called instance member functions, since they cannot execute without instances
        // Member functions can access any member of class
        // These can be defined in class or outside
        // For defining outside, provide a declaration inside. Like:
        void member_function (int, int);
        void set_data (int x, int y) {
            a = x; b = y;
        }
        void show_data () {
            cout << "a = " << a << " b = " << b << endl;
        }
        // We can create an add function or basically overwrite the definition of + for Complex objects
        Complex add (Complex c) {
            Complex temp;
            // a and b belong to the caller object (IMPORTANT!!!!)
            temp.a = a + c.a;
            temp.b = b + c.b;
            return temp;
        }
        // Overloading of + operator (i.e : Binary Operator => Requires 2 operands)
        // In these Binary Operators, one operand will be the caller object and the other we can pass as argument
        Complex operator + (Complex c) {
            Complex temp;
            temp.a = a + c.a;
            temp.b = b + c.b;
            return temp;
        }
        // In Overloading of Unary Operator, Only 1 Operand is required, which will be the caller object
        Complex operator - () {
            Complex temp;
            temp.a = -a;
            temp.b = -b;
            return temp;
        }

        // Constructor Overloading is Similar to Function Overloading, The name is same, only the parameters differ
        // Default Constructor
        Complex () {
            a = 0; b = 0;
        }
        // Parameterized Constructor
        Complex (int x, int y) {
            a = x; b = y;
        }
        Complex (int k) {
            a = k;
        }
        // Copy Constructor 
        // The passing by reference is essential
        // Why ? Because Lets say you dont pass by reference. 
        // In the main we wrote Complex c1(c2), Copy Constructor is called
        // Now Complex c is created with value c2 (So Copy Constructor is called again)
        // Therefore Copy Constructor keeps on calling again and again => Infinite Recursion
        // To prevent this we pass c by reference, so copy constructor is not called for this parameter
        Complex (Complex &c) {
            a = c.a;
            b = c.b;
        }

        // Destructor 
        ~Complex () {
            cout << "God is Great\n";
        }

        // Friend Function
        friend void friend_func(Complex);
};
// For this function to be a member. It needs:
// Same return type, name and the membership label
void Complex::member_function (int x, int y) {
    return;
}


/*
Static Local Variable:
=> Concept as it is taken from C
=> They are by default initialized to zero
=> Their lifetime is throughout the program
*/
void fun () {
    // x is given memory as soon as program execution starts
    // x is not destroyed even if fun function ends
    // x is destroyed only at the end of the program
    // x has default value 0
    static int x;
    // y is given memory only when fun function is called
    // y is destroyed as soon as fun function completes
    // y has default garbage value
    int y;
    Complex obj;
}

/*
Static Member Variable / Class Variable:
=> Declared inside the class body
=> Also known as class member variable
=> Must be defined outside the class
=> Does not belong to any object, but to whole class
=> Only one copy of static member variable for whole class
=> Any object can use the same copy of class variable
=> They can also be used with class name
*/
class Account {
    private:
        int balance; // Instance Member variable
        static float roi; // Static Member Variable Or Class Variable
    public:
        void setBalance (int b) {
            balance = b;
        }
        static void setRoi(float r) { // Static Member function => can be called without object
            roi = r;
        }
};
// Without this line, the static member variable does not get memory
// Thus its memory does not belong on the object, thus it is Class Variable
float Account::roi = 3.5;


/*
Static Member Function / Class Function:
=> They are qualified with the keyword static
=> They are also called class member functions
=> They can be invoked with or without object
=> They can only access static members of the class

Question) Are instance member functions more powerful than static member functions?
        As they have access to both class and instance member variables,
        whereas static member functions have access to only the static member variables/class variables.
Answer => No, since when there is no object created, one can only change the static member variable/class variable
        using a static member function and not the instance member function.
        Since instance member functions need an instance/object to act upon.
*/

/*
Constructor:
=> Constructor is a member function of a class
=> Name of Constructor should be the same as the name of the class
=> It has no return type, so can't use return keyword
=> It must be an instance member function, that is, it can never be static

How to call Constructor?
=> Constructor is implicitly invoked when an object is created
=> Constructor is used to solve problem of initialization

Why it is called Constructor?
=> Because it CONSTRUCTS an object. How ?
The thing is when an object is created of a class, it's member variables contain garbage values.
Thus it does not map/represent with anything yet. So if we do not initialize it's values and start calling different utility functions, it fails
Thus Constructor solves this problem of initialization and makes an Object a OBJECT.

Types of Constructors:
1. Default Contructor:
The Compiler supplies us with a default constructor, which accepts no parameter
If we create even one constructor on our own, then this default constructor does not work (We have to create the default constructor as well)
2. Parameterized Constructor:
Accepts Parameters in the constructor function
3. Copy Constructor:
When an object created of a class is initialized with another object of the same class
Then Copy Constructor is classes.
The Compiler supplies us with a default copy constructor, but we can also create our own
*/

/*
Destructor:
=> It is an instance member function of a class
=> Its name is same as the class but preceded by tilde (~) Symbol
=> Destructor can never be static
=> Destructor has no return type
=> Destructor takes no argument (No Overloading is Possible)

When does it run?
=> It is invoked implicitly when object is going to destroy

Why do we even need it?
=> Consider the case: An object of a class has an instance member variable ptr, which is a pointer pointing to an EXTERNAL memory
=> Now if the object were to destroy, the ptr would also destory, but that external memory would still be there (And we would not have its address)
=> Thus we can use a destructor which basically will release this external memory just before the object will destroy
=> Otherwise, that external memory would be consuming space. And we would have no way to access it without its address.
*/


/*
Operator Overloading:
Any Symbol can be used as a function name:
=> If it is a valid operator in C++
=> If it is preceded by the operator keyword
=> We cannot overload sizeof and ?: operator

Overloading of Binary Operator:
=> In these, two operands will be there, one operand will be the caller object and the other we can pass as argument

Overloading of Unary Operator:
=> In these, only one operand is there, which will be the caller object

Overloading of Unary (++ (Pre and Post)):
=> We have to create different overloaded functions separately for both pre and post utility as below
*/
class Integer {
    private:
        int x;
    public:
        void setData (int a) {
            x = a;
        }
        void showData () {
            cout << "x = " << x;
        }
        // Pre increment operator overloading
        Integer operator ++ () {
            Integer i;
            i.x = ++x;
            return i;
        }
        // Post Increment Operator Overloading
        // Even though we do not pass any argument, but we have to mention it: So compile can differentiate between the two - pre and post
        Integer operator ++ (int) {
            Integer i;
            i.x = x++;
            return i;
        }
};

int main () {
    // c1 is an Object (Not a variable)    
    Complex c1(3, 5), c2(6), c3, c5, c6; 

    // The below line will cause copy constructor to call
    Complex c4(c1);
    
    // c1 is the caller object, rest is member function
    c3 = c1.add(c2);
    c1.set_data(3, 4);

    // Below operation works, because we performed operator overloading
    // Two ways of writing
    c5 = c1 + c2;
    c5 = c1.operator+(c2);
    // Two ways of writing
    c6 = -c1;
    c6 = c1.operator-();

    // Each object of Account class gets it balance variable
    // But all of them have access to only one roi (Class Variable) 
    Account a1, a2;
    // Account::roi = 4.5; This could have been done if roi was not private
    // We thus used the instance member function of the account class using an object to set roi
    a1.setRoi(4.5f);
    // But roi exists even is object is not created, then how can we access it without using object and roi being private
    // We use a static member function, which can be called without an object
    Account::setRoi(4.5f);

    // Check if Destructor is called
    fun();

    // Integer Class
    Integer i1, i2;
    i1.setData(3);
    i1.showData();
    // i2 = ++i1;
    i2 = i1++;
    i1.showData();
    i2.showData();
}