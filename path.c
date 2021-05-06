#include<stdio.h>
#include<string.h>
#include<math.h>
#include "algorithm.c"
//#include<stack>
int read_map(){
    double xmin,xmax,ymin,ymax;
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
int save_map(){
    FILE* fp = fopen("map.txt", "w");
        if(fp==NULL){
            return 0;
        }
    for(int i=1;i<=MaxL ; i++){
        fprintf(fp,"%0.6lf %0.6lf\n%0.6lf %0.6lf\n\n", Nodes[Links[i].node1].x,Nodes[Links[i].node1].y,Nodes[Links[i].node2].x,Nodes[Links[i].node2].y);
    }
    return 1;
}
int save_file(){
    FILE* fp = fopen("ans.txt", "w");
        if(fp==NULL){
            return 0;
        }
    for(int i=ct;i>1;i--){
        fprintf(fp,"%0.6lf %0.6lf\n", Nodes[ans[i]].x ,Nodes[ans[i]].y);
        fprintf(fp,"%0.6lf %0.6lf\n\n", Nodes[ans[i-1]].x, Nodes[ans[i-1]].y);
    }
    return 1;
}
