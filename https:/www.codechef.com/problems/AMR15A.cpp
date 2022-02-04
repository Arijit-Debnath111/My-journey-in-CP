#include <iostream>
using namespace std;

int main() {
	int N,lucky=0;
	cin>>N;
	for(int i=0;i<N;i++){
	    int CSW;
	    cin>>CSW;
	    if(CSW%2==0){
	        lucky++;
	    }
	}
	if(lucky>(N-lucky)){
	    cout<<"READY FOR BATTLE"<<endl;
	}
	else{
	    cout<<"NOT READY"<<endl;
	}
	return 0;
}
