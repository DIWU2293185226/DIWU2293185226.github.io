//#include<bits/stdc++.h>
//using namespace std;
//int a[1000001];
//int main(){
//	int t;cin>>t;
//	while(t--){
//		int n,temp,key=1;cin>>n;
//		vector<int>odd;
//		vector<int>even;
//		for(int i=0;i<n;i++)cin>>a[i];
//		sort(a,a+n);
//		for(int i=0;i<n/2;i++)odd.push_back(a[i]);
//		for(int i=n/2;i<n;i++)even.push_back(a[i]);
//		for(int i=0,j=0,k=0;i<n;i++){
//			if((i+1)%2!=0){
//				if(j==odd.size())continue;
//				a[i]=odd[j];
//				j++;
//			}
//			else {
//				if(k==even.size())continue;
//				a[i]=even[k];
//				k++;
//			}
//		}
//		for(int i=0;i<n;i++){
//			if(i==0){
//				if(a[i]<a[n-1]&&a[i]<a[i+1]);
//				else {
//					key=0;
//					break;
//				}
//			}
//			else if(i==n-1){
//				if(a[i]>a[i-1]&&a[i]>a[0]);
//				else {
//					key=0;
//					break;
//				}
//			}
//			else if((i+1)%2==0&&i!=n-1){
//				if(a[i]>a[i-1]&&a[i]>a[i+1]);
//				else{
//					key=0;
//					break;
//				}
//			}
//			else if((i+1)%2!=0&&i!=0){
//				if(a[i]<a[i-1]&&a[i]<a[i+1]);
//				else{
//					key=0;
//					break;
//				}
//			}
//		}
//		if(key){
//			cout<<"YES"<<endl;
//			for(int i=0;i<n;i++){
//				cout<<a[i]<<' ';
//			}
//			cout<<endl;
//		}
//		else cout<<"NO"<<endl;
//	}
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int a[1000001];
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int n,key=1,ans=0;cin>>n;
//		for(int i=0;i<n;i++){
//			cin>>a[i];
//		}
//		for(int i=1;i<n;i++){
//			if(a[i-1]>a[i]){
//				ans++;
//				i++;
//			}
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}







//#include<iostream>
//using namespace std;
//inline void slove(){
//	int a[100];
//	int n,ans=0;cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//		ans+=a[i];
//	}
//	if(ans%n==0){
//		for(int i=0;i<n;i++){
//			if(a[i]==ans/n){
//				cout<<"YES"<<endl;
//				return;}
//		}
//	}
//	cout<<"NO"<<endl;
//}
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		slove();
//	}
//	return 0;
//}

