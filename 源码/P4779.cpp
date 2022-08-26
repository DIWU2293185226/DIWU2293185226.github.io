#include<bits/stdc++.h>
using namespace std;
const int MaxN = 100010, MaxM = 500010;
struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
int n, m, s;

inline void add_edge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
    node(int d,int p){dis=d;pos=p;}
};
priority_queue<node> q;
void dijkstra()
{
    dis[s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if( vis[x] )
            continue;
        vis[x] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[y] > dis[x] + e[i].dis )
            {
                dis[y] = dis[x] + e[i].dis;
                if( !vis[y] )
                {
                    q.push( ( node ){dis[y], y} );
                }
            }
        }
    }
}

int main()
{
    scanf( "%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;++i)dis[i] = INT_MAX;
    for( register int i=0; i<m; ++i )
    {
        register int u, v, d;
        scanf( "%d%d%d", &u, &v, &d );
        add_edge( u, v, d );
    }
    dijkstra();
    for( int i = 1; i <= n; i++ )
        printf( "%d ", dis[i] );
    return 0;
}












//#include<bits/stdc++.h>
//using namespace std;
//struct node{
//	int s;
//	int v;
//	int e;
//	node(int start,int value,int end){
//		s=start;
//		v=value;
//		e=end;
//	}
//};
//queue<int>ans;
//queue<node>a;
//int visit[maxn];
//int de[maxn];
//void init(){
//	memset(visit,0,sizeof(visit));
//	memset(de,0,sizeof(de));
//}
//int main(){
//	while(cin>>n>>m&&(n||m)){
//		init();
//		topo
//	}
//}
