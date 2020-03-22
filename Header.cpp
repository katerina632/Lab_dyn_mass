#include "Header.h"
#include<ctime>
#include<iostream>
#include"windows.h"

using namespace std;

//a) функція створення динамічного масиву вказаного розміру;

int* createArr(int size)
{	
	int* arr = new int[size];
	return arr;
}

//b) ф - ція заповнення випадковими числами;
void fillArr(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		arr[i]  = rand() % 21;		
	}
}

//c) виводу масиву на консоль;
void ShowArr(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//d) доповнення масиву одним елементом; функція отримує адресу масиву, розмір та елемент для доповнення
int* addElement(int*& arr, int& size, int& value)
{
	int* newArr = new int[size + 1];
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		newArr[size] = value;
		size++;
		delete[] arr;
		arr = newArr;
		return newArr;
}

//e) видалення елемента за вказаною позицією;
int* Del_elem(int*& arr, int& size, int& poz)
{	--size;
		int* newArr = new int[size];
		for (int i = 0; i < size; i++) {
			if (i < poz - 1)
				newArr[i] = arr[i];
			else
				newArr[i] = arr[i + 1];
		}
		delete[]arr;
		arr = newArr;
		return newArr;
}

//f) вставка нового елемента у довільну допустиму позицію у масиві;
int* Add_poz_elem(int*& arr, int& size, int& poz, int& newElement)
{	size++;
		int* newArr = new int[size];
		for (int i = 0; i < size; i++) {
			if (i == poz - 1)
				newArr[i] = newElement;
			else if (i<poz)
				newArr[i] = arr[i];
			else{
				newArr[i] = arr[i-1];
			}
		}
		delete[]arr;
		arr = newArr;
		return newArr;
}

//*g) вставки блоку елементів(блок елементів записаний у динамічний одновимірний масив)
int* Add_mass_elem(int*& arr, int& size, int*& blokElem, int& size2)
{
	int* newArr = new int[size += size2];
		for (int i = 0, j = 0; i < size; i++) {
			if (i >= size - size2) {
				newArr[i] = blokElem[j];
				j++;
			}
			else
				newArr[i] = arr[i];
		}
		delete[]arr;
		arr = newArr;
		return newArr;
}

//*h) видалення блоку елементів(кількість елементів та позиція, з якої починається 
int* Del_mass_elem(int*& arr, int& size, int& poz1, int& poz2)
{
	int num = poz2 - poz1 + 1;
		size -= num;
		int* newArr = new int[size];
	
		for (int i = 0; i < size; i++) {
			if (i < poz1 - 1)
				newArr[i] = arr[i];
			else
				newArr[i] = arr[i + num];
		}
		delete[]arr;
		arr = newArr;
		return newArr;
}

//k)Зробити функцію по знаходженню максимально і мінімального
void Min_Max(int* arr, int size, int* max, int* min)
{
	*max = arr[0];
	 *min = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > *max) {
				*max = arr[i];
			}
			if (arr[i] < * min) {
				*min = arr[i];
			}
		}
		cout << endl;
}
//l)Зробити функцію по знаходженню середнього арефметичного
void Serednje(int* arr, int size, float* ser)
{
	float sum = 0;
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		*ser = sum / size;
		cout << endl;
}

//m)Зробити функцію для виводу оберненого масиву
void zvorotnij(int* arr, int size)
{
	for (int i = size - 1; i >= 0; i--) {
				cout << arr[i] << " ";
			}
			cout << endl << endl;
}



