#include <bits/stdc++.h>
#include <stdio.h>
#define loop(i,start,end) for(int (i)=start;(i)<(int)(end);++(i))
#define tc int t;scanf("%d",&t); while(t--)
#define ll long long
#define pr pair<int, int>
#define mp make_pair
 
using namespace std;
 
 
struct blocks
{
	int size;
	vector < ll > prefix_max,next_greater,arr;
	vector < ll > shoot_count,ult_end;
    int lazy;
    
 
	blocks(){}
	void init(int s, int start, vector <ll> b)
	{
		size=s;
		lazy=0;
		
		arr.clear();
        shoot_count.clear();
        ult_end.clear();
        next_greater.clear();
        prefix_max.clear();
        
		stack < pair<ll,ll> > st;
		pair < ll , ll> p;
		st.push(mp(b[start],0));
 
		ll mx=b[start];
		prefix_max.emplace_back(mx);
		shoot_count.emplace_back(0);
		ult_end.emplace_back(0);
		next_greater.emplace_back(0);
        arr.emplace_back(b[start]);
 
		loop(i,1,size)
		{
			arr.emplace_back(b[start+i]);
			ll next=b[start+i];
			shoot_count.emplace_back(0);
			ult_end.emplace_back(0);
			next_greater.emplace_back(0);
    
			mx=max(mx,b[start+i]);
			prefix_max.emplace_back(mx);
            
			if(!st.empty())
			{
				p=st.top();
				st.pop();
				while(p.first<next)
				{
 
					next_greater[p.second]=i;
					if(st.empty())
						break;
					p=st.top();
					st.pop();
				}
				if(p.first>=next)
					st.push(p);
				
			}
			st.push(mp(next,i));
		}
 
 
    
		while(!st.empty())
		{
			p=st.top();
			st.pop();
 
			next_greater[p.second]=-1;
 
		}
 
 
		for(int i=size-1;i>=0;i--)
		{
			if(next_greater[i]==-1)
			{
				shoot_count[i]=1;
				ult_end[i]=i;
			}
			else
			{
				shoot_count[i]=1+shoot_count[next_greater[i]];
				ult_end[i]=ult_end[next_greater[i]];
			}
		}
 
 
 
 
	}
 
 
    pair < ll, ll > first_call(ll start, ll value)
    {
        while(start<size && start!=-1)
        {
            if(arr[start]>=value)
            {
                return mp(start,ult_end[start]);
            }
            start=next_greater[start];
        }
        return mp(-1,value);
    }
 
	pair < ll, ll > get_next(ll start,ll value)
	{
 
		int ans;
 
		ans=lower_bound(prefix_max.begin(),prefix_max.end(),value)-prefix_max.begin();
		
		if(ans==size)
		return mp(-1,-1);
		
		
	    return mp(ans,ult_end[ans]);
	}
 
 
	void update(int idx,ll value)
	{
		arr[idx]+=value;
 
        
        
        
        stack < pair<ll,ll> > st;
		pair < ll , ll> p;
		st.push(mp(arr[0],0));
 
		ll mx=arr[0];
		prefix_max[0]=mx;
		
		
 
 
		loop(i,1,size)
		{
			
			ll next=arr[i];
    
			mx=max(mx,arr[i]);
			prefix_max[i]=mx;
            
			if(!st.empty())
			{
				p=st.top();
				st.pop();
				while(p.first<next)
				{
 
					next_greater[p.second]=i;
					if(st.empty())
						break;
					p=st.top();
					st.pop();
				}
				if(p.first>=next)
					st.push(p);
				
			}
			st.push(mp(next,i));
		}
 
 
    
		while(!st.empty())
		{
			p=st.top();
			st.pop();
 
			next_greater[p.second]=-1;
 
		}
 
 
		for(int i=size-1;i>=0;i--)
		{
			if(next_greater[i]==-1)
			{
				shoot_count[i]=1;
				ult_end[i]=i;
			}
			else
			{
				shoot_count[i]=1+shoot_count[next_greater[i]];
				ult_end[i]=ult_end[next_greater[i]];
			}
		}
 
        
	}
	
	
 
};
 
int main()
{
    ios_base::sync_with_stdio (true);
    cin.tie(NULL);
    
	int i;int n,q;
	tc{
        scanf("%d%d",&n,&q);
		int block_size=1000;
        
		int total_blocks=n/block_size+(n%block_size!=0);
		struct blocks block[total_blocks];
 
		vector < ll > arr;
		ll temp;
 
		loop(i,0,n)
		{
			scanf("%lld",&temp);
			arr.emplace_back(temp);
		}
        
		loop(i,0,total_blocks-1)
		{
			block[i].init(block_size,i*block_size,arr);
		}
        
		block[total_blocks-1].init(n-(total_blocks-1)*block_size,(total_blocks-1)*block_size,arr);
 
		while(q--)
		{
			char ch;
			cin>>ch;
			if(ch=='+')
			{
				ll x;
                scanf("%d%lld",&i,&x);
                i--;
				int in_block=i/block_size;
				
                
				int index=i%block_size;
				
				
				block[in_block].arr[index]+=x;
				block[in_block].lazy=1;
			}
			else
			{
				ll l,r;
				scanf("%d%lld%lld",&i,&l,&r);
				i--;
				int in_block=i/block_size;
			
 
				int start=i%block_size;
				
 
				
 
				pair < ll, ll > p;
 
				ll ans=0;
				int flag=0;
                int call=0;
				
				while(in_block<total_blocks)
				{
				    if(block[in_block].lazy==1)
				    {
				        block[in_block].update(0,0);
				        block[in_block].lazy=0;
				    }
				    if(call==0)
				    {
				        p=block[in_block].first_call(start,l);
				    }
				    else
					{
					    
					    p=block[in_block].get_next(start,l);
					}
					call++;
					if(p.first!=-1)
					{
					 	if(block[in_block].arr[p.second]<=r)
					 	{
					 		ans+=block[in_block].shoot_count[p.first];
					 		
					 		l=block[in_block].arr[p.second]+1;
					 		if(l>=r)
					 		{
								break;
							}
					 	}
					 	else
					 	{
					 		start=p.first;
                            int z=0;
					 		while(start<block[in_block].size)
					 		{
					 		    z=1;
					 			if(l<=block[in_block].arr[start])
					 			{
					 				
					 				ans++;
					 				
					 				if(block[in_block].arr[start]>=r)
					 				{
					 					break;
					 				}
					 				
					 				start=block[in_block].next_greater[start];
					 				if(start==-1)
					 					break;
					 				
					 				l=block[in_block].arr[start];
					 				
					 			}
					 			else
					 			{
					 				break;
					 			}
					 		}
					 		if(z==0)
					 		ans++;
					 		break;
					 	}
					}
					
					start=0;
					in_block++;
				}
				printf("%lld\n",ans);
			}
		}
 
	}
	return 0;
}  
