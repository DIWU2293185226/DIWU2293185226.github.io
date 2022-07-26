//#include<iostream>
//#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//using namespace std;
//int main(){
//	TIE
//	int t;cin>>t;
//	while(t--){
//		string s,t;
//		int m;cin>>m;
//		
//	}
//	return 0;
//	
//}





#include<bits/stdc++.h>
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std;
long long sum[1000001<<2],add[1000001<<2];
int old[1000001];
//建树 
//更新父节点 
void uppush(int st){sum[st]=sum[st<<1]+sum[st<<1|1];}
void build(int l,int r,int st){
	if(l==r){
		sum[st]=old[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,st<<1);
	
	build(mid+1,r,st<<1|1);
	uppush(st);
}
//st用于定位 
//下推标记 
void pushdown(int st,int ln,int rn){
	if(add[st]){
		//下推标记
		add[st<<1]+=add[st];
		add[st<<1|1]+=add[st];
		//保持数据一致
		sum[st<<1]+=add[st]*ln;
		sum[st<<1|1]+=add[st]*rn;
		//原标记标0
		add[st]=0; 
	}
}

//查询区间 
long long query(int L,int R,int l,int r,int st){
	if(L<=l&&r<=R)return sum[st];
	int mid=(l+r)>>1;
	long long  ans=0;
	pushdown(st,mid-l+1,r-mid);
	if(L<=mid)ans+=query(L,R,l,mid,st<<1);
	if(mid<R)ans+=query(L,R,mid+1,r,st<<1|1);
	return ans;
}
int main(){
	TIE
	int n,m,temp;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>old[i];
	sort(old+1,old+1+n,greater<int>());
	build(1,n,1);
	while(m--){
		int x,y;cin>>x>>y;
		long long ans=0;
		ans=query(x-y+1,x,1,n,1);
		cout<<ans<<endl;
	}
	return 0;
	
}








//#include<iostream>
//#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//using namespace std;
//int main(){
//	TIE
//	int t;cin>>t;
//	while(t--){
//		int n,m,ans=0,temp;cin>>n>>m;
//		for(int i=0;i<n;i++){
//			cin>>temp;
//			ans+=temp;
//		}
//		if(ans-m>0)cout<<ans-m<<endl;
//		else cout<<0<<endl;
//	}
//	return 0;
//	
//}
