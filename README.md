## ACM暑期训练笔记

记录一些刷过的题和题解

### 刷过的一些DP

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).
###dfs
岛屿数量问题，给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

输出岛屿的个数。
```markdown
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j);
                }
        return count;
    }
    void bfs(vector<vector<char>>&grid,int i,int j){
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
### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/DIWU2293185226/DIWU2293185226.github.io/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
