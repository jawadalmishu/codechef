#include<iostream>

#include<cstdio>

#include<cmath>

using namespace std;

int a[100005],tree[300015];

int gcd(int p,int q){

    while(q!=0){

        int temp=q;

        q=p%q;

        p=temp;

    }

    return p;

}

void init(int node,int b,int e){

    if(b==e){

        tree[node]=a[b];

        return;

    }

    int left=2*node;

    int right=(2*node)+1;

    int mid=(b+e)/2;

    init(left,b,mid);

    init(right,mid+1,e);

    int j=tree[left];

    int k=tree[right];

    int temp=k;

    k=max(j,k);

    if(k!=temp) j=temp;

    k=gcd(k,j);

    tree[node]=k;

}

int query(int node,int b,int e,int i,int j){

    if(j<b || i>e) return 0;

    if(b>=i && e<=j) return tree[node];

    int left=2*node;

    int right=(2*node)+1;

    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j);

    int p2=query(right,mid+1,e,i,j);

    int temp=p1;

    p1=max(p1,p2);

    if(p1!=temp) p2=temp;

    p1=gcd(p1,p2);

    return p1;

}

int main()

{

    int test,n,q,l,r;

    scanf("%d",&test);

    for(int i=0;i<test;i++){

        scanf("%d %d",&n,&q);

        for(int j=1;j<=n;j++) scanf("%d",&a[j]);

        init(1,1,n);

        for(int j=0;j<q;j++){

            scanf("%d %d",&l,&r);

            int g=query(1,1,n,1,l-1);

            int h=query(1,1,n,r+1,n);

            int temp=g;

            g=max(g,h);

            if(g!=temp) h=temp;

            g=gcd(g,h);

            printf("%d\n",g);

        }

    }

    return 0;

}