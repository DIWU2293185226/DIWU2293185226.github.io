#include<iostream>
#include<map>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,cut=0,temp;cin>>n;
		map<int,int>index;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(index.find(temp)==index.end()){
				index.insert(make_pair(temp,1));
			}
			else {
				index[temp]++;
			}
		}
		map<int,int>::iterator it=index.begin();
		for(;it!=index.end();it++){
			if(it->second>1)cut++;
		}
		if(index.size()>1){
			if(cut==index.size())cout<<cut<<endl;
			else cout<<cut+1<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}







//把没排序的与下去，与运算得到的值会越来越小，拿到X&a[i]=X 
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int n,minn=-1,temp;cin>>n;
//		for(int i=0;i<n;i++){
//			cin>>temp;
//			if(i!=temp)minn=temp&minn;
//		}
//		cout<<minn<<endl;
//	}
//	return 0;
//}












//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int n,cut=1,st;cin>>n;
//		string temp;cin>>temp;
//		if(n%2==0)st=n/2-1;
//		else st=n/2;
//		char c=temp[st];
//		for(int i=st-1;i>=0;i--){
//			if(temp[i]==c)cut++;
//			else break;
//		}
//		if(n%2!=0)cout<<2*cut-1<<endl;
//		else cout<<2*cut<<endl;
//	}
//	return 0;
//}

