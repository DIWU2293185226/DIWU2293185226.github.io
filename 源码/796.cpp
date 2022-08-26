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
////只有一位1，在最低位补1
////有两位及以上1，最低的一位1位补1 
//using namespace std;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int cut=0,n,temp,pos,mx=pow(2,30);cin>>n;
//		//记录二进制1的个数及位置，等于2跳出
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
