#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

int n1,n2,k1,k2;

typedef long long ll;

#define mod 1000000007

ll dp[101][101][11][11];

ll f(int m1,int m2,int l1,int l2){

    if(m1==n1 && m2==n2) return 1;

    if((l1==k1 && m1<n1 && m2==n2) || (l2==k2 && m2<n2 && m1==n1)) return 0;

    if(dp[m1][m2][l1][l2]!=-1) return dp[m1][m2][l1][l2];

    ll ret1=0,ret2=0;

    if(l1+1<=k1 && m1+1<=n1){

        ret1=f(m1+1,m2,l1+1,0);

    }

    if(l2+1<=k2 && m2+1<=n2){

        ret2=f(m1,m2+1,0,l2+1);

    }

    return dp[m1][m2][l1][l2]=((ret1%mod)+(ret2%mod))%mod;

}

int main()

{

    int test;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d %d %d",&n1,&n2,&k1,&k2);

        memset(dp,-1,sizeof(dp));

        printf("%lld\n",f(0,0,0,0));

    }

    return 0;

}