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
    void q2(vector<int> arr) {
        int cnt = 0;
        bool found = false;
        for(int k = arr.size()-1; k >= 2; k--){
            int i = 0;
            int j = k-1;
            while(i < j){
                cnt++;
                if(arr[i] + arr[j] == arr[k]) {
                    cout << i+1 << ", " << j+1 << ", " << k+1 << endl;
                    found = true;
                    break;
                }
                else if(arr[i] + arr[j] < arr[k]) i++;
                else j--;
            }if(found) break;
        }
        if(!found) cout << "No sequence found" << endl;
        cout << "Number of comparisons: " << cnt << endl;
    }
    void q3(vector<int> arr, int key) {
        int cnt = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            for(int j = i+1; j < arr.size(); j++){
                if(abs(arr[i] - arr[j]) == key){
                    cnt++;
                }
            }
        }cout << "Number of pairs with difference " << key << ": " << cnt << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 3;
    // week1::q1(arr, key);
    // week1::q2(arr, key);
    // week1::q3(arr, key);
    week2::q1(arr, key);
    week2::q2(arr);
    week2::q3(arr, key);
    return 0;
}

