//��A^B�������λ����ʾ��������
//˵����A^B�ĺ����ǡ�A��B�η���
#include<iostream>
using namespace std;
void slove(long long n,int m){
	long long ans=1;
	while(m){
		if(m&1){ans*=n%1000;m--;}//��������һ��base 
		n=n*n%1000;//ż�������n/2��base^2 
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
