#include<iostream>
#include<cmath>
using namespace std;

int is_power_of_2(unsigned int x)
{
    unsigned int temp=x,i,r;
    long int bin=0;
    for(i=0;temp;i++)
    {
        r=temp%2;
        temp/=2;
        bin=bin*10+r;
    }
    if(bin==1)
        return (i-1);
    else
        return 0;

}



long long add(int power)
{
    if(power==0)
        return 1;
    else
        return ((power+1)*pow(3,power)+add(power-1));
}

long long int F(unsigned int a,unsigned int b)
{
    int i1,i2,power1,power2;
    unsigned int temp1=a,temp2=b;
    long long int sum=0;

    for(i1=0;!(power1=is_power_of_2(temp1));++i1)
    {
        temp1--;
    }

    for(i2=0;!(power2=is_power_of_2(temp2));++i2)
    {
        temp2--;
    }

    for(int n=power1;n<power2;n++)
    {
       sum+=add(n);
    }



    return sum;

}

int main()
{
    int T;
    cin>>T;
    unsigned int L[T],R[T];

    for(int i=0;i<T;++i)
    {
        cin>>L[i];
        cin>>R[i];
    }

    for(int i=0;i<T;++i)
    {
        cout<<F(L[i],R[i])<<endl;
    }
    return 0;
}
