/*************************************************
** ���� : ʵ�����ʵ�ֵ�������ֻ���������㷨
** ���� : 2019Jibinquan
** ���� : 2020-9-23 / 15:57
** ��ϵ : 431263064@qq.com
/**************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << " " << a << endl
using namespace std;
typedef long long ll;
const double pi = acos(-1);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxn = 100007;//1e5+7 
const ll mod = 1000000007;//1e9+7

typedef struct LNode{
	int data;
	LNode* next;
}LNode,*Linklist;


Linklist initList() //��ʼ������ 
{
	Linklist L = new LNode;
	L->next = NULL;
	return L;
}

void insert_back(Linklist &L,int e) //β�巨����Ԫ�� 
{
	LNode *p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = NULL;
	p->next = s;
}

void Creatlist(Linklist& L) //����һ������ ����һ�β���������� 
{
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	int n,e;
	LNode* s = new LNode;
	LNode* pre = new LNode;
	pre = p;
	cout << "�������ʼԪ�ظ�����" << endl;
	cin >> n;
	cout << "������Ԫ�أ�" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> e;
		s = new LNode;
		s->data = e;
		s->next = NULL;
		pre->next = s;
		pre = pre->next;
	}
}

void printList(Linklist L) //��ӡ���� 
{
	LNode* p = L->next;
	while (p->next != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data << endl;
}

int getlength(Linklist L) //�õ������� 
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

bool isempty(Linklist L) //�����п� 
{
	LNode* p = L;
	if (p->next == NULL) {
		return true;
	}
	else return false;
}

int find(Linklist L, int pos)//�����±����ĳһԪ�� 
{
	LNode* p = L->next;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	return p->data;
}

int findpos(Linklist L, int e)//Ѱ��ĳһԪ�ص�һ�γ��ֵ�λ�� 
{
	int pos = 1;
	LNode* p = L->next;
	while (p->next != NULL) {
		if (p->data == e) {
			return pos;
		}
		p = p->next;
		pos++;
	}
	return -1;
}

void insertelm(Linklist& L, int pos, int e)//��ָ��λ�ò���Ԫ�� 
{
	LNode* p = L;
	for (int i = 1; i < pos; i++){
		p = p->next;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void deleteelm(Linklist& L, int pos)//ɾ��ָ��λ�õ�Ԫ�� 
{
	LNode* p = L;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	LNode* s = p->next;
	p->next = p->next->next;
	free(s);
}

void reverseList(Linklist& L)//��ת���� 
{
	LNode* p = L->next->next;
	LNode* pre = L->next;
	pre->next = NULL;
	LNode* tp = new LNode;
	while (p->next != NULL) {
		tp = p->next;
		p->next = pre;
		pre = p;
		p = tp;
	}
	p->next = pre;
	L->next = p;
}

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	int pos, e;
	Linklist L = initList();
	cout << "���ڳ�ʼ��������" << endl;
	if (isempty(L)) {
		cout << "��ǰ����Ϊ��" << endl;
	}
	else {
		cout << "��ǰ����Ϊ��" << endl;
	}
	Creatlist(L);
	if (isempty(L)) {
		cout << "��ǰ����Ϊ��" << endl;
	}
	else {
		cout << "��ǰ����Ϊ��" << endl;
	}
	cout << "��ǰ����" << endl;
	printList(L);
	cout <<"��ǰ�����ȣ�"<< getlength(L) << endl;
	cout << "������Ҫ�����λ�ú���ֵ��" << endl;
	cin >> pos >> e;
	insertelm(L, pos, e);
	cout << "��ǰ����" << endl;
	printList(L);
	cout << "������Ҫ��ѯ��λ�ã�" << endl;
	cin >> pos;
	cout << "��λ��Ԫ��Ϊ��" << find(L, pos) << endl;
	cout << "������Ҫ��ѯ��Ԫ�أ�" << endl;
	cin >> e;
	pos = findpos(L, e);
	if (pos == -1) {
		cout << "δ�ҵ���Ԫ�أ�" << endl;
	}
	else {
		cout << "��Ԫ�س��ֵĵ�һ��λ��Ϊ��" << pos << endl;
	}
	cout << "������Ҫɾ����λ�ã�" << endl;
	cin >> pos;
	deleteelm(L, pos);
	cout << "��ǰ����" << endl;
	printList(L);
	cout << "ԭ������������" << endl;
	reverseList(L);
	printList(L);
	system("pause");
	
	return 0;
}
