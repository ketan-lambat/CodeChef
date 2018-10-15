#include <stdio.h>
#include <math.h>

int prime(int n)
{
    int flag, i, a, Pcount=0;
    for(i=2; i<n; i++)
    {
        flag=1;
        for(int j=0; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            Pcount++;
    }

    int Parr[Pcount];
    for(i=2; i<n; i++)
    {
        flag=1;
        for(int j=0; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            Parr[Pcount]=i;
    }


    semiprime(Parr[Pcount], n);
}

int checkPrime(int x)
{
    int flag, i;
    for(i=2; i<x; i++)
    {
        flag=1;
        for(int j=0; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            return flag;
    }

}
int semiprime(int Parr[], int n)
{
    int Scount=0, x;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        x=i/Parr[j];
       if(i%Parr[j]==0 && checkPrime(x)==1)
        Scount++;
        }
    }
    int Sarr[Scount];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        x=i/Parr[j];
       if(i%Parr[j]==0 && checkPrime(x)==1)
        Sarr[i]=x;
        }
    }
}

int main()
{
    int n, b;
    scanf("%d", &n);
    prime(n);
    int ans;
    for(int i=0; i<n; i++)
    {
        ans=0;
        b=n-Sarr[i];
        for(int j=0; j<n; j++)
        {
            if(b==Sarr[j])
               {
                ans=1;
                break;
                }

        }
        if(ans==1)
            printf("YES");
        else
            printf("NO";)
    }

}
