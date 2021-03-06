#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

unordered_set<int> vis;
vector<int> breadthfirst;
unordered_map<int, vector<int>> adj;

void bfs(int src){

    queue<int> q;
    //use a queue and do it, its easy
    q.push(src);
    while (q.size() > 0){
        int s = q.front();
        q.pop();
        vis.insert(s);
        for(auto y : adj[s]){
            if(vis.find(y) == vis.end()){
                vis.insert(y);
                breadthfirst.push_back(y);
                q.push(y);
            }
        }
        
    }

}

int main(){
    int edges;
    cout<<"Enter the number of edges ";
    cin>>edges;
    for(int i = 0 ; i < edges; i++){
        int to, from;
        cout<<"Enter the FROM edge ";
        cin>>from;
        cout<<"Enter the TO EDGE ";
        cin>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<int> vertices;
    for(auto x : adj){
        //cout<<"Edge is "<<x.first<<endl;
        vertices.push_back(x.first);
        for(auto y : x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    sort(vertices.begin(), vertices.end());
    /*for(auto x : vertices){
        cout<<x<<" ";
    }*/
    for(auto x : vertices){
        if(vis.find(x) == vis.end()){
            vis.insert(x);
            cout<<"Going in at "<<x<<endl;
            breadthfirst.push_back(x);
            bfs(x);
        }
    }
    for(auto x : breadthfirst){
        cout<<x<<" ";
    }
    return 0;
}
