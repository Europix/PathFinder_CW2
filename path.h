#define MaxL 2345
#define MaxN 6286
#define MNode MaxN-MaxL
#define infi 0x3f3f3f3f
struct Node{
    long long int id;
    double x;
    double y;
}Nodes[MaxN-MaxL+100];
int ct=1;
struct Link{
    int node1;
    int node2;
    double length;
}Links[MaxL+100];

double map[MNode+10][MNode+10];
// Store map
double dis[MNode+10];
// Store distance
int vis[MNode+10];
int route[MNode+10];
//Store routes for destination node
int ans[MNode+10];
int read_map();
//Read map from .map File
void initial();
int dijkstra(int u);
//Main algorithm
int save_map();
int save_file();
int addroute(int u,int v,int x);
