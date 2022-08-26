
//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N=1e3+10;
//int tree[N],a[N];
//int n,cnt=0;
//void dfs(int u)
//{
//    if(u>n)return;
//    int lson=2*u;
//    int rson=2*u+1;
//    dfs(lson);
//    dfs(rson);
//    tree[u]=a[++cnt];
//}
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin>>n;
//    for(int i=1;i<=n;i++)
//        cin>>a[i];
//    dfs(1);
//    for(int i=1;i<=n;i++)
//        i==n?printf("%d\n",tree[i]):printf("%d ",tree[i]);
//    return 0;
//}

//#include <bits/stdc++.h>
// 
//using namespace std;
//typedef long long ll;
//const int maxn = 1000 + 5;
//const int INF = 0x7FFFFFFF;
// 
//struct mmp {
//    string name;
//    string idcard;
//    int shen;
//    int times;
//    int index;
//};
// 
//map<string, int> mp;
//set<string> smp;
//set<string> vHave;
//vector<mmp> v;
// 
//bool cmp(mmp a, mmp b) {
//    if (a.times == b.times)
//        return a.index < b.index;
//    return a.times < b.times;
//}
// 
//int main() {
//    int D, P;
//    scanf("%d %d", &D, &P);
//    for (int day = 1; day <= D; day++) {
//        int ti, si;
//        cin >> ti >> si;
//        vector<mmp> use;
//        for (int i = 1; i <= ti; i++) {
//            string name;
//            string idcard;
//            int shen;
//            int hh;
//            int mm;
//            cin >> name;
//            cin >> idcard;
//            cin >> shen;
//            scanf("%d:%d", &hh, &mm);
//            bool flag = true;
//            if (idcard.length() != 18)
//                continue;
//            for (auto j:idcard)
//                if (!(j >= '0' && j <= '9'))
//                    flag = false;
//            if (flag) {
//                if (shen && vHave.find(idcard) == vHave.end()) {
//                    v.push_back(mmp{name, idcard, shen, hh * 60 + mm, i});
//                    vHave.insert(idcard);
//                }
//                use.push_back(mmp{name, idcard, shen, hh * 60 + mm, i});
//            }
//        }
//        sort(use.begin(), use.end(), cmp);
//        int now = 0;
//        for (int i = 0; i < use.size() && now < si; i++) {
//            if (mp[use[i].idcard] == 0 || day >= P + mp[use[i].idcard] + 1) {
//                now++;
//                mp[use[i].idcard] = day;
//                cout << use[i].name << " " << use[i].idcard << endl;
//            }
//        }
//    }
//    for (auto i:v)
//        cout << i.name << " " << i.idcard << endl;
//    return 0;
//}
