#include <string.h>
#include <iostream>       // std::cerr
#include <vector>

#include "mystl.h"
#include "MyString.h"
#include "MyStackImpl.h"

#define stop __asm nop

using namespace std;
using namespace myStl;


int main(int argc, char* argv[])
{
/*
	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);

	//Point pt1(1,2), pt2(-3,-4);
	//Swap(pt1, pt2);
*/

    //Testing history

    MyString s1("One"), s2("Two");
    Swap(s1, s2);


    MyStack<int, 5> stack;
    stack.push(1);

    int a1 = 5;
    stack.push(a1);

    while(!stack.empty())
    {
        cout << "stack.pop() = " << stack.pop() << endl;
    }

    if(stack.empty())
    {
        cout << "Stack is empty"<<endl;
    }

    vector<MyString> vector1(5);
    vector1.push_back(MyString("Two"));

    try
    {
        //for(int i = 0; i < 6; i++)
        //	stack1.pop();
    }
    catch (exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
    }

    MyStack<MyCircle, 5> stackCircle;

    for(int i = 0; i<5; i++)
        stackCircle.push(MyCircle(i,i+1,i+2));

    for(int i = 0; i<5; i++)
        cout << stackCircle.pop();

    MyCircle circle = MyCircle(0,0,0);
    circle.setX(11);
    cout << "x +y  = " << circle.getXY()<<endl;
//	cout << stack;
//	cout << stack1;

    return 0;
}

