#include<iostream>
#define find for(int i=1;i<n-1;i++)
using namespace std;
int a[1000001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int k,n;cin>>n>>k;
		for(int i=0;i<n;i++)cin>>a[i];
		if(k==1){
			cout<<(n-1)/2<<endl;
		}
		else {
		int count=0;
			find if(a[i]>a[i-1]+a[i+1])count++;
			cout<<count<<endl;
		}
	}
	
	return 0;
}

