










//#include<iostream>
//#include<vector>
//using namespace std;
//inline int read()
//{
//	int x=0,w=1; char c=getchar();
//	while (c<'0' || c>'9') {if (c=='-') w=-1; c=getchar();}
//	while (c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
//	return w*x;
//}
//int main(){
//	int n,m,temp,cut=0;n=read();m=read();
//	int vis[m+1]={0};
//	vector<int>a;a.push_back(0);
//	for(int i=1;i<=n;i++){
//		temp=read();
//		a.push_back(temp);
//	}
//	int st=1,en=1;
//	for(;en<=n;en++){
//		if(!vis[a[en]])cut++;
//		vis[a[en]]++;
////		if(vis[a[st]]>1)st++;
//		if(cut==m)break;
//	}
//	for(;st<=en;st++){
//		if(vis[a[st]]==1)break;
//		else{
//			vis[a[st]]--;
//		}
////		ans=min(ans,en-st);
//	}
//	int i=en+1,l=st,r=en;
//	while(i<n)
//    {
//        vis[a[i]]++;
//        en++;
//        i++;
//        while(vis[a[st]]>1)
//            vis[a[st++]]--;
//        if(r-l>en-st)
//        {
//            r=st;
//            l=en;
//        }
//    }
//	cout<<l<<' '<<r<<endl;
//	return 0;
//}





//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<deque>
//using namespace std;
//const int maxsize = 2000010;
//int n,m;
//struct node
//{
//    int val;
//    int pos;
//}A[maxsize];
//deque<node> min_Q;
//inline int read()
//{
//	int x=0,w=1; char c=getchar();
//	while (c<'0' || c>'9') {if (c=='-') w=-1; c=getchar();}
//	while (c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
//	return w*x;
//}
//int min_que[maxsize]; 
//int main()
//{
//    n = read(),m = read();
//    for(int i = 1;i <= n;i++)
//    {
//        A[i].val = read();
//        A[i].pos = i - 1;
//    }
//    min_que[0] = 0;
//    for(int i = 1;i < n;i++)
//    {
//        while(!min_Q.empty()&&min_Q.back().val >= A[i].val)
//            min_Q.pop_back();
//        min_Q.push_back(A[i]);
//        while(!min_Q.empty()&&min_Q.front().pos < i - m)
//            min_Q.pop_front();
//        min_que[i] = min_Q.front().val;
//    }
//    for(int i = 0;i < n;i++)
//        printf("%d\n",min_que[i]);	
//            
//}




//#include<iostream>
//#include<queue>
//using namespace std;
//priority_queue<pair<long long,int>,vector<pair<long long,int> >,less<pair<long long,int> > >maxg;
//priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >ming;
//inline int read()
//{
//	int x=0,w=1; char c=getchar();
//	while (c<'0' || c>'9') {if (c=='-') w=-1; c=getchar();}
//	while (c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
//	return w*x;
//}
//long long a[1000001];
//vector<long>l;
//vector<long>h;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n,k;cin>>n>>k;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	for(int i=1;i<=n;i++){
//		maxg.push(make_pair(a[i],i));
//		ming.push(make_pair(a[i],i));
//		if(i>=k){
//			while(maxg.top().second<=i-k)maxg.pop();
//			while(ming.top().second<=i-k)ming.pop();
//			cout<<ming.top().first<<' ';
//			h.push_back(maxg.top().first);	
//		}
//	}
//	cout<<endl;
//	for(int i=0;i<h.size();i++)cout<<h[i]<<' ';
//	return 0;
//}




//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//inline int read()
//{
//	int x=0,w=1; char c=getchar();
//	while (c<'0' || c>'9') {if (c=='-') w=-1; c=getchar();}
//	while (c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
//	return w*x;
//}
//struct node{
//	int index;
//	int value;
//	node(int in,int va):index(in),value(va){};
//};
//bool operator >(const node &v1,const node &v2){
//		return v1.value>v2.value;
//}
//bool operator <(const node &v1,const node &v2){
//		return v1.value<v2.value;
//}
//priority_queue<node>a;
//vector<int>old;
//int main(){
//	int n,k,x;cin>>n>>k;
//	for(int i=0;i<n;i++)cin>>x,old.push_back(x);
//	for(int i=0;i<n;i++){
//		a.push(node(i,old[i]));
//		if(i>=k-1){
//			while(a.top().index<i-k+1)a.pop();
//			cout<<a.top().value<<endl;
//		}
//	}
//	return 0;
//}
