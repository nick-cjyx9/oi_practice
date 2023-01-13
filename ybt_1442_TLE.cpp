#include <bits/stdc++.h>
using namespace std;
int N,stk[114],tot,maxn=-1;
bool vis[114],DEBUG=1;int nxt[10000000];
template<typename L> inline void logr(L a){
	if(DEBUG)cout<<a;
}
inline void dfs(int its,int sum,int len){
	logr(stk[its]);logr("->");
	if(sum+stk[its]==len){
		logr("\nD ");
		for(int j=1;j<=N;j++){
			if(vis[j]==0){
				vis[j]=1;
				dfs(j,0,len);
				vis[j]=0;
				return ;
			}
		}logr("\nanswer:");cout<<len;exit(0);
	}else if(sum+stk[its]<len) for(int i=its+1;i<=N;i++){
		if(vis[i]==0&&stk[its]+stk[i]+sum<=len){
			vis[i]=1;
			dfs(i,sum+stk[its],len);
			vis[i]=0;
			logr("x");
			i=nxt[i];
			if(i==N)return ;
		}
	}
	//logr("![");logr(its);logr(",");logr(len);logr("]");
}
bool cmp(int a,int b){return a>b;}
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>stk[i];tot+=stk[i];
		if(stk[i]>maxn)maxn=stk[i];
	}
	logr("tot:");logr(tot);logr('\n');
	sort(stk+1,stk+N+1,cmp);
	//数据录入与排序
	if(DEBUG)for(int i=1;i<=N;i++)cout<<stk[i]<<' ';
	logr('\n');
	nxt[N]=N;
    for(int i=N-1;i>0;i--){
        if(stk[i]==stk[i+1]) nxt[i]=nxt[i+1];
        else nxt[i]=i;
    }
	for(int i=maxn;i<=tot;i++){
		if(tot%i!=0)continue;
		logr(i);logr(":");
		vis[1]=1;
		dfs(1,0,i);
		logr('\n');
		memset(vis,0,sizeof(vis));
	}
}
