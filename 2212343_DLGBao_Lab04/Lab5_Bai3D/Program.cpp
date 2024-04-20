#include <iostream>

#include <fstream>

#include <cstddef>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	LIST danhSach;

	int soMenu = 18,
		menu;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, danhSach);
		system("PAUSE");
	} while (menu > 0);
}