
/*************************************************
** 功能 : 数据结构实验五：串及其匹配
** 作者 : 2019Jibinquan
** 创建 : 2020-10-14 / 16:00
** 版权 : 431263064@qq.com
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


struct str {
	char ch[maxn];

	void initstr() {
		memset(ch, '\0', sizeof(ch));
	}

	void setstr(){
		initstr();
		cout << "请输入字符串:" << endl;
		cin >> ch;
	}

	int leng() {
		for (int i = 1; i <= maxn; i++) {
			if (ch[i] == '\0' || ch[i] == '\n') {
				return i ;
			}
		}
	}

	void uion(str s2) {
		int pos = leng();
		if (leng() + s2.leng() >= maxn) {
			cout << "无法完全合并" << endl;
			for (int i = 0; i + pos <= maxn; i++) {
				ch[i + pos] = s2.ch[i];
			}
		}
		else {
			for (int i = 0; i < s2.leng(); i++) {
				ch[i + pos] = s2.ch[i];
			}
		}
	}

	void outstr(){
		cout << ch << endl;
	}

	int bfpos(str s2) {
		int res = -1;
		for (int i = 0; i < leng(); i++) {
			bool flag = 1;
			for (int j = 0; j < s2.leng(); j++) {
				if (ch[i+j] != s2.ch[j]) {
					flag = 0;
					break ;
				}
			}
			if (flag) {
				res = i;
				break;
			}
		}
		return res;
	}
};


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	str s1, s2;
	cout << "输入s1" << endl;
	s1.setstr();
	cout << "输入s2" << endl;
	s2.setstr();
	cout << "s1: ";
	s1.outstr();
	cout << "s2: ";
	s2.outstr();
	cout << "s1的长度: " << s1.leng() << endl;
	cout << "s2的长度: " << s2.leng() << endl;
	int pos = s1.bfpos(s2);
	if (pos != -1) {
		cout << "s2可以在s1的" << pos << "后匹配" << endl;
	}
	else {
		cout << "两个串无法匹配" << endl;
	}
	s1.uion(s2);
	cout << "合并后:" << endl;
	s1.outstr();
	system("pause");

	return 0;
}
