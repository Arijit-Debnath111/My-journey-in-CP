#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int p,itemPrice=2048,ans=0;
	    cin>>p;
	    while(p>0){
	        ans+=p/itemPrice;
	        p%=itemPrice;
	        itemPrice/=2;
	        
	        
	        
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
