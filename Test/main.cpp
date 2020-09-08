#include<iostream>
using namespace std;
struct point{
    int row;
    int value;
};
int main()
{
    int n,a,b;// n表示向量U，V的维数，a和b表示两个向量所含非0值的个数
    scanf("%d %d %d",&n,&a,&b);
    //向量V的稀疏表示
    point U[a+10];
    int Uvisit[n+10];
    point V[b+10];
    int Vvisit[n+10];
    for(int i=0;i<=n;i++)
    {
        Uvisit[i]=0;
        Vvisit[i]=0;
    }
    for(int i=0;i<a;i++)
    {
        scanf("%d %d",&U[i].row,&U[i].value);
        Uvisit[U[i].row]=U[i].value;
    }
    for(int i=0;i<b;i++)
    {
        scanf("%d %d",&V[i].row,&V[i].value);
        Vvisit[V[i].row]=V[i].value;
    }
    int res=0;
    for(int i=0;i<=n;i++)
    {
        if(Uvisit[i]!=0&&Vvisit[i]!=0)
        {
            res+=Uvisit[i]*Vvisit[i];
        }
    }
    cout<<res;
    return 0;
}
/*
 *
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
 */