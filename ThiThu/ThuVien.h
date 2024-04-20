#define MAX 100

struct nhanvien
{
	char maNV[8];
	char hoNV[10];
	char tenLot[10];
	char ten[10];
	char diachi[12];
	int namSinh;
	double luong;
};

typedef nhanvien dulieu;

struct tagNode
{
	dulieu info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(dulieu x);
void CreatList(LIST& l);
int IsEmpty(LIST l);
void InsertHead(LIST& l, dulieu x);
int DocFile(char* filename, LIST& l);
void Xuat_DSNV(LIST& l);
void Xuat_NV(dulieu p);
void TieuDe();

NODE* GetNode(dulieu x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}


void InsertHead(LIST& l, dulieu x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
		return;
	}
	if (l.pHead == NULL) //DS rong
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead; //chen vao dau DS
		l.pHead = new_ele;
	}
}

void InsertTail(LIST& l, dulieu x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("CLS");
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

int DocFile(char* filename, LIST& l)
{
	dulieu x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(l);

	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoNV;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.diachi;
		in >> x.namSinh;
		in >> x.luong;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

void TieuDe()
{
	int i;
	cout << endl;
	cout << ":";
	for (i = 0; i < 62; i++)
	{
		cout << '=';

	}
	cout << "\n";
	cout << ':';
	cout << setiosflags(ios::left);
	cout << setw(10) << "Ma SV"
		<< ":"
		<< setw(7) << "Ho"
		<< ":"
		<< setw(9) << "Ten lot"
		<< ":"
		<< setw(9) << "Ten"
		<< ":"
		<< setw(11) << "Nam Sinh"
		<< ":"
		<< setw(10) << "Luong"
		<< ":";
	cout << endl;
	cout << ":";
	for (i = 0; i < 62; i++)
	{
		cout << '=';
	}
}

void Xuat_NV(dulieu x)
{
	cout << endl << ':';
	cout << setiosflags(ios::left)
		<< setw(10) << x.maNV
		<< setw(8) << x.hoNV
		<< setw(10) << x.tenLot
		<< setw(10) << x.ten
		<< setw(12) << x.namSinh
		<< setw(8) << setprecision(2) << setiosflags(ios::fixed) << x.luong;
	cout << ':';
}

void Xuat_DSNV(LIST& l)
{
	TieuDe();
	if (IsEmpty(l))
	{
		cout << "Danh sach rong!";
		return;
	}
	NODE* p;
	p = l.pHead;
	while (p != NULL)
	{
		Xuat_NV(p->info);
		cout << "\n";
		p = p->pNext;
	}
}

int DemSoLuong(LIST& l, char* f)
{
	NODE* p;
	p = l.pHead;
	int i = 0;
	while (p != NULL)
	{
		if (_stricmp(f, p->info.hoNV) == 0)
		{
			i++;
		}
		p = p->pNext;
	}
	return i;
}

int DemSLLLuongVaNamSinh(LIST& l)
{
	NODE* p;
	p = l.pHead;
	int i = 0;
	while (p != NULL)
	{
		if (p->info.luong)
		{
			p = p->pNext;
			i++;
		}
	}
	return i;
}

double TrungBinhLuong(LIST& l)
{
	NODE* p;
	p = l.pHead;
	int n;
	double dtb;
	int Tong = 0;
	n = DemSLLLuongVaNamSinh(l);
	while (p != NULL)
	{
		Tong += p->info.luong;
		p = p->pNext;
	}
	dtb = Tong / n;
	return dtb;
}

int TrungBinhNamSinh(LIST& l)
{
	NODE* p;
	p = l.pHead;
	int n;
	double dtb;
	int Tong = 0;
	n = DemSLLLuongVaNamSinh(l);
	while (p != NULL)
	{
		Tong += p->info.namSinh;
		p = p->pNext;
	}
	dtb = Tong / n;
	return dtb;
}

void DaoNguocDanhSach(LIST l)
{
	NODE* p;
	LIST ll;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	CreatList(ll);
	while(p != NULL)
	{
		InsertHead(ll, p->info);
		p = p->pNext;
	}
	cout << "Danh sach sau khi dao nguoc: ";
	Xuat_DSNV(ll);
}

void ChenDauDS(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}