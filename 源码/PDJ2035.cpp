//求A^B的最后三位数表示的整数。
//说明：A^B的含义是“A的B次方”
#include<iostream>
using namespace std;
void slove(long long n,int m){
	long long ans=1;
	while(m){
		if(m&1){ans*=n%1000;m--;}//奇数单拆一个base 
		n=n*n%1000;//偶数，拆成n/2个base^2 
		m>>=1;
	}
	cout<<ans%1000<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int m;
	long long n;
	cin>>n>>m;
	while(n||m){
		slove(n,m);
		cin>>n>>m;
	}
	return 0;
}
