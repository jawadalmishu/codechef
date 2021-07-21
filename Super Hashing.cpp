#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

typedef long long ll;

int l,s,arr[60];

ll dp[53][53][1600];

ll f(int coun,int i,int make){

    if(i<0 || coun==0){

        if(make==0 && coun==0){

            return 1;

        }

        return 0;

    }

    if(dp[coun][i][make]!=-1) return dp[coun][i][make];

    ll ret1=0,ret2=0;

    if(make-arr[i]>=0) ret1=f(coun-1,i-1,make-arr[i]);

    ret2=f(coun,i-1,make);

    return dp[coun][i][make]=ret1+ret2;

}

int main()

{

    int test;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<52;i++)

        arr[i]=i+1;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&l,&s);

        if(l<=52 && s<=1378) printf("Case %d: %lld\n",i+1,f(l,51,s));

        else printf("Case %d: 0\n",i+1);

    }

    return 0;

}