#include<bits/stdc++.h>
using namespace std; 
vector<string>a;
int main(){
	string temp;
	char c;
	int n,m;cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,temp);
		a.push_back(temp);
	}
//	cout<<a[0]<<endl;
	int i=0;
	for(;i<n;i++){
		if(a[i].find("easy")!=-1||a[i].find("qiandao")!=-1)continue;
		else {m--;if(m==-1)break;}
	}
	if(m>-1)cout<<"Wo AK le"<<endl;
	else if(m==-1) cout<<a[i]<<endl;
    return 0;
}
