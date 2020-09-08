#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<char,string> dic={{'1',"2"},{'2',"4"},{'3',"8"},{'4',"16"},{'5',"32"},{'6',"64"},{'7',"128"},{'8',"256"},{'9',"512"}};
void doubl2(string& s)
{
    char c;
    string temp;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        string t=dic[c];
        temp+=t;
    }
    s=temp;
    return;
}
int main()
{
    int n;
    string s;
    int count=0;
    cin>>n>>s;
    string temp="1";
    while(n--)
        doubl2(temp);
    int longs=s.size();
    cout<<temp.substr(4,6)<<endl;
    for(int i=0;i<temp.size();i++)
    {
        string s1=temp.substr(i,i+longs);
        cout<<i<<" "<<i+longs<<endl;
        cout<<s1<<endl;
        if(s1==s)
        {
            i+=s.size();
            cout<<"did it"<<endl;
            count++;
        }
        s1="";
    }
    cout<<count;
    return 0;
}
