#include<iostream>
using namespace std;
struct point
{
    int x;
    int y;
    int type;// 0 A 1 B
};
bool check(int a,int b,int c,point p[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a+b*p[i].x+c*p[i].y!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n,m; //n points m query
    cin>>n>>m;
    point p[100];
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%d %d %c",&p[i].x,&p[i].y,&c);
        if(c=='A')
            p[i].type=0;
        else 
            p[i].type=1;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(check(a,b,c,p,n))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        } 
    }
    return 0;
}