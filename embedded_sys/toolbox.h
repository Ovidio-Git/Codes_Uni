// compiler one time
#ifndef _TOOLBOX_H_
#define _TOOLBOX_H_

// call standart librarys
#include <string.h>

/** Search a varaible  target in chain string
 *
 *  char chain[] -> string
 *  char target[] -> Target variable
 *  Return -> value of variable
 */
void search(char chain[], char target[]);


/** Render html template
 * 
 *  char file[] -> filename html
 *  char socket[] -> socket for send information
 *  return -> -1 if html file not found
 */
int render(char file[], int socket);

#include "toolbox.c"
#endif