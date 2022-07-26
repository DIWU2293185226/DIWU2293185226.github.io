#include<bits/stdc++.h>
using namespace std; 
vector<string>a;
set<string>index;
int main(){
	string temp;
	int n,m;cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,temp);
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	cout<<endl;
	for(int i=0;i<a.size();i++)cout<<a[i]<<endl;
	for(int i=0,j=0;i<n;i++)index.insert(a[i]);
	cout<<endl;
	for(set<string>::iterator it=index.begin();it!=index.end();it++)cout<<*it<<endl;
	int cut=0,num[index.size()];
	set<string>::iterator it=index.begin();
	for(int i=0,j=0;i<a.size();i++){
		if(a[i]==*it)cut++;
		else{
			num[j]=cut;
			cut=1;
			it++;
			j++;
		}
	}
	cout<<index.size()<<endl;
	it=index.begin();
	for(int i=0;i<index.size();i++,it++)cout<<num[i]<<' '<<*it<<endl;
    return 0;
}
