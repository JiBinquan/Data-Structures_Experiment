/*************************************************
** ���� : ���ݽṹʵ��ˣ�ͼ��DFS��BFS����
** ���� : 2019Jibinquan
** ���� : 2020-11-18 / 15:51
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
#define inr register int 
using namespace std;
typedef long long ll;
const double pi = acos(-1);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxn = 100007;//1e5+7 
const ll mod = 1000000007;//1e9+7

vector<int>G[maxn];

int n, m, len = 0;
int vis[maxn];
int dans[maxn];
int bans[maxn];


/*----------------------------------*
		 Function Definition
*-----------------------------------*/


void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

void init(int st)
{
	len = 0;
	memset(vis, 0, sizeof(vis));
	vis[st] = 1;
}

void dfs(int st)
{
	dans[++len] = st;
	for (int i = 0; i < G[st].size(); i++) {
		if (!vis[G[st][i]]) {
			vis[G[st][i]] = 1;
			dfs(G[st][i]);
		}
	}
}

void bfs(int st)
{
	queue<int>q;
	q.push(st);
	while (!q.empty()) {
		int nw = q.front();
		bans[++len] = nw;
		q.pop();
		for (int i = 0; i < G[nw].size(); i++) {
			if (!vis[G[nw][i]]) {
				vis[G[nw][i]] = 1;
				q.push(G[nw][i]);
			}
		}
	}
}


/*----------------------------------*
		  Main Function
*-----------------------------------*/


int main()
{
	cout << "������һ����ͨͼ��ĸ�����ߵĸ���n m������0 0����" << endl;
	while (cin >> n >> m) {
		if (!(n || m)) {
			break;
		}
		else {
			cout << "������������֮����һ����u v" << endl;
			for (int i = 1, u, v; i <= m; i++) {
				cin >> u >> v;
				add_edge(u, v);
			}
			int st;
			cout << "�����������㣺" << endl;
			cin >> st;
			init(st);
			dfs(st);
			init(st);
			bfs(st);
			cout << "ͼ��dfs����˳��" << endl;
			for (int i = 1; i <= n; i++) {
				cout << dans[i] << " \n"[i == n];
			}
			cout << "ͼ��bfs����˳��" << endl;
			for (int i = 1; i <= n; i++) {
				cout << bans[i] << " \n"[i == n];
			}
		}
	}
	system("pause");
	return 0;
}

/*
1 2
1 3
2 4
2 5
4 8
5 8
3 6
3 7
6 7
*/

