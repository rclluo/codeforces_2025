#include <bits/stdc++.h>
using namespace std;

int n,x,y;
vector<long long> A,B,C;

bool check(int w) {
    long long lx=max(1,x-w),hx=min(x+y-w-1,x);
    for (int i=0; i<n; i++) {
        long long a=A[i],b=B[i],c=C[i];
        long long d=x+y-w;
        if (b-a>0) {
            lx=max(lx,(-c+b*d+(b-a-1))/(b-a));
        } else if (a-b>0) {
            hx=min(hx,(c-b*d)/(a-b));
        } else {
            if (a*d>c) {
                return false;
            }
        }
    }
    return lx<=hx;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        A.resize(n);
        B.resize(n);
        C.resize(n);
        for (int i=0; i<n; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }
        long long lower=0,upper=x+y-2;
        long long curr;
        while (upper>lower) {
            curr=(lower+upper)/2;
            if (check(curr)) {
                upper=curr;
            } else {
                lower=curr+1;
            }
        }
        cout << lower << '\n';
    }
}
