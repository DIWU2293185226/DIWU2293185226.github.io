#include<iostream>
using namespace std;
int slove(int n){
	int temp=0,arr[21];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=n-1;i>0;i--)if(arr[i]>arr[i-1])swap(arr[i],arr[i-1]);
	int ans=arr[0],temp_max=arr[0];
	for(int i=1;i<n;i++){
		temp+=arr[i];
		if(temp_max<=temp){
			temp-=temp_max;
			temp_max=max(temp,arr[i]);
			temp=min(temp,arr[i]);
			if(i==n-1)ans+=temp;
			else ans+=temp_max;
		}
	}
	return ans;
}
int main(){
	int ans=0,n[4];
	for(int i=0;i<4;i++)cin>>n[i];
	for(int i=0;i<4;i++)ans+=slove(n[i]);
	cout<<ans<<endl;
	return 0;
}
