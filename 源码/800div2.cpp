//#include<bits/stdc++.h>
////#include<iostream>
////记录前缀和，末尾不为0.出现负数。提前出现0 
//#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//
//int main(){
//	TIE
//	int t;cin>>t;
//	while(t--){
//		int n,key=1;cin>>n;
//		long long a[n],sum[n];
//		cin>>a[0];
//		for(int i=1;i<n;i++){
//			cin>>a[i];
//			a[i]+=a[i-1];
//		}
//		for(int i=0;i<n;i++){
//			if(a[i]<0){
//				key=0;
//				break;
//			}
//			if(a[i]==0){
//				for(int j=i+1;j<n;j++)if(a[j]!=0)key=0;
//				break;
//			}
//		}
//		if(a[n-1])key=0;
//		if(key)cout<<"YES"<<endl;
//		else cout<<"NO"<<endl;
//	}
//	
//	
//	return 0;
//}
//








//B
//#include<bits/stdc++.h>
////#include<iostream>
//
//#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//
//int main(){
//	TIE
//	int t;cin>>t;
//	while(t--){
//		int n,p=0,q=1;cin>>n;
//		long long ans=0;
//		char a[n];
//		for(int i=0;i<n;i++)cin>>a[i];
//		for(;q<n;q++){
//			if(a[q]!=a[q-1])ans+=q;
//		}
//		cout<<ans+n<<endl;
//	}
//	return 0;
//}













//A
//#include<bits/stdc++.h>
////#include<iostream>
//
//#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//
//int main(){
//	TIE
//	int t;cin>>t;
//	while(t--){
//		int a,b;cin>>a>>b;
//		int key=a>b?0:1;
//		if(!key){
//			for(int i=0;i<b;i++)cout<<'0'<<'1';
//			for(int i=b;i<a;i++)cout<<'0';
//			cout<<endl;
//		}
//		else{
//			for(int i=0;i<a;i++)cout<<'1'<<'0';
//			for(int i=a;i<b;i++)cout<<'1';
//			cout<<endl;
//		}
//		
//	}
//	
//	return 0;
//}
