#include<iostream>
#include<queue>
#include<algorithm>
#define read for(int i=0;i<n;i++)
#define read1 for(int i=1;i<n;i++)
//using namespace std;
//int a[10001];
////priority_queue<int>q;
//int main(){
//	int n;
//	cin>>n;
//	read
//		cin>>a[i];
//	sort(a,a+n);
////	read
////		q.push(a[i]);
//	long long ans=0,temp=a[0];
//	read1{
//		temp+=a[i];
//		ans+=temp;
//		}
//	cout<<ans<<endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//优先队列是线性复杂度 
using namespace std;
int temp,n,ans;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	cin>>n;
	read cin>>temp,q.push(temp);
	while(q.size()>=2){
		int temp_a=q.top();q.pop();
		int temp_b=q.top();q.pop();
		ans+=temp_a+temp_b;
		q.push(ans);
	}
	cout<<ans<<endl;
	return 0;
}
