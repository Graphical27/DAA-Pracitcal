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


//? Main function for week 1 - 2

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int key = 3;
//     // week1::q1(arr, key);
//     // week1::q2(arr, key);
//     // week1::q3(arr, key);
//     week2::q1(arr, key);
//     week2::q2(arr);
//     week2::q3(arr, key);
//     return 0;
// }

#define ln "\n"
#define ll long long

namespace week3{
    void q1(vector<int> v){
        int cnt = 0;
        if(v.size() == 0){
            cout << "Empty array" << ln;
            return;
        }
        for(int i = 1; i < v.size(); i++){
            int key = v[i]; 
            int j = i-1;
            while(j>=0 && v[j] > key){
                cnt++;
                v[j+1] = v[j]; 
                j--;
            }
            if(j>=0) cnt++; 
            v[j+1] = key;
        }
        cout << "Number of comparisons: " << cnt << ln;
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }cout << ln;
    }
    void q2(vector<int> v){
        int cnt = 0;
        if(v.size() == 0){
            cout << "Empty array" << ln;
            return;
        }
        
        for(int i = 0; i < v.size()-1; i++){
            int min_idx = i;
            for(int j = i+1; j < v.size(); j++){
                cnt++;
                if(v[j] < v[min_idx]){
                    min_idx = j;
                }
            }
            if(min_idx != i){
                swap(v[min_idx], v[i]);
            }
        }
        cout << "Number of comparisons: " << cnt << ln;
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }cout << ln;
    }
    void q3(vector<int> v) {
        if(v.size() == 0) {
            cout << "Empty array" << ln;
            return;
        }
        sort(v.begin(), v.end());
        bool hasDuplicate = false;
        for(int i = 1; i < v.size(); i++) {
            if(v[i] == v[i-1]) {
                hasDuplicate = true;
                break;
            }
        }
        cout << (hasDuplicate ? "YES" : "NO") << ln;
    }
}

//? main function for week 3

// int main(){
//     vector<int> v = {3,3,2,6,91,5,10,12};
//     week3::q1(v);
//     week3::q2(v);
//     week3::q3(v);
//     return 0;
// }


namespace week4{
    void merge(vector<int>& arr,int left,int mid, int right, int& comp, int& inv){
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1),R(n2);
        for(int i = 0; i < n1; i++) L[i] = arr[left + i];
        for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2){
            comp++;
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
                k++;
            }else{
                arr[k++] = R[j++];
                inv+= (n1 - i);
            }
        }
        while(i < n1){
            arr[k++] = L[i++];
        }
        while(j < n2){
            arr[k++] = R[j++];
        }
    }

    void mergesort(vector<int>& arr,int left, int right, int& comp, int& inv){
        if(left < right){
            int mid = left + (right - left) / 2;
            mergesort(arr,left,mid,comp,inv);
            mergesort(arr,mid+1,right,comp,inv);
            merge(arr,left,mid,right,comp,inv);
        }
    }

    void q1(vector<int> arr){
        int comp = 0, inv = 0;
        if(arr.size() == 0){
            cout << "Empty Array" << ln;
            return;
        }
        mergesort(arr,0,arr.size()-1,comp,inv);
        cout << "Sorted Array: ";
        for(auto i:arr) cout << i << " ";
        cout << ln;
        cout << "Comp" << comp << " Inversion: " << inv << ln;
    }
    int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
        int random = low + rand() % (high - low + 1);
        swap(arr[random], arr[high]);
        swaps++;
        
        int pivot = arr[high];
        int i = low - 1;
        
        for(int j = low; j < high; j++) {
            comparisons++;
            if(arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
        swap(arr[i + 1], arr[high]);
        swaps++;
        return i + 1;
    }
    
    void quickSort(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
        if(low < high) {
            int pi = partition(arr, low, high, comparisons, swaps);
            
            quickSort(arr, low, pi - 1, comparisons, swaps);
            quickSort(arr, pi + 1, high, comparisons, swaps);
        }
    }
    
    void q2(vector<int> v) {
        if(v.size() == 0) {
            cout << "Empty array" << ln;
            return;
        }
        
        int comparisons = 0, swaps = 0;
        
        quickSort(v, 0, v.size()-1, comparisons, swaps);
        
        cout << "Sorted array: ";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << ln;
        cout << "Number of comparisons: " << comparisons << ln;
        cout << "Number of swaps: " << swaps << ln;
    }
    void q3(vector<int> v,int k){
        if(k < 0 || k > v.size()){
            cout << "Invalid k value" << ln;
            return;
        }
        priority_queue<int, vector<int> , greater<int>> minHeap;
        priority_queue<int> maxHeap;

        for(auto i:v){
            minHeap.push(i);
            maxHeap.push(i);
        }
        int kthsmallest;
        for(int i = 0; i< k; i++){
            kthsmallest = minHeap.top();
            minHeap.pop();
        }
        int kthlargest;
        for(int i = 0; i< k; i++){
            kthlargest = maxHeap.top();
            maxHeap.pop();
        }
        cout << "smallest: " << kthsmallest << " Largest: " << kthlargest << ln;
    }
}


//? main function for week4
// int main(){
//     vector<int> v = {3,3,2,6,91,5,10,12};
//     week4::q1(v);
//     week4::q2(v);
//     week4::q3(v,3);
// }

namespace week5{
    void q1(vector<char> v) {
        unordered_map<char, int> freq;
        for(char c : v) {
            freq[c]++;
        }
        char maxChar = v[0];
        int maxCount = 0;
        for(auto pair : freq) {
            if(pair.second > maxCount) {
                maxCount = pair.second;
                maxChar = pair.first;
            }
        }
        cout << "Character with maximum occurrences: " << maxChar << endl;
        cout << "Number of occurrences: " << maxCount << endl;
    }
    void q2(vector<int> v, int key) {
        sort(v.begin(), v.end());
        int left = 0;
        int right = v.size() - 1;
        bool found = false;
        
        while(left < right) {
            int sum = v[left] + v[right];
            if(sum == key) {
                found = true;
                cout << "Found two elements " << v[left] << " and " << v[right] 
                     << " whose sum equals " << key << ln;
                break;
            }
            else if(sum < key) {
                left++;
            }
            else {
                right--;
            }
        }
        
        if(!found) {
            cout << "No two elements found whose sum equals " << key << ln;
        }
    }
    void q3(vector<int> arr1, vector<int> arr2) {
        int i = 0, j = 0;
        cout << "Common elements: ";
        
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        cout << ln;
    }
}


int main(){
    vector<char> v = {'a', 'b', 'c', 'a', 'b', 'a', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    week5::q1(v);
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};
    week5::q2(v1,5);
    week5::q3(v1,v2);
}