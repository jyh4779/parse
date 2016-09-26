#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 128

typedef struct{
    char *key;
    char *body[8];
} st_PARSE;

int parse(char *szBODY, int len, st_PARSE *p);
char *strtok_s(char *text, char *point);
int getParam(st_PARSE *p, char *key, char **data);
