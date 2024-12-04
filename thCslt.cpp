#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct PhanSo {
	int num; //tu so
	int den; //mau so
};

struct node {
	PhanSo key; //phan so
	struct node* next;
};

struct list {
	int* head;
};



//khoi khai bao ham
node* getNode(PhanSo newKey);
int length(node* head);
std::ostream& operator<< (std::ostream& outDev, const PhanSo& ps);
std::istream& operator>> (std::istream& inDev, PhanSo& ps);
void addFirst(node*& head, node*& tail, PhanSo key);
void addLast(node*& head, node*& tail, PhanSo &k);
void insertAfter(node* q, PhanSo k);
void deleteBegin(node*& head, node*& tail);
void deleteMiddle(node* &q, node*& head);
void deleteEnd(node*& head, node*& tail);
void XayDungDanhSachPhanSo(node*& head, node*& tail);
void XuatDanhSach(node* head);
void ThemPhanSo(node*& head, node*& tail, PhanSo& newFrac);
void ChenPhanSo(node*& head, node*& tail, int& pos, PhanSo& k);
void XoaPhanSo(node*& head, node*& tail, int &pos);
//khoi khai bao ham




//khoi dinh nghia ham
std::ostream& operator<< (std::ostream& outDev, const PhanSo& ps) {
	if (ps.den == 1 || ps.num == 0) outDev << ps.num;
	else outDev << ps.num << "/" << ps.den;
	return outDev;
}

std::istream& operator>> (std::istream& inDev, PhanSo& ps) {
	inDev >> ps.num >> ps.den;
	return inDev;
}

node* getNode(PhanSo newKey) {
	node* Node;
	Node = (node*)malloc(sizeof(node));

	if (Node == nullptr) {
		std::cout << "Thua thay, khong du bu nho de them phan tu moi.";
		exit(0);
	}
	Node->key = newKey;
	Node->next = nullptr;
	return Node;
}

void addFirst(node* &head, node* &tail, PhanSo key) {
	node* pNodePtr = getNode(key);
	if (head == nullptr) {
		head = tail = pNodePtr;
	}
	else {
		pNodePtr->next = head;
		head = pNodePtr;
	}
}

void addLast(node*& head, node*& tail, PhanSo& k) {
	node* ptr = getNode(k);
	node* q;
	if (head == nullptr) {
		head = tail = ptr;
	}
	else {
		tail->next = ptr;
		tail = ptr;
	}
}


void deleteBegin(node*& head, node*& tail) {
	node* q;
	if (head == tail) {
		free(head);
		head = tail = nullptr;
	}
	else {
		q = head;
		head = head->next;
		free(q);
	}
}
void XayDungDanhSachPhanSo(node*& head, node*& tail) {
	PhanSo inputFraction; //use for input
	while (1) {
		std::cout << "Moi thay nhap day phan so (nhap phan so 0 de thoat): ";
		std::cin >> inputFraction;
		if (inputFraction.num == 0 && inputFraction.den == 0)
			break;
		addFirst(head, tail, inputFraction);
	}
}
void XuatDanhSach(node* head) {
	if (head == nullptr) {
		std::cout << "Thua thay, danh sach rong\n";
	}
	else {
		std::cout << "Thua thay, danh sach phan so la: \n";
		for (node* p = head; p; p = p->next) {
			std::cout << (*p).key << ' ';
		}
		std::cout << "\n";
	}
}
void ThemPhanSo(node*& head, node*& tail, PhanSo& newFrac) {
	//them phan so vao cuoi danh sach
	std::cout << "Moi thay nhap phan so can them vao cuoi danh sach: ";
	std::cin >> newFrac;
	node* newLastFrac = getNode(newFrac);
	if (head == nullptr) {
		head = tail = newLastFrac;
	}
	else {
		tail->next = newLastFrac; //error tail was nullptr
		tail = newLastFrac;
	}
}
int length(node* head) {
	//dem so phan tu trong danh sach lien ket
	node* ptr;
	int count = 0;
	for (ptr = head; ptr; ptr = ptr->next) count++;
	return count;
}

void insertAfter(node* q, PhanSo k) {
	node* p;
	p = getNode(k);
	p->next = q->next;
	q->next = p;
}

void deleteMiddle(node*& q, node*& head) {
	node* ptr;
	for (ptr = head; ptr->next != q; ptr = ptr->next);
	(ptr->next) = q->next;
	free(q);
}

void deleteEnd(node*& head, node*& tail) {
	node* q;
	if (head == tail) {
		free(head);
		head = tail = nullptr;
	}
	else {
		for (q = head; q->next != tail; q = q->next);
		free(tail);
		q->next = nullptr;
	}

}

void ChenPhanSo(node*& head, node*& tail, int& pos, PhanSo& k) {
	int n, i = 0;
	node* q;
	std::cout << "Moi thay nhap vi tri can chen phan so: ";
	std::cin >> pos;
	std::cout << "Moi thay nhap phan so can chen: ";
	std::cin >> k;
	n = length(head);
	if ((pos < 0) || pos > n) {
		std::cout << "Thua thay, vi tri chen khong phu hop.\n";
		return;
	}
	if (pos == 0) {
		addFirst(head, tail, k);
	}
	else if (pos == n) {
		addLast(head, tail, k);
	}
	else {
		for (q = head; i < pos - 1; i++, q = q->next);
		insertAfter(q, k);
	}
}




void XoaPhanSo(node*& head, node*& tail, int &pos) {
	//xoa 1 phan so tai mot vi tri xac dinh trong danh sach
	int n;
	int i;
	node* q;
	n = length(head);
	std::cout << "Moi thay nhap vi tri can xoa phan so: ";
	std::cin >> pos;
	if ((pos < 0) || (pos >= n)) {
		std::cout << "Vi tri xoa khong phu hop\n";
		return;
	}
	if (pos == 0) deleteBegin(head, tail);
	else if (pos == n - 1) deleteEnd(head, tail);
	else {
		for (q = head, i = 0; i < pos; q = q->next, i++);
		deleteMiddle(q, head);		
	}
}
void HuyDanhSach(node*& head) {
	node* p;
	while (head) {
		p = head;
		head = head->next;
		free(p);
	}
}
//khoi dinh nghia ham

int main() {
	
	node* head = nullptr;
	node* tail = nullptr;
	XayDungDanhSachPhanSo(head, tail);
	XuatDanhSach(head);
	PhanSo newFrac = { 0, 0 };
	ThemPhanSo(head, tail, newFrac);
	XuatDanhSach(head);
	PhanSo k;
	int insertPos = 0;
	ChenPhanSo(head, tail, insertPos, k);
	XuatDanhSach(head);
	int deletePos = 0;
	XoaPhanSo(head, tail, deletePos);
	XuatDanhSach(head);
	HuyDanhSach(head);
}
