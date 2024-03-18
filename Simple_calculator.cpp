#include <iostream>
using namespace std;

class temp
{
public:
    int a, b, c;
    char op;

    void getvalue1();
    void getvalue2();
    void getop();

    void sub();
    void add();
    void mul();
    void div();

} obj;

int main()
{
    obj.getvalue1();
    while (1)
    {
        obj.getop();

        if (obj.op == '=')
        {
            cout << "Result : " << obj.a<<endl;
            break;
            return 1;
        }
        obj.getvalue2();

        if (obj.op == '+')
            obj.add();
        if (obj.op == '-')
            obj.sub();
        if (obj.op == '*')
            obj.mul();
        if (obj.op == '/')
            obj.div();
    }
    return 0;
}
void temp ::getvalue1()
{
    cout << "Enter the Value : ";
    cin >> a;
}
void temp ::getvalue2()
{
    cout << "Enter the Value : ";
    cin >> b;
}
void temp ::getop()
{
    cout << "Enter the Operator : ";
    cin >> op;
}
void temp ::add()
{
    c = a + b;
    cout << a << " + " << b << " ::  " << c << endl;
    a = c;
    b = 0;
}
void temp ::sub()
{
    c = a - b;
    cout << a << " - " << b << " ::  " << c << endl;
    a = c;
    b = 0;
}
void temp ::mul()
{
    c = a * b;
    cout << a << " * " << b << " ::  " << c << endl;
    a = c;
    b = 0;
}
void temp ::div()
{
    c = a / b;
    cout << a << " / " << b << " ::  " << c << endl;
    a = c;
    b = 0;
}