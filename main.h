#include <iostream>
#include <fstream>
#include <cassert>

#include <stdlib.h>
#include <assert.h>
#include <string.h>

using namespace std;

#ifndef MAIN_H
#define MAIN_H

int MAXIMUM_SIZE = 1000;
int MAXIMUM_LENGTH = 40;

char** create_array(void);
int read_input(char**, istream&);
bool is_unique(char**, char*, int);
void sort(char**, int);
void write_output(char**, ostream&, int);
void removeArray(char**, int);

#endif // MAIN_H
