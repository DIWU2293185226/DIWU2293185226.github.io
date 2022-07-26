


//#include<iostream>
//#include<cmath>
//using namespace std;
//int main(){
//	int l,n;cin>>l>>n;
//	int ans;
//	char c='a';
//	char a[l];
//	n=pow(26,l)-n;
//	for(int i=0;i<l;i++){
//		ans=n%26;
//		a[i]=c+ans;
//		n/=26;
//	}
//	for(int i=l-1;i>=0;i--)cout<<a[i];
//	return 0;
//}



//#include<iostream>
//#include<cmath>
//using namespace std;
//int main(){
//	int t;cin>>t;
//	while(t--){
//		string c;cin>>c;
//		int sign=0,sum=0;
//		for(int i=0;i<c.size();i++){
//			if(c[i]=='(')sum++;
//			else if(c[i]==')'){
//				sum--;
//				if(sum<0){
//					sum++;
//					sign--;
//				}
//			}
//			else {
////				sum--;
//				sign++;
//			}
//			if(sum==0&&sign==1){
//				sum++;
//				sign--;
//			}
//		}
//		if(abs(sum)==sign)cout<<"YES"<<endl;
//		else cout<<"NO"<<endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
// 
//const int MAXN=200200;
//const int MAXM=20;
//int a[MAXN],dp[MAXN][MAXM];
// 
//void ST(int n)
//{
//	int i,j;
//	for(i=1;i<=n;i++)
//		dp[i][0]=a[i];
//	for(j=1;j<MAXM;j++)
//	{
//		for(i=1;i+(1<<j)-1<=n;i++)
//			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
//	}
//}
// 
//int rmq(int l,int r)
//{
//	if(l>r)
//		swap(l,r);
//	int k=log(r-l+1)/log(2);
//	return max(dp[l][k],dp[r-(1<<k)+1][k]);
//}
// 
//int main()
//{       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n,m,i,q,sx,sy,tx,ty,k;
//	scanf("%d%d",&n,&m);
//	for(i=1;i<=m;i++)
//		scanf("%d",&a[i]);
//	ST(m);
//	scanf("%d",&q);
//	while(q--)
//	{
//		scanf("%d%d%d%d%d",&sx,&sy,&tx,&ty,&k);
//		sx+=(n-sx)/k*k;
//		tx+=(n-tx)/k*k;
//		if(sx==tx&&abs(ty-sy)%k==0&&rmq(sy,ty)<sx)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//}
