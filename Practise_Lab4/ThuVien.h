#define MAX 100

typedef int duLieu;

struct tagNode
{
	duLieu info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

//Khai bao nguyen mau cac ham
//Nhap, Xuat , he thong
void XuatDS(LIST l);
int File_List(char* f, LIST& l);
NODE* GetNode(duLieu x);
void CreateList(LIST& l);
int IsEmpty(LIST l);

//Tim kiem
NODE* Search_First(LIST l, duLieu x);
NODE* Search_End(LIST l, duLieu x);
int Search_Node_x_First(LIST l, duLieu x);
int Search_Node_x_End(LIST l, duLieu x);
void Search_Node_x(LIST l, duLieu x);

//Chen
void AddFirst(LIST& l, NODE* new_ele);
void InsertHead(LIST& l, duLieu x);
void AddTail(LIST& l, NODE* new_ele);
void InsertTail(LIST& l, duLieu x);
void InsertAfter(LIST& l, NODE* q, duLieu x);
void Insert_x_After_first_y(LIST& l, duLieu y, duLieu x);
void Insert_x_After_End_y(LIST& l, duLieu y, duLieu x);

//Huy
void RemoveHead(LIST& l);
void RemoveTail(LIST& l);
void RemoveList(LIST& l);
int RemoveNode_First(LIST& l, duLieu x);
int RemoveNode_End(LIST& l, duLieu x);
void Remove_x(LIST& l, duLieu x);

//Sap xep
void List_Selection_Sort1(LIST& l);
void List_Selection_Sort2(LIST& l);

//Chuc nang khac
int SoNut_x(LIST l, duLieu x);
int SoNut(LIST l);
void Copy(LIST& l1, LIST l);
void Hoanvi(duLieu& x, duLieu& y);

NODE* GetNode(duLieu x)
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

void CreateList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}

int File_List(char* f, LIST& l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreateList(l);
	duLieu x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

void XuatDS(LIST l)
{
	NODE* p;
	if (IsEmpty(l))
	{
		cout << "\nDS rong!\n";
		return;
	}
	p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}

NODE* Search_First(LIST l, duLieu x)
{
	NODE* p;
	p = l.pHead;
	while ((p != NULL) && (p->info != x))
		p = p->pNext;
	return p;
}

int Search_NODE_x_First(LIST l, duLieu x)
{
	NODE* p;
	int i = 0;
	p = l.pHead;
	while ((p != NULL) && (p->info != x))
	{
		p = p->pNext;
		i++;
	}
	if (p == NULL)
		i = -1;
	return i;
}

NODE* Search_End(LIST l, duLieu x)
{
	NODE* p, * q = NULL;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			q = p;
		p = p->pNext;
	}
	return q;
}

int Search_Node_x_End(LIST l, duLieu x)
{
	NODE* p;
	int kq = -1, i = 0;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			kq = i;
		i++;
		p = p->pNext;
	}
	return kq;
}

