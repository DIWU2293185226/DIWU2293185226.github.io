//#include<bits/stdc++.h>
//#define maxn 101
//using namespace std;
//int n,m;
//int cur[maxn];//״̬���� 
//int topo[maxn];//������ 
//int head[maxn];//�ڽӱ��ʵ�֣���ϲ������ʵ�ֵ�С��������vector���� 
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
//	cur[u] = -1;//���Ϊ����״̬
//	for(int i=head[u];i!=-1;i = last[i])
//	{
//		if(cur[v[i].t]<0) return false;//�ڵ㴦�ڷ���״̬���������򻷣����ش���
//		if(!cur[v[i].t]&&!dfs(v[i].t)) return false ;//��Ȼ�ýڵ�û�з��ʣ����������ӽڵ�������򻷣����ش��� 
//	}
//	cur[u] = 1;//���Ϊ����״̬
//	topo[--t] =  u;
//	return true;
//}
//void init()//��ʼ�� 
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

//nΪ�ڵ������mΪ�����Ľڵ��ϵ
//00��ǽ�����������������Ľڵ�˳�� 

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
vector<int> ans;//�� 
vector<node> v;
queue<int> q;//���� 
bool book[maxn];//������飬�����ظ����� 
int head[maxn];
int last[maxn*maxn];
int de[maxn];//�� 
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
void find_point()//�ҵ����Ϊ0�ĵ㣬��� 
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
