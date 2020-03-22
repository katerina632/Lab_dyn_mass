#include<iostream>
#include"windows.h"
#include<ctime>
#include "Header.h"

using namespace std;	


int main() {
	
	int value;
	int action = 0;
	float ser=0;
	int max = 0;
	int min = 0;
	int poz = 0;
	int newElement = 0;
	srand(time(0));
	int* arr;
	int* blokElem=0;
	int poz1, poz2;
	int size, size2;

	cout << "Vvedit' rozmir masyvu->_ ";
	cin >> size;
	cout << endl;

    arr=createArr(size);

	fillArr(arr, size);
	cout << "Vash masyv: ";
	ShowArr(arr, size);		

	do {
	cout << endl;
	cout << "1. Znajty MIN ta MAX elementy masyvu" << endl;
	cout << "2. Znajty serednje znachennja elementiv masyvu" << endl;
	cout << "3. Vyvesty obernenyj massyv" << endl;
	cout << "4. Dodaty novuj element d masyv" << endl;
	cout << "5. Vydalennja za vkazanoju pozucijeju" << endl;
	cout << "6. Vstavyty element u dovil'nu pozyciju" << endl;
	cout << "7. Vstavka bloka elementiv" << endl;
	cout << "8. Vydalennja bloku elementiv" << endl;
	cout << "9. Exit" << endl << endl;

	cout << "Vyberit' diju-> ";
	cin >> action;

	switch (action) {
	case 1:
		Min_Max(arr, size, &max, &min);
		cout << "MIN znachennja masyvu: " << min << "\nMAX znachennja masyvu: " << max << endl << endl;
		break;
	case 2:
		Serednje(arr, size, &ser);
		cout << "Serednje znachennja masyvu: " << ser << endl << endl;
		break;
	case 3:
		cout << endl;
		cout << "Obernenyj masyv do danogo: " ;
		zvorotnij(arr, size);
		break;
	case 4:
		cout << "Vvedit' znacennja novogo elementy masyvu->_ ";
		cin >> value;
		addElement(arr, size, value);
		cout << "Vash masyv: ";
	ShowArr(arr, size);

		break;
	case 5:
		cout << "Vvedit' nomer pozyciji->_ ";
		cin >> poz;
		if (poz<1 || poz > size) {
			cout << "Nepravul'na pozucija!" << endl;
		}
		Del_elem(arr, size, poz);
		cout << "Vash masyv: ";
		ShowArr(arr, size);
		break;
	case 6:
		cout << "Vvedit' novyj element->_ ";
		cin >> newElement;
		cout << "Vvedit' nomer pozyciji->_ ";
		cin >> poz;
		if (poz<1 || poz > size) {
			cout << "Nepravul'na pozucija!" << endl;
		}
		Add_poz_elem(arr, size, poz, newElement);
		cout << "Vash masyv: ";
		ShowArr(arr, size);
		break;
	case 7:
		cout << "Vvedit' kil'kist' elementiv, jaki hochete dodaty->_ ";
		cin >> size2;
		blokElem = new int[size2];
		for (int i = 0; i < size2; i++) {
			cout << "Vvedit' " << i + 1 << " element->_ ";
			cin >> blokElem[i];
		}
		Add_mass_elem(arr, size, blokElem, size2);		
		cout << "Vash masyv: ";
		ShowArr(arr, size);
		break;
	case 8:		
			cout << "Vvedit'pershu pozuciju->_ ";
			cin >> poz1;
			if (poz1<1 || poz1>size - 1) {
				cout << "Nepravul'na pozucija!" << endl;	
				break;
			}		
						
			cout << "Vvedit'drugu pozuciju->_ ";
			cin >> poz2;
			if (poz2< poz1 || poz2>size || poz2 < 2) {
				cout << "Nepravul'na pozucija!" << endl;	
				break;
			}
			
			Del_mass_elem(arr, size, poz1, poz2);
			cout << "Vash masyv: ";
			ShowArr(arr, size);
		break;
	case 9:
		cout << "Bye:)" << endl;
		break;
	default:
		cout << "Error!" << endl;
	}

} while (action != 9);

	delete[] arr;
	delete[] blokElem;
	
	system("pause");
	return 0;
}