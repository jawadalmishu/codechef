#include<cstdio>

#include<cstring>

#include<iostream>

using namespace std;

#define mod 100

typedef long long ll;

ll dp[105][105];

int arr[105];

int sum(int st,int ed){

    int sum=0;

    for(int i=st;i<=ed;i++)

        sum=((sum%mod)+(arr[i]%mod))%mod;

    return sum;

}

ll f(int beg,int ends){

    if(beg>=ends) return 0;

    if(dp[beg][ends]!=-1) return dp[beg][ends];

    ll ans=100000000000000000;

    for(int mid=beg;mid<ends;mid++){

        ll op_left=f(beg,mid);

        ll op_right=f(mid+1,ends);

        ans=min(ans,op_left+op_right+sum(beg,mid)*sum(mid+1,ends));

    }

    return dp[beg][ends]=ans;

}

int main()

{

    int n;

    while(scanf("%d",&n)!=-1){

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

        }

        memset(dp,-1,sizeof(dp));

        printf("%lld\n",f(0,n-1));

    }

    return 0;

}