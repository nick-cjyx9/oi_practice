#include <bits/stdc++.h>
using namespace std;
//TÕÍ¡À
int N,stk[114],tot,maxn=-1;
bool vis[114],DEBUG=0;//int tong[100000];
template<typename L> inline void logr(L a){
	if(DEBUG)cout<<a;
}
inline void dfs(int its,int sum,int len){
	logr(stk[its]);logr("->");
	if(sum+stk[its]==len){
		logr(' ');
		for(int j=1;j<=N;j++){
			if(vis[j]==0){
				vis[j]=1;
				dfs(j,0,len);
				vis[j]=0;
				return ;
			}
		}cout<<len;exit(0);
	}else if(sum+stk[its]<len) for(int i=its;i<=N;i++){
		if(vis[i]==0&&stk[its]+stk[i]+sum<=len){//&&stk[i]!=stk[its]
			vis[i]=1;
			dfs(i,sum+stk[its],len);
			vis[i]=0;
		}
	}logr("!");return ;
}
bool cmp(int a,int b){return a>b;}
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>stk[i];tot+=stk[i];
		if(stk[i]>maxn)maxn=stk[i];
//		if(tong[stk[i]]==0)tong[stk[i]]=i;
	}
	logr("tot:");logr(tot);logr('\n');
	sort(stk+1,stk+N+1,cmp);
	for(int i=maxn;i<=tot;i++){
		if(tot%i!=0)continue;
		logr(i);logr(":");
		vis[1]=1;
		dfs(1,0,i);
		logr('\n');
		memset(vis,0,sizeof(vis));
	}
}
