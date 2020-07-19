#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
bool isadj[751][751];
int set[751];
struct point{
    double x, y;
};
struct edge{
    int src, dst;
    double w;
};
double dist(point a, point b)
{
    double x1, y1, x2, y2;
    x1 = a.x; y1 = a.y;
    x2 = b.x; y2 = b.y;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int find(int x){return x == set[x] ? x : find(set[x]);}
vector <edge> Edges;
vector <point> points;
int main()
{
    int n, m;
    
    while(~scanf(" %d", &n)){
        Edges.clear();
        points.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                isadj[i][j] = 0;
            }
            set[i] = i;
        }
        point t_point;
        for(int i = 0; i < n; i++){
            scanf(" %lf %lf", &t_point.x, &t_point.y);
            points.push_back(t_point);
        }
        scanf(" %d", &m);
        int a, b;
        for(int i = 0; i < m; i++){
            scanf(" %d %d", &a, &b);
            --a, --b;
            isadj[b][a] = isadj[a][b] = 1;
        }
        int s = points.size();
        edge t_edge;
        for(int i = 0; i < s; i++){
            for(int j = i + 1; j < s; j++){
                if(!isadj[i][j]){ 
                    t_edge.src = i; t_edge.dst = j;
                    t_edge.w = dist(points[i], points[j]);
                    Edges.push_back(t_edge); 
                }else{
                    t_edge.src = i; t_edge.dst = j;
                    t_edge.w = 0.0;
                    Edges.push_back(t_edge); 
                } 
            }
        }
        sort(Edges.begin(), Edges.end(), cmp);
        int e = 0;
        double ans = 0.0;
        s = Edges.size();
        for(int i = 0; i < s; i++){
            t_edge = Edges[i];
            a = find(t_edge.src); b = find(t_edge.dst);
            if(a != b){
                set[a] = b;
                ans += t_edge.w;
                e++;
            }
        }
        printf("%.2f\n", ans);
    }
}
