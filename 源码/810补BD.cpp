#include<bits/stdc++.h>
#define TLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		
		
	}
	
	return 0;
}



//#include<bits/stdc++.h>
//#define TLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//int main(){
//	TLE
//	int t;cin>>t;
//	while(t--){
//		int n,m;cin>>n>>m;
//		int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX;
//		int b[n+1];
//		for(int i=1;i<=n;i++){
//			cin>>b[i];
//		}
//		vector< pair<int,int> >a(m);
//		for(int i=0;i<m;i++){
//			cin>>a[i].first>>a[i].second;
//		}
//		if(m%2==0){
//			cout<<0<<endl;
//			continue;
//		}
//		else {
//			vector<int>ans(2*n+1);
//			for(int i=0;i<m;i++){
//				ans[a[i].first]++;
//				ans[a[i].second]++;
//			}
//			for(int i=1;i<=n;i++){
//				if(ans[i]%2==1)min1=min(min1,b[i]);
//			}
//			for(int i=0;i<m;i++){
//				if(ans[a[i].first]%2==0&&ans[a[i].second]%2==0){
//				min2=min(min2,b[a[i].first]+b[a[i].second]);
//					
//				}
//			}
//		}
//		cout<<min(min1,min2)<<endl;
//	}
//	return 0;
//}

//#define ll long long
//using namespace std;
//int main()
//{	TLE
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int n,m;
//        cin>>n>>m;
//        vector<int>a(n+1);
//        for(int i=1; i<=n; i++)
//            cin>>a[i];
//        vector<pair<int,int> >xy(m);
//        for(int i=0; i<m; i++)
//            cin>>xy[i].first>>xy[i].second;
//        if(m%2==0)
//            cout<<0<<endl;
//        else
//        {
//            int Min1=100000,Min2=100000;
//            vector<int>py(n+1);
//            for(int i=0; i<m; i++)
//            {
//                py[xy[i].first]++;
//                py[xy[i].second]++;
//            }
//            for(int i=1; i<=n; i++)
//                if(py[i]&1)
//                    Min1=min(Min1,a[i]);
//            for(int i=0; i<m; i++)//
//                if(py[xy[i].first]%2==0&&py[xy[i].second]%2==0)
//                    Min2=min(Min2,a[xy[i].first]+a[xy[i].second]);
//            cout<<min(Min1,Min2)<<endl;
//        }
//    }
//    return 0;
//}
