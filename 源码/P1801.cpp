#include<iostream>
#include<queue>
#include<vector>
#define read for(int i=0;i<n;i++)
#define order for(int i=0;i<m;i++)
#define make for(int j=p;i<index;j++)
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
vector<int>nums;
priority_queue<int,vector<int>,greater<int> >temp_min;
priority_queue<int>temp_max;
int p;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m,x,index;
	cin>>n>>m;
//	nums.push_back(0);
	read cin>>x,nums.push_back(x);
	order{
		cin>>index;
		make{
			temp_max.push(nums[j]);
			if(temp_max.size()==i+1){temp_min.push(temp_max.top());temp_max.pop();}
		}
		p=index;
		cout<<temp_min.top()<<endl;
		temp_max.push(temp_min.top());
		temp_min.pop();
	}
	return 0;
}
//ÎÞÊä³ö? 
//using namespace std;
//int a[200005];
//int main(){    
//    priority_queue<int>A;
//    priority_queue<int,vector<int>,greater<int> >B;
//    int n,m,r=1,q;scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//    for(int i=1;i<=m;i++){
//        scanf("%d",&q);
//        for(int j=r;j<=q;j++){
//            A.push(a[j]);
//            if(A.size()==i)B.push(A.top()),A.pop();
//        }
//        r=q+1;
//        printf("%d\n",B.top());
//        A.push(B.top()),B.pop();
//    }
//    return 0;
//}
