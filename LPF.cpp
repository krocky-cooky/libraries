
struct LPF {
    int n;
    vector<int> lpf;
    vector<int> primes;
    vector<int> prime_power;
    vector<int> prev_divisor;
    vector<int> divisor_count;
    LPF(int _n): n(_n),lpf(n+1),prime_power(n+1,1),prev_divisor(n+1,1),divisor_count(n+1) {
        for(int i=2;i <= n; ++i) {
            if(!lpf[i]) {
                primes.push_back(i);
                lpf[i] = i;
                prime_power[i] = 1;
            }

            for(int p : primes) {
                if(p*i > n) break;
                lpf[p*i] = p;
                if(p == lpf[i]) {
                    prev_divisor[p*i] = prev_divisor[i];
                    prime_power[p*i] = prime_power[i] + 1;
                    break;
                }
                prev_divisor[p*i] = i;
                prime_power[p*i] = 1;
            }
        }
        divisor_count[1] = 1;
        for(int i = 2;i <= n; ++i) {
            divisor_count[i] = divisor_count[prev_divisor[i]]*(prime_power[i] + 1);
        }
    }

    int get_divisor_count(int x) {
        if(x > n) {
            return -1;
        }
        return divisor_count[x];
    }
};