/*************************************************
** 功能 : 数据结构实验六：递归在链表的应用
** 作者 : 2019Jibinquan
** 创建 : 2020-10-14 / 16:57
** 联系 : 431263064@qq.com
/**************************************************/

#include "pch.h"
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

typedef struct LNode {
	int data;
	LNode* next;
}LNode, *Linklist;


Linklist initList() //初始化链表
{
	Linklist L = new LNode;
	L->next = NULL;
	return L;
}

void insert_back(Linklist &L, int e) //尾插法插入元素
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
	int n, e;
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
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
}


int ans,rpos, cnt = 0;

void dfs(Linklist L) {
	if (L->next != NULL) {
		dfs(L->next);
	}
	cnt++;
	if (cnt == rpos) {
		ans = L->data;
	}
}

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{
	int pos, e;
	Linklist L = initList();
	cout << "正在初始化链表……" << endl;
	Creatlist(L);
	cout << "请输入要找的位置(倒数): " << endl;
	cin >> rpos;
	dfs(L);
	cout << "该元素为: ";
	cout << ans << endl;
	system("pause");

	return 0;
}
