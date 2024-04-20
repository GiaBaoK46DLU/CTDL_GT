void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, LIST& l, int& n);

void XuatMenu()
{
	cout << "==========CHON CHUC NANG==========" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "1. Nhap file" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Dem ho Nguyen co trong danh sach" << endl;
	cout << "4.Tinh trung binh luong va nam sinh\n";
	cout << "5.Dao nguoc danh sach nhan vien\n";
	cout << "6.Chen nut SV vao dau danh sach\n";
	cout << "7.Chen nut SV sau nut co ma so la LD15332\n";
	cout << "8.Xoa 1 nut co ma so la LD15332\n";
}

int ChonMenu(int soMenu)
{
	int chon;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap so tu 0 - " << soMenu << " de chon chuc nang: ";
		cin >> chon;
		if (0 <= chon && chon <= soMenu)
			break;
	}
	return chon;
}

void XuLyMenu(int menu, LIST& l,int& n)
{
	char filename[MAX];
	int kq, kq1;
	char f[MAX];
	nhanvien nv = { "LD99", "Nguyen", "Hoang", "Van", "Yen_Bai", 2003, 2800000 };
	NODE* p = new NODE;
	p = GetNode(nv);
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap file\n";
		do
		{
			cout << "Nhap tap tin ban muon tao: ";
			cin >> filename;
			kq = DocFile(filename, l);
			if (!kq)
				cout << "Khong doc duoc file\n";
		} while (!kq);
		cout << "Danh sach vua tao: \n";
		Xuat_DSNV(l);
		break;
	case 2:
		system("CLS");
		cout << "2. Xuat danh sach\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "Danh sach hien tai: \n";
		Xuat_DSNV(l);
		cout << "3. Dem ho Nguyen co trong danh sach: ";
		cin >> f;
		cout<<"So luong nhan vien co ten ho Nguyen:" << DemSoLuong(l, f);
		break;
	case 4:
		system("CLS");
		cout << "Danh sach hien tai: \n";
		Xuat_DSNV(l);
		cout << "\n4.Tinh trung binh luong: " << TrungBinhLuong(l);
		cout << "\n4.Tinh trung binh nam sinh: " << TrungBinhNamSinh(l);
		break;
	case 5:
		system("CLS");
		cout << "Danh sach hien tai: \n";
		Xuat_DSNV(l);
		cout << "5.Dao nguoc danh sach nhan vien\n";
		DaoNguocDanhSach(l);
		break;
	case 6:
		system("CLS");
		cout << "Danh sach hien tai: \n";
		Xuat_DSNV(l);
		cout << "6.Chen nut SV vao dau danh sach\n";
		ChenDauDS(l, p);
		Xuat_DSNV(l);
		break;
	case 7:
		system("CLS");
		cout << "Danh sach hien tai: \n";
		Xuat_DSNV(l);
		cout << "7.Chen nut SV sau nut co ma so la LD15332\n";
		break;
	case 8:
		system("CLS");
		cout << "Danh sach hien tai: \n";
		Xuat_DSNV(l);
		cout << "8.Xoa 1 nut co ma so la LD15332\n";
		break;
	}
}