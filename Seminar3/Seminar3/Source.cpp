#include<iostream>
#include<string>

using namespace std;

struct Matrix {
	int** matrix;
	int rows;
	int columns;


	void printMatrix(Matrix matrix) {
		for (int i = matrix.rows - 1; i >= 0; i--)
		{
			for (int j = matrix.columns - 1; j >= 0; j--) {
				cout << matrix.matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

char* readFromConsole()
{
	char charArr[100];
	cout << "Introduceti textul: ";
	cin.getline(charArr, 100);

	char* text = new char[strlen(charArr) + 1];
	strcpy_s(text, strlen(charArr) + 1, charArr);

	return text;
}

char* readFromConsoleUsingString()
{
	string str;
	cout << "Introduceti textul: ";
	getline(cin, str);

	char* text = new char[str.length() + 1];
	strcpy_s(text, str.length() + 1, str.c_str());

	return text;
}

Matrix createMatrix()
{
	Matrix m;
	cout << "Introduceti numarul de randuri: ";
	cin >> m.rows;
	cout << "Introduceti numarul de coloane: ";
	cin >> m.columns;

	m.matrix = new int* [m.rows];
	for (int i = 0; i < m.rows; i++)
	{
		m.matrix[i] = new int[m.columns];
	}

	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			cout << "matrix[" << i << "][" << j << "]=";
			cin >> m.matrix[i][j];
		}
	}

	return m;
}

int main()
{
	cout << "Introduceti un numar: ";
	int a;
	cin >> a;

	cin.ignore();

	char* text = readFromConsole();
	cout << text << endl;
	delete[] text;
	text = nullptr;

	text = readFromConsoleUsingString();

	cout << text << endl;
	delete[] text;
	text = nullptr;

	Matrix matrix = createMatrix();
	matrix.printMatrix(matrix);

	for (int i = 0; i < matrix.rows; i++)
	{
		delete[] matrix.matrix[i];
	}

	delete[] matrix.matrix;
	matrix.matrix = nullptr;
	matrix.rows = 0;
	matrix.columns = 0;

	return 0;
}