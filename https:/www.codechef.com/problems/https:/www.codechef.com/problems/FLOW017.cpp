#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int A[3],max=INT_MIN,smax=INT_MIN;
        cin>>A[0]>>A[1]>>A[2];
        for(int j=0;j<3;j++){
            if(A[j]>max){
                smax=max;
                max=A[j];
            }
            else if(A[j]>smax){
                smax=A[j];
            }
            
        }
        cout<<smax<<endl;
    }
}

