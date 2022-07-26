#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
vector<pair<int,int>>a;
bool operator cpm(const pair<int,int>&temp){
	return this.x<temp.x;
}
int main(){
	int n,a,b;
	cin>>a,b;
	for(int i=0;i<n;i++){
		int temp_a,temp_b;
		cin>>temp_a>>temp_b;
		a.push_back(make_pair(tmep_a,temp_b));
	}
	sort(a.begin(),a.end(),cmp);
	int max=0;
	for(int )
}





//#include<cstring>
//using namespace std;
//int t,n;
//int s[200005];
//int main(){
//	scanf("%d",&t);
//	while(t--){
//		memset(s,0,sizeof(s));
//		scanf("%d",&n);
//		puts("2"); 
//		for(int i=1;i<=n;i++){
//			if(s[i]) continue;
//			int a=i;
//			while(a<=n){
//				printf("%d ",a);
//				s[a]=1;
//				a*=2;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			if(!s[i]) printf("%d ",i);
//		}
//		printf("\n");
//	}
//	return 0;}





//#include<iostream>
//#include<cmath>
//#include<vector>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int t,cut=0,n;
//	cin>>t;
//	while(t--){
//		cin>>n;
//		int i=1,d=0;
//		while(1){
//			int temp=pow(i,2);
//			if(temp<=n){d++;}
//			else {
//				if(n>=d*(d+1))d++;
////				if(n==3)d++;
//				break;
//			}
//			i++;
//		}
//		cout<<d<<endl;
//		int j=1;
//		vector<int>a(n);
//		bool vis[n]={0};
//		for(int i=1;i<=n;i++)a[i-1]=i;
//		for(int i=1;i*d<=n;i++){
//			int j=i;
//			while(1){
//				if(j*d<=n){
//					if(!vis[j-1]&&!vis[j*d-1]){
//						vis[j-1]=1;
//						vis[j*d-1]=1;
//						cout<<j<<' '<<j*d<<' ';}
//					else if(vis[j-1]&&!vis[j*d-1]){
//						vis[j-1]=1;
//						vis[j*d-1]=1;
//						cout<<j*d<<' ';}
//					j*=d;
//				}
//				else break;	
//			}
//		}
//		for(int i=0;i<a.size();i++)if(!vis[i])cout<<a[i]<<' ';
//		cout<<endl;
//	}
//	return 0;
//}
