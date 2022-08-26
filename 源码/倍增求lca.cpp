#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

//前置定理：二次幂序列中任意不同数可以组合出所有的正整数 

const int maxn = 10005;
int parents[maxn][20], depth[maxn];
//parents数组用于记录，某节点的二次幂祖先；depth记录节点深度 
int n, from[maxn], root = -1;
//from判断节点是否有父亲，找root用 
vector<int> G[maxn];
//记录节点关系 

void init()
{
    memset(parents, -1, sizeof(parents));
    memset(from, -1, sizeof(from));
    memset(depth, -1, sizeof(depth));
}

//建树 
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
    //建图，记录节点的2的0次幂祖先，标记该点有父亲 
    for (int i = 1; i <= n; ++i) {
        if (from[i] == -1) root = i;
    }//求root 
}

//深搜获取节点深度 
void getDepth_dfs(int u)
{
    int len = G[u].size();
    for (int i = 0; i < len; ++i) {
        int v = G[u][i];
        depth[v] = depth[u] + 1;
        getDepth_dfs(v);
    }
}

//广搜获取深度 
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

//获取每一个节点的二次幂祖先 
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
	//让u是深度较大的一个，方便操作 
    if (depth[u] < depth[v]) swap(u, v);
    
    //获得u深度最大的二次幂跨度 
    int i = -1, j;
    while ((1 << (i + 1)) <= depth[u]) ++i;
    
    //让u的深度与v一致 
    for (j = i; j >= 0; --j) {
    	//在每一次>=时更新而不是在<时才更新，避免u跑到v上方 
        if (depth[u] - (1 << j) >= depth[v]) {
            u = parents[u][j];
        }
    }
    //u和v深度相同时，如果uv是同一节点直接返回 
    if (u == v) return u;
    //从uv最远的祖宗开始往下找，找到他们祖宗不同的时候往上跳，最后迭代的结果就是最近公共祖先的子节点 
    for (j = i; j >= 0; --j) {
        if (parents[u][j] != parents[v][j]) {
            u = parents[u][j];
            v = parents[v][j];
        }
    }
    //上面解释了，迭代结果是最近公共祖先的子节点，因此返回他的父亲 
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
        //cout << u << " 和 " << v << " 的最近公共祖先(LCA)是: " << ans << endl; 
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
