#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef     long long int    ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(int i=a;i<=b;i++)
#define     FORD(i,b,a)      for(int i=b;i>a;i--)
#define     FORDE(i,b,a)     for(ll i=b;i>=a;i--)
#define     debug(x)         cout<< '>'<<#x<<" : "<<x<<"\n";
#define     debug2(x,y)      cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";
#define     debug3(x,y,z)    cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";cout<< '>'<<#z<<" : "<<z<<"\n";
#define     umap             unordered_map
#define     uset             unordered_set
#define     lb               lower_bound
#define     ub               upper_bound
#define     mp               make_pair
#define     in               insert
#define     s                second
#define     f                first
#define     nn               cout<<"\n"
#define     pb               push_back
#define     testcase         int t;cin>>t;while(t--)
#define     gcd(a,b)         __gcd(a,b)
#define     maxv             INT_MAX
#define     minv             INT_MIN
#define     MOD              1000000007
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>


ll nCrModpDP(ll n, ll r) 
{ 
    
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (ll i = 1; i <= n; i++) 
    { 
        
        for (ll j = min(i, r); j > 0; j--) 
  
            
            C[j] = (C[j] + C[j-1])%MOD; 
    } 
    return C[r]; 
} 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll ntopowermandMod(ll n,ll m,ll mod_v)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowermandMod(n,m/2,mod_v);
        val=val%mod_v;
        val=val*val;
        val=val%mod_v;
        if(m%2==1)
        {
        val=val*n;
        val=val%mod_v;
        }
        return val;

    }
    
}
ll ntopowerm(ll n,ll m)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowerm(n,m/2);
        val=val*val;
        if(m%2==1)
        {
        val=val*n;
        }
        return val;

    }
    
}
template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll sum_b=0;
        vector <ll> boxes(m);
        FOR(i,0,m) {cin>>boxes[i];
            sum_b+=boxes[i];
        }
        ll sz=64;
        vector<ll> box_sz(sz+1,0);
        FOR(i,0,m)
        {
            ll vz=log2(boxes[i]);
            box_sz[vz]++;
        }
        ll tmp=n;
        ll curr=0;
        bool flg=true;
        // dispvector<ll>(box_sz);
        ll last=0;
        while(tmp>0)
        {
            ll dic=tmp%2;
            box_sz[curr]-=dic;
            tmp=tmp/2;
            if(box_sz[curr]<0)
            {
                flg=false;
                
            }
            curr++;
        }
            // dispvector<ll>(box_sz);

        if(flg)
        {
            // cout<<"**"<<endl;            
            cout<<0<<endl;

        }
        else if(sum_b>=n)
        {
            ll ans=0;
            reverse(box_sz.begin(),box_sz.end());
            // dispvector<ll>(box_sz);
            FOR(i,0,sz)
            {
                if(box_sz[sz-i]<0)
                {
                    while(i<sz &&box_sz[sz-i]<=0)
                    {
                        i++;
                        ans++;
                    }

                    box_sz[sz-i]--;
                    box_sz[sz-1-i]+=(box_sz[sz-i])/2;

                }
                else
                {
                    box_sz[sz-1-i]+=(box_sz[sz-i])/2;
                    box_sz[sz-i]=box_sz[sz-i]%2;
                }
                
            }
            // dispvector<ll>(box_sz);

                        
            cout<<ans<<endl;
                
        }
        else
        {
        cout<<-1<<endl;                
        }
        
        


    }
    return 0;
}
