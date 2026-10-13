#include <iostream>

using namespace std;

int* initVector(int size)
{
	int* vector = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "vector[" << i << "]=";
		cin >> vector[i];
	}

	return vector;
}

void printVector(int* vector, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "vector[" << i << "]=" << vector[i];
	}

	cout << endl;
}


char* readFromConsole()
{
	char charArry[100];

	cout << "Introduceti textul: ";
	cin >> charArry;

	cout << charArry << endl;

	char* newCharArr = new char[strlen(charArry) + 1];
	strcpy_s(newCharArr, strlen(charArry) + 1, charArry);

	return newCharArr;
}


int main()
{
	cout << "Introduceri dimensiunea vectorului: ";

	int size = 0;
	cin >> size;

	int* vector = initVector(size);

	int v[] = { 1,2,3,4 };

	cout << sizeof(v) << endl;

	cout << sizeof(vector) << endl;

	printVector(vector, size);

	delete[] vector;
	vector = nullptr;



	char* charArr = readFromConsole();

	cout << charArr << endl;

	delete[] charArr;
	charArr = nullptr;

	return 0;
}