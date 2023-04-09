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

const int maxn=1001 ;
int n , m ;
bool adj[maxn][maxn];
bool M[maxn][maxn];
bool sat[maxn];
int msize=0;
bool seen[maxn][2];
bool dfs(int u,bool b){
    if(seen[u][b])
        return false ;
    if(!sat[u] and b){
        sat[u]=true;
        return true;
    }
    for(int i=1;i<=n;i++){
        if(adj[u][i] and M[u][i]==b){
            bool a=dfs(i,!b);
            if(a){     
                if(M[u][i]){
                    msize--;
                }
                else{
                    msize++;
                }
                M[u][i]=!M[u][i];
                M[i][u]=!M[i][u];
                sat[u]=sat[i]=true;
                return true;
            }
        }
    }
    return false;
}
void augment(){
    for(int i=1;i<=n;i++){
        seen[i][true]=seen[i][false]=false;
    }
    for(int i=1;i<=n;i++){
        if(!sat[i])
            if(dfs(i,false))
                return;
    }
}
signed main(){
    cin>>n>>m;
    for(int i = 0; i < m;i++){
        int u,v;
        cin >> u >> v ;
        adj[u][v] = adj[v][u] = true;
        if(!sat[u] and !sat[v]){
            M[u][v] = M[v][u] = true ;
            sat[u] = sat[v] = true ;
            msize ++ ;
        }
    }
    while(1){
        int oldsize = msize ;
        augment() ;
        if(msize==oldsize)
            break;
    }
    cout<<msize<<endl;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(M[i][j])
                cout<<i<<" <--> "<<j<<endl;
        }
    }
    return 0;
}
