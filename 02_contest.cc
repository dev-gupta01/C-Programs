#include<bits/stdc++.h> 
/*#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; */
using namespace std;
#define ll long long int
#define MOD 1000000007
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define ford(i,a,b) for(ll i=a;i>=b;i--)
#define all(arr) arr.begin(),arr.end()
#define mp make_pair
#define sorti(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.rbegin(),v.rend())
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first5lo
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::unordered_map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
ll power(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y&1) 
            res=(res*x); 
        y=y>>1;
        x=(x*x);
    }
    return (res);
}
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
void findi(int n,vector<int> &v){
    int bit=0;
    while(n){
        int x=n%2;
        v[bit]+=x;
        n/=2;
        bit++;
    }
}
int main(){
    string s;cin>>s;
    int a[26]={0};
    for(int i=0;i<s.length();i++)
        a[s[i]-'a']++;
    for(int i=0;i<s.length();i++){
        if(a[s[i]-'a']!=0){
            cout<<s[i];
            a[s[i]-'a']=0;
        }
    }
    cout<<endl;
}