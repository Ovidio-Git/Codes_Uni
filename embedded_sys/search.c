#include <stdio.h>
#include <string.h>

void search(char chain[], char target[]){

    int  n = 0;
    char m = 0;
    char i = 0;
    char len = strlen(target);
    char find[10];


    while (1){
        if (chain[n]==target[m]){
            while(chain[n] == target[m]){
                n++;
                m++;
                if (m==len){
                    while(chain[n] != ' ' && chain[n] != '\n'){
                        find[i]=chain[n];
                        i++;
                        n++;
                    }
                    break;
                }
            }
            if(m==len){
                break;
            }
        }
        n++;
    }
    printf("==>");
    for (int i =0; i <= 8; i++){
        printf("%c", find[i]);
    }
    printf("<==");
}


int main(){
    char b[]="Accept-Language: en-US,en;q=0.9  Username=er32 Password=89re ccep� ";
    char t[]="Username=";
    search(b, t);
}