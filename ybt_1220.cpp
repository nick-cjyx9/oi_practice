#include <bits/stdc++.h>
using namespace std;
int n,hans;char words[30][30],key;
//����洢����
short vis[30],DEBUG=0;
//ÿ�����ʶ�����ڡ������г������Σ�ʹ��short����vis����
template<typename L> inline void logr(L a){
	if(DEBUG)cout<<a;
}
//debug�����Ƿ�������̱��������ǵ��ԣ�

inline int coin(char a[],char b[]){
	/*
		coin(char[],char[])->int
		�ж��β�a��b�Ƿ�����β��ӣ�
		�����غϲ��ִ�С
	*/
	int i=strlen(a)-1,j=0;
	while(1){
		if(j==strlen(b)) return 0;
		//�����߽磬��δ�ѵ�a��β��ĸ
		if(a[i]==b[j]){
			//�ӱ�ǵ����
			int ans=1;
			for(int o=j-1;o>=0;o--){
				if(b[o]!=a[i-j+o])return 0;
				ans++;
				//���غ�һƱ���
			} return (ans!=strlen(a)&&ans!=strlen(b))?ans:0;
			//����coin("at","atide")���������
		} j++;
	}
}
inline void dfs(int h,int cnt){
	if(cnt>hans)hans=cnt;
	//���´�
	for(int i=1;i<=n;i++){
	int coinn=coin(words[h],words[i]);
	//������"��β��"
	if(coinn!=0&&vis[i]!=2){
		vis[i]++;
		logr(words[i]);logr("->");
		dfs(i,strlen(words[i])+cnt-coinn);
		vis[i]--;
		//��׼��������
	}}logr('\n');
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>words[i];
	cin>>key;
	for(int i=1;i<=n;i++)
	if(words[i][0]==key){
		//�����Լ�֦��key��ͷ�ĵ��ʴ�ͷ
		vis[i]++;
		logr(words[i]);logr("--\n");
		dfs(i,strlen(words[i]));
		vis[i]--;
	}
	cout<<hans;
	return 0;
}
