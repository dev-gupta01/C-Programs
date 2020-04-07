#include<bits/stdc++.h>
using namespace std;
int get_fibonacci_last_digit_fast(long long n) {
    if(n<=1)
        return n;
    int f1=0,f2=1,f3;
    for(int i=0; i<n-1;i++){
        f3=(f1+f2)%10;
        f1=f2%10;
        f2=f3%10;
    }
    return f3;
}
int fibonacci_sum_fast(long long n) {
    int new_last_n = get_fibonacci_last_digit_fast(n%60);
    int new_last_m = get_fibonacci_last_digit_fast((n+1)%60);
    return (new_last_m*new_last_n)%10;
}
int main(){
  long long int n;
  cin>>n;
  int ans=fibonacci_sum_fast(n);
  cout<<ans<<"\n";
}
