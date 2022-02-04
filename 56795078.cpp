#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int A,B,C;
        cin>>A>>B>>C;
        if(A+B+C==180){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
	
	return 0;
}
