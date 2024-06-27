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

class Complex {
    private:
        int a, b;
    public:
        void set_data (int x, int y) {
            a = x; b = y;
        }
        void show_data () {
            cout << "a = " << a << " b = " << b << endl;
        }
        
        // Friend Function
        friend void friend_func(Complex);

        // Overloading of Binary Operator
        friend Complex operator + (Complex, Complex);

        // Overloading of Unary Operator
        friend Complex operator - (Complex);

        // Overloading of Insertion (<<) and Extraction (>>) Operator
        // Return type of (<<) should be the same as the class of which (<<) is a part of, i.e ostream
        friend ostream& operator << (ostream&, Complex);
        // Return type of (>>) should be the same as the class of which (>>) is a part of, i.e istream
        // Here Complex will also be by reference, because we are changing the actual arguments
        friend istream& operator >> (istream&, Complex&);
};

Complex operator + (Complex X, Complex Y) {
    Complex temp;
    temp.a = X.a + Y.a;
    temp.b = X.b + Y.b;
    return temp;
}

Complex operator - (Complex X) {
    Complex temp;
    temp.a = -X.a;
    temp.b = -X.b;
    return temp;
}

ostream& operator << (ostream &dout, Complex C) {
    dout << "a = " << C.a << " b = " << C.b << "\n";
    return dout;
}

istream& operator >> (istream &din, Complex &C) {
    din >> C.a >> C.b;
    return din;
}

/*
Friend Function:
=> It is not a member function of a class to which it is a friend
=> Friend function is declared in the class with the friend keyword
=> It must be defined outside the class to which it is friend

=> It can access any member of the class to which it is friend
=> Friend function cannot access members of the class directly
=> It has no caller object
=> It should not be defined with membership label

=> ****Friend function can become friend to more than one class
=> It does not matter, whether to declare friend function in private or public: Since it is not a member function

Essential features of Friend Function:
1. Used when one wants to access members variables of multiple different classes at the same time
2. Number of arguments passed in a member function = X
   ****Number of arguments passed in this member function, when it is defined as a FRIEND function = X + 1
3. We can Overload Insertion and Extraction Operators as well using friend function
    Why friend function? Because we want access to cin, cout objects and our custom class object variables at the same time
*/
void friend_func (Complex c) {
    // Since It cannot act on any caller object, thus it does not have access to instance member variables
    // So we pass an object to get access to these variables
    cout << "Sum is " << c.a + c.b << endl;
}
class B;
class A {
    private:
        int a;
    public:
        void setData (int y) {a = y;}
        // Since we are using A, B before Definition of Class B: We need to define it earlier
        friend void func (A, B);
};

class B {
    private:
        int b;
    public:
        void setData (int y) {b = y;}
        friend void func (A, B);
};
void func (A o1, B o2) {
    cout << "Sum is " << o1.a + o2.b << "\n";
}


/*
Friend Class:
=> Member function of one class can become friend to another class
*/
class C {
    public:
        void fun() {}
        void foo () {}
};
class D {
    // We add a scope resolution operator, to specify that member function fun of A is a friend to B Class
    // Without this resolution, the fun function will be treated as the one declared outside below
    // friend void A::fun();
    // friend void A::foo();

    // If we want to friend all function of A in Class B
    // Better Method => We friend the complete class
    friend class C;
};
void fun () {}


int main () {
    Complex c1, c2, c3;
    cin >> c1; // cin.operator>>(c1) as a member function, operator>>(cin, c1) as a friend function
    cout << c1; // cout.operator<<(c1) as a member function, operator<<(cout, c1) as a friend function
    c2.set_data(3, 4);
    // Unary Operator Overloaded as a Friend Function
    c3 = operator-(c2);
}