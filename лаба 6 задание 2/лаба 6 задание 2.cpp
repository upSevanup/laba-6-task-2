#include <iostream>
#include <clocale>

using namespace std;

/*
* Лабораторная работа 6. Поливцев Михаил, ИВТ-31. Задание 2 (со статическим выделением памяти).
* Индивидуальный вариант задания 16.
* Дана квадратная матрица A порядка M. Найти минимальный элемент для каждой ее диагонали, 
* параллельной главной (начиная с одноэлементной диагонали A1,M ).
*/

int main() {
	setlocale(LC_ALL, "ru");

	const int MAX_M = 10; 
	int array[MAX_M][MAX_M];
	int m;
	cout << "Введите порядок матрицы >> ";
	cin >> m;
	if (m > MAX_M || m < 1) {
		cout << "неверный ввод" << endl;
		return 1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << "Введите элемент матрицы >> ";
			cin >> array[i][j];
		}
	}

	cout << "\n-----------------------------------------------" << endl;
	// вывод матрицы для удобства
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n-----------------------------------------------" << endl;

	int res[MAX_M];
	int s = 0, n = 1;

	for (int i = m - 1; i >= 0; i--) {
		int iInd = i;
		for (int j = 0; j < n; j++) {
			res[s] = array[j][iInd];
			s++;
			iInd++;
		}
		n++;
		int min = res[0];
		for (int l = 1; l < s; l++) {
			if (res[l] < min) {
				min = res[l];
			}
		}
		cout << min << endl;
		s = 0;
	}

	n = m - 1;
	for (int i = 1; i < m; i++) {
		int iInd = i;
		for (int j = 0; j < n; j++) {
			res[s] = array[iInd][j];
			s++;
			iInd++;
		}
		n--;
		int min = res[0];
		for (int l = 1; l < s; l++) {
			if (res[l] < min) {
				min = res[l];
			}
		}
		cout << min << endl;
		s = 0;
	}
}