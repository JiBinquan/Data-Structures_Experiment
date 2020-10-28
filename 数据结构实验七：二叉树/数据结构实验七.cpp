/*************************************************
** 功能 : 数据结构实验七：二叉树
** 作者 : 2019Jibinquan
** 创建 : 2020-10-21 / 15:59
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
#include <string>
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

typedef struct node {
	char data;
	node* lson, *rson;
}node, *root;

string st;
int pos;

void build(root &o)
{
	//cout << st[pos] << endl;
	if (st[pos] == '#') {
		o = NULL;
	}
	else {
		o = new node;
		o->data = st[pos];
		if (pos + 1 < st.length()) {
			pos++;
			build(o->lson);
		}
		else {
			o->lson = NULL;
		}
		if (pos + 1 < st.length()) {
			pos++;
			build(o->rson);
		}
		else {
			o->rson = NULL;
		}
	}

}

void DLR(root o)
{
	if (o != NULL) {
		cout << o->data << ' ';
		DLR(o->lson);
		DLR(o->rson);
	}
}


void LDR(root o)
{
	if (o != NULL) {
		LDR(o->lson);
		cout << o->data << ' ';
		LDR(o->rson);
	}
}

void LRD(root o)
{
	if (o != NULL) {
		LRD(o->lson);
		LRD(o->rson);
		cout << o->data << ' ';
	}
}



stack<root>sta;

void LDR_stack(root o)
{
	node* p = o;
	node* q = new node;
	while (p || !sta.empty()) {
		if (p) {
			sta.push(p);
			p = p->lson;
		}
		else {
			q = sta.top();
			sta.pop();
			cout << q->data << ' ';
			p = q->rson;
		}
	}
}

int countNode(root o)
{
	if (o != NULL) {
		return countNode(o->lson) + countNode(o->rson) + 1;
	}
	else return 0;

}

int mxdep(root o)
{
	if (o != NULL) {
		return max(mxdep(o->lson), mxdep(o->rson)) + 1;
	}
	return 0;

}

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{
	node* o = NULL;
	cin >> st;
	pos = 0;
	build(o);
	cout << "前序遍历：" << endl;
	DLR(o);
	cout << endl;
	cout << "中序遍历：" << endl;
	LDR(o);
	cout << endl;
	cout << "后序遍历：" << endl;
	LRD(o);
	cout << endl;
	cout << "树的节点数为： " << countNode(o) << endl;
	cout << "树的深度为： " << mxdep(o) << endl;
	cout << "非递归的中序遍历：" << endl;
	LDR_stack(o);
	cout << endl;
	system("pause");
	return 0;
}
