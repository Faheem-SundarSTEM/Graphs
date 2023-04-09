/*
	Author --> Faheem khan
	Depth First Search Code .
*/
// # include <bits/stdc++.h>
# include <iostream>
# include <vector>  
# include <algorithm>
# include <cmath>
# include <set>
# include <map>
# include <string>
# include <climits>
using namespace std ;
# define int long long
# define all(x) (x).begin(),(x).end()
# define f_Actoral ios::sync_with_stdio(false); cin.tie(0) ;
# define print(a) for(auto i:a){cout<<i<<' ';}cout<<endl ;
// M_u_h_a_m_m_a_d  S.A.W  ...</>... 
// a == 97 ; 0 == 48  ; A  == 65 ;

const int N = 1e5 + 10 ;
vector <int> G[N] ;
set <int> s;
bool seen[N] ;
void dfs(int v){
	if(seen[v]){
		return ;
	}
	cout << v << ' ' ;
	seen[v] = true ;
	for(auto i:G[v]){
		dfs(i) ;
	}
}

signed main(){
	int n,m ; cin >> n >> m ; // no of node and no of edges 
	for(int i = 0 ;i < m;i++){
		int u,v ;
		cin >> u >> v ;
		G[v].push_back(u) ;
		G[u].push_back(v) ;
	}
	int cnt = 0 ;
	for(int i = 1 ;i <= n;i++){
		if(!seen[i]){
			dfs(i) ;
			cnt ++ ;
		}
	}
	cout << "connected components = "<<  cnt << endl ;
}
// Time Complexity: O(V+E)
