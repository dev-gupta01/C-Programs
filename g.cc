#include<iostream>
using namespace std;
class mnc{
    char cname[25];
    protected:
        char hoffice[25];
    public:
        mnc();
        void enter();
};
class branch:public mnc{
    long noe;
    char ctry[25];
    protected:
        void association();
    public:
        branch();
        void add();
};
int main(){
    branch b1;
    b1.association();
    
}