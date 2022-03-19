//
//  main.cpp
//  Shinganshina
//
//  Created by Berkay Gunen on 19.03.2022.
//

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a,int size){
    for(int i = 1;i<size;i++){
        int temp = a[i];
        for(int k=i;k>0 && temp < a[k-1];k--){
            a[k] = a[k-1];
            a[k-1] = temp;
        }
    }
    
    cout << "Function:" << endl;
    for(int i = 0;i<size;i++){
        cout << a.at(i) << endl;
    }
    cout << "Function ends:" << endl;
}

int main() {
    // insert code here...
    int t,e,adder,counter = 0;
    vector<int> other,eren;
    cin >> t >> e;
    for(int i = 0;i<t;i++){
        cin >> adder;
        other.push_back(adder);
    }
    for(int i = 0;i<e;i++){
        cin >> adder;
        eren.push_back(adder);
    }
    for(int i = 0;i<e;i++){
        cout << eren.at(i) << endl;
    }
    insertionSort(eren,int(eren.size()));
    for(int i = 0;i<e;i++){
        cout << eren.at(i) << endl;
    }
    for(int i=0;i<e;i++){
        counter = 0;
        for(int k=0;k<t;k++){
            if(eren.at(i) > other.at(k)) counter++;
        }
        cout << counter;
        if(i != e-1)    cout << " ";
    }
    return 0;
}

/*
 6 6
 94 63 9 98 69 99
 17 17 85 61 71 22
*/
