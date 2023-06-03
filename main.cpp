#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
void show(T* ptr, int size) {
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << " ";
	}
	//cout << "----------------------------" << endl;
}

void show_char(char** ptr, int size) {
	for (int i = 0; i < size; i++) {
		cout << &ptr[i] << endl;
	}
	cout << "----------------------------" << endl;
}

template <typename T>
int difference(T* ptr, int size)
{
	//cout << "Исходный массив: ";
	//show(ptr, size);
	T min = *ptr, max = *ptr;
	for (int i = 0; i < size; i++)
	{
		if (*ptr > max)
			max = *ptr;
		if (*ptr < min)
			min = *ptr;
		ptr++;
	}
	cout << "Разница: " << max - min << endl;
	return max - min;
}

int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));
	// Рандомизация размера массивов
	int size = 50 + rand() % (100 - 50 + 1);

	int* int_mass = new int[size];
	char* char_mass = new char[size];
	float* float_mass = new float[size];
	double* double_mass = new double[size];
	char** charr_mass = new char* [size];

	// Заполнение массивов
	for (int i = 0; i < size; i++) {
		int_mass[i] = 50 + rand() % (100 - 50 + 1);
		char_mass[i] = rand() % (100-50+1) + 50;
		float_mass[i] = (float(rand()) / RAND_MAX * (100 - 50 + 1) + 50) / (float(rand()) / RAND_MAX * (100 - 50) + 1); 
		double_mass[i] = (double(rand()) / RAND_MAX * (100 - 50 + 1) + 50) / (double(rand()) / RAND_MAX*(100 - 50) + 1);
		charr_mass[i] = &char_mass[i];
	}

	int callback;
	while (true) {
		system("cls");
		cout << "Меню выбора типа элементов массива:" << endl
			<< "(1) int" << endl
			<< "(2) char" << endl
			<< "(3) float" << endl
			<< "(4) double" << endl
			<< "(5) char*" << endl
			<< "(0) Выход" << endl
			<< "Ваш выбор: ";
		cin >> callback;
		try
		{
			if (!(callback >= 0 && callback <= 5))
			{
				throw "Ошибка: Не верный выбор в меню";
			}
		}
		catch (const char* i)
		{
			cout << i << endl;
		}
		switch (callback) {
		case 1:
			difference(int_mass, size); show(int_mass, size);
			break;
		case 2:
			difference(char_mass, size); show(char_mass, size);
			break;
		case 3:
			difference(float_mass, size); show(float_mass, size);
			break;
		case 4:
			difference(double_mass, size); show(double_mass, size);
			break;
		case 5:
			difference(charr_mass, size); show_char(charr_mass, size);
			break;
		case 0:
			return 0;
		}
		system("pause");
	}
	
	return 0;
}