// Prakex5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class SmartArray {
public:
	int lenght = 0;
	int* array = new int;


	void add(int num) {																		// Функция добавляющая в конец массива значение
		int *newArray = new int[lenght + 1];												// Т.к в массиве нельзя менять длинну, нам необходимо создать новый с длинной на 1 больше
		for (int i = 0; i < lenght; i++) {													// Заполняем массив прежними значениями
			newArray[i] = array[i];
		}
		newArray[lenght] = num;																// Добавляем в конец значение
		lenght++;
		delete[] array;
		array = newArray;
	}
	void displayArray() {
		for (int i = 0; i < lenght; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	void displayLenght() {
		cout << "Текущие количество элементов: " << lenght << endl;
	}
	void displayNum(int i) {
		cout << "Элемент под индексом " << i << ": " << array[i] << endl;
	}
	void changeNum(int i, int new_num) {
		array[i] = new_num;
	}
	void deleteNum(int i) {																	// Фукнция удаляющая значение в массиве
		int* newArray = new int[lenght - 1];												// По той же причине создаем новый с длинной на 1 меньше
		int flag = 0;
		for (int j = 0; j < lenght; j++) {
			if (j == i) {																	// Заполняем массив данными пропуская то значение, которое нам необходимо удалить
				flag++;
				continue;
			}
			newArray[j - flag] = array[j];
		}
		delete array;
		lenght--;
		array = newArray;
	}
	void insertNum(int i, int num) {														// Фукнция вставляющая элемент по индексу
		int* newArray = new int[lenght + 1];												// Также создаем новый с длинной на 1 больше
		int flag = 0;
		for (int j = 0; j < lenght + 1; j++) {												// Заполняем массив данными, записывая новое значение по индексу и сдвигая все после
			if (j == i) {
				flag++;
				newArray[i] = num;
				continue;
			}
			newArray[j] = array[j - flag];
		}
		delete array;
		lenght++;
		array = newArray;
	}

};
int main()
{
	setlocale(LC_ALL, "rus");
	SmartArray ar;
	ar.add(5);
	ar.add(7);
	ar.add(8);
	ar.displayLenght();
	ar.displayNum(2);
	ar.changeNum(2, 19);
	ar.displayNum(2);
	ar.displayArray();
	ar.deleteNum(1);
	ar.displayArray();
	ar.add(10);
	ar.insertNum(1, 7);
	ar.displayArray();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
