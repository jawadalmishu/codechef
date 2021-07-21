#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>

#include<vector>

using namespace std;

typedef long long ll;

ll n,tree[100009];

ll query(ll idx){

    ll sum=0;

    while(idx>0){

        sum=sum+tree[idx];

        idx=idx-(idx & -idx);

    }

    return sum;

}

void update(ll idx){

    while(idx<=n){

        tree[idx]=tree[idx]+1;

        idx=idx+(idx & -idx);

    }

}

bool cmp(pair<ll,ll>a,pair<ll,ll>b){

    if(a.first<b.first) return true;

    return false;

}

int main()

{

    ll x,y,b[100009],c[100009];

    vector<pair<ll,ll> >a;

    scanf("%lld",&n);

    for(ll i=0;i<n;i++){

        scanf("%lld %lld",&x,&y);

        b[i]=y;

        a.push_back(make_pair(x,y));

    }

    sort(b,b+n);

    sort(a.begin(),a.end(),cmp);

    for(ll i=0;i<n;i++){

        ll idx=lower_bound(b,b+n,a[i].second)-b;

        c[i]=idx+1;

    }

    ll coun=0;

    for(ll i=n-1;i>=0;i--){

        ll x=query(c[i]-1);

        coun+=x;

        update(c[i]);

    }

    printf("%lld\n",coun);

    return 0;

}