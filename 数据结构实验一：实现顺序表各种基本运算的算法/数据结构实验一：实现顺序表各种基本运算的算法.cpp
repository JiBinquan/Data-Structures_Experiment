/*************************************************
** 功能 : 数据结构实验1 实现顺序表各种基本运算的算法
** 作者 : 2019Jibinquan
** 创建 : 2020-9-16 / 16:02
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

struct Sqlist {
	int arr[maxn];
	int len;

	void setSqlist(int n){
		len = n;
		cout << "请输入数据：" << endl;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
	}
	
	void outSqlist() {
		cout << "当前顺序表：" << endl;
		for (int i = 1; i <= len; i++) {
			cout << arr[i] << " \n"[i == len];
		}
	}
	
	int maxnum() {
		int mx = -inf;
		for (int i = 1; i <= len; i++) {
			mx = max(mx, arr[i]);
		}
		return mx;
	}
	
	void insertnum(int pos, int x) {
		if (pos > len+1 || pos < 1) {
			cout << "输入位置有误" << endl;
			return;
		}
		for (int i = len; i >= pos; i--) {
			arr[i + 1] = arr[i];
		}
		arr[pos] = x;
		len++;
	}
	
	void deletenum(int pos) {
		if (pos > len || pos < 1) {
			cout << "输入位置有误" << endl;
			return;
		}
		for (int i = pos; i < len; i++) {
			arr[i] = arr[i + 1];
		}
		arr[len] = 0;
		len--;
	}
	
	void increasesort(){
		sort(arr + 1, arr + 1 + len);
	}
	
	void dicreasesort() {
		int n = len;
		while (n) {
			for (int i = 1; i < n; i++) {
				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
			n--;
		}
	}
	
};

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	int n,p,x;
	Sqlist sl;
	cout << "请输入数组长度" << endl;
	cin >> n;
	sl.setSqlist(n);
	sl.outSqlist();
	cout << "最大元素：" << endl;
	cout << sl.maxnum() << endl;
	cout << "请输入要插入的位置和数值：" << endl;
	cin >> p >> x;
	sl.insertnum(p, x);
	sl.outSqlist();
	cout << "请输入要删除的位置：" << endl;
	cin >> p;
	sl.deletenum(p);
	sl.outSqlist();
	sl.increasesort();
	cout << "升序排序后的";
	sl.outSqlist();
	sl.dicreasesort();
	cout << "降序排序后的";
	sl.outSqlist();
	system("pause");
	
	return 0;
}
