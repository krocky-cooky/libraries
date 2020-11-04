#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define irep(i,a,b) for(int i=int(a);i<(int)b;++i)
#define rrep(i,a,b) for(int i=int(a);i>=(int)b;--i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vecctor<ll>>
#define vp vector<pair<ll,ll>>
#define pb push_back
#define se second
#define fi first
#define all(v) v.begin(),v.end()



using namespace std;
using ll = long long;
const ll INF = 1e18;
const double PI = acos(-1);

const ll mod = 1e9 + 7;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll modpow(ll a,ll b){
    if(b == 0){
        return 1;
    }
    if(b%2 == 0){
        ll tmp = modpow(a,b/2);
        return tmp*tmp%mod;
    }else{
        return modpow(a,b-1)*a%mod;
    }

}



int main(void)
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
   
    return 0;
}
