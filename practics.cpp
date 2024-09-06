#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,6,8,9};
    int size = sizeof(arr)/sizeof(int);
    int maxd = arr[size-1]-arr[0];
     int mind = INT_MAX;
      int i=0;
      int j=1;
      while(j<size){
        int lo = arr[i];
        int hi = arr[j];
        mind = min(mind,hi-lo);
        i++;
        j++;
      }
      cout<<"Min : "<<mind<<endl<<"Max : "<<maxd<<endl;
}