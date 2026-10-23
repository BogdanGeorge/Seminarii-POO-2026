#include<iostream>
#include<string>
using namespace std;

enum Formadeinvatamant {
	CuFrecventa = 100,
	CuFrecventaRedusa
};

class Student {
public:
	string nume;
	string facultate;
	int an = 0;
	Formadeinvatamant formadeinvatamant = Formadeinvatamant::CuFrecventa;
	Student()
	{
		this->nume = "";
		this->facultate = "";
		this->an = 0;
		this->formadeinvatamant = Formadeinvatamant::CuFrecventa;


		cout << "Constructorul implicit a fost apelat" << endl;
	}

	Student(string nume, string facultate, int an, Formadeinvatamant formaDeInvatamant)
	{
		this->nume = nume;
		this->facultate = facultate;
		this->an = an;
		this->formadeinvatamant = formaDeInvatamant;
		cout << "Constructorul cu parametri a fost apelat" << endl;
	}




	void seteazaNume(string nume)
	{
		this->nume = nume;
	}

	void afisare()
	{
		//cout << (*this).nume << endl;
		//cout << (*this).facultate << endl;
		//cout << (*this).an << endl;

		//cout << nume << endl;
		//cout << facultate << endl;
		//cout << an << endl;

		cout << this->nume << endl;
		cout << this->facultate << endl;
		cout << this->an << endl;
		if (this->formadeinvatamant == Formadeinvatamant::CuFrecventa)
		{
			cout << "Forma de invatamant cu frecventa" << endl;
		}
		else {
			cout << "Forma de invatamant cu  frecventa redusa" << endl;
		}
	}
};

//
//
//void citire(Student& s)
//{
//	cout << "Nume:";
//	cin >> s.nume;
//
//	cout << "Facultate:";
//	cin >> s.facultate;
//
//	cout << "Anul de studiu:";
//	cin >> s.an;
//
//}

int main()
{
	Student s1("Bogdan", "CSIE", 2, Formadeinvatamant::CuFrecventa);
	//s1.nume = "Bogdan";
	//s1.facultate = "CSIE";
	//s1.an = 2;
	s1.afisare();

	Student s2("Razvan", "EAM", 3, Formadeinvatamant::CuFrecventaRedusa);
	//s2.nume = "Razvan";
	//s2.facultate = "EAM";
	//s2.an = 3;
	s2.afisare();

	//Student sArray[2];
	//sArray[0] = s1;
	//sArray[1] = s2;


	return 0;
}