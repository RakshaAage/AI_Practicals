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
void buildGraph(Graph &g)
{
    int vertices, edges, src, dest;
    
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    cout<<"Enter edges (src dest):\n";
    for (int i = 0; i < edges; ++i) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
}

int main()
{
    Graph g;
    buildGraph(g);
    int  ch;

    while(true)
    {
        cout << "\nEnter 0 for DFS, 1 for BFS, or -1 to exit: ";
        cin >> ch;

        switch (ch) {
            case 0:
                cout << "DFS is: ";
                 g.visited.clear(); // Reset visited map
                g.dfs(0);
                break;
            case 1:
                cout << "BFS is: ";
                 g.visited.clear(); // Reset visited map
                g.q.push(0);
                g.visited[0] = true;
                g.bfs();
                break;
            case -1:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice!";
                break;
        }
    }
}