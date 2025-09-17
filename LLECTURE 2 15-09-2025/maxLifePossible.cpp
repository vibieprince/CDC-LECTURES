// A scooter requires two tyres to run at any given time. You are given N tyres, and each tyre has a lifespan of L years. The scooter consumes both tyres simultaneously while running.

// Your task is to determine the maximum time (in years) the scooter can be used by rotating and reusing the tyres optimally until all tyres are worn out.

#include<iostream>
using namespace std;

int main(){
    int totalTyres;
    cout<<"Enter total tyres : ";
    cin>>totalTyres;

    int runningTyres;
    cout<<"Enter running tyres : ";
    cin>>runningTyres;

    double life = 1;

    double totalLife = (totalTyres*life)/runningTyres;
    cout<<totalLife;
}