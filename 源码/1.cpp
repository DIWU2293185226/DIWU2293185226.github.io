
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(false);cin.tie(0);
//	int i,t;
//	cin>>t;
//	int n,m;
//	int a[210000];
//	int b[210000];
//	int c[210000];
//	for(i=1;i<=t;i++){
//		cin>>n>>m;
//		int e=0;
//		memset(b,0,sizeof(b));
//		memset(c,0,sizeof(c));
//		for(int j=1;j<=n;j++){
//			cin>>a[j];
//			if(a[j]==1){
//				e++;
//				b[e]=j;
//			}
//		}
//		int k=0;
//		for(int j=n;j>=1;j--){
//			if(a[j]==1){
//				k++;
//				c[k]=n-j+1;
//			}
//		}
//		if(m>e){
//			cout<<"-1"<<endl;
//		
//		}
//		else{
//		 int minn=10000000;
//			for(int j=0;j<=e-m;j++){
//				minn=min(b[j]+c[e-m-j],minn);
//			}
//			cout<<minn<<endl;
//		}
//	}	
//	
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//set<int>index;
//vector<int>a;
//int main(){
//	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin>>t;
//	while(t--){
//		int n,temp,ans,r;cin>>n;
//		for(int i=0;i<n;i++){
//			cin>>temp,a.push_back(temp),index.insert(temp);
//		}
//		r=(a.size()-index.size());
////		cout<<index.size()<<endl;
//		if(r%2==0||r==0)cout<<index.size()<<endl;
//		else cout<<index.size()-1<<endl;
//		a.clear();index.clear();
//	}
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(false);cin.tie(0);
//	int t,ans=0,temp;cin>>t;
//	while(t--){
//		cin>>temp;
//		ans^=temp;
//	}
//	cout<<ans;
//    return 0;
//}
