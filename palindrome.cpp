//
//  main.cpp
//  Palindrome
//
//  Created by Berkay Gunen on 19.03.2022.
//

#include <iostream>
#include <string>
using namespace std;

void calculate() {
    int n,k,min_change = 0;
    string chars;
    cin >> n >> k;
    cin >> chars;
    int hash_table[7]{0};
    char** arrs = new char*[n/k];
    for (int j = 0; j<n/k; j++) {
        arrs[j] = new char[k];
    }
    for (int l = 0; l<n/k; l++) {
        for (int m = 0; m<k; m++) {
            arrs[l][m] = chars[l*k+m];
        }
    }
    /*for (int l = 0; l<n/k; l++) {
        for (int m = 0; m<k; m++) {
            cout << arrs[l][m];
            if(m == k-1)    cout << "\n";
            else cout << " ";
        }
    }*/
    int max;
    for(int j=0;j<k/2;j++){
        max = 0;
        for(int t = 0;t<7;t++){
            hash_table[t] = 0;
        }
        for(int i = 0;i<n/k;i++){
            hash_table[arrs[i][j] - 'A']++;
            hash_table[arrs[i][k-j-1] - 'A']++;
        }
        /*cout << "Hash table content:" << endl;
        for(int t = 0;t<7;t++){
            cout << hash_table[t];
        }
        cout << endl;*/
        for(int t = 0;t<7;t++){
            if(hash_table[t] > max){
                max = hash_table[t];            }
        }
        min_change += 2*n/k - max;
    }
    if(k % 2 != 0){
        max = 0;
        for(int t = 0;t<7;t++){
            hash_table[t] = 0;
        }
        for(int i = 0;i<n/k;i++){
            hash_table[arrs[i][k/2] - 'A']++;
        }
        /*cout << "Hash table content:" << endl;
        for(int t = 0;t<7;t++){
            cout << hash_table[t];
        }
        cout << endl;*/
        for(int t = 0;t<7;t++){
            if(hash_table[t] > max){
                max = hash_table[t];            }
            }
        min_change += n/k - max;
    }
    /*cout << "Hash table content:" << endl;
    for(int t = 0;t<7;t++){
        cout << hash_table[t];
    }*/
    //cout << arrs[0] << ' ' << arrs[1] << ' ' << arrs[2] << ' ' << arrs[3];
    /*int similarity, max_similarity;
    for (int o = 0; o < k; o++) {
        max_similarity = 1;
        for (int p = 0; p < n/k; p++) {
            similarity = 1;
            for (int r = p+1; r < n/k; r++) {
                if (arrs[p][o] == arrs[r][o]) {
                    similarity++;
                }
            }
            max_similarity=similarity>max_similarity?similarity:max_similarity;
        }
        min_change += n/k - max_similarity;
    }*/
    cout << min_change <<endl;
}

int main() {
// write your code here
    int cases;
    cin >> cases;
    for (int i = 0; i<cases; i++) {
        calculate();
    }

    return 0;
}
