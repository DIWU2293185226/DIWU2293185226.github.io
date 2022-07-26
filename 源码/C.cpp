//804div2
#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
int p[100005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,temp;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>temp;
			p[temp]=i;
		}
		int l=p[0],r=p[0],ans=1;
		for(int i=1;i<=n-1;i++){
			if(p[i]>r){
				r=p[i];
			}
			else if(p[i]<l){
				l=p[i];
			}
			else{
				ans=(ans*(r-l+1-i))%m;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}





//// Educational Codeforces Round 131 (Rated for Div. 2)
//#include<bits/stdc++.h>
//using namespace std;
//long long a[1000000];
//int n,m,temp;
//bool check(long long t){
//	long long cut1=0,cut2=0;
//	for(int i=1;i<=n;i++){
//		temp=min(a[i],t);
//		if(temp==a[i]){
//			cut1+=t-a[i]>>1;
//		}
//		else cut2+=a[i]-t;
//	}
//	if(cut1>=cut2)return true;
//	else return false;
//	
//}
//
////二分答案，每次检查不擅长的人能分担的任务数是否小于擅长的人多出来的任务数 
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int temp;cin>>n>>m;
//		for(int i=1;i<=n;i++)a[i]=0;
//		for(int i=1;i<=m;i++){
//			cin>>temp;
//			a[temp]++;
//		}
////		sort(a+1,a+n+1);
//		long long l=1,r=m*2;
//		while(l<r){
//			long long mid=l+r>>1;
//			if(check(mid))r=mid;
//			else l=mid+1;
//		}
//		cout<<l<<endl;
//	}
//	return 0;
//}



//809C
//#include<iostream>
////#define int long long
//using namespace std;
//signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		long long n,ans=0;cin>>n;
//		long long a[n+1];
//		long long dp[n+1],p[n+1];
//		//p记录有几座cool city，dp记录补充的方块数 
//		for(int i=1;i<=n;i++)cin>>a[i];
//		if(n%2==1){
//			for(int i=2;i<n;i+=2)ans+=max(0ll,max(a[i-1],a[i+1])-a[i]+1);
//			cout<<ans<<endl;
//		}
//		//偶数会存在2，3都能选，4，5等等都能选的情况，直接步进一定有落单
//		// 因为要cool尽量多，所以需要判断p 
//		else{
//			dp[2]=max(0ll,max(a[3],a[1])-a[2]+1);
//			p[2]=1;p[3]=1;p[4]=2;
//			dp[3]=max(0ll,max(a[4],a[2])-a[3]+1);
//			dp[4]=dp[2]+max(0ll,max(a[5],a[3])-a[4]+1);
//			for(int i=5;i<=n;i++){
//				if(p[i-2]==p[i-3]){
//					p[i]=max(p[i-2],p[i-3])+1;
//					dp[i]=min(dp[i-2],dp[i-3])+max(0ll,max(a[i+1],a[i-1])-a[i]+1);
//				}
//				else if(p[i-2]>p[i-3]){
//					p[i]=p[i-2]+1;
//					dp[i]=dp[i-2]+max(0ll,max(a[i+1],a[i-1])-a[i]+1);
//				}
//				else {
//					p[i]=p[i-3]+1;
//					dp[i]=dp[i-3]+max(0ll,max(a[i+1],a[i-1])-a[i]+1);
//				}
//			}
//			cout<<min(dp[n-1],dp[n-2])<<endl;
//		}
//
//	}
//	return 0;
//}
