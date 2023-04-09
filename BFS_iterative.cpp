/*
        Author  -- >  Faheem khan
        Breadth First search  Code .
*/
// # include <bits/stdc++.h>
# include <iostream>
# include <vector>  
# include <algorithm>
# include <cmath>
# include <set>
# include <map>
# include <string>
# include <deque>
# include <climits>
using namespace std ;
# define int long long
# define all(x) (x).begin(),(x).end()
# define f_Actoral ios::sync_with_stdio(false); cin.tie(0) ;
# define print(a) for(auto i:a){cout<<i<<' ';}cout<<endl ;
// M_u_h_a_m_m_a_d  S.A.W  ...</>... 
// a == 97 ; 0 == 48  ; A  == 65 ;

const int N = 1e5 ; 
vector<int> G[N] ;
bool seen[N] ;
int parent[N];
int dist[N];

void bfs(int v){
    seen[v] = true ;
    parent[v] = v ;
    dist[v] = 0 ;
    deque <int> queue ;
    queue.push_back(v);
    while(queue.size()){
        int u = queue[0] ;
        queue.pop_front() ;
        for(auto i:G[u]){
            if (!seen[i]){
                seen[i] = true;
                parent[i] = u;
                dist[i] = dist[u] + 1 ;
                queue.push_back(i);
            }
        }
    }
}
signed main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v ;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cnt = 0 ;
    for (int i = 1 ; i <= n; i++){
        if (!seen[i]){
            bfs(i);
            cnt++;
        }
    }
    cout << cnt << endl ;
    return 0;
}
