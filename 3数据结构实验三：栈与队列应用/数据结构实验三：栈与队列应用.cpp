/*************************************************
** ���� : ���ݽṹʵ����
** ���� : 2019Jibinquan
** ���� : 2020-10-7 / 15:56
** ��Ȩ : 431263064@qq.com
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

char sta[maxn];

void brackets()//����ƥ�� 
{
	char ch;
	int top = 0;
	bool flag = 1;
	cout << "������Ҫ�����жϵ��������У�" << endl;
	getchar();
	while ((ch = getchar()) == '(' || ch == ')') {
		if (ch == '(') {
			sta[++top] = ch;
		}
		else {
			if (top > 0) {
				top--;
			}
			else {
				flag = 0;
			}
		}
	}
	if (top != 0) {
		flag = 0;
	}
	if (flag) {
		cout << "�����п��Գɹ�ƥ��" << endl;
	}
	else {
		cout << "�������޷��ɹ�ƥ��" << endl;
	}
}
	
string mque[maxn];
string fque[maxn];

void dance()//������� 
{
	int mn, fn, wc, sm;
	cout << "�������ж�����" << endl;
	cin >> mn;
	cout << "�������ж�����" << endl;
	for (int i = 0; i < mn; i++) {
		cin >> mque[i];
	}
	cout << "������Ů������" << endl;
	cin >> fn;
	cout << "������Ů������" << endl;
	for (int i = 0; i < fn; i++) {
		cin >> fque[i];
	}
	cout << "��������ش�С" << endl;
	cin >> wc;
	wc = min(wc, min(fn, mn));
	cout << "������������Ŀ" << endl;
	cin >> sm;
	int mz = 0, fz = 0;
	for (int i = 1; i <= sm; i++) {
		cout << "��" << i << "����" << endl;
		for (int j = 1; j <= wc; j++) {
			cout << "��" << j << "�飺" << endl;
			cout << "�У�" << mque[mz] << " Ů��" << fque[fz] << endl;
			mz = (mz + 1) % mn ;
			fz = (fz + 1) % fn ;
		}
	}

}
	

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	string op;
	cout << "������Ҫ���еĲ�����" << endl;
	cout << "����'bracket'��ƥ������ " << endl;
	cout << "����'dance'����ⷽ�� " << endl;
	cout << "����'end'�Խ��� " << endl;
	while (cin >> op) {
		if (op == "end") {
			break;
		}
		else if (op == "bracket") {
			brackets();
		}
		else if (op == "dance") {
			dance();
		}
		else {
			cout << "ָ�����" << endl;
		}
		cout << "������Ҫ���еĲ�����" << endl;
	}
	system("pause");
	
	return 0;
}
