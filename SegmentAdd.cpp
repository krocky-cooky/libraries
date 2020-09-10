template<class T>
struct SegmentAdd{
    vector<T>dat;
    int n = 1;
    const T INF = numeric_limits<T>::max();
    SegmentAdd(vector<T> v) {
        int sz = v.size();
        while(n < sz)n *= 2;
        dat.resize(2*n-1);
        rep(i,sz){
            dat[i+n-1] = v[i];
        }
        for(int i = n-2; i >= 0; --i){
            dat[i] = dat[2*i+1] + dat[2*i+2];
        }
    }

    void update(int i,T x){
        i += (n-1);
        dat[i] += x;
        while(i > 0){
            i = (i-1)/2;
            dat[i] += x;
        }
    }

    T query_sub(int a,int b,int k,int l,int r){
        if(a >= r || b <= l)return 0;
        if(a <= l && b >= r)return dat[k];
        T n1 = query_sub(a,b,2*k+1,l,(l+r)/2);
        T n2 = query_sub(a,b,2*k+2,(l+r)/2,r);
        return n1 + n2;
    }

    T query(int a,int b){
        return query_sub(a,b,0,0,n);
    }

};