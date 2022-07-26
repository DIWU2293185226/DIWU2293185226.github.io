#include<bits/stdc++.h>
using namespace std;
int main(){
	string stu;
	int t,l;
	while(cin>>t){
		l=0;
//		cin>>t;
		cin>>stu;
		for(int i=0;i<stu.length();i++)if(stu[i]=='L')l++;
		cout<<t-stu.length()+l<<' '<<l<<endl;
	} 
	return 0;
}


