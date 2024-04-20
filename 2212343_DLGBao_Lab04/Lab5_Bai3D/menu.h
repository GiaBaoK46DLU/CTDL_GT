void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, LIST& l);

void XuatMenu()
{
	cout << "================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n===================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap so de chon chuc nang tuong ung: ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LIST& l)
{
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu";
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim x Co/Khong?\n";
		break;
	}
}