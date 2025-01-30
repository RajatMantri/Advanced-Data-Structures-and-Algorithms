class DisjointSet{
    public:
        vector<int> parent,size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int find_U_parent(int node){
            if(node==parent[node]) return node;
            parent[node]=find_U_parent(parent[node]);
            return parent[node];
        }
        void reset(int n){
            parent[n]=n;
            size[n]=1;
        }
        void unionBySize(int u,int v){
            int Ult_u=find_U_parent(u);
            int Ult_v=find_U_parent(v);
            if(Ult_u==Ult_v) return;
            if(size[Ult_u]>size[Ult_v]){
                parent[Ult_v]=Ult_u;
                size[Ult_u]+=size[Ult_v];
            }
            else{
                parent[Ult_u]=Ult_v;
                size[Ult_v]+=size[Ult_u];
            }
        }  
};