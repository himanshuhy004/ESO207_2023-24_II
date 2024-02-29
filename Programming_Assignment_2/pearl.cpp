#include <iostream> 
#include<vector>
using namespace std;
 
int main()
{ 
    
    int n,k;
    cin>>n>>k;
    k--;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i+1);
    }
 
    int i=0;
    int cnt = n;
    while(v.size()!=0)
    {
        i= (i+k)%cnt;
        cout<<*(i+v.begin())<<" ";
        v.erase(i+v.begin());
        cnt--;
    }
 
return 0;
}