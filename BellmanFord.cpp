struct edge{
    ll from,to,cost;
};

struct BellmanFord{
    ll n;
    vector<ll>dist;
    vector<edge>es;

    BellmanFord(ll _n): n(_n),dist(_n,1e18){}

    void add(ll from,ll to,ll cost){
        es.pb({from,to,cost});
    }

    bool search(ll x,ll check = -1){
        dist[x] = 0;
        rep(i,n-1){
            for(edge e : es){
                if(dist[e.from] == 1e18)continue;
                dist[e.to] = min(dist[e.to],dist[e.from] + e.cost);
            }
        }
        bool flag = true;
        vector<ll>sub = this->dist;
        rep(i,n){
            for(edge e : es){
                if(sub[e.from] == 1e18)continue;
                if(chmin(sub[e.to],sub[e.from] + e.cost)){
                    sub[e.to] = -1e18;
                }
            }
        }
        if(check == -1)rep(i,n)flag = flag & (sub[i] == this->dist[i]);
        else flag = this->dist[n-1] == sub[n-1];
        return flag;
    }
};