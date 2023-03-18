#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define irep(i,a,b) for(int i=int(a);i<(int)b;++i)
#define rrep(i,a,b) for(int i=int(a);i>=(int)b;--i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll,ll>>>
#define vpl vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define pb push_back
#define se second
#define fi first
#define all(v) v.begin(),v.end()
#define v(T) vector<T>
#define vv(T) vector<vector<T>>

using namespace std;

template<typename T> istream& operator>>(istream&i,v(T)&v){rep(j,v.size())i>>v[j];return i;}
template<typename T> string join(const v(T)&v){stringstream s;rep(i,v.size())s<<' '<<v[i];return s.str().substr(1);}
template<typename T> ostream& operator<<(ostream&o,const v(T)&v){if(v.size())o<<join(v);return o;}



using ll = long long;
const ll INF = LLONG_MAX-1e9;
const double PI = acos(-1);

const ll mod = 1e9 + 7; //998244353;

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
