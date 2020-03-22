#pragma once
int* createArr(int size);

void fillArr(int* arr, int size);

void ShowArr(int* arr, int size);

int* addElement(int*& arr, int& size, int& value);

int* Del_elem(int*& arr, int& size, int& poz);

int* Add_poz_elem(int*& arr, int& size, int& poz, int& newElement);

int* Add_mass_elem(int*& arr, int& size, int*& blokElem, int& size2); 

int* Del_mass_elem(int*& arr, int& size, int& poz1, int& poz2);

void Min_Max(int* arr, int size, int* max, int* min);

void Serednje(int* arr, int size, float* ser);

void zvorotnij(int* arr, int size);