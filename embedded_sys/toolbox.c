#include "toolbox.h"


/** Render html template
 *
 *  char file[] -> filename html
 *  char socket[] -> socket for send information
 *  return -> -1 if html file not found
 */
int render(char file[], int socket){

    // Website templates files
    char *ptrContent = NULL;
    long filesize = 0;
    FILE* ptrfile = NULL;

    // Open file
    ptrfile = fopen(file, "r");
    if (ptrfile == NULL){
        printf("[ERROR] File not found\n\r");
        return (-1);
    }
    printf("[+] html found\n\r");

    //  File size
    fseek(ptrfile, 0L, SEEK_END); // go end file
    filesize = ftell(ptrfile);
    fseek(ptrfile, 0L, SEEK_SET); // go start file
    printf("[+] html size [%ld] bytes\n\r", filesize); // print file size

    ptrContent = (char*) malloc(filesize);    // reserving memory
    fread(ptrContent, 1, filesize, ptrfile);  // reading file content
    send(socket, ptrContent, filesize, 0);  // sending website file
    for(int i=0; i<100000000; i++); // delay for testing
    close(socket); // close client socket
    free(ptrContent);   // freeing memory
    fclose(ptrfile);    // close file
}



/** Search a varaible  target in chain string
 *
 *  char chain[] -> string
 *  char target[] -> Target variable
 *  Return -> value of variable
 */
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


