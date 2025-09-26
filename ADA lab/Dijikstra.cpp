#include<iostream>
using namespace std;

void dij(int cost[10][10],int source,int n,int visited[10],int dis[10]){
    int i,j,min,u,w;

    for(i=1;i<=n;i++){
        visited[i]=0;
        dis[i]=cost[source][i];
    }
    visited[source]=1;
    dis[source]=0;

    for(j=2;j<=n;j++){
          min=999;
        for(i=1;i<=n;i++){
            if(!visited[i]){
                if(dis[i]<min){
                    min=dis[i];
                    u=i;
                }
            }
        }
        visited[u]=1;
        for(w=1;w<=n;w++){
            if(cost[u][w]!=999 && visited[w]==0){
                if(dis[w]> cost[u][w]+dis[u])
                  dis[w]=cost[u][w]+dis[u];
            }
        }
    }
}

int main(){
    int source,cost[10][10], n,i,j,visited[10],dis[10];

    cout<<"Enter the No. of vertices :";
    cin>>n;
     cout<<"Enter the cost matrix (0 for self loop & 999 for no edge) \n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
        cin>>cost[i][j];
       }
    }
    cout<<"Enter the source :";
    cin>>source;

    dij(cost,source,n,visited,dis);

    for(i=1;i<=n;i++){
        if(i!=source){
            cout<<"\nShortest path from "<<source<<" --> "<< i<<" is "<<dis[i];
        }
    }
}

