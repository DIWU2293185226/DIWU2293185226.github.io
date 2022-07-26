#include<iostream>
#define uint unsigned int
unsigned int seed;
inline unsigned int getnext(int seed){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
using namespace std;
const int maxn=10000001;
unsigned int a[maxn],b[maxn],p[maxn];
int main(){
	int n;
	cin>>n>>seed;
	for(int i=0;i<n;i++)a[i]=getnext(seed);
	
	return 0;
}
