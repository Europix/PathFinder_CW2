#include<stdio.h>
#include<string.h>
#include<math.h>
#include "path.c"
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
    if(dis[input2]<=99999)printf("The shortest distance from node %d to %d is %.6lf\n",input1,input2,dis[input2]);
    else printf("Sorry, can't find a way from node %d to %d.", input1,input2);
    addroute(input1,input2,1);
    printf("CT:%d",ct);
    if(save_map() && save_file())printf("\n Successful saved map.txt and ans.txt\n");
    else printf("\n Failed To save the map. Please try again.\n");
    return 0;
}
