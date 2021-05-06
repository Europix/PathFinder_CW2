#include<stdio.h>
#include<string.h>
#include<math.h>
//#include<stack>
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
int ct=1;
double map[MNode+10][MNode+10];
double dis[MNode+10];
int vis[MNode+10];
int route[MNode+10];
int ans[MNode+10];
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
void save_map(){
    FILE* fp = fopen("map.txt", "w");
        if(fp==NULL){
            return 0;
        }
    for(int i=1;i<=MaxL ; i++){
        fprintf(fp,"%0.6lf %0.6lf\n%0.6lf %0.6lf\n\n", Nodes[Links[i].node1].x,Nodes[Links[i].node1].y,Nodes[Links[i].node2].x,Nodes[Links[i].node2].y);
    }
}
void save_file(){
    FILE* fp = fopen("ans.txt", "w");
        if(fp==NULL){
            return 0;
        }
    for(int i=ct;i>1;i--){
        fprintf(fp,"%0.6lf %0.6lf\n", Nodes[ans[i]].x ,Nodes[ans[i]].y);
        fprintf(fp,"%0.6lf %0.6lf\n\n", Nodes[ans[i-1]].x, Nodes[ans[i-1]].y);
    }
}
int main(){
    if(!read_map()){
        printf("Failed to read Final_Map.map, please try again.\n");
        return 0;
    }
    int input1,input2;
    printf("Please Input the 2 nodes' ID :\n");
    scanf("%d %d",&input1,&input2);
    if(input1>MNode || input1<=0 || input2>MNode || input2<=0){
        printf("Invalid Input!");
        return 0;
    }
    route[0]=input1;
    initial();
    dijkstra(input1);
    for(int i=1;i<=MaxL;i++){
        if(Nodes[i].id==-2540)printf("%d",i);
    }
    //if(dis[input1][i]<99999)printf("%d\n",i);
    //if(dis[input2]<=99999){
            printf("The shortest distance from node %d to %d is %.6lf\n",input1,input2,dis[input2]);
            int lo=input2;
                while (lo){
                    ans[ct]=lo;
                    if(route[lo]==input2)break;
                    lo=route[lo];
                    ct++;
            }
            ans[ct]=input1;
            for(int i=ct;i>=1;i--)printf("%d->",ans[i]);
            save_map();
            save_file();
    //}
    //else printf("Sorry, can't find a way from node %d to %d.", input1,input2);
//    fprintf("%d\n", dis[input1][input2]);
   // print(input1,input2);
    //for(int i=1;i<=MNode;i++)if(dis[i]>0.001&&dis[i]<99999)printf("%d->%d: %lf\n",input1,i,dis[i]);
    /*for(int i=1;i<=MNode;i++){
            dijkstra(1);
            for(int j=1;j<=MNode;j++){
                    if(dis[i][j]>0)printf("%d->%d: %lf\n",i,j,dis[i][j]);
                    if(dis[j][i]>0)printf("%d->%d: %lf\n",j,i,dis[j][i]);
            }
    }*/
    return 0;
}
