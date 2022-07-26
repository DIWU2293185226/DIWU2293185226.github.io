#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

//ǰ�ö������������������ⲻͬ��������ϳ����е������� 

const int maxn = 10005;
int parents[maxn][20], depth[maxn];
//parents�������ڼ�¼��ĳ�ڵ�Ķ��������ȣ�depth��¼�ڵ���� 
int n, from[maxn], root = -1;
//from�жϽڵ��Ƿ��и��ף���root�� 
vector<int> G[maxn];
//��¼�ڵ��ϵ 

void init()
{
    memset(parents, -1, sizeof(parents));
    memset(from, -1, sizeof(from));
    memset(depth, -1, sizeof(depth));
}

//���� 
void getData()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        parents[v][0] = u;
        from[v] = 1;
    }
    //��ͼ����¼�ڵ��2��0�������ȣ���Ǹõ��и��� 
    for (int i = 1; i <= n; ++i) {
        if (from[i] == -1) root = i;
    }//��root 
}

//���ѻ�ȡ�ڵ���� 
void getDepth_dfs(int u)
{
    int len = G[u].size();
    for (int i = 0; i < len; ++i) {
        int v = G[u][i];
        depth[v] = depth[u] + 1;
        getDepth_dfs(v);
    }
}

//���ѻ�ȡ��� 
void getDepth_bfs(int u)
{
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            depth[G[v][i]] = depth[v] + 1;
            Q.push(G[v][i]);
        }
    }
}

//��ȡÿһ���ڵ�Ķ��������� 
void getParents()
{
    for (int up = 1; (1 << up) <= n; ++up) {
        for (int i = 1; i <= n; ++i) {
            parents[i][up] = parents[parents[i][up - 1]][up - 1];
        }
    }
}

int Lca(int u, int v)
{
	//��u����Ƚϴ��һ����������� 
    if (depth[u] < depth[v]) swap(u, v);
    
    //���u������Ķ����ݿ�� 
    int i = -1, j;
    while ((1 << (i + 1)) <= depth[u]) ++i;
    
    //��u�������vһ�� 
    for (j = i; j >= 0; --j) {
    	//��ÿһ��>=ʱ���¶�������<ʱ�Ÿ��£�����u�ܵ�v�Ϸ� 
        if (depth[u] - (1 << j) >= depth[v]) {
            u = parents[u][j];
        }
    }
    //u��v�����ͬʱ�����uv��ͬһ�ڵ�ֱ�ӷ��� 
    if (u == v) return u;
    //��uv��Զ�����ڿ�ʼ�����ң��ҵ��������ڲ�ͬ��ʱ�����������������Ľ����������������ȵ��ӽڵ� 
    for (j = i; j >= 0; --j) {
        if (parents[u][j] != parents[v][j]) {
            u = parents[u][j];
            v = parents[v][j];
        }
    }
    //��������ˣ��������������������ȵ��ӽڵ㣬��˷������ĸ��� 
    return parents[u][0];
}

void questions()
{
    int q, u, v;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        int ans = Lca(u, v);
        cout << ans << endl;
        //cout << u << " �� " << v << " �������������(LCA)��: " << ans << endl; 
    }
}

int main()
{
    init();
    getData();
    depth[root] = 1;
    getDepth_dfs(root);
    //getDepth_bfs(root);
    getParents();
    questions();
}
/*
9
1 2
1 3
1 4
2 5
2 6
3 7
6 8
7 9
5
1 3
5 6
8 9
8 4
5 8
*/
