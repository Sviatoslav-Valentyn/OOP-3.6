#include <iostream>
#include <Windows.h>
using namespace std;
class B1
{
	int b1;
public:
	B1()
		: b1(0)
	{ }
	B1(int x)
	{
		b1 = x;
	}
	void show_B1()
	{
		cout << "class B1:" << endl;
		cout << "show_B1()" << endl
			<< "B1::b = " << b1 << endl << endl;
	}
	int get_b1() const
	{
		return b1;
	}
};

class D1 : public B1
{
	int d1;
public:
	D1(int x, int y)
		:B1(y)
	{
		d1 = x;
	}
	void show_D1()
	{
		cout << "class D1:" << endl;
		show_B1();
		cout << "show_D1()" << endl
			<< "D1::d1 = " << d1 << endl << endl;
	}
};

class D2 : private B1
{
	int d2;
	public:
			D2(int x, int y)
				:B1(y)
			{
				d2 = x;
			}
			void show_D2()
			{
				cout << "class D2:" << endl;
				show_B1();
				cout << "show_D2()" << endl
					<< "D2::d2 = " << d2 << endl << endl;
			}
};
class D3 : public D1, public D2 
{
	int d3;
	public:
			D3(int	x, int y, int z, int i, int j)
				: D1(y,z), D2(i,j)
			{
				d3 = x;
			}
			void show_D3()
			{
				cout << "class D3:" << endl;
				show_D1();
				show_D2();
				cout << "show_D3()" << endl
					<< "D3::d3 = " << d3 << endl << endl;
			}
};
class B2 : public D3
{
	int b2;
	public:
		B2(int	x, int y, int z, int i, int j, int q)
			:D3(x,y,z,i,q)
		{
			b2 = x;
		}
		void show_B2()
		{
			cout << "class B2:" << endl;
			show_D3();
			cout << "show_B2()" << endl
				<< "B2::b2 = " << b2 << endl << endl;
		}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	B1 o0(777);
	cout << "B o0(777);" << endl;
	cout << "sizeof(B1) = " << sizeof(B1) << endl;
	cout << endl << "Ієрархія класу B1: " << endl;
	o0.show_B1();
	D1 o1(111, 222);
	cout << "D1 o1(111, 222);" << endl;
	cout << "sizeof(D1) = " << sizeof(D1) << endl;
	cout << endl << "Ієрархія класу D1: " << endl;
	o1.show_D1();
	D2 o2(1000, 2000);
	cout << "D2 o2(1000, 2000);" << endl;
	cout << "sizeof(D2) = " << sizeof(D2) << endl;
	cout << endl << "Ієрархія класу D2: " << endl;
	o2.show_D2();
	D3 o3(100, 200, 300, 400, 500);
	cout << "D3 o3(100, 200, 300, 400, 500);" << endl;
	cout << "sizeof(D3) = " << sizeof(D3) << endl;
	cout << endl << "Ієрархія класу D3: " << endl;
	o3.show_D3();
	B2 o4(1, 2,3,4,5,6);
	cout << "B2 o4(1, 2, 3, 4, 5);" << endl;
	cout << "sizeof(B2) = " << sizeof(B2) << endl;
	cout << endl << "Ієрархія класу B2: " << endl;
	o4.show_B2();
	return 0;
}