#include"iostream.h"
//#include<cmath>
const long maxn=1000001;
using namespace std;
long long ans[maxn<<2],sign_add[maxn<<2],sign_mul[maxn<<2];
int a[maxn],n,m,p;
void new_fa(int pos){ans[pos]=(ans[pos<<1]+ans[pos<<1|1])%p;}
void build(int l,int r,int pos){
	if(l==r){
		ans[pos]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	new_fa(pos);
}
void pushdown(int pos,int ln,int rn){
	ans[pos<<1]=(ans[pos<<1]*sign_mul[pos]+sign_add[pos]*ln)%p;
	ans[pos<<1|1]=(ans[pos<<1|1]*sign_mul[pos]+sign_add[pos]*rn)%p;
	sign_mul[pos<<1]=(sign_mul[pos<<1]*sign_mul[pos])%p;
	sign_mul[pos<<1|1]=(sign_mul[pos<<1|1]*sign_mul[pos])%p;
	sign_add[pos<<1]=(sign_mul[pos]*sign_add[pos<<1]+sign_add[pos])%p;
	sign_add[pos<<1|1]=(sign_mul[pos]*sign_add[pos<<1|1]+sign_add[pos])%p;
	sign_add[pos]=0;
	sign_mul[pos]=1;
	
}

void updata_add(int L,int R,int l,int r,int pos,int value){
	if(L<=l&&r<=R){
		ans[pos]=(ans[pos]*value*(r-l+1))%p;
		sign_add[pos]=(sign_add[pos]+value)%p;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(pos,mid-l+1,r-mid);
	new_fa(pos);
	if(L<=mid)updata_add(L,R,l,mid,pos<<1,value);
	if(R>mid)updata_add(L,R,mid+1,r,pos<<1|1,value);
	new_fa(pos);
}
void updata_mul(int L,int R,int l,int r,int pos,int value){
	if(l>=L&&r<=R){
		sign_add[pos]=(sign_add[pos]*value)%p;
		sign_mul[pos]=(sign_mul[pos]*value)%p;
		ans[pos]=(ans[pos]*value)%p;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(pos,mid-l+1,r-mid);
	ans[pos]=ans[pos<<1]+ans[pos<<1|1];
	if(L<=mid)updata_mul(L,R,l,mid,pos<<1,value);
	if(R>mid)updata_mul(L,R,mid+1,r,pos<<1|1,value);
	new_fa(pos);
}
long long query(int L,int R,int l,int r,int pos){
	if(L<=l&&r<=R){return ans[pos];}
	int mid=(l+r)>>1;
	long long ans=0;
	pushdown(pos,mid-l+1,r-mid);
	if(L<=mid)ans=(ans+query(L,R,l,mid,pos<<1))%p;
	if(R>mid)ans=(ans+query(L,R,mid+1,r,pos<<1|1))%p;
	return ans;
}
int main(){
	int l,r,k;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int order;
		long long ans=0;
		cin>>order>>l>>r;
		switch(order){
			case 1:
				cin>>k;
				updata_mul(l,r,1,n,1,k);
				break;
			case 2:
				cin>>k;
				updata_add(l,r,1,n,1,k);
				break;
			case 3:
				ans=query(l,r,1,n,1);
				cout<<ans%p<<endl;
				break;
		}
	}
	return 0;
}
