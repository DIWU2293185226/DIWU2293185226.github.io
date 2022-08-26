//#include<bits/stdc++.h>
//using namespace std;
//int p;
//struct node{
//	int i,j;
//	bool last;
//	bool operator <{a[p][i]+a[p+1][j]<a[p][ans.i]+a[p][ans.j]}
//	bool operator >{a[p][i]+a[p+1][j]>a[p][ans.i]+a[p][ans.j]}
//};
//int ans[2005];
//vector< vector<int> >a(0);
//vector<int>temp(0);
//priority_queue<node>q;
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		int n,m,tp;
//		cin>>n>>m;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<m;j++){cin>>tp;temp.push_back(tp);}
//			a.push_back(temp);
//			temp.clear();
//		}
//		
//	}
//	return 0;
//} 


//可行吗？A0依次把下面的数组扫一遍加上来 
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<queue>
//#include<vector>
//#define P pair<int,int>
//#define x first
//#define y second
//
//using namespace std;
//const int N=2010;
//
//int n,m,T;
//int a[N],b[N],c[N];
//
//void merge()   //将序列a和b组合后挑出前n小的数存储到a中
//{
//    priority_queue<P,vector<P>,greater<P> > heap;
//    for(int i=0;i<m;i++) heap.push({a[0]+b[i],0});
//    
//    for(int i=0;i<m;i++)
//    {
//        P t=heap.top();
//        heap.pop();
//        int s=t.x,p=t.y;
//        c[i]=s;
////        heap.push({s-a[p]+a[p+1],p+1});
//    }
//    for(int i=0;i<m;i++) a[i]=c[i];
//}
//
//
//int main()
//{
//    cin>>T;
//    while(T--)
//    {
//        scanf("%d%d",&n,&m);
//        for(int i=0;i<m;i++) scanf("%d",&a[i]);
//        sort(a,a+m);
//        for(int i=0;i<n-1;i++)
//        {
//            for(int j=0;j<m;j++) scanf("%d",&b[j]);
//            merge();
//        }
//        for(int i=0;i<m;i++) printf("%d ",a[i]);
//        puts("");
//    }
//    
//    return 0;
//}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int t,n,m;
struct node
{
	int a[2005];
}s[105];
int p;
struct mes
{
	int j,k;
	bool g;
	bool operator >(const mes b)const
	{
		return s[p].a[j]+s[p+1].a[k]<s[p].a[b.j]+s[p+1].a[b.k];
	}
	bool operator <(const mes b)const
	{
		return s[p].a[j]+s[p+1].a[k]>s[p].a[b.j]+s[p+1].a[b.k];
	}
};
mes make_mes(int x,int y,int z)
{
	mes ret;
	ret.j=x,ret.k=y,ret.g=z;
	return ret;
}
priority_queue<mes>q;
int b[2005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=n;++j)
			{
				scanf("%d",&s[i].a[j]);
			}
			sort(s[i].a+1,s[i].a+n+1);
		}
		for(int i=1;i<m;++i)
		{
			p=i;
			while(!q.empty())q.pop();
			q.push(make_mes(1,1,0));
			for(int j,k,t=1;t<=n;++t)
			{
				j=q.top().j;
				k=q.top().k;
				bool ab=q.top().g;
				q.pop();
				b[t]=s[i].a[j]+s[i+1].a[k];
				if(!ab)q.push(make_mes(j+1,k,ab));
				q.push(make_mes(j,k+1,1));
			}
			for(int j=1;j<=n;++j)
			{
				s[i+1].a[j]=b[j];
			}
		}
		for(int i=1;i<=n;++i)
		{
			printf("%d ",s[m].a[i]);
		}
		printf("\n");
	}
	return 0;
}

