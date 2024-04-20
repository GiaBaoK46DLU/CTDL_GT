struct NODE
{
	int data;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;//con tro dau tien
	NODE* pTail;//con tro cuoi cung
};

void CreatList(LIST& list);
NODE* GetNode(int data);
bool IsEmpty(LIST list);
void InsertTail(LIST& list, int data);
int FileReader(char* filename, LIST& list);
void Output(LIST list);
bool KiemTraPhanTu(LIST list, int x);
void Copy(LIST& b, LIST a);
LIST Giao2TapHop(LIST a, LIST b);
LIST Hop2TapHop(LIST a, LIST b);
LIST Hieu2TapHop(LIST a, LIST b);
LIST HieuDoiXung2TapHop(LIST a, LIST b);
void TichDescrates(LIST a, LIST b);
int KiemTraQuanHeBaoHam(LIST a, LIST b);
int LucLuongTapHop(LIST list);

void CreatList(LIST& list)
{
	list.pHead = list.pTail = NULL;//tao lap con tro
}

NODE* GetNode(int data)
{
	NODE* pNode = new NODE;//tro toi vung nho moi
	if (!pNode)
		return NULL;
	pNode->data = data;
	pNode->pNext = NULL;
	return pNode;
}

bool IsEmpty(LIST list)
{
	if (list.pHead == NULL)
		return true;
	return false;
}

void InsertTail(LIST& list, int data)//chen cuoi
{
	NODE* pNode = GetNode(data);
	if (!pNode)
		return;
	if (IsEmpty(list))
		list.pHead = list.pTail = pNode;//TH1: Danh sach chua co gi
	else
	{
		list.pTail->pNext = pNode;
		list.pTail = pNode;//pNext moi thi thanh nut cuoi cung
	}
}

int FileReader(char* filename, LIST& list)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(list);
	int x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(list, x);
	}
	in.close();
	return 1;
}

void Output(LIST list)
{
	NODE* pNode = list.pHead;
	if (IsEmpty(list))
		return;
	cout << "{ ";
	while (pNode)
	{
		cout << pNode->data;
		pNode = pNode->pNext;
		if (pNode)
			cout << ", ";
	}
	cout << " }\n";
}

bool KiemTraPhanTu(LIST list, int x)
{
	NODE* pNode = list.pHead;
	while (pNode)
	{
		if (pNode->data == x)
			return true;
		pNode = pNode->pNext;
	}
	return false;
}

void Copy(LIST& b, LIST a)
{
	NODE* pNode = a.pHead;
	while (pNode)
	{
		InsertTail(b, pNode->data);
		pNode = pNode->pNext;
	}
}

LIST Giao2TapHop(LIST a, LIST b)
{
	LIST result;
	CreatList(result);
	NODE* pNode = a.pHead;
	while (pNode)
	{
		if (KiemTraPhanTu(b, pNode->data))
			InsertTail(result, pNode->data);//Tao 1 ds moi chua phan tu chung cua 2 tap hop
		pNode = pNode->pNext;
	}
	return result;
}

LIST Hop2TapHop(LIST a, LIST b)
{
	LIST result;
	CreatList(result);
	Copy(result, a);
	NODE* pNode = b.pHead;
	while (pNode)
	{
		if (!KiemTraPhanTu(a, pNode->data))
			InsertTail(result, pNode->data);
		pNode = pNode->pNext;
	}
	return result;
}

LIST Hieu2TapHop(LIST a, LIST b)
{
	LIST result;
	CreatList(result);
	NODE* pNode = a.pHead;
	while (pNode)
	{
		if (!KiemTraPhanTu(b, pNode->data))//nhung phan tu cua a khong co trong b thi chen vao danh sach moi, con co trong b thi khong duoc chen vao danh sach moi
			InsertTail(result, pNode->data);
		pNode = pNode->pNext;
	}
	return result;
}

LIST HieuDoiXung2TapHop(LIST a, LIST b)
{
	LIST result, D, E;
	CreatList(result);
	CreatList(D);
	CreatList(E);
	D = Giao2TapHop(a, b);
	E = Hop2TapHop(a, b);
	result = Hieu2TapHop(E, D);
	return result;

	/*Cach giai 2*/
	/*LIST result, D, E;
	CreatList(result);
	CreatList(D);
	CreatList(E);
	D = Hieu2TapHop(a, b);
	E = Hieu2TapHop(b, a);
	result = Hop2TapHop(D, E);
	return result;*/
}

void TichDescrates(LIST a, LIST b)
{
	if (!a.pHead || !b.pHead)
		return;
	cout << "{ ";
	NODE* pNode = a.pHead;
	while (pNode)
	{
		NODE* kNode = b.pHead;
		while (kNode)
		{
			cout << '(' << pNode->data << ',' << kNode->data << ')';
			cout << ", ";
			kNode = kNode->pNext;
		}
		pNode = pNode->pNext;
	}
	cout << "} ";
}

int KiemTraQuanHeBaoHam(LIST a, LIST b)
{
	NODE* pNode = a.pHead;
	int result = -1;
	while (pNode)
	{
		if (!KiemTraPhanTu(b, pNode->data))
			result = 0;
		pNode = pNode->pNext;
	}
	return result;
}

int LucLuongTapHop(LIST list)
{
	int result = 0;
	NODE* pNode = list.pHead;
	if (!pNode)
		return 0;
	while (pNode)
	{
		result++;
		pNode = pNode->pNext;
	}
	return result;
}