
// Matrix
struct mat {
  typedef mint TT;
  int h, w;
  vv(TT) d;
  mat(){}
  mat(int h, int w, TT v=0):h(h),w(w),d(h,vector<TT>(w,v)){}
  v(TT)& operator[] (int i) { return d[i];}
  const v(TT)& operator[] (int i) const { return d[i];}
  void fil(TT v=0) { rep(i,h)rep(j,w) d[i][j] = v;}
  void unit() { rep(i,h)rep(j,w) d[i][j] = (i==j);}
  mat operator+(const mat& a) const { // same size
    mat res(h,w);
    rep(i,h)rep(j,w) res[i][j] = d[i][j]+a[i][j];
    return res;
  }
  mat operator-(const mat& a) const { // same size
    mat res(h,w);
    rep(i,h)rep(j,w) res[i][j] = d[i][j]-a[i][j];
    return res;
  }
  mat operator*(const mat& a) const { // w = a.h
    mat res(h,a.w);
    rep(i,h)rep(k,w)rep(j,a.w) res[i][j] += d[i][k]*a[k][j];
    return res;
  }
  mat power(ll a) { // h = w
    if (a == 0) {
      mat res(h,w); res.unit();
      return res;
    }
    mat res = power(a/2);
    res = res*res;
    if (a&1) res = res*(*this);
    return res;
  }
};
//



