#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int inf = 1e9;

struct value{
    int nearestNode;
    int dist_nearestNode;
    value(){
        nearestNode = inf;
        dist_nearestNode = inf;
    }
};

int main(){
    int n, Q, m, x;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<value> val(n+1); //nearest node, dist
    
    for(int i=1; i<=n; i++){
        cin >> x;
        if(i == 1) continue;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    queue<pair<int, int>> q; //node, distance from nearest marked node

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> x;
        q.push({x, 1});
        val[x].nearestNode = x;
        val[x].dist_nearestNode = 0;
    }

    //bfs
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto child : adj[node]){
            if(d <= val[child].dist_nearestNode){
                val[child].dist_nearestNode = d;
                if(val[node].nearestNode < val[child].nearestNode){
                    val[child].nearestNode = val[node].nearestNode;
                    q.push({child, d+1});
                }
            }
        }
    }

    cin >> Q;

    while(Q--){
        cin >> x;
        cout << val[x].nearestNode << '\n';
    }

}