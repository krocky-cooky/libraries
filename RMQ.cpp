//区間最大値または最小値を求めるセグメント木の構造体

template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    T bound;  //最小値のときはinf,それ以外の時0となる
    int n;
    bool flag; //最大値でtrue
    vector<T> dat;
    RMQ(int n_,bool flag_ = true) : n(),flag(flag_), dat(n_ * 4,flag_ ? 0 : INF){
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
        if(flag_){
            bound = 0;
        }else{
            bound = INF;
        }
    }

    T func(T a,T b){
        if(flag){
            return max(a,b);
        }else{
            return min(a,b);
        }
    }

    void update(int i,T x){
        i += n - 1;
        dat[i] = x;
        while(i > 0){
            i = (i-1)/2;
            dat[i] = func(dat[i*2+1],dat[i*2+2]);
        }
    }


    T query(int a,int b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(int a,int b,int k,int l,int r){
        if(r <= a || b <= l){
            return bound;
        }else if(a <= l && r <= b){
            return dat[k];
        }else{
            T v_l = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T v_r = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return func(v_l, v_r);
        }
    }


};