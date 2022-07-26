#include<iostream>
#define in for(int i=1;i<=n;i++)
#define work for(int i=1;i<=m;i++)
using namespace std;
long long sum[1000001<<2],add[1000001<<2];
int old[1000001],n,m,order;
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
//点修改 
void Update(int L,int C,int l,int r,int rt){//l,r表示当前节点区间，rt表示当前节点编号  
    if(l==r){//到叶节点，修改   
        sum[rt]+=C;
//		add[st]+=C;  
        return;  
    }  
    int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);//单独的点修改不需要下推标记，但点修改和区间修改混合使用时需要下推标记  
    //根据条件判断往左子树调用还是往右   
    if(L <= m) Update(L,C,l,m,rt<<1);  
    else       Update(L,C,m+1,r,rt<<1|1);  
    uppush(rt);}
//更新区间 
void updata(int L,int R,int l,int r,int st,int value){
	if(L<=l&&r<=R){
		sum[st]+=value*(r-l+1);
		add[st]+=value;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(st,mid-l+1,r-mid);//对于相对标记而言，懒操作对子区间的更新发生在下一次操作（查询或者更新）的时候 
	if(L<=mid)updata(L,R,l,mid,st<<1,value);
	if(mid<R)updata(L,R,mid+1,r,st<<1|1,value);
	uppush(st);//更新本节点信息 
}
//查询区间 
long long query(int L,int R,int l,int r,int st){
	if(L<=l&&r<=R)return sum[st];
	int mid=(l+r)>>1;
	long long  ans=0;
	pushdown(st,mid-l+1,r-mid);//对之前打标的区间更新他的子区间 
	if(L<=mid)ans+=query(L,R,l,mid,st<<1);
	if(mid<R)ans+=query(L,R,mid+1,r,st<<1|1);
	return ans;
}
int main(){
	cin>>n>>m;
	in cin>>old[i];
	build(1,n,1);
//	for(int i=0;i<n<<1;i++) cout<<sum[i]<<endl;
	work{
		int l,r,k;
		long long ans=0;
		cin>>order;
		if(order==1){
			cin>>l>>r>>k;
			updata(l,r,1,n,1,k);
		}
		else{
			cin>>l>>r;
			ans=query(l,r,1,n,1);
			cout<<ans<<endl;
		}	
	}
	return 0;
}
