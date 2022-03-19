//
//  main.cpp
//  Bowling
//
//  Created by Berkay Gunen on 19.03.2022.
//

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int count = 0;
void bringDown(bool** &table,int x,int y,int direction,int n){
    if(x<0 || y<0 || x == n || y == n){
        return;
    }
    /*cout << "Called with: " << endl << " x: " << x << " y: " << y << " direction: " << direction << " n: " << n << endl;*/
    if(!table[x][y])    count++;
    table[x][y] = true;
    if(direction == 0 /* && y > 0*/){
        bringDown(table, x+1, y-1, direction,n);
        bringDown(table, x, y-1, direction,n);
        bringDown(table, x-1, y-1, direction,n);
    }
    else if(direction == 1 /* && x > 0*/){
        bringDown(table, x-1, y-1, direction,n);
        bringDown(table, x-1, y, direction,n);
        bringDown(table, x-1, y+1, direction,n);
    }
    else if(direction == 2 /*&& y < n-1*/){
        bringDown(table, x+1, y+1, direction,n);
        bringDown(table, x, y+1, direction,n);
        bringDown(table, x-1, y+1, direction,n);
    }
    else if(direction == 3 /*&& x < n-1*/){
        bringDown(table, x+1, y-1, direction,n);
        bringDown(table, x+1, y, direction,n);
        bringDown(table, x+1, y+1, direction,n);
    }
}

int main() {
    int n,x,y,direction;
    cin >> n;
    cin >> x >> y;
    cin >> direction;
    bool** table = new bool*[n];
    for(int i = 0;i<n;i++){
        table[i] = new bool[n]{false};
    }
    /*for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cout << table[i][k];
            if(k != n-1)    cout << " ";
            else cout << "\n";
        }
    }*/

    bringDown(table, x, y, direction,n);
    cout << count;
    return 0;
}

