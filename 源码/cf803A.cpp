#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int t;
	cin>>t;
	while(t--){
		int n,temp;
		cin>>n;
		for(int i=0;i<n;i++)cin>>temp;
		cout<<temp<<endl;
	}
	return 0;
}

