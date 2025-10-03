#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int partition(vector<double> &array,int low,int high){
    double pivot = array[low];
    int i = low;
    int j = high;
    while(i<=j){
        while(i<=high && array[i] <= pivot) i++;
        while(j>=low && array[j]>pivot) j--;
        if(i<j) swap(array[i],array[j]);
    }
    swap(array[low],array[j]);
    return j;
}

vector<double> KnearestToOrigin(vector<pair<int,int>> arr,int k){
    vector<double> array;
    for(pair<int,int> i : arr){
        double dist = sqrt(i.first*i.first + i.second*i.second);
        array.push_back(dist);
    }

    int low = 0,high = array.size()-1;
    while(low<=high){
        int mid = partition(array,low,high);
        if(mid==k-1) return vector<double>(array.begin(),array.begin()+k);
        else if(mid>k) high = mid-1;
        else low = mid+1;
    }
    return {};
}

int main() {
    vector<pair<int,int>> points = {{1,2}, {3,4}, {2,2}, {5,1}, {0,1}, {3,3}};
    int k = 3;
    vector<double> nearest = KnearestToOrigin(points, k);

    cout << "The " << k << " nearest distances to origin are: ";
    for (double d : nearest) cout << d << " ";
    cout << endl;

    return 0;
}
