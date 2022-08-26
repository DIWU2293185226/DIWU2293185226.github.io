


#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	while(n--){
		int a,b,temp,bottom;
		cin>>a>>b;
		temp=abs(a-b);
		bottom=min(a,b);
		if(bottom<temp||bottom==temp){
			if(a<b){
			for(int i=0;i<a;i++)cout<<'0';
			for(int i=0;i<b;i++)cout<<'1';
			cout<<endl;}
			else {
			for(int i=0;i<b;i++)cout<<'1';
			for(int i=0;i<a;i++)cout<<'0';
			cout<<endl;				
			}
		}
		else {
			int key=1,ans_1=0,ans_0=0;
			temp=a>b?a,key=1:b,key=0;
			for(int i=0;i<a+b;i++){
				if(i%2==0){
					if(key==1&&ans_0!=a){ans_0++;cout<<'0';}
					else if(!key&&ans_1!=b) {ans_1++;cout<<'1';}
					else {
					if(ans_1==b&&ans_0!=a)cout<<'1';
					else if(ans_1!=b&&ans_0==a)cout<<'0';}
				}
				else{
					if(key==1&&ans_1!=b){ans_1++;cout<<'1';}
					else if(!key&&ans_0!=a){ans_0++;cout<<'0';}
					else{
					if(ans_1==b&&ans_0!=a)cout<<'1';
					else if(ans_1!=b&&ans_0==a)cout<<'0';}					
				}				
			}
			cout<<endl;
		}
	}
	return 0;
}
