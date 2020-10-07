/*************************************************
** 功能 : 实验二：实现单链表各种基本运算的算法
** 作者 : 2019Jibinquan
** 创建 : 2020-9-23 / 15:57
** 联系 : 431263064@qq.com
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


Linklist initList() //初始化链表 
{
	Linklist L = new LNode;
	L->next = NULL;
	return L;
}

void insert_back(Linklist &L,int e) //尾插法插入元素 
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

void Creatlist(Linklist& L) //创建一个链表 ，可一次插入多组数据 
{
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	int n,e;
	LNode* s = new LNode;
	LNode* pre = new LNode;
	pre = p;
	cout << "请输入初始元素个数：" << endl;
	cin >> n;
	cout << "请输入元素：" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> e;
		s = new LNode;
		s->data = e;
		s->next = NULL;
		pre->next = s;
		pre = pre->next;
	}
}

void printList(Linklist L) //打印链表 
{
	LNode* p = L->next;
	while (p->next != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data << endl;
}

int getlength(Linklist L) //得到链表长度 
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

bool isempty(Linklist L) //链表判空 
{
	LNode* p = L;
	if (p->next == NULL) {
		return true;
	}
	else return false;
}

int find(Linklist L, int pos)//根据下标查找某一元素 
{
	LNode* p = L->next;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	return p->data;
}

int findpos(Linklist L, int e)//寻找某一元素第一次出现的位置 
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

void insertelm(Linklist& L, int pos, int e)//在指定位置插入元素 
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

void deleteelm(Linklist& L, int pos)//删除指定位置的元素 
{
	LNode* p = L;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	LNode* s = p->next;
	p->next = p->next->next;
	free(s);
}

void reverseList(Linklist& L)//反转链表 
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
	cout << "正在初始化链表……" << endl;
	if (isempty(L)) {
		cout << "当前链表为空" << endl;
	}
	else {
		cout << "当前链表不为空" << endl;
	}
	Creatlist(L);
	if (isempty(L)) {
		cout << "当前链表为空" << endl;
	}
	else {
		cout << "当前链表不为空" << endl;
	}
	cout << "当前链表：" << endl;
	printList(L);
	cout <<"当前链表长度："<< getlength(L) << endl;
	cout << "请输入要插入的位置和数值：" << endl;
	cin >> pos >> e;
	insertelm(L, pos, e);
	cout << "当前链表：" << endl;
	printList(L);
	cout << "请输入要查询的位置：" << endl;
	cin >> pos;
	cout << "该位置元素为：" << find(L, pos) << endl;
	cout << "请输入要查询的元素：" << endl;
	cin >> e;
	pos = findpos(L, e);
	if (pos == -1) {
		cout << "未找到该元素！" << endl;
	}
	else {
		cout << "该元素出现的第一个位置为：" << pos << endl;
	}
	cout << "请输入要删除的位置：" << endl;
	cin >> pos;
	deleteelm(L, pos);
	cout << "当前链表：" << endl;
	printList(L);
	cout << "原地逆序后的链表：" << endl;
	reverseList(L);
	printList(L);
	system("pause");
	
	return 0;
}
