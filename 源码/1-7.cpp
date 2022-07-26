#include<iostream>
#include<string>
#include<vector>
//inline int read()
//{
//	int x=0,w=1; char c=getchar();
//	while (c<'0' || c>'9') {if (c=='-') w=-1; c=getchar();}
//	while (c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
//	return w*x;
//}
using namespace std;
int cut;
string A,B;
string ca[1000],cb[1000];
void dfs(int ptr,int l){
	int temp;
	for(int i=0;i<l;i++){
		if(ptr=A.find(ca[i])){
			A.erase(ptr,ptr+ca[i].size());
			A.insert(ptr,cb[i]);
			cut++;
			dfs(ptr,l);
		}
	}
	if(A==B&&cut<11)return;
	else if(cut>10)return;
	return;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string temp;cin>>A>>B;
	int i=0;
	while(cin>>temp){
		ca[i]=temp;
		cin>>cb[i];
		i++;
	}
	dfs(0,i);
	if(cut<11)cout<<cut<<endl;
	else cout<<"NO ANSWER!"<<endl;
	return 0;
}
