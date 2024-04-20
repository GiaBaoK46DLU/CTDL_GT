void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ma sinh vien";
	cout << "\n4. Tim kiem theo ten-Xuat cac sinh vien cung ten";
	cout << "\n5. Tim kiem theo ho-Xuat cac sinh vien cung ho";
	cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc";
	cout << "\n7. Tim kiem theo lop-Xuat danh sach sinh vien trong lop";
	cout << "\n8. Tim kiem nhi phan theo tich luy (neu truong tich luy co thu tu)";
}

//Hàm ChonMenu
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

//Hàm Xử lý menu
void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	char maSV[10], ten[10], hoSV[10], lop[6];
	double dtb;
	int kq;
	int i;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach sinh vien";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach sinh vien\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim kiem theo ma sinh vien";
		Xuat_DSSV(a, n);
		cout << "\nNhap ma so sinh vien: ";
		cin >> maSV;
		cout << "\nSinh vien duoc tim kien la: \n";
		i = Tim_MaSo_DauTien(maSV, a, n);
		Xuat_SV(a[i]);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem theo ten--Xuat cac sinh vien cung ten\n";
		Xuat_DSSV(a, n);
		cout << "\nNhap ten sinh vien can tim: ";
		cin >> ten;
		Tim_TheoTen(ten, a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo ho--Xuat cac sinh vien cung ho\n";
		Xuat_DSSV(a, n);
		cout << "\nNhap ho sinh vien can tim: ";
		cin >> hoSV;
		Tim_TheoHo(hoSV, a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc\n";
		Xuat_DSSV(a, n);
		cout << "Diem trung binh cho truoc la: ";
		cin >> dtb;
		Tim_TheoDTB(dtb, a, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo lop--Xuat cac sinh vien thuoc lop\n";
		Xuat_DSSV(a, n);
		cout << "\nNhap lop can tim sinh vien: ";
		cin >> lop;
		Tim_TheoLop(lop, a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim kien nhi phan theo tich luy";
		Xuat_DSSV(a, n);
		TKNP_Theo_TichLuy(a, n);
		break;
	}
}