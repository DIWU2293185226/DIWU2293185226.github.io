//#include<bits/stdc++.h>
//using namespace std;
//
//int length,wide,C,mapp[3002][3002],Max=-999999999,maxx,maxy,f[3002][3002];
//
//int read(){
//	int s=0,w=1;char ch=getchar();
//	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
//	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
//	return s*w;
//}
//
//int main(){
//	length=read();wide=read();C=read();
//	for(int i=1;i<=length;i++)
//	   for(int j=1;j<=wide;j++){
//	       mapp[i][j]=read();
//	       f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+mapp[i][j];
//	   }
//	for(int i=1;i<=length-C+1;i++)
//	   for(int j=1;j<=wide-C+1;j++){
//	   	  int sum=f[i+C-1][j+C-1]+f[i-1][j-1]-f[i-1][j+C-1]-f[i+C-1][j-1];
//	   	  if(sum>Max)Max=sum,maxx=i,maxy=j;
//	   }
//	cout<<maxx<<" "<<maxy;
//	return 0;
//}




//#include<iostream>
//using namespace std;
//int a[10000][10000],ans;
//inline int slove(int i,int j,int c){
//	int ans=0;
//	for(;i<=i+c-1;i++){
//		for(;j<=j+c-1;j++)
//			ans+=a[i][j];
//	}
//	return ans;
//}
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n,m,c,x,y,temp=-99999;cin>>n>>m>>c;
//	for(int i=0;i<n;i++)
//		for(int j=0;j<m;j++)
//			cin>>a[i][j];
//	for(int i=0;i<n-c+1;i++){
//		for(int j=0;j<m-c+1;j++){
//			ans=slove(i,j,c);
//			if(ans>temp){
//				temp=ans;
//				x=i;
//				y=j;
//			}
//		}
//	}
//	cout<<x<<' '<<y<<endl;
//	return 0;
//}



//
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//const int MAXN=200200;
//char s[MAXN];
//set<pair<ll,ll> > st;
//set<pair<ll,ll> >::iterator it;
//
//int main()
//{
//	int T,n,c,q;
//	ll l,r,x,len;
//	scanf("%d",&T);
//	while(T--)
//	{
//		scanf("%d%d%d",&n,&c,&q);
//		scanf("%s",s+1);
//		len=n;
//		st.clear();
//		while(c--)
//		{
//			scanf("%lld%lld",&l,&r);
//			st.insert(make_pair(len+1,l));
//			len+=r-l+1;
//		}
//		while(q--)
//		{
//			scanf("%lld",&x);
//			while(x>n)
//			{
//				it=st.lower_bound(make_pair(x,1ll<<60));
//				it--;
//				x-=it->first-it->second;
//			}
//			printf("%c\n",s[x]);
//		}
//	}
//}

