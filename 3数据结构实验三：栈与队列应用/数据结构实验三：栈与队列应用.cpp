/*************************************************
** 功能 : 数据结构实验四
** 作者 : 2019Jibinquan
** 创建 : 2020-10-7 / 15:56
** 版权 : 431263064@qq.com
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

void brackets()//括号匹配 
{
	char ch;
	int top = 0;
	bool flag = 1;
	cout << "请输入要进行判断的括号序列：" << endl;
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
		cout << "该序列可以成功匹配" << endl;
	}
	else {
		cout << "该序列无法成功匹配" << endl;
	}
}
	
string mque[maxn];
string fque[maxn];

void dance()//舞伴问题 
{
	int mn, fn, wc, sm;
	cout << "请输入男队人数" << endl;
	cin >> mn;
	cout << "请输入男队姓名" << endl;
	for (int i = 0; i < mn; i++) {
		cin >> mque[i];
	}
	cout << "请输入女队人数" << endl;
	cin >> fn;
	cout << "请输入女队姓名" << endl;
	for (int i = 0; i < fn; i++) {
		cin >> fque[i];
	}
	cout << "请输入舞池大小" << endl;
	cin >> wc;
	wc = min(wc, min(fn, mn));
	cout << "请输入舞曲数目" << endl;
	cin >> sm;
	int mz = 0, fz = 0;
	for (int i = 1; i <= sm; i++) {
		cout << "第" << i << "曲：" << endl;
		for (int j = 1; j <= wc; j++) {
			cout << "第" << j << "组：" << endl;
			cout << "男：" << mque[mz] << " 女：" << fque[fz] << endl;
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
	cout << "请输入要进行的操作：" << endl;
	cout << "输入'bracket'以匹配括号 " << endl;
	cout << "输入'dance'以求解方程 " << endl;
	cout << "输入'end'以结束 " << endl;
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
			cout << "指令错误！" << endl;
		}
		cout << "请输入要进行的操作：" << endl;
	}
	system("pause");
	
	return 0;
}
