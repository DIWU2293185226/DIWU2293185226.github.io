#include<iostream>
#define in for(int i=1;i<=n;i++)
#define work for(int i=1;i<=m;i++)
using namespace std;
long long sum[1000001<<2],add[1000001<<2];
int old[1000001],n,m,order;
//���� 
//���¸��ڵ� 
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
//st���ڶ�λ 
//���Ʊ�� 
void pushdown(int st,int ln,int rn){
	if(add[st]){
		//���Ʊ��
		add[st<<1]+=add[st];
		add[st<<1|1]+=add[st];
		//��������һ��
		sum[st<<1]+=add[st]*ln;
		sum[st<<1|1]+=add[st]*rn;
		//ԭ��Ǳ�0
		add[st]=0; 
	}
}
//���޸� 
void Update(int L,int C,int l,int r,int rt){//l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���  
    if(l==r){//��Ҷ�ڵ㣬�޸�   
        sum[rt]+=C;
//		add[st]+=C;  
        return;  
    }  
    int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);//�����ĵ��޸Ĳ���Ҫ���Ʊ�ǣ������޸ĺ������޸Ļ��ʹ��ʱ��Ҫ���Ʊ��  
    //���������ж������������û�������   
    if(L <= m) Update(L,C,l,m,rt<<1);  
    else       Update(L,C,m+1,r,rt<<1|1);  
    uppush(rt);}
//�������� 
void updata(int L,int R,int l,int r,int st,int value){
	if(L<=l&&r<=R){
		sum[st]+=value*(r-l+1);
		add[st]+=value;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(st,mid-l+1,r-mid);//������Ա�Ƕ��ԣ���������������ĸ��·�������һ�β�������ѯ���߸��£���ʱ�� 
	if(L<=mid)updata(L,R,l,mid,st<<1,value);
	if(mid<R)updata(L,R,mid+1,r,st<<1|1,value);
	uppush(st);//���±��ڵ���Ϣ 
}
//��ѯ���� 
long long query(int L,int R,int l,int r,int st){
	if(L<=l&&r<=R)return sum[st];
	int mid=(l+r)>>1;
	long long  ans=0;
	pushdown(st,mid-l+1,r-mid);//��֮ǰ��������������������� 
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
