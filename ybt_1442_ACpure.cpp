#include <bits/stdc++.h>
int cnt,N,stk[70],tot,maxn=-1;
bool vis[70];int nxt[1000];
template<typename L> inline void Read(L &X){
	char c=getchar();L zhi=0,fu=1;
	while(not isdigit(c)){if(c=='-')fu=-1;c=getchar();}
	while(isdigit(c)){zhi=(zhi<<1)+(zhi<<3)+c-'0';c=getchar();}
	X=fu*zhi;
}
inline void dfs(int its,int sum,int len){
	if(sum+stk[its]==len){
		for(int j=1;j<=N;j++){
			if(vis[j]==0){
				vis[j]=1;
				dfs(j,0,len);
				vis[j]=0;
				return ;
			}
		}std::cout<<len;exit(0);
	}else if(sum+stk[its]<len) for(int i=its+1;i<=N;i++){
		if(vis[i]==0&&stk[its]+stk[i]+sum<=len){
			vis[i]=1;
			dfs(i,sum+stk[its],len);
			vis[i]=0;
			if(len-sum-stk[its]==stk[i]||sum+stk[its]==0)return ;
			i=nxt[i];
			if(i==N)return ;
		}
	}
}
bool cmp(int a,int b){return a>b;}
int main(){
	Read(cnt);int temp;
	for(int i=1;i<=cnt;i++){
		Read(temp);
		if(temp<=50){
			stk[++N]=temp;
			tot+=stk[N];
			if(stk[N]>maxn)maxn=stk[N];
		}
	}
	std::sort(stk+1,stk+N+1,cmp);
	nxt[N]=N;
    for(int i=N-1;i>0;i--){
        if(stk[i]==stk[i+1]) nxt[i]=nxt[i+1];
        else nxt[i]=i;
    }
	for(int i=maxn;i<=tot;i++){
		if(tot%i!=0)continue;
		vis[1]=1;
		dfs(1,0,i);
		memset(vis,0,sizeof(vis));
	}
}
