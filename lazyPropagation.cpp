class sgTree{
    public:
        vector<int> segment,lazy;
        sgTree(int n){
            segment.resize(4*n+1);
            lazy.resize(4*n+1);
        }

        void build(int idx,int low,int high,vector<int> &a){
            if(low==high){
                segment[idx]=a[low];
                return;
            }

            int mid=(low+high)>>1;
            build(2*idx+1,low,mid,a);
            build(2*idx+2,mid+1,high,a);

            segment[idx]=segment[2*idx+1]+segment[2*idx+2];
        }

        int query(int idx,int low,int high,int l,int r){
            if(lazy[idx]!=0){
                segment[idx]+=(high-low+1)*lazy[idx];
                //if not a leaf node
                if(low!=high){
                    lazy[2*idx+1]+=lazy[idx];
                    lazy[2*idx+2]+=lazy[idx];
                }
                lazy[idx]=0;
            } 

            if(low>r||high<l) return 0;

            if(l<=low&&high<=r) return segment[idx];

            int mid=(low+high)>>1;
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);

            return left+right;
        }

        void update(int idx,int low,int high,int l,int r,int val){
            if(lazy[idx]!=0){
                segment[idx]+=(high-low+1)*lazy[idx];
                if(low!=high){
                    lazy[2*idx+1]+=lazy[idx];
                    lazy[2*idx+2]+=lazy[idx];
                }
                lazy[idx]=0;
            } 

            if(low>r||high<l) return;

            if(l<=low&&high<=r){
                segment[idx]+=(high-low+1)*val;

                if(low!=high){
                    lazy[2*idx+1]+=val;
                    lazy[2*idx+2]+=val;
                }
                return;
            }

            int mid=(low+high)>>1;
            update(2*idx+1,low,mid,l,r,val);
            update(2*idx+2,mid+1,high,l,r,val);

            segment[idx]=segment[2*idx+1]+segment[2*idx+2];
        }

};