#include<stdio.h>
#include<string.h>
#include<math.h>
#include "path.c"
int main(){
    int mark=0;
    int total_mark=0;
    printf("------Ready to Deploy Test------\n");
    printf("Start testing read_map(), 10 marks\n");
    mark+=read_map()*5;
    printf("Return value of read_map(), %d/5 marks.\n", mark);
    for(int i=1;i<=5;i++){
        if(Links[rand()%1000].length!=0)mark++;
    }
    printf("Test random value in map, %d/5 marks.\n",mark-5);
    printf("Got %d/10 marks.\n\n",mark);
    total_mark+=mark;
    mark=0;
    //Read_map();
    printf("Start testing initial(), 15 marks. \nTesting 3 different values.\n");
    initial();
    if(map[43][43]==0)mark+=5;
    if(map[1234][1611]>=0.01)mark+=5;
    if(map[Links[222].node1][Links[222].node2]<=999)mark+=5;
    printf("Got %d/15 marks. \n\n",mark);
    total_mark+=mark;
    mark=0;
    //initial();
    printf("Start testing save_map(), 10 marks.\n");
    mark+=save_map()*5;
    printf("Return value of read_map(), %d/5 marks.\n", mark);
    mark+=5;
    FILE* fp = fopen("map.txt", "w");
        if(fp==NULL){
            mark-=5;
            printf("File not found.\n");
        }
        else printf("Passed File Test. \n");
    printf("Got %d/10 marks. \n\n",mark);
    total_mark+=mark;
    mark=0;
    //save_map()
    printf("Start Testing main algorithms. 30 marks.\n");
    printf("Testing invalid inputs, 10 marks.\n");
    if(!dijkstra(-114514))mark+=5;
    if(!dijkstra(1919810))mark+=5;
    printf("Testing dijkstra value, 20 marks.\n");
    if(dijkstra(1))mark+=5;
    if(dis[1289]<=20 && dis[1290]<=20)mark+=5;
    if(dis[14]>=500 && dis[58]>=500)mark+=5;
    if(vis[14] && vis[58])mark+=5;
    printf("Got %d/30 marks. \n\n",mark);
    total_mark+=mark;
    mark=0;
    //dijkstra
    printf("Start Testing addroute(). 25 marks.\n");
    printf("Testing invalid input values.\n");
    if(!addroute(-5,4,1))mark+=5;
    if(!addroute(5,19,-1))mark+=5;
    if(mark==10)printf("Test Passed, got 10 marks.\n");
    printf("Testing addroute(1,14) and its value.\n");
    addroute(1,14,0);
    if(ct==33)mark+=5;
    if(ans[33]==1 && ans[1]==14)mark+=5;
    if(ans[32]==1290)mark+=5;
    printf("Got %d/25 marks. \n\n",mark);
    total_mark+=mark;
    mark=0;
    //addroute
    printf("Start testing save_file(), 10 marks.\n");
    mark+=save_file()*5;
    printf("Return value of read_map(), %d/5 marks.\n", mark);
    mark+=5;
    FILE* ffp = fopen("ans.txt", "w");
        if(ffp==NULL){
            mark-=5;
            printf("File not found.\n");
        }
        else printf("Passed File Test. \n");
    //save_file
    printf("Got %d/10 marks. \n\n",mark);
    total_mark+=mark;
    mark=0;
    printf("---------------- End of Test ---------------\n");
    printf("Total Mark: %d/100\n",total_mark);
    if(total_mark==100)printf("Congratulations! You Passed All Tests.\n");
}
