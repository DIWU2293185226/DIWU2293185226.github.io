//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int t,m;cin>>t;cin>>m;
//	while(t--){
//		int n,x;cin>>n;
//		map<int,int> a1,a2;
//		for(int i=1;i<=n;i++){
//			cin>>x;
//			if(!a1[x])a1[x]=i;
//		}
//		for(int i=n;i>0;i--)if(!a2[x])a2[x]=i;
//		while(m--){
//			int a,b;
//			cin>>a>>b;
//			(a1[a]&&a2[b]>a1[a]&&a2[b])?cout<<"yes"<<endl:cout<<"no"<<endl;
//		}
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef PARRY
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	int n, k;
    	cin >> n >> k;
    	map<int, int> a, b;
    	for(int i=1; i<=n; i++){
        	int x;
        	cin >> x;
        	if(a[x]==0)
            	a[x]=i;
        	b[x]=i;
    }
    	for(int i=0; i<k; i++){
       	int x, y;
       	cin >> x >> y;
       	if(a[x]&&a[y]&&a[x]<b[y]){
            cout << "YES" << endl;
            continue;
       }
        cout << "NO" << endl;
    }
}
    return 0;
}
