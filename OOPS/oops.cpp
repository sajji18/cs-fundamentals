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

=> Class if a description of an object
=> Object is an instance of a class

State of an Object is the collection of the isntance member variables for that object
If we change any variable of the object, the state is said to be changed
OOPS says that the objects state should be changed only through the object functions

The instance member functions of an object are collectively called behaviour of the object

Thus,
Instance Member Variables - Attributes, Data Members, Fields, Properties
Instance Member Functions - Methods, Procedures, Actions, Operations, Services
*/
struct Complex {
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
        Complex add (Complex c) {
            Complex temp;
            // a and b belong to the caller object (IMPORTANT!!!!)
            temp.a = a + c.a;
            temp.b = b + c.b;
            return temp;
        }
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



int main () {
    // c1 is an Object (Not a variable)    
    Complex c1, c2, c3; 
    // c1 is the caller object, rest is member function
    c3 = c1.add(c2);
    c1.set_data(3, 4);


    // Each object of Account class gets it balance variable
    // But all of them have access to only one roi (Class Variable) 
    Account a1, a2;
    // Account::roi = 4.5; This could have been done if roi was not private
    // We thus used the instance member function of the account class using an object to set roi
    a1.setRoi(4.5f);
    // But roi exists even is object is not created, then how can we access it without using object and roi being private
    // We use a static member function, which can be called without an object
    Account::setRoi(4.5f);
}