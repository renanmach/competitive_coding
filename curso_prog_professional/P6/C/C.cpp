#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int MAXM = 100000 + 5;
const int MAXT = 10000 + 5;

int m, t;

int text[MAXM], pattern[MAXT], b[MAXT];

void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    
    while(i < t) {
        while(j >= 0 && pattern[j] != pattern[i]) j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

bool kmpSearch() {
    int i = 0, j = 0;
    
    while(i < m) {
        while(j >= 0 && text[i] != pattern[j]) j = b[j];
        j++;
        i++;
        if(j == t) return true;
    }
    
    return false;
}

int note_to_num(char note) {
    switch(note) {
        case 'A': return 0;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 5;
        case 'E': return 7;
        case 'F': return 8;
    }
    
    return 10;
}

int main(void) {
    char note,note2;
    
    scanf("%d %d\n", &m, &t);
    
    while(m != 0 && t != 0) {
        for(int i = 0 ; i < m; i++) {
            scanf("%c%c", &note,&note2); 
            
            text[i] = note_to_num(note);
            
            if(note2 == '#') {
                text[i] += 1;
                getchar();
                
            }
            else if(note2 == 'b') {
                text[i] -= 1;
                if(text[i] < 0) text[i] = 11; // Ab => G#
                
                 getchar();
            }
        }
        
        for(int i = 0 ; i < t; i++) {
            scanf("%c%c", &note,&note2); 
            pattern[i] = note_to_num(note);
            
            if(note2 == '#') {
                pattern[i] += 1;
                getchar();
                
            }
            else if(note2 == 'b') {
                pattern[i] -= 1;
                if(pattern[i] < 0) pattern[i] = 11; // Ab => G#
                
                getchar();
            }
        }
        
        kmpPreprocess();
        if(kmpSearch()) printf("S\n");
        
        else {
            bool found = false;
            
            for(int k = 1 ; k <= 11; k++) {
                for(int i = 0; i < t; i++) 
                  pattern[i] = (pattern[i]+1) % 12;

                 //kmpPreprocess();
                 if(kmpSearch()) {
                     found = true;
                     break;
                 }
            }
            
            if(found) printf("S\n");
            else printf("N\n");
        }
        
        scanf("%d %d\n", &m, &t);
    }
    
    return 0;
}
