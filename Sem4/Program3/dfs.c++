#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

unordered_set<int> vis;
vector<int> depthfirst;
unordered_map<int, vector<int>> adj;
stack<int> st;

void dfs(int src){
    vis.insert(src);
    st.push(src);
    for(auto x : adj[src]){
        if(vis.find(x) == vis.end()){
            vis.insert(x);
            depthfirst.push_back(x);
            dfs(x);
        }
    }
    cout<<st.top()<<" ";
    st.pop();
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
            //cout<<"Going in at "<<x<<endl;
            depthfirst.push_back(x);
            dfs(x);
        }
    }
    /*for(auto x : depthfirst){
        cout<<x<<" ";
    }*/
    return 0;
}
