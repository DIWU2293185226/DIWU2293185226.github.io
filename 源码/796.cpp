#include<iostream>
#include<cmath>
using namespace std;
int a[100001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,ans=0,cut=0;cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]%2==0){
				ans+=a[i];
				cut++;
			}
		}
		int mi=INT_MAX;
		if(cut!=n){
			cout<<cut<<endl;
		}
		else {
			for(int i=0;i<n;i++){
				int cur=0;
				while(a[i]%2==0){
					a[i]/=2;
					cur++;
				}
				mi=min(cur,mi);
			}
			cout<<mi+n-1<<endl;
		}
		}
		
	return 0;}








//#include<iostream>
//#include<cmath>
////ֻ��һλ1�������λ��1
////����λ������1����͵�һλ1λ��1 
//using namespace std;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int cut=0,n,temp,pos,mx=pow(2,30);cin>>n;
//		//��¼������1�ĸ�����λ�ã�����2����
//		for(int i=30;i>=0;i--){
//			if(n<<i&mx){
//				cut++;
//				if(cut==2)break;
//				pos=i;
//			}
//		}
//		temp=pow(2,30-pos);
//		if(n==1||n==2)cout<<3<<endl;
//		else {
//			if(cut==2) cout<<temp<<endl;
//			else cout<<temp+1<<endl;
//		}
//	}
//	return 0;
//}
