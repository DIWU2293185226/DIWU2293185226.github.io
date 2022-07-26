#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n,a,b,c,temp;cin>>t;
	while(t--){
		cin>>n;
		if(n%3==0)cout<<n/3<<' '<<n/3+1<<' '<<n/3-1<<endl;
		else {
			temp=n/3;
			if(n-3-2*temp!=0)cout<<temp+1<<' '<<temp+2<<' '<<n-3-2*temp<<endl;
			else cout<<temp<<' '<<temp+2<<' '<<n-3-2*temp+1<<endl;
		}
	}
	return 0;
}
