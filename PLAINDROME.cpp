#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    char *arr=new char;
    int n;

    for(n=0;getchar()!='\n';n++)
    {
        cin>>arr;
        fflush(stdin);
        arr++;
    }
    arr--;

    for(int i=0;i<n;i++)
    cout<<endl<<arr[i]<<endl;

    return 0;

}
