//1.w之间全相同的字符串× 2.全w字符串√
#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;
	string temp,s;
	while(t--){
		int n,key=1,k=1,r=0,b=0;cin>>n;
		int a_a,b_b,l;
		char c;
		cin>>s;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='R'){temp.push_back(s[i-1]);r++;}
			else if(s[i-1]=='B'){temp.push_back(s[i-1]);b++;}
			else {
				if(r==temp.size()||b==temp.size()&&s[i]!=s[i-1])key=0;
				r=0;b=0;
				temp.clear();
				k=0;
			}
		}
		if(k)if(r==temp.size()||b==temp.size())key=0;
		if(key)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 



//#include<iostream>;
//using namespace std;
//int main(){
//	int t;cin>>t;
//	while(t--){
//		int temp;cin>>temp;
//		if(temp<1399||temp==1399)cout<<"Division 4"<<endl;
//		else if((1400<temp||temp==1400)&&(temp<1599||temp==1599))cout<<"Division 3"<<endl;
//		else if((1600<temp||temp==1600)&&(temp<1899||temp==1899))cout<<"Division 2"<<endl;
//		else cout<<"Division 1"<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<map>
//#include<vector>
//using namespace std;
//map<int,int>temp;
//vector<int>a;
//int main(){
//	int t,ans,x,cut=1;
//	cin>>t;
//	while(t--){
//		temp.clear();
//		a.clear();
//		ans=0;
//		int n,l,mid;cin>>n;
//		for(int i=0;i<n;i++){cin>>mid;a.push_back(mid);}
//		int i=0;
//		for(;i<n;i++){
//			if(temp.find(a[i])==temp.end())temp.insert(make_pair(a[i],1));
//			else temp[a[i]]++;
//			if(temp[a[i]]==3){cout<<a[i]<<endl;break;}
//		}
////		cout<<temp[a[i]]<<endl;
//		if(temp[a[i]]!=3)cout<<"-1"<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//	int t;cin>>t;
//	while(t--){
//		int n,temp,key=1;cin>>n;
//		vector<int>odd,even;
//		for(int i=1;i<=n;i++){
//			cin>>temp;
//			if(i%2==0){
//				even.push_back(temp);
//				if(even.size()>1)if(even[i/2-1]%2!=even[i/2-2]%2)key=0;	
//			}
//			else {
//				odd.push_back(temp);
//				if(odd.size()>1)if(odd[(i+1)/2-1]%2!=odd[(i+1)/2-2]%2)key=0;}
//		}
//		if(key)cout<<"YES"<<endl;
//		else cout<<"NO"<<endl;
//		even.clear();
//		odd.clear();
//	}
//	return 0;
//}

