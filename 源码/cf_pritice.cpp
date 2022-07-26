//n个数的数组，分成两部分，使得两部分分别做xor，取两者加和最大的情况 
//贪心，优先高位异 
#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000001],ans;
int mian(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,less);
	
}
