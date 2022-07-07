## ACM暑期训练笔记

记录一些刷过的题和题解

### 处理技巧

## 提高io效率的小技巧

```markdown
ios::sync_with_stdio(false);
cin.tie(0);
//sync_with_stdio函数是同时兼容scanf、printf与cin、cout的开关
//兼容的同时造成了额外的开销
//解绑操作如上
```
## 手动开优化
```markdown
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
```
## 大数求余
对于x^a，当a增大时，数值会呈指数级增长，超过int32甚至int64的范围之后会因为数值过大产生返回值错误。
解决方案：循环求余、快速幂求余
1.循环求余：
已知求余运算性质：
![image](https://user-images.githubusercontent.com/99236821/176842133-01a7f993-eff5-4f06-a1da-b05006c38f03.png)
```markdown
//p为一大数,比如可为1e9+7;
long long remainder(int x,int a,int p){
    long long rem=1;
    for(int i=0;i<a;i++)rem=(rem*x)%p;
    return rem;
}
```
2.快速幂求余：
![image](https://user-images.githubusercontent.com/99236821/176842308-2e955161-377b-434c-9f97-0c6661a7ba92.png)
快速幂的时间复杂度相较循环求余更低一些。
```markdown
//p取值同上
long long remainder(int a,int x,int p){
    long long rem=1;
    while(a>0){
    if(a%2)rem=(rem*x) % p;
    x=pow(x,2)%p;
    a//=2;
    }

}
```
### 线段树
详细资料：https://www.cnblogs.com/AC-King/p/7789013.html
线段树是一种二叉树，当然可以像一般的树那样写成结构体，指针什么的。
但是它的优点是，它也可以用数组来实现树形结构，可以大大简化代码。
数组形式适合在编程竞赛中使用，在已经知道线段树的最大规模的情况下，直接开足够空间的数组，然后在上面建立线段树。
简单的记法： 足够的空间 = 数组大小n的四倍。
实际上足够的空间 =  （n向上扩充到最近的2的某个次方）的两倍。
举例子：假设数组长度为5，就需要5先扩充成8，8*2=16.线段树需要16个元素。如果数组元素为8，那么也需要16个元素。

线段树可递归实现也可非递归实现，优先非递归实现

P3372线段树模板
```markdown

```

### 图
## 洛谷P1462通往奥格瑞玛的道路
单源最短路+二分
关于为什么使用二分：
所有类似于“求解所有的最大值中的最小值”的问题，都应该先想一想用二分答案的方法来写。
因为二分答案就是用来求解这种问题的，它通过猜测目前的答案+验证目前答案是否成立来求解，这种“假设已经知道答案”的方法比用题目信息求解答案的方法要优秀很多，而且复杂度也仅仅是加了一个log。

但是还要注意一点，除了这种经典问法以外，还要通过答案是否具有单调性来判断是否可以使用二分答案的方法

```markdown
#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
long long f[N];//点的费用 
vector< pair< int , long long> >vec[N];//存边 
priority_queue< pair< long long, int > >que;
int vis[N];
long long dis[N];
long long b, v;
int n, m, x, y;
int check(int x)
{
	if(f[1] > x) return 0;//如果第一个点就不能走,直接返回不行 
	for(int i = 1; i <= n; ++ i){
		dis[i] = 1e18;//必备的初始化,没有会致错 
		vis[i] = 0;
	}
	dis[1] = 0;
	que.push(make_pair(0, 1));//修改的dijk 
	while(!que.empty()){
		int u = que.top().second;
		que.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < vec[u].size(); ++ i){
			int v = vec[u][i].first;
			if(f[v] > x) continue;//如果新拓展的点不符合要求,继续寻找 
			long long w = vec[u][i].second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				que.push(make_pair(-dis[v], v));
			if(v == n){//如果已经到达,判断是否生命值有剩余 
				if(dis[n] >= b) return 0;
				else return 1;
			}	
		}
	}
}
	return 0;//如果没有到达,直接返回不行 
}
int main()
{
	long long mxx = -1;
	scanf("%d%d%lld", &n, &m, &b);
	for(int i = 1; i <= n; ++ i){
		scanf("%lld", &f[i]);
		mxx = max(mxx, f[i]);//寻找上边界 
	}
	for(int i = 1; i <= m; ++ i){
		scanf("%d%d%lld", &x, &y, &v);
		vec[x].push_back(make_pair(y, v));
		vec[y].push_back(make_pair(x, v));
	}
	long long ans = -1, l = 1, r = mxx;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(check(mid)) ans = mid, r = mid - 1;//更形ans 
		else	l = mid + 1;
	}
	if(ans == -1) puts("AFK");//如果每次都没有扩展成功说明不能到达 
	else printf("%lld\n", ans);
	return 0;
}
```
### 刷过的一些DP


```markdown
```

### dfs

## 岛屿数量问题
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

输出岛屿的个数。
```markdown
class Solution {
public:
    int numIslands(vector<vector<char>> & grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j);
                }
        return count;
    }
    void bfs(vector<vector<char>> &grid,int i,int j){
        if(i>=grid.size()||i<0||j>=grid[i].size()||j<0||grid[i][j]=='0')return;
        grid[i][j]='0';
        bfs(grid,i+1,j);
        bfs(grid,i,j+1);
        bfs(grid,i-1,j);
        bfs(grid,i,j-1);
        // grid[i][j]='1';
        //不需要回溯
    }
};

```
思路较简单：1.进一个点，开始记数
         2.进入bfs，把所有能搜到的相邻点标0
         
##矩阵中的路径
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
![image](https://user-images.githubusercontent.com/99236821/176806135-7a78f6ed-c73a-4a68-be9f-977c55eb62da.png)

```markdown
class Solution {
public:
    int m,n; 
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        // int si[m][n];
        // for(int i=0;i<m;i++)
        //     for(int j=0;j<n;j++)si[i][j]=0;
        // set(si);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dfs(board,word,i,j,0))return true;
        return false;
    }
    bool dfs(vector<vector<char>>&board,string word,int i,int j,int k){
        if(i>=m||i<0||j>=n||j<0||board[i][j]!=word[k])return false;//越界判定+已访问
        if(k==word.size()-1)return true;//探到终止位置
        bool ans;
        // sign[i][j]=1;
        board[i][j]='/0';
        ans=dfs(board,word,i+1,j,k+1)||dfs(board,word,i,j+1,k+1)||dfs(board,word,i-1,j,k+1)||dfs(board,word,i,j-1,k+1);
        board[i][j]=word[k];
        return ans;
    }
};
```
没什么特别的，正常dfs加回溯。
### 分治
## 数组中的逆序对
一道想了很久的痛苦分治。

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
0 <= 数组长度 <= 50000。

思路：不断将数组二分，在归并排序的过程中，统计逆序数。

拆分的终止条件：left>=right。

这里用一个temp数组暂存左右子组。

使用p,q两个指针分别指向左右子组的首元素。归并排序过程中，借助两指针的移动完成排序。
排序并记录逆序对数的过程：
    1.如果左指针越界：右子组当前元素排入nums中，并自增；
    2.如果右指针越界：左子组当前元素排入nums中，并自增；
    3.如果左子组当前元素小于等于右子组元素：左子组当前元素排入nums中，并自增;（2，3条件可合并）
    4.如果左子组当前元素大于右子组元素：右子组当前元素排入nums中，并自增；ans（记录逆序数用）+=m-p+1；
    （左右子组分别都已归并排序好，所以若左子组当前元素大于右子组当前元素，那么左子组后续所有元素均大于右子组当前元素）

```markdown
class Solution {
public:
    int reversePairs(vector<int>& nums) {
    vector<int>temp(nums.size());
    return fenzhi(nums,temp,0,nums.size()-1);
    }
    int fenzhi(vector<int>& nums,vector<int>& temp,int l,int r){
    if(l>=r)return 0;//指针越界，终止
    int m=(l+r)/2;//取得中间值
    int ans=fenzhi(nums,temp,l,m)+fenzhi(nums,temp,m+1,r);//分割数组
    for(int i=l;i<=r;i++)temp[i]=nums[i];//暂存元素
    int p=l,q=m+1;//pq指针指向左右子组首元素
    for(int i=l;i<=r;i++){
        if(p==m+1)nums[i]=temp[q++];
        else if(q==r+1||temp[p]<=temp[q])nums[i]=temp[p++];
        else if(temp[q]<temp[p]){nums[i]=temp[q++];ans+=m-p+1;}
    }
    return ans;
    }
};
```
