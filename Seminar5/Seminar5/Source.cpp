#include<iostream>
#include<string>

using namespace std;

enum tipContBancar {
	debit = 1,
	credit = 2
};

class contBancar {
private:
	const string iban;
	int sold;
	tipContBancar tipCont;
	static int nrConturiBancare;

public:
	contBancar() : iban("")
	{
		this->sold = 0;
		this->tipCont = tipContBancar::debit;
		cout << "Constructorul implicit a fost apelat" << endl;
		nrConturiBancare++;
	}

	contBancar(string _iban, int _sold, tipContBancar _tipCont) : iban(_iban)
	{
		this->sold = _sold;
		this->tipCont = _tipCont;
		cout << "Constructorul cu parametrii a fost apelat" << endl;
		nrConturiBancare++;
	}

	contBancar(const contBancar& c) : iban(c.iban), sold(c.sold), tipCont(c.tipCont)
	{
		//this->iban = c.iban;
		//this->sold = c.sold;
		//this->tipCont = c.tipCont;

		cout << "Constructor de copiere a fost apelat" << endl;
		nrConturiBancare++;

	}

	int getsold()
	{
		return sold;
	}
	void setsold(int s)
	{
		this->sold = s;
	}

	static int getNrConturiCreate()
	{
		return nrConturiBancare;
	}

	void afiseazaDetaliiCont()
	{
		cout << "IBAN = " << iban << endl;
		cout << "Sold = " << sold << endl;
		if (tipCont == tipContBancar::debit)
			cout << "TipCont = Debit" << endl;
		if (tipCont == tipContBancar::credit)
			cout << "TipCont = Credit" << endl;
	}

	~contBancar()
	{
		cout << "Destructorul clasei a fost apelat" << endl;
		nrConturiBancare--;
	}
};

int contBancar::nrConturiBancare = 0;

void test(contBancar c)
{
	c.setsold(100);
	cout << c.getsold() << endl;

}
int main()
{
	cout << "Seminar 5" << endl;

	contBancar c1;
	contBancar c2("RO123", 10, tipContBancar::credit);
	c1.afiseazaDetaliiCont();
	c2.afiseazaDetaliiCont();

	cout << "================================" << endl;

	contBancar c3 = c2;

	test(c3);
	test(c3);
	test(c3);
	test(c3);
	test(c3);
	c3.afiseazaDetaliiCont();


	cout << "================================" << endl;

	contBancar* pointerToC3 = &c3;

	pointerToC3->afiseazaDetaliiCont();

	contBancar* pointerToC4 = new contBancar("RO12345", 123, tipContBancar::credit);

	pointerToC4->afiseazaDetaliiCont();

	cout << "================================" << endl;

	delete pointerToC4;

	cout << contBancar::getNrConturiCreate() << endl;

	return 0;
}