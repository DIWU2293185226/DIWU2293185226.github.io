#include <iostream>
#include <vector>
 
void solve(){
	int n;
	std::cin >> n;
	int a[n];
	for(int i{}; i < n; ++i)
		std::cin >> a[i];
	std::cout << a[0] << "\n";
}
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--)
		solve();
	return 0;} 










//#include <bits/stdc++.h>
// 
//using namespace std;
// 
//const int MAX = 200007;
//const int MOD = 1000000007;
// 
//void solve() {
//	int n;
//	cin >> n;
//	vector<int> pos, neg, a;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		if (x > 0) {pos.push_back(x);}
//		else if (x < 0) {neg.push_back(x);}
//		else {
//			if (a.size() < 2) {a.push_back(x);}
//		}
//	}
//	if (pos.size() > 2 || neg.size() > 2) {cout << "NO\n"; return;}
//	
//	for (int i=0 ;i<pos.size();i++) {a.push_back(pos[i]);}
//	for (int i=0 ;i<neg.size();i++) {a.push_back(neg[i]);}
//	
//	for (int i = 0; i < a.size(); i++) {
//		for (int j = i + 1; j < a.size(); j++) {
//			for (int k = j + 1; k < a.size(); k++) {
//				bool ok = false;
//				for (int l = 0; l < a.size(); l++) {
//					if (a[i] + a[j] + a[k] == a[l]) {ok = true;}
//				}
//				if (!ok) {cout << "NO\n"; return;}
//			}
//		}
//	}
//	cout << "YES\n";
//}
// 
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
//	// solve();
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//void slove(){
//	int n,temp;
//	cin>>n;
//	vector<int>a;
//	for(int i=0;i<n;i++){cin>>temp;a.push_back(temp);}
//	for(int i=0;i<a.size();i++)
//		for(int j=i+1;j<a.size();j++){
//			for(int k=j+1;k<a.size();k++){
//				int key=0;
//				for(int l=0;l<a.size();l++)if(a[i]+a[j]+a[k]==a[l])key=1;
//				if(!key){cout<<"NO"<<endl;return;}
//			}
//		}
//	cout<<"YES"<<endl;
//	return;
//}
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//	slove();
//	}
//	return 0;
//}









