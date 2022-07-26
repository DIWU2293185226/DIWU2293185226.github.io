#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;

struct edge{
	int to,next,dis;
};
edge e[maxn];
//bool vis[maxn];
int head[maxn],dis[maxn];
int n,m,cnt;
struct node{
	int pos;
	int dis;
	node(int p,int d){pos=p;dis=d;}
	bool operator <(const node &n)const{return n.dis<dis;}
};
void add_edge(){
	cnt++;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	e[cnt].dis=c;
	e[cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
priority_queue<node>q;
void slove(int s){
	for(int i = 1; i <= n; ++i) dis[i] = maxn;
    dis[s] = 0;
    q.push(node(s, 0));
    while(!q.empty()) {
        node cur = q.top(); q.pop();
        if(dis[cur.pos] < cur.dis) continue;
        for(int i = head[cur.pos]; i; i = e[i].next) {
            if(dis[e[i].to] > cur.dis + e[i].dis) {
                dis[e[i].to] = cur.dis + e[i].dis;
                q.push(node(e[i].to, dis[e[i].to]));
            }
        }
    }
}
int main(){
	int ans;
	memset(head,-1,sizeof(head));
//	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)dis[i]=maxn;
	for(int i=0;i<m;i++)add_edge();
	slove(1);
	for(int i=1;i<=n;i++)ans+=dis[i];
	slove(n);
	for(int i=1;i<=n<<1;i++)ans+=dis[i];
	printf("%d",ans);
	return 0;
}
