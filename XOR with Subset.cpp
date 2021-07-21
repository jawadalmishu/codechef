#include<iostream>

#include<cstdio>

#include<vector>

#include<cstring>

using namespace std;

int arr[1005],n,dp[1005][1033];

int knap(int i,int make){

    if(i>=n) return make;

    if(dp[i][make]!=-1) return dp[i][make];

    int ret=0;

    ret=max(ret,knap(i+1,arr[i]^make));

    ret=max(ret,knap(i+1,make));

    return dp[i][make]=ret;

}

int main()

{

    int test,k;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        memset(dp,-1,sizeof(dp));

        scanf("%d %d",&n,&k);

        for(int j=0;j<n;j++) scanf("%d",&arr[j]);

        int g=knap(0,k);

        printf("%d\n",g);

    }

    return 0;

}