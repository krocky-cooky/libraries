/*
エッジの重みが正の場合にのみ、最短経路を探索することができる



→未確定ノードのうち距離が最小のノードを確定とする
→そのノードからいけるノードをqueueに追加する
*/  

struct edge{
    ll from,to,cost;
};

struct dijkstra{
    ll n;
    vector<ll>dist;
    vector<vector<edge>>es;
    dijkstra(ll _n):n(_n),dist(_n,1e18),es(_n){}
    void add(ll from,ll to,ll cost){
        es[from].pb({from,to,cost});
    }
    void search(ll x){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>que;
        que.push({0,x});
        dist[x] = 0;
        while(!que.empty()){
            auto k = que.top();que.pop();
            ll d = k.first,i = k.second;
            if(d > dist[i])continue;
            for(edge e : es[i]){
                if(dist[e.to] > d + e.cost){
                    dist[e.to] = d + e.cost;
                    que.push({dist[e.to],e.to});
                }
            }
        }
    }
};

