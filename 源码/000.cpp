#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int>&a,pair<string,int>&b){
	if(a.second==b.second)return a.first<b.first;
	else return a.second>b.second;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k,sum=0;cin>>n>>m>>k;
	vector<pair<string,int> >a;
	string tmp1;
	int tmp2;
	for(int i=0;i<n;i++){
		cin>>tmp1>>tmp2;
		if(tmp2<m&&tmp2>=60)sum+=20;
		else if(tmp2>=80&&tmp2<=100)sum+=50;
		if(tmp2>=m)a.push_back(make_pair(tmp1,tmp2));
	}
	sort(a.begin(),a.end(),cmp);
	cout<<sum<<endl;
	int rank=1,end=a.size();
	cout<<a[0].first<<' '<<a[0].second<<endl;
	for(int i=1;i<end;i++){
		if(a[i].second==a[i-1].second)end++;
		cout<<rank<<' '<<a[i].first<<' '<<a[i].second<<endl;}
	return 0;
}



//#include<bits/stdc++.h>
//#pragma GCC optimize(3,"Ofast","inline")
//using namespace std;
//int a[100005];
////int vis[100005]={0};
//inline int dfs(int cut,int sign){
////	vis[sign]=1;
//	cut++;
//	if(a[sign]==-1)return cut;
//	cut=dfs(cut,a[sign]);
//	return cut;
//}
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n,ans=0,cut=0;cin>>n;
//	vector<int>temp;
//	vector<int>temp_ans;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	for(int i=1;i<=n;i++){
//		if(a[i]==-1)temp.push_back(1);
//		else{
//			if(a[i]>temp.size()){
//				cut=dfs(1,a[i]);
//			}
//			else cut=temp[a[i]-1]+1;
//			temp.push_back(cut);
//			ans=max(cut,ans);}
//	}
//	cout<<ans<<endl;
////	for(int i=0;i<temp.size();i++)cout<<temp[i]<<endl;	
//	for(int i=1;i<=n;i++)if(temp[i-1]==ans)temp_ans.push_back(i);
//	for(int i=0;i<temp_ans.size();i++){
//		if(i==temp_ans.size()-1)cout<<temp_ans[i];
//		else cout<<temp_ans[i]<<' ';
//	}
//	cout<<endl;
//	return 0;
//}







//#include<bits/stdc++.h>
//using namespace std;
//int a[105];
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n,minn=INT_MAX;cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		minn=min(minn,a[i]);
//		}
//	for(int i=1;i<=n;i++){
//		cout<<'#'<<i<<endl;
//		for(int j=1;j<=a[i];j++){
//			if(j<=minn){
//				for(int k=i+n*10*(j-1);k<=n*10*j;k+=n)
//					cout<<k<<' ';
//				cout<<endl;}
//			else{
//				for(int k=minn*n*10+minn*10*(j-3)+i;k<=minn*n*10+minn*10*(j-2);k+=minn)
//					cout<<k<<' ';
//				cout<<endl;
//			}
//		}
//		
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t,sum=0;cin>>t;
//	map<string,int>people;
//	int tmp_num;
//	string tmp_name;
//	for(int i=0;i<t;i++){
//		cin>>tmp_name;
//		cin>>tmp_num;
////		getchar();
//		people.insert(make_pair(tmp_name,tmp_num));
//		sum+=tmp_num;
//	}
//	int avg=sum/t/2;
//	int ans1=INT_MAX;
//	map<string,int>::iterator it=people.begin();
////	map<string,int>::iterator it2=people.begin();
//	for(;it!=people.end();it++){
//		if(abs(it->second-avg)<ans1){
//			ans1=abs(it->second-avg);
//			tmp_name=it->first;
//			tmp_num=it->second;
//			}
//	}
//	cout<<avg<<' '<<tmp_name<<endl;
//
//	return 0;
//}
