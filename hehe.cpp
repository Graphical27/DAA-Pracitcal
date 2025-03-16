#include<bits/stdc++.h>
using namespace std;

namespace week1{
    void q1(vector<int> arr, int key){
        int count = 0;
        for(int i=0;i<arr.size();i++){
            count++;
            if(arr[i]==key){
                cout<<"Found at index "<<i<<endl;
                cout<<"Number of comparisons: "<<count<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
        cout<<"Number of comparisons: "<<count<<endl;
    }
    void q2(vector<int> v, int key){
        int cnt = 0;
        int low = 0, high = v.size()-1;
        while(low<=high){
            cnt++;
            int mid = low + (high-low)/2;
            if(v[mid] == key){
                cout << "Found at index " << mid << endl;
                cout << "Number of comparisons: " << cnt << endl;
                return;
            }
            v[mid] < key ? low = mid+1 : high = mid-1;
        }
        cout << "Not found" << endl;
        cout << "Number of comparisons: " << cnt << endl;
    }
    
    void q3(vector<int> arr, int key) {
        int cnt = 0;
        int n = arr.size();
        int step = sqrt(n);
        int prev = 0;
        while(arr[min(step, n)-1] < key) {
            cnt++;
            prev = step;
            step += sqrt(n);
            if(prev >= n) {
                cout << "Not Present" << endl;
                cout << "Number of comparisons: " << cnt << endl;
                return;
            }
        }
        while(arr[prev] < key) {
            cnt++;
            prev++;
            if(prev == min(step, n)) {
                cout << "Not Present" << endl;
                cout << "Number of comparisons: " << cnt << endl;
                return;
            }
        }
        
        if(arr[prev] == key) {
            cnt++;
            cout << "Present" << endl;
            cout << "Number of comparisons: " << cnt << endl;
            return;
        }
        
        cout << "Not Present" << endl;
        cout << "Number of comparisons: " << cnt << endl;
    }
}


namespace week2{
    void q1(vector<int> arr, int key) {
        int cnt = 0;
        int copies = 0;
        for(int i = 0; i < arr.size(); i++){
            cnt++;
            if(arr[i] == key) copies++;
            else if(arr[i] > key) break;
        } if(copies > 0) {
            cout << "Key " << key << " is present" << endl;
            cout << "Number of copies: " << copies << endl;
        } else {
            cout << "Key not present" << endl;
        } cout << "Number of comparisons: " << cnt << endl;
    }
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 3;
    // week1::q1(arr, key);
    // week1::q2(arr, key);
    // week1::q3(arr, key);
    week2::q1(arr, key);
    return 0;
}

