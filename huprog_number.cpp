//
//  main.cpp
//  HUPROG
//
//  Created by Berkay Gunen on 19.03.2022.
//
#define SIZE 1000000000
#include <iostream>
#include <string>
using namespace std;

int counter(int x){
    int count = 0;
    for(int i = 0;i<to_string(x).length();i++){
        if(to_string(x)[i] == '2' || to_string(x)[i] == '6'){
            count++;
        }
    }
    return count;
}

int main() {
    // insert code here...
    /*int A,T,smallest,*v1,*v2;
    bool comp = false;
    cin >> A >> T;
    v1 = new int[T];
    v2 = new int[T];
    for(int n = A;n<A+T;n++){
        v1[n - A] = counter(n);
    }
    smallest = A+1;
    while(true){
        if(counter(smallest) == counter(A)){
            for(int n = smallest;n<smallest+T;n++){
                v2[n-smallest] = counter(n);
            }
            for(int i=0;i<T;i++){
                if(v1[i] != v2[i])  break;
                else if(i == T-1 && v1[i] == v2[i]) comp = true;
            }
            if(comp){
                break;
            }
        }
        smallest++;
    }
    delete [] v1;
    delete [] v2;
    cout << smallest << endl;
    */
    int A,T,smallest=2,array[SIZE];
    bool comp = false;
    cin >> A >> T;
    smallest = A+1;
    for(int i=1;i<SIZE;i++){
        array[i] = counter(i);
    }
    for(;smallest<SIZE && !comp;smallest++){
        if(array[smallest] == array[A]){
            for(int j=0;j<T;j++){
                if (array[A+j] != array[smallest+j]){
                    break;
                }
                else if(j == T-1){
                    comp = true;
                    break;
                }
            }
        }
        if(comp)    break;
    }
    cout << smallest << endl;
    return 0;
    
}

    //for(int i=0;i<v1.size();i++){
    //    cout << v1.at(i) << endl;
    //}
