#include <iostream>
using namespace std; 

#define INF 100000000

int map[101][101];

void floydWarshall(int n){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if((map[j][k]>map[j][i]+map[i][k]) && (map[j][i]!=INF) && (map[i][k]!= INF)){
                    map[j][k]=map[j][i]+map[i][k];
                }
            }
        }
    }

    int capitalCityDistance=INF; 
    int capitalCity=0;

    for(int i=1; i<=n; i++){
        int distance=0; 
        for(int j=1; j<=n; j++){
            distance += map[i][j];
        }

        if (distance<capitalCityDistance){
            capitalCityDistance = distance;
            capitalCity=i;
        }
    }
    cout<<capitalCity<<endl;
}
int main(){
    int n, m, u, v, w;

    while(cin>>n>>m){

        for (int i=0; i<101; i++){
            for (int j=0; j<101; j++){
                if (i!=j)
                    map[i][j]=INF;
                else
                    map[i][j]=0;
            }
        }
        
        while(m--){
            cin>>u>>v>>w;
            map[u][v]=w;
            map[v][u]=w;
        }

        floydWarshall(n);
    }
}
