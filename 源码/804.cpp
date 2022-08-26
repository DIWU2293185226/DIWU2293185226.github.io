#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
	int n;cin>>n;
	if(n%2==0)cout<<0<<' '<<n/2<<' '<<n/2<<endl;
	else cout<<-1<<endl;
	}
    return 0;
}


//804div2.B
//#include<bits/stdc++.h>
//#pragma GCC optimize (2)
//using namespace std;
//inline void build2(vector<vector<int> >&a,int j,int m){
//	a[j][1]=1;
//	a[j][2]=1;
//	for(int i=5;i<m;){
//		if((i-1)%4==0){
//			a[j][i]=1;
//			a[j][i+1]=1;
//			i+=4;
//			}
//		}
//}
//inline void build1(vector<vector<int> >&a,int n,int m){
//	a[n][0]=1;
//	for(int i=3;i<m;){
//		if((i-3)%4==0){
//			a[n][i]=1;
//			a[n][i+1]=1;
//			i+=4;
//			}
//		}
//}
//int main(){
//	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int n,m;cin>>n>>m;
//		vector<vector<int> >a(100,vector<int>(100));
//		a[0][0]=1;
//		for(int i=3;i<m;){
//			if((i-3)%4==0){
//				a[0][i]=1;
//				a[0][i+1]=1;
//				i+=4;
//			}
//		}//构造第一行
//		int ans=0,key=2;
//		for(int i=1;i<n;i++){
//			if(ans%2==0){
//				if(a[i-1][0]==1){build2(a,i,m);key=2;}
//				else {build1(a,i,m);key=1;}
//				ans++;
//			}
//			else {
//				if(key==1){build1(a,i,m);ans++;}
//				else if(key==2){build2(a,i,m);ans++;}
//			}
//		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<m;j++)
//				cout<<a[i][j]<<' ';
//			cout<<endl;
//		}
//	}
//    return 0;
//}
