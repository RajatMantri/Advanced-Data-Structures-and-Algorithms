class sgTree{
    vector<int> segment;
    public:
        sgTree(int n){
            segment.resize(4*n+1);
        }

        void build(int idx,int low,int high,vector<int> &a){
            if(low==high){
                segment[idx]=a[low];
                return;
            }

            int mid=(low+high)>>1;
            build(2*idx+1,low,mid,a);
            build(2*idx+2,mid+1,high,a);

            segment[idx]=min(segment[2*idx+1],segment[2*idx+2]);
        }

        int query(int idx,int low,int high,int l,int r){
            //l r low high   low high  l r
            if(low>r||high<l) return INT_MAX;
            //l low high r
            else if(l<=low&&high<=r) return segment[idx];

            int mid=(low+high)>>1;
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);

            return min(left,right);
        }

        void update(int idx,int low,int high,int i,int val){
            if(low==high){
                segment[idx]=val;
                return;
            }

            int mid=(low+high)>>1;
            if(i<=mid) update(2*idx+1,low,mid,i,val);
            else update(2*idx+2,mid+1,high,i,val);

            segment[idx]=min(segment[2*idx+1],segment[2*idx+2]);
        }

};