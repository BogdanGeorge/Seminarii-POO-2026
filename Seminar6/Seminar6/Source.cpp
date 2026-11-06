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
	int* tranzactii;
	int nrtranzactii;
	tipContBancar tipCont;
	static int nrConturiBancare;

public:
	contBancar() : iban("")
	{
		this->tranzactii = nullptr;
		this->nrtranzactii = 0;
		this->tipCont = tipContBancar::debit;
		cout << "Constructorul implicit a fost apelat" << endl;
		nrConturiBancare++;
	}

	contBancar(string _iban, tipContBancar _tipCont, int* tranzactii, int nrtranzactii) : iban(_iban)
	{
		// this->tranzactii = tranzactii; -> copie superficiala
		if (tranzactii != nullptr && nrtranzactii > 0)
		{
			this->nrtranzactii = nrtranzactii;
			this->tranzactii = new int[nrtranzactii];
			for (int i = 0; i < nrtranzactii; i++) {
				this->tranzactii[i] = tranzactii[i];
			}
		}
		else
		{
			this->nrtranzactii = 0;
			this->tranzactii = nullptr;
		}

		this->tipCont = _tipCont;
		cout << "Constructorul cu parametrii a fost apelat" << endl;
		nrConturiBancare++;
	}

	contBancar(const contBancar& c) : 
		iban(c.iban)
		//tranzactii(c.tranzactii), -> copie superficiala
	{
		this->tipCont = c.tipCont;
		cout << "Constructor de copiere a fost apelat" << endl;
		if (c.tranzactii != nullptr && c.nrtranzactii > 0) {
			this->nrtranzactii = c.nrtranzactii;
			this->tranzactii = new int[c.nrtranzactii];
			for (int i = 0; i < c.nrtranzactii; i++) {
				this->tranzactii[i] = c.tranzactii[i];
			}
		}
		else
		{
			this->tranzactii = nullptr;
			this->nrtranzactii = 0;
		}
		nrConturiBancare++;

	}

	contBancar& operator=(const contBancar& c)
	{
		if (this == &c)
		{
			return *this;
		}

		this->tipCont = c.tipCont;

		if (this->tranzactii != nullptr)
		{
			delete[] this->tranzactii;
			this->tranzactii = nullptr;
			this->nrtranzactii = 0;
		}

		if (c.tranzactii != nullptr && c.nrtranzactii > 0)
		{
			this->nrtranzactii = c.nrtranzactii;
			this->tranzactii = new int[c.nrtranzactii];
			for (int i = 0; i < c.nrtranzactii; i++)
			{
				this->tranzactii[i] = c.tranzactii[i];
			}
		}
		else
		{
			this->nrtranzactii = 0;
			this->tranzactii = nullptr;
		}

		return *this;
	}

	int* getTranzactii()
	{
		if (this->nrtranzactii > 0 && this->tranzactii != nullptr)
		{
			int* copy = new int[this->nrtranzactii];
			for (int i = 0; i < this->nrtranzactii; i++)
			{
				copy[i] = this->tranzactii[i];
			}

			return copy;
		}
		else {
			return nullptr;
		}
	}

	void setTranzactii(int* tranzactii, int nrTranzactii)
	{
		if (this->tranzactii != nullptr)
		{
			delete[] this->tranzactii;
			this->tranzactii = nullptr;
			this->nrtranzactii = 0;
		}

		if (nrTranzactii > 0 && tranzactii != nullptr)
		{
			this->nrtranzactii = nrTranzactii;
			this->tranzactii = new int[nrTranzactii];
			for (int i = 0; i < nrTranzactii; i++)
			{
				this->tranzactii[i] = tranzactii[i];
			}
		}
		else {
			this->tranzactii = nullptr;
			this->nrtranzactii = 0;
		}


	}

	int getsold()
	{
		int sold = 0;
		for (int i = 0; i < nrtranzactii; i++) {
			sold = sold + tranzactii[i];
		}
		return sold;
	}

	static int getNrConturiCreate()
	{
		return nrConturiBancare;
	}

	void afiseazaDetaliiCont()
	{
		cout << "IBAN = " << iban << endl;
		cout << "Sold = " << getsold() << endl;
		for (int i = 0; i < nrtranzactii; i++) {
			cout << "Tranzactia " << i << " = " << tranzactii[i] << endl;
		}
		if (tipCont == tipContBancar::debit)
			cout << "TipCont = Debit" << endl;
		if (tipCont == tipContBancar::credit)
			cout << "TipCont = Credit" << endl;
	}

	void seteazaTranzactie(int pozitia, int valoare) {
		if (pozitia < this->nrtranzactii && pozitia >= 0) {
			this->tranzactii[pozitia] = valoare;
		}
	}

	~contBancar()
	{
		if (this->tranzactii != nullptr)
		{
			delete[] tranzactii;
			tranzactii = nullptr;
			nrtranzactii = 0;
		}

		cout << "Destructorul clasei a fost apelat" << endl;
		nrConturiBancare--;
	}
};


// PROPUNERE Exercitiu suplimentar

class Student
{
	char* nume;
	int anStudiu;
	int numarAbsente;
	// Adaugati un membru constant ( ex: int numarMatricol )
	// Adaugati un membru static ( ex: int nrMaximAbsente )

public:
	Student(const char* nume, int anStudiu, int numarAbsente)
	{
		this->anStudiu = anStudiu;
		this->numarAbsente = numarAbsente;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	// Constructor implicit
	// Modificati constructor cu parametrii sa initializeze toti membrii clasei
	// Principiul celor 3
	// getter + setter
	// adaugati o metoda care verifica daca studentul poate intra in examen ( are mai putine absente decat numarul maxim permis )
};

int contBancar::nrConturiBancare = 0;

int main()
{
	int tranzactii[2] = { 1,2 };
	contBancar cont1("RO123", debit, tranzactii, 2);
	tranzactii[0] = 100;
	cont1.afiseazaDetaliiCont();
	cout << "----------------------------------" << endl;

	contBancar cont2 = cont1;
	cont1.seteazaTranzactie(0, 5);
	cont1.afiseazaDetaliiCont();
	cont2.afiseazaDetaliiCont();


	cout << "----------------------------------" << endl;

	contBancar cont3("Ro123456", tipContBancar::credit, tranzactii, 2);

	cont3 = cont2 = cont1;


	cont2.seteazaTranzactie(0, 1234);

	cont3.afiseazaDetaliiCont();

	cout << "----------------------------------" << endl;

	cont3 = cont3;
	cont3.afiseazaDetaliiCont();


	cout << "----------------------------------" << endl;

	int* tranzactii2 = cont3.getTranzactii();

	delete[] tranzactii2;
	tranzactii2 = nullptr;


	cout << "----------------------------------" << endl;

	Student s("Bogdan", 2, 0);

	return 0;
}