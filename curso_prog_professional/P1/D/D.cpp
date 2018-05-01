#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

#define MAXN 105
#define entro() cout << "entro" << endl

void inline swap(int v[], int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

int partition(int v[], int l, int r) {
    int pivot = v[r];
    
    int i = l-1;
    for(int j = l; j <= r-1; j++) {
        if(v[j] < pivot) {
            i++;
            swap(v, i, j);
        }
    }
    
    swap(v,i+1,r);
    return i+1;
}

void quicksort(int v[], int l, int r) {
    if(r <= l) return;
    
    int m = partition(v,l,r);
    quicksort(v,l,m-1);
    quicksort(v,m+1,r);
}

// debug function
void print_v(int v[], int n) {
    for(int i = 0 ; i < n ; i++) {
        cout << v[i] << " ";
    }
    
    cout << endl;
}

int ciel[MAXN];
int jiro_def[MAXN];
int jds; // jiro defense size
int jiro_atk[MAXN];
int jas; // jiro attack size

int main(void) {
    int n,m;
    char type[4];
    int val;
    
    // get max between two approaches
    // the first is attacking only jiro's cards on attack mode and making the max damage
    // possible.
    
    // the second is destroying all jiro's cards and possibly attacking jiro's
    // life directly.
    int all_dead = 0, not_all_dead = 0;
    
    jds = jas = 0;
    
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++) {
        cin >> type;
        cin >> val;
        
        if(type[0] == 'A') jiro_atk[jas++] = val;
        else jiro_def[jds++] = val; 
    }
    
    for(int i = 0 ; i < m ; i++) {
        cin >> ciel[i]; 
    }
    
    quicksort(ciel,0,m-1);
    quicksort(jiro_atk,0,jas-1);
    quicksort(jiro_def,0,jds-1);
    
    // first approach: kill only jiro's cards on attack mode
    for(int c = m-1, j = 0; c >= 0 && j < jas; c--, j++) {
        if(ciel[c] <= jiro_atk[j]) {
            break;
        }
        
        not_all_dead += ciel[c] - jiro_atk[j];
    }

    // second approach: killing all jiro's cards
    int remaining_def = jds;
    // try to destroy all cards on defense using the cards with the least damage
    // possible to destroy them
    for(int j = 0, c = 0; j < jds; j++) {
        while(c < m && ciel[c] <= jiro_def[j]) c++;
        if(c == m) break;
        
        // used this card
        ciel[c++] = -1;
        remaining_def--;
    }
    
    // destroyed all cards on defense
    if(remaining_def == 0) {
        int remaining_atk = jas;
        // try to detroy all cards on attack mode
        for(int c = 0, j = 0; j < jas && c < m; c++) {
            if(ciel[c] == -1) {
                continue;
            }
            
            while(c < m && ciel[c] < jiro_atk[j]) c++;
            if(c == m) break;
            
            
            all_dead += ciel[c] - jiro_atk[j];
            ciel[c] = -1;
            remaining_atk--;
            j++;
        }
        
        // try to attack jiro's life directly
        if(remaining_atk == 0) {
           for(int c = 0; c < m; c++) {
               if(ciel[c] == -1) continue;
               all_dead += ciel[c];
           }
        }
    }
    
    if(all_dead > not_all_dead) cout << all_dead << endl;
    else cout << not_all_dead << endl;
    
    return 0;
}
