
//С���� 

#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
struct ha//С����
{
    int x; 
    int d;//�ڵ��� 
    bool operator < (const ha &a) const 
    {
        return x > a.x;
    }
}; 
struct haha//С����
{
    int x; 
    int d;//�ڵ���
}; 
ha e;
haha ee;
int d[1000010];
priority_queue <ha> q;
int n, m, s, xx, yy, zz, i;
vector<haha> a[1000000];
int main()
{
    scanf("%d%d%d",&n ,&m ,&s);
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&xx ,&yy ,&zz);
        ee.d = yy;
        ee.x = zz;
        a[xx].push_back(ee);
    }
    for(i = 1; i <= n; i++) d[i] = 2000003647;
    e.d = s;
    e.x = 0; 
    d[s] = 0;
    q.push(e);//��� 
    while (!q.empty())//���зǿ� 
    {
        e = q.top(); q.pop();//����
        int v = e.d;//ȡ���ڵ���
        int d1 = e.x;
        if (d[v] < d1) continue;//˵����������ٴ�֮���������
        //�˴γ��ӵĲ�����s�����������·��
        //��������θ���ǰ��v�����ĵ��Ѿ�����һ���� 
        //���Ժ���Ҳ��������ɳڲ��� 
        int len = a[v].size(); 
        for(i = 0; i < len; i++)
        {
            haha g = a[v][i];
            if ((d[v] + g.x < d[g.d]) || (d[g.d] == -233))//�ɳڲ��� 
            {
                d[g.d] = d[v] + g.x;
                e.d = g.d;
                e.x = d[g.d];
                q.push(e);
            }
        }
    }
    for (i=1; i <= n; i++) //��� 
    if (d[i] == 2000003647) cout << 2147483647 << " "; else cout << d[i] << " ";
    return 0;
}

//ǰ���Ǵ洢 
/*
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 2147483647;
const int maxn = 10000 + 10;
const int maxm = 500000 + 10;
int n, m, s;
int fir[maxn], nxt[maxm], to[maxm], val[maxm], cnt;
void add_edge(int u, int v, int w) //ǰ���Ǽӱ�
{
    nxt[++cnt] = fir[u];
    fir[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
struct Node 
{
    int d, id;
    Node(){}
    Node(int d, int id) : d(d), id(id){}
    bool operator < (const Node& rhs) const
      {
        return d > rhs.d;//���� < �����
      }
};
int dis[maxn], vis[maxn];
void Dijkstra(int s)
{
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[s]=0;
    priority_queue<Node> Q;
    Q.push(Node(0,s));
    while(!Q.empty()) 
      {
        Node u = Q.top(); Q.pop();
        if(vis[u.id]) continue;  //��ĳ�����Ѿ������µ�����,�Ͳ����ٴθ���������
        vis[u.id] = 1;
        for(int e = fir[u.id]; e; e = nxt[e]) 
          {
            int v = to[e], w = val[e];
            if(u.d + w < dis[v]) 
              {
                dis[v] = u.d + w;
                Q.push(Node(dis[v],v));
              }
          }
      }
}
int main()
{
    scanf("%d%d%d",&n ,&m ,&s);
    for(int u, v, w, i=0; i < m; i++)
      {
        scanf("%d%d%d",&u ,&v ,&w);
        add_edge(u, v, w);
      }
    Dijkstra(s);
    for(int i = 1; i <= n; i++) printf("%d ", dis[i]);
    return 0;
}
*/

//pair�洢 
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#define MAXN 20000
#define INF 2147483647
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
struct edge
{
    int to;
    int cost;
};
vector<edge> G[MAXN];//g[i]--i to g[i].to cost cost
int n, m, s;
int dis[MAXN];
void dijk(int s)
{
    for(int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    pq.push(make_pair(0,s));
   // cout<<dis[s]<<endl;
    while(!pq.empty())
    {
        pii u = pq.top();
        pq.pop();
        int x = u.second; // bian hao
        //cout<<x<<endl;
        for(int i = 0; i < G[x].size(); i++)
        {
            edge e = G[x][i];
            if(dis[e.to] > dis[x] + e.cost)
            {
                dis[e.to] = dis[x] + e.cost;
                pq.push(make_pair(dis[e.to], e.to));
               // cout<<dis[e.to]<<endl;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s;
    int from, to, cost;
    edge in;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&from ,&to ,&cost);
        in.to = to; in.cost = cost;
        G[from].push_back(in);
    }
   // cout<<endl;
    dijk(s);
    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}
*/

