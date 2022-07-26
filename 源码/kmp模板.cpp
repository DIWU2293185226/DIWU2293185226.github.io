//#include<iostream>
//#include<string>
//using namespace std;
//string a,b;
//int next[1000001];
//void getnext(){
//	int j=0,k=-1;
//	next[j]=k;
//	while(j<b.size()){
//		if(k==-1||b[j]==b[k]){
//			j++;
//			k++;
//			next[j]=k;
//		}
//		else k=next[k];
//	}
//}
//int kmp(int st){
//	int j=0;
//	while(a[st]!='\0'&&j!=b.size()){
//		if(a[st]==b[j]){
//			st++;
//			j++;
//		}
//		else {
//			j=next[j];
//		}
//	}
//	if(j==b.size())return st-j;
//	else return -1;
//}
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cin>>a>>b;
//	int ans=0;getnext();
//	while(1){
//		if(ans!=0&&ans==-1)break;
//		ans=kmp(ans);
//		if(ans!=-1)cout<<ans+1<<endl;
//	}
//	for(int i=1;i<=b.size();i++)cout<<next[i]<<' ';
//	cout<<endl;
//	return 0;
//} 


#include<iostream>

#include<cstring>

#define MAXN 1000010

using namespace std;


int kmp[MAXN];

int la,lb,j; 

char a[MAXN],b[MAXN];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>a+1;
    cin>>b+1;
    la=strlen(a+1);
    lb=strlen(b+1);
    for (int i=2;i<=lb;i++)
	   {     
	   while(j&&b[i]!=b[j+1])
        j=kmp[j];    
       if(b[j+1]==b[i])j++;    
        kmp[i]=j;
       }
    j=0;
    for(int i=1;i<=la;i++)
	   {
          while(j>0&&b[j+1]!=a[i])
           j=kmp[j];
          if (b[j+1]==a[i]) 
           j++;
          if (j==lb) {cout<<i-lb+1<<endl;j=kmp[j];}
       }

    for (int i=1;i<=lb;i++)
    cout<<kmp[i]<<" ";
    return 0;
}
