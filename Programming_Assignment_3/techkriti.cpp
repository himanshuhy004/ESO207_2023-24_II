#include<iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1; i<=n; i++) cin >> a[i];

    int ans=0;
    int id[n+1] = {0};

    for(int i=1; i<=n; i++){
        if(id[i]) continue;

        int node = i;
        while(id[node]==0){
            id[node] = i;
            node = a[node];
            ans++;
        }
        ans--;
    }

    for(int i=1; i<n; i++){
        if(id[i] == id[i+1]){
            cout << ans-1 << '\n';
            return;
        }
    }
    cout << ans+1 << '\n';
}

int main(){

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

    return 0;
}