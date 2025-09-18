#include<iostream>
using namespace std;
// We have three rods Source,Destination,Extra
// We have n disks in source rod and have to place in destination disk using extra rod 

void towerOfHanoi(int disk,char Source,char Destination,char Extra){
    if(disk<=0) return;
    towerOfHanoi(disk-1,Source,Extra,Destination);
    cout<<"Move "<<disk<<" from "<<Source<<" to "<<Destination<<"\n";
    towerOfHanoi(disk-1,Extra,Destination,Source);
}

int main(){
    int n;
    cout<<"Enter the number of rods : ";
    cin>>n;
    towerOfHanoi(n,'S','D','E');
    return 0;
}