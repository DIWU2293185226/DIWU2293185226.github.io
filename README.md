## ACM暑期训练笔记

记录一些刷过的题和题解

### 处理技巧

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
### 刷过的一些DP


```markdown
```

###dfs

##岛屿数量问题
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
### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/DIWU2293185226/DIWU2293185226.github.io/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
