//#include<bits/stdc++.h>
//using namespace std;
//const int N=10010;
//vector<pair<int,long long>>vec[N];
//priority_queue< pair< long long, int > >que;
//bool vis[N];
//long long f[N];
//long long dis[N];
//int n,m,x,y;
//long long b,v;




#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
long long f[N];//��ķ��� 
vector< pair< int , long long> >vec[N];//��� 
priority_queue< pair< long long, int > >que;
int vis[N];
long long dis[N];
long long b, v;
int n, m, x, y;
int check(int x)
{
	if(f[1] > x) return 0;//�����һ����Ͳ�����,ֱ�ӷ��ز��� 
	for(int i = 1; i <= n; ++ i){
		dis[i] = 1e18;//�ر��ĳ�ʼ��,û�л��´� 
		vis[i] = 0;
	}
	dis[1] = 0;
	que.push(make_pair(0, 1));//�޸ĵ�dijk 
	while(!que.empty()){
		int u = que.top().second;
		que.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < vec[u].size(); ++ i){
			int v = vec[u][i].first;
			if(f[v] > x) continue;//�������չ�ĵ㲻����Ҫ��,����Ѱ�� 
			long long w = vec[u][i].second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				que.push(make_pair(-dis[v], v));
			if(v == n){//����Ѿ�����,�ж��Ƿ�����ֵ��ʣ�� 
				if(dis[n] >= b) return 0;
				else return 1;
			}	
		}
	}
}
	return 0;//���û�е���,ֱ�ӷ��ز��� 
}
int main()
{
	long long mxx = -1;
	scanf("%d%d%lld", &n, &m, &b);
	for(int i = 1; i <= n; ++ i){
		scanf("%lld", &f[i]);
		mxx = max(mxx, f[i]);//Ѱ���ϱ߽� 
	}
	for(int i = 1; i <= m; ++ i){
		scanf("%d%d%lld", &x, &y, &v);
		vec[x].push_back(make_pair(y, v));
		vec[y].push_back(make_pair(x, v));
	}
	long long ans = -1, l = 1, r = mxx;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(check(mid)) ans = mid, r = mid - 1;//����ans 
		else	l = mid + 1;
	}
	if(ans == -1) puts("AFK");//���ÿ�ζ�û����չ�ɹ�˵�����ܵ��� 
	else printf("%lld\n", ans);
	return 0;
}
