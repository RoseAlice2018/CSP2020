#include<cstdio>
#include<vector>
using namespace std;

int n;
int a, b;
long long ans; // 使用 long long

vector<pair<int, int> > u, v;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    int id, val;
    for(int i=0; i<a; i++) {
        scanf("%d%d", &id, &val);
        u.push_back({id, val});
    }

    for(int i=0; i<b; i++) {
        scanf("%d%d", &id, &val);
        v.push_back({id, val});
    }

    int i=0, j=0;
    while(i<a && j<b){
        if(u[i].first==v[j].first){
            ans += u[i].second * v[j].second;
            i++; j++;
        }
        else if(u[i].first>v[j].first){
            j++;
        }
        else{
            i++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
