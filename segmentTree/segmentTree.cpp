#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
    int sz;vector<ll>seg;
    void build(int l,int r,int node,vector<ll>&arr)
    {
        if(l==r)
        {
            if(l<arr.size())
            {
                seg[node]=arr[l];
            }
            return;
        }
        build(l,mid,L,arr);
        build(mid+1,r,R,arr);
        seg[node]=seg[L]+seg[R];
    }
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        if(idx<=mid)
        {
            update(l,mid,L,idx,val);
        }
        else
        {
            update(mid+1,r,R,idx,val);
        }
        seg[node]=seg[L]+seg[R];
    }
    ll query(int l,int r,int node,int lq,int rq)
    {
        if(r<lq||l>rq)
        {
            return 0;
        }
        if(l>=lq&&r<=rq)
        {
            return seg[node];
        }
        ll lft=query(l,mid,L,lq,rq);
        ll rgt=query(mid+1,r,R,lq,rq);
        return lft+rgt;
    }
public:
    SegmentTree(vector<ll>&arr)
    {
        sz=1;int n=arr.size();
        while(sz<n) sz*=2;
        seg=vector<ll>(sz*2);
        build(0,sz-1,0,arr);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
#undef L
#undef R
};
