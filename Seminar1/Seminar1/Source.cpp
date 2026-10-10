#include<iostream>
using namespace std;

namespace MyCalculator
{
	int suma(int a, int b)
	{
		return a + b;
	}

	float impartire(int a, int b)
	{

		if (b != 0)
			return (float)a / (float)b;
		else return 0;

	}
}
void interschimbare(int a, int b)
{
	int aux = a;
	a = b;
	b = aux;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}

// Se interschimba doar valorile locale ale pointerilor a si b.
// Adresele variabilelor din main nu se modifica, iar valorile stocate la acele adrese raman neschimbate.
// 
//void InterschimbareCuPointeri(int* a, int* b)
//{
//	int* aux = a;
//	a = b;
//	b = aux;
//	cout << "InterschimbareCuPointeri a=" << *a << endl;
//	cout << "InterschimbareCuPointeri b=" << *b << endl;
//}


void InterschimbareCuPointeri(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
	cout << "InterschimbareCuPointeri a=" << *a << endl;
	cout << "InterschimbareCuPointeri b=" << *b << endl;
}


void InterschimbareCuReferinta(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
	cout << "InterschimbareCuReferinta a=" << a << endl;
	cout << "InterschimbareCuReferinta b=" << b << endl;
}

int main()
{
	int a = 0;
	int b = 1;

	int sum = MyCalculator::suma(a, b);

	cout << sum;
	cout << endl;
	float imp = MyCalculator::impartire(b, a);
	float impr = MyCalculator::impartire(1, 2);


	cout << "rezultatul impartirii este: " << impr << endl;
	interschimbare(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	int* PointerToa = &a;
	int* PointerTob = &b;

	InterschimbareCuPointeri(PointerToa, PointerTob);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	cout << "PointerToa=" << *PointerToa << endl;
	cout << "PointerTob=" << *PointerTob << endl;

	InterschimbareCuReferinta(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

}