//#pragma GCC optimize(3,"Ofast","inline")
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<map>
//#include<string>
//#define TLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
////bool  cmp(const pair<int,int>&a,const pair<int,int>& b){
////	return a.second<b.second;
////}
//int main(){
//	TLE
//	int t;cin>>t;
//	while(t--){
//		vector<pair<int,int> >query;
//		vector<pair<int,int> >p1;
//		vector<pair<int,int> >p2;
//		int n,temp;cin>>n;
//		for(int i=0;i<n;i++){
//			cin>>temp;
//			query.push_back(make_pair(i+1,temp));
//		}
//		for(int i=0;i<n-3;i++){
//			for(int j=i+2;j<n-1;j++){
//				if(query[i].second<query[j].second)p1.push_back(make_pair(query[i].first,query[j].first));
//			}
//			for(int j=i+3;j<n;j++){
//				if(query[i+1].second>query[j].second)p2.push_back(make_pair(query[i+1].first,query[j].first));
//			}
//		}
////		for(int i=0;i<p1.size();i++)cout<<p1[i].first<<' '<<p1[i].second<<endl;
////		for(int i=1;i<n-2;i++){
////			for(int j=i+2;j<n;j++){
////				if(query[i].second>query[j].second)p2.push_back(make_pair(query[i].first,query[j].first));
////			}
////		}
//		int ans=0;
//		for(int i=0;i<p1.size();i++){
//			for(int j=0;j<p2.size();j++){
//				if(p1[i].first<p2[j].first&&p2[j].first<p1[i].second&&p2[j].second>p1[i].second)ans++;
//			}
//		}
//		cout<<ans<<endl;
////		query.clear();p1.clear();p2.clear();		
//	}
//	return 0;
//}
//³¬Ê± 

//const int N = 5e5 + 10, mod = 1e9 + 7;
//using namespace std;
//typedef pair<int, int>PII;
//using namespace std;
//int n, m, ans;
//int p[5005];
//long long pre[5100][5100];
//
//void solve()
//{
//	int n;
//	 cin >> n;
//	 for(int i = 1; i <= n; i ++) cin >> p[i];
//    
//    for(int i = 1; i <= n; i ++) 
//    	for(int j = 1; j <= n; j++ ) pre[i][j] = 0; 
//    for(int i = 1; i <= n; i ++)
//    {
//        for(int j = 1; j <= n; j ++)
//            pre[i][j] += pre[i - 1][j];
//        for(int j= p[i]; j <= n;j++)
//            pre[i][j] ++;
//    }
//    
//    long long ans = 0;
//	for(int b = 1; b <= n; b ++) 
//	    for(int c=b + 1; c <= n; c++)
//	        // a ±È c Ð¡
//	       ans += pre[b-1][p[c] - 1] * (pre[n][p[b]] - pre[c][ p[b]]);
//	cout << ans << '\n';
//}
//
//signed main()
//{
//    int T;
//    cin>> T;
//    while(T --)
//    	solve();
//    return 0;
//}


//#include<iostream>
//#include<vector>
//#include<map>
//#include<string>
//#define TLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//int main(){
//	TLE
//	int t;cin>>t;
//	while(t--){
//		string s;
//		int n,ans=0,cut=0;cin>>n>>s;
//		char temp='#';
//		for(int i=0;i<n;i+=2){
//			if(s[i]!=s[i+1])ans++;
//			else {
//				if(s[i]!=temp){
//					cut++;
//					temp=s[i];
//				}
//			}
//		}
//		if(cut==0)cut=1;
//		cout<<ans<<' '<<cut<<endl;
//		
//	}
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<string>>
//#define TLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//int main(){
//	TLE
//	int t;cin>>t;
//	while(t--){
//		vector<int>temp;
//		string s;
//		int n,cut=1,ans=0,key=0;cin>>n>>s;
//		char a,b;
//		a=s[0];
//		for(int i=1;i<n;i++){
//			b=s[i];
//			if(a==b)cut++;
//			else{
//				temp.push_back(cut%2);
//				cut=1;
//			}
//			a=b;
//		}
//		temp.push_back(cut%2);
////		for(int i=0;i<temp.size();i++)cout<<temp[i]<<endl;
//		cut=1;
//		for(int i=0;i<temp.size();i++){
//			if(key==0&&temp[i]==1){
//				key=1;
//			}else if(key==1&&temp[i]==1){
//				key=0;
//				ans+=cut;
//				cut=1;
//			}else if(key==1&&temp[i]==0)cut++;
//		}
//		cout<<ans<<endl;
//		temp.clear();
//	}
//	return 0;
//}




//#include<iostream>
//#include<map>
//#define TLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//using namespace std;
//int main(){
//	TLE
//	int t;cin>>t;
//	while(t--){
//		map<int,int>a;
//		int n,temp,cut=0,key=0;cin>>n;
//		for(int i=0;i<n;i++){
//			cin>>temp;
//			if(a.find(temp)==a.end())a.insert(make_pair(temp,1));
//			else {a[temp]++;
//			if(a[temp]>1)key=1;}
//		}
//		if(a.find(0)!=a.end()&&a[0]!=0)cout<<n-a[0]<<endl;
//		else if(key)cout<<n<<endl;
//		else cout<<n+1<<endl;
//	}
//	return 0;
//}
