#include<stdio.h>
#include<string.h>
#include<math.h>
#include "path.h"
void initial(){
    for(int i=1;i<MaxL;i++){
        for(int j=1;j<=MNode;j++){
            if(Links[i].node1 == Nodes[j].id)Links[i].node1 = j;
            if(Links[i].node2 == Nodes[j].id)Links[i].node2 = j;
        }
    }
    for(int i=1;i<=MNode;i++){
        for(int j=1;j<=MNode;j++){
            map[i][j]=99999.99;
        }
    }
    for(int i=1;i<=MNode;i++)map[i][i]=0;
    for(int i=1;i<MaxL;i++){
        if(Links[i].node1<=MNode && Links[i].node2<=MNode){
            map[Links[i].node1][Links[i].node2] = Links[i].length;
            map[Links[i].node2][Links[i].node1] = Links[i].length;
        }
    }
}
void dijkstra(int u){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=MNode;i++){
            dis[i]=map[u][i];
    }
    vis[u]=1;
    for(int i=1;i<MNode;i++){
        double mini=99999.99;
        int temp;
        for(int j=1;j<MNode;j++){
            if(!vis[j] && dis[j]<mini){
                mini=dis[j];
                temp=j;
            }
        }
        vis[temp]=1;
        for(int j=1;j<MNode;j++){
            if(map[temp][j]<=99999 && (!vis[j]) && map[temp][j]+dis[temp]<dis[j]){
                    dis[j]=map[temp][j]+dis[temp];
                    route[j]=temp;
            }
        }
    }
}
