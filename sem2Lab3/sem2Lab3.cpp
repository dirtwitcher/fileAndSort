// sem2Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void _tmain(int argc, _TCHAR* argv[])
{
	ifstream f("input.txt");
	int x = 0;
	while (!f.eof())
	{
		if (f.get() == '\n')
			x++;
	}
	f.clear();    
	f.seekg(0, f.beg); // перемещает текущую позицию чтения на pos байтов, считая от одной из трех позиций, определяемых параметром seek_dir: ios::beg (от начала файла), ios::cur (от текущей позиции), ios::end (от конца файла); 

	int *a = new int[x];

	for (int i = 0; i < x; i++)
	{
		f >> a[i];
		cout << a[i] << endl;
	}
	f.close();

	cout << "After sort: " << endl;
	// sortirovka viborom
		int j = 0;
		int tmp = 0;
		for (int i = 0; i<x; i++){
			j = i;
			for (int k = i; k<x; k++){
				if (a[j]>a[k]){
					j = k;
				}
			}
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	
		for (int i = 0; i < x; i++)
		{
			cout << a[i] << endl;
		}

		ofstream ff("output.txt");
		for (int i = 0; i < x; i++)
		{
			ff << a[i] << endl;
		}
		ff.clear();
		ff.close();
		delete a;

	system("pause");
}

