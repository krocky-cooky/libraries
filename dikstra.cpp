struct edge{
    ll from,to,cost;
};

struct dikstra{
    ll n;
    vector<ll>dist;
    vector<bool>done;
    vector<vector<edge>>es;
    dikstra(ll _n):n(_n),dist(_n,1e18),done(_n,false),es(_n){}
    void add(ll from,ll to,ll cost){
        es[from].pb({from,to,cost});
    }
    void search(ll x){
        priority_queue<pair<ll,ll>>que;
        que.push({0,x});
        done[x] = true;
        dist[x] = 0;
        while(!que.empty()){
            auto k = que.top();que.pop();
            ll d = -k.first,i = k.second;
            if(d > dist[i])continue;
            for(edge e : es[i]){
                if(done[e.to])continue;
                if(dist[e.to] > d + e.cost){
                    dist[e.to] = d + e.cost;
                    que.push({-dist[e.to],e.to});
                }
            }
        }
    }
};

