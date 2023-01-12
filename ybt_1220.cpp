#include <bits/stdc++.h>
using namespace std;
int n,hans;char words[30][30],key;
//定义存储变量
short vis[30],DEBUG=0;
//每个单词都最多在“龙”中出现两次，使用short类型vis数组
template<typename L> inline void logr(L a){
	if(DEBUG)cout<<a;
}
//debug控制是否输出过程变量（就是调试）

inline int coin(char a[],char b[]){
	/*
		coin(char[],char[])->int
		判断形参a，b是否能首尾相接，
		返回重合部分大小
	*/
	int i=strlen(a)-1,j=0;
	while(1){
		if(j==strlen(b)) return 0;
		//超出边界，尚未搜到a串尾字母
		if(a[i]==b[j]){
			//从标记点回搜
			int ans=1;
			for(int o=j-1;o>=0;o--){
				if(b[o]!=a[i-j+o])return 0;
				ans++;
				//不重合一票否决
			} return (ans!=strlen(a)&&ans!=strlen(b))?ans:0;
			//对于coin("at","atide")此类的特判
		} j++;
	}
}
inline void dfs(int h,int cnt){
	if(cnt>hans)hans=cnt;
	//更新答案
	for(int i=1;i<=n;i++){
	int coinn=coin(words[h],words[i]);
	//遍历，"找尾巴"
	if(coinn!=0&&vis[i]!=2){
		vis[i]++;
		logr(words[i]);logr("->");
		dfs(i,strlen(words[i])+cnt-coinn);
		vis[i]--;
		//标准搜索回溯
	}}logr('\n');
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>words[i];
	cin>>key;
	for(int i=1;i<=n;i++)
	if(words[i][0]==key){
		//可行性剪枝，key开头的单词打头
		vis[i]++;
		logr(words[i]);logr("--\n");
		dfs(i,strlen(words[i]));
		vis[i]--;
	}
	cout<<hans;
	return 0;
}
