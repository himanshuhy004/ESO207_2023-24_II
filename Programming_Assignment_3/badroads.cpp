#include<iostream> 
#include<queue>
#include<vector>
using namespace std;

void merge(vector<int> &v, int l, int r){
    int mid = l+(r-l)/2;

    vector<int> a, b;

    for(int i=l; i<=mid; i++){
        a.push_back(v[i]);
    }
    for(int i=mid+1; i<=r; i++){
        b.push_back(v[i]);
    }
    int n1 = a.size(), n2 = b.size();
    int i=0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }
    while(i < n1) v[k++] = a[i++];
    while(j < n2) v[k++] = b[j++];
}

void mergeSort(int l, int r, vector<int> &v){
    if(l >= r) return;

    int mid = l + (r-l) / 2;
    mergeSort(l, mid, v);
    mergeSort(mid+1, r, v);
    merge(v, l, r);
}

struct node{
    int data;
    node* next;
    node* prev;
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void deleteNode(node** head, node* curr){
    if(head == NULL || curr == NULL) return;
    if(*head == curr) *head = curr->next;
    if(curr -> next != NULL) curr->next->prev = curr->prev;
    if(curr -> prev != NULL) curr->prev->next = curr->next;
    free(curr); 
}

bool found(vector<int> &v, int x){
    int s = 0, e = v.size()-1;
    while(s <= e){
        int mid = s + (e-s) / 2;
        if(v[mid] == x) return true;
        if(v[mid] < x) s = mid+1;
        else e = mid-1;
    }
    return false;
}

int main(){
    int n, m; 
    cin >> n >> m;

    node *head, *curr, *tmp;
    head = new node(0);
    curr = head;
    for(int x=1; x<n; x++)
    {
        curr -> next = new node(x);
        curr -> next -> prev = curr;
        curr = curr->next;     
    }

    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        mergeSort(0, adj[i].size()-1, adj[i]);
    }

    int ans = -1;
    int vis[n] = {0};

    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        ans++;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            curr = head;
            while(curr != NULL){
                int child = curr->data;
                tmp = curr->next;
                if(!found(adj[node], child) && !vis[child]){
                    q.push(child);
                    vis[child] = 1;
                    deleteNode(&head, curr);
                }
                curr = tmp;
            }
        }
    }

    cout << ans << '\n';

}