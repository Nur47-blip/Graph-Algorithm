#include <bits/stdc++.h>

using namespace std;

int n,m;
string isi[1000];
bool vis[1000][1000];

bool isValid(int i, int j){
	if (i>=0 and i<=n-1 and j>=0 and j<=m-1 and isi[i][j]=='.' and vis[i][j]==false) return true;
	else return false;
}

void dfs(int i, int j){
	vis[i][j]=true;
	if (isValid(i-1,j)) dfs(i-1,j);
	if (isValid(i+1,j)) dfs(i+1,j);
	if (isValid(i,j-1)) dfs(i,j-1);
	if (isValid(i,j+1)) dfs(i,j+1);
}

int main(){

	cin>>n>>m;
	
	for (int i=0;i<n;i++){
		cin>>isi[i];
	}
	
	int cnt=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (isi[i][j]=='.' and vis[i][j]==false){
				cnt++;
				dfs(i,j);
			}
		}
	}
	
	cout<<cnt<<endl;

	return 0;
}
