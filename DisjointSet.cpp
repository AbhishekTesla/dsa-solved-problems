#include<bits/stdc++.h>
using namespace std;

// Time Complexity:  The actual time complexity is O(4) which is very small and close to 1. So, we can consider 4 as a constant.


class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);  //1-based indexing
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

//Path Compression finding parent for given node
    int findPar(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findPar(parent[node]);
    }

// UnionByRank connecting the two nodes
    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u==ulp_v)
        return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }

};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}