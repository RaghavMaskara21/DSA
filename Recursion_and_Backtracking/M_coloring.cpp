bool isValid(int node, vector<int> &colour, bool graph[101][101], int V, int col){
    for(int i=0;i<V;i++){
        if(i!=node && graph[i][node] ==1 && colour[i]==col){
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<int> &colour, int m, int V, bool graph[101][101]){
    if(node==V){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isValid(node, colour, graph, V, i)){
            colour[node]=i;
            if(solve(node+1, colour, m, V, graph)==true) return true;
            colour[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> colour(V,0);
    if(solve(0,colour, m, V, graph)==true) return true;
    return false;
    
}