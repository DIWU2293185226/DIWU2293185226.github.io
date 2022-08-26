//#include<bits/stdc++.h>
//#define maxn 101
//using namespace std;
//int n,m;
//int cur[maxn];//状态数组 
//int topo[maxn];//答案数组 
//int head[maxn];//邻接表的实现，不喜欢这种实现的小伙伴可以用vector数组 
//int last[maxn*maxn];
//struct node{
//	int s;
//	int t;
//	node(int x,int y)
//	{
//		s = x;
//		t = y;
//	}
//};
//vector<node> v;
//int t;
//bool dfs(int u)
//{
//	cur[u] = -1;//标记为访问状态
//	for(int i=head[u];i!=-1;i = last[i])
//	{
//		if(cur[v[i].t]<0) return false;//节点处于访问状态，存在有向环，返回错误
//		if(!cur[v[i].t]&&!dfs(v[i].t)) return false ;//虽然该节点没有访问，但是他的子节点出现有向环，返回错误 
//	}
//	cur[u] = 1;//标记为结束状态
//	topo[--t] =  u;
//	return true;
//}
//void init()//初始化 
//{
//	memset(head,-1,sizeof(head));
//	memset(last,-1,sizeof(last));
//	memset(cur,0,sizeof(cur));
//	t = n;
//	int x,y;
//	v.clear();
//	for(int i=0;i<m;i++)
//	{
//		cin>>x>>y;
//		v.push_back(node(x,y));
//		last[i] = head[x];
//		head[x] = i;
//	}
//}
//bool topo_sort()
//{
//	for(int i=1;i<=n;i++)
//	{
//		if(!cur[i])
//		if(!dfs(i))
//		return false;
//	}
//	return true;
//}
//void AC()
//{
//	while(cin>>n>>m&&(m||n))
//	{
//		init();
//		if(topo_sort())
//		for(int i=0;i<n;i++)
//		cout<<topo[i]<<" ";
//		cout<<endl;
//	}
//}
//int main()
//{
//	AC();
//	return 0;
//}

//n为节点个数，m为给出的节点关系
//00标记结束，输出拓扑排序后的节点顺序 

#include<bits/stdc++.h>
#define maxn 101
using namespace std;
struct node
{
	int s;
	int t;
	node(int x,int y)
	{
		s = x;
		t = y;
	}
};
vector<int> ans;//答案 
vector<node> v;
queue<int> q;//队列 
bool book[maxn];//标记数组，不能重复访问 
int head[maxn];
int last[maxn*maxn];
int de[maxn];//度 
int n,m;
void init()
{
	memset(head,-1,sizeof(head));
	memset(last,-1,sizeof(last));
	memset(book,0,sizeof(book));
	memset(de,0,sizeof(de));
	v.clear();
	int x,y;
	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		v.push_back(node(x,y));
		de[y]++;
		last[i] = head[x];
		head[x] = i;
	}
}
void find_point()//找到入度为0的点，入队 
{
	for(int i=1; i<=n; i++)
	{
		if(!book[i]&&!de[i])
		{
			q.push(i);
			book[i] = true;
		}
	}
}
void topo_sort()
{
	ans.clear();
	find_point();
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		ans.push_back(t);
		for(int i = head[t]; i!=-1; i = last[i])
		{
			de[v[i].t]--;
		}
		find_point();
	}
	if(ans.size()<n)
		cout<<"false"<<endl;
	else
		for(int i=0; i<n; i++)
			cout<<ans[i]<<" ";
	cout<<endl;
}
void AC()
{
	while(cin>>n>>m&&(n||m))
	{
		init();
		topo_sort();
	}
}
int main()
{
	AC();
	return 0;
}
