#include<stdio.h>
#include<string.h>
#include<math.h>
#define MaxL 2345
#define MaxN 6286
#define MNode MaxN-MaxL
#define infi 0x3f3f3f3f
double xmin,xmax,ymin,ymax;
struct Node{
    long long int id;
    double x;
    double y;
}Nodes[MaxN-MaxL+100];
struct Link{
    int node1;
    int node2;
    double length;
}Links[MaxL+100];
double map[MNode+10][MNode+10];
double dis[MNode+10][MNode+10];
int vis[MNode+10];
int read_map(){
    FILE* fp = fopen("Final_Map.map", "r");
        if(fp==NULL){
            return 0;
        }
        fscanf(fp,"<bounding minLat=%lf minLon=%lf maxLat=%lf maxLon=%lf /bounding>\n",&ymin,&ymax,&xmin,&xmax);
        long long int temp1,temp2;
        double te1,te2,te3,te4;
        int temp5;
        char s[15];
        for(int i=2;i<=MaxL;i++){
                fscanf(fp,"<link id=%lld node=%d node=%d way=%d length=%lf veg=%lf arch=%lf land=%lf POI= ",&te1,&Links[i-1].node1,&Links[i-1].node2,&temp1,&Links[i-1].length,&te2,&te3,&te4);
                 fgets(s,40,fp);
        }
        for(int i=MaxL+1;i<=MaxN;i++){
                fscanf(fp,"<node id=%lld lat=%lf lon=%lf /node>\n",&Nodes[i-MaxL].id,&Nodes[i-MaxL].y,&Nodes[i-MaxL].x);
        }
        return 1;
}
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
    for(int i=1;i<=MNode;i++)dis[u][i]=map[u][i];
    vis[u]=1;
    for(int i=1;i<MNode;i++){
        double mini=infi;
        int temp;
        for(int j=1;j<MNode;j++){
            if(!vis[j] && dis[u][j]<mini){
                mini=dis[u][j];
                temp=j;
            }
        }
        vis[temp]=1;
        for(int j=1;j<=MNode;j++){
            if(map[temp][i]+dis[u][temp]<dis[u][i]){
                    dis[u][i]=map[temp][i]+dis[u][temp];
        }
    }
    }
}
int main(){
    if(!read_map()){
        printf("Failed to read Final_Map.map, please try again.\n");
        return 0;
    }
    initial();
    int i=0;
    for(i=1;i<=MNode;i++){
    dijkstra(i);
    //for(int j=1;j<=MNode;j++)if(dis[i][j]>0.001&&dis[i][j]<99999)printf("%d->%d: %lf\n",i,j,dis[i][j]);
  //  printf("%.2lf\n",temp);
    }
  /*
    for(int i=1;i<=MNode;i++){
            dijkstra(1);
            for(int j=1;j<=MNode;j++){
                    if(dis[i][j]>0)printf("%d->%d: %lf\n",i,j,dis[i][j]);
                    if(dis[j][i]>0)printf("%d->%d: %lf\n",j,i,dis[j][i]);
            }
    }
    */
    return 0;
}
