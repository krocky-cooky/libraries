
struct StronglyConnectedComponents{
    vector<vector<ll>> tg,rg,ret;
    vector<ll> order,used,comp;
    ll n;
    StronglyConnectedComponents(vector<vector<ll>> g):n(g.size()),tg(g.size()),rg(g.size()),used(g.size()),comp(g.size(),-1){
        rep(i,g.size()){
            for(ll to : g[i]){
                tg[i].pb(to);
                rg[to].pb(i);
            }
        }
    }

    void dfs(ll now){
        if(used[now])return;
        used[now] = 1;
        for(ll to : tg[now])dfs(to);
        order.pb(now);
    }

    void rdfs(ll now,ll count){
        if(comp[now] != -1)return;
        comp[now] = count;
        for(ll to : rg[now])rdfs(to,count);

    }

    void build(void){
        rep(i,n)dfs(i);
        reverse(order.begin(),order.end());
        ll group = 0;
        for(ll node : order){
            if(comp[node] == -1){
                rdfs(node,group);
                group++;
            }
        }

        ret.resize(group);
        rep(i,n){
            for(ll to : g[i]){
                ll s = comp[to],t = comp[i];
                if(s != t)ret[t].pb(s);
            }
        }


    }

};