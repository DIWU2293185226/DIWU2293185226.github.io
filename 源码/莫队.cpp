//https://www.cnblogs.com/WAMonster/p/10118934.html
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 1010000
#define maxb 1010
int aa[maxn], cnt[maxn], belong[maxn];
int n, m, size, bnum, now, ans[maxn];
struct query {
	int l, r, id;
} q[maxn];
//奇偶性排序，对于左端点在同一奇数块的区间，右端点按升序排列，反之降序 
int cmp(query a, query b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
#define isdigit(x) ((x) >= '0' && (x) <= '9')
int read() {
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = (res << 1) + (res << 3) + c - 48, c = getchar();
	return res;
}
void printi(int x) {
	if(x / 10) printi(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	scanf("%d", &n);
	size = sqrt(n);
	bnum = ceil((double)n / size);
	for(int i = 1; i <= bnum; ++i) 
		for(int j = (i - 1) * size + 1; j <= i * size; ++j) {
			belong[j] = i;
		}
	//上方进行分块预处理 
	//我们将大小为n的序列分为n??√个块，从1到n??√编号，然后根据这个对查询区间进行排序。
	//一种方法是把查询区间按照左端点所在块的序号排个序，如果左端点所在块相同，再按右端点排序。 
	for(int i = 1; i <= n; ++i) aa[i] = read(); 
	m = read();
	for(int i = 1; i <= m; ++i) {
		q[i].l = read(), q[i].r = read();
		q[i].id = i;
	}
	sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
	for(int i = 1; i <= m; ++i) {
		int ql = q[i].l, qr = q[i].r;
		while(l < ql) now -= !--cnt[aa[l++]];
		while(l > ql) now += !cnt[aa[--l]]++;
		while(r < qr) now += !cnt[aa[++r]]++;
		while(r > qr) now -= !--cnt[aa[r--]];
		ans[q[i].id] = now;
	}
	for(int i = 1; i <= m; ++i) printi(ans[i]), putchar('\n');
	return 0;
}


