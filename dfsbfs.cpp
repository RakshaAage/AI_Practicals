#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

class Graph{
    public:
    map<int,list<int>> adjList;
    map<int, bool>visited;
    queue<int>q;

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    } 

    void dfs(int node)
    {
        visited[node]=true;
        cout<<node<<" ";
        for(int i : adjList[node])
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
    }

    void bfs()
    {
        if(q.empty()) return;
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int i : adjList[node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
        bfs();
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,6);

    int ch;
    cout<<"Enter 0 for dfs and 1 for bfs: ";
    cin>>ch;
    if(!ch){
        cout<<"DFS is: ";
        g.dfs(0);
    }
    else{
        cout<<"BFS is: ";
        g.q.push(0);
        g.visited[0]=true;
        g.bfs();
    }
    return 0;
}