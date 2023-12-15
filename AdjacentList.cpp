#include<bits/stdc++.h>

using namespace std;

class graph{
   public:
   
   unordered_map<int,list<int>>adj;

   void addEdge(int u,int v,bool direction){
    // direction==0 ->undirected graph vice versa for directed

    //creating an edge u to v
    adj[u].push_back(v);
    if (direction==0)
    {
        /* code */
        adj[v].push_back(u);
    }
    
   }
   void print(){
      for(auto i : adj){
          cout<<i.first<<"->";
          for(auto j: i.second){
               cout<<j<<", ";
          }
          cout<<endl;
      }

   }
};




int main(){
    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;
    int m;
    cout<<"Enter the number of edge:";
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u>>v;

        g.addEdge(u,v,0);//undirected


    }
    g.print();
}