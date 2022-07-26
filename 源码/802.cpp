#include<bits/stdc++.h>
using namespace std;
void trimZero(vector<int> &A) {
	while (A.back() == 0 && A.size() > 1) A.pop_back();
}
 
vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	trimZero(C);
	return C;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		string k;cin>>k;
		vector<int>temp;
		for(int i=0;i<n;i++)temp.push_back(k[i]-'0');
		if(k[0]!='9'){
			vector<int>temp1;
			vector<int>ans; 
			for(int i=0;i<n;i++)temp1.push_back(9);
			trimZero(temp);
			trimZero(temp1);
			ans=sub(temp1,temp);
			for(int i=0;i<ans.size();i++)cout<<ans[i];
			cout<<endl;
		}
		else{
			vector<int>temp2;
			vector<int>ans;
			for(int i=0;i<=n;i++)temp2.push_back(1);
			trimZero(temp);
			trimZero(temp2);
			ans=sub(temp2,temp);
			for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
			cout<<endl;			
		}
	}
	return 0;
}
