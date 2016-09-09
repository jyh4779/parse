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
int getParamListElement(st_PARSE *p, char *key, int idx, char **data);

static int cnt;

int main(){
    cnt = 0;
    int ret,j,k;
	char *data;
    char szBODY[]="MOBILE_NUM=123456789012&MODIFY_FLAG=1&CONTROL_COUNT=2&CONTROL_NM=관제탑이름1,관제탑이름2&CONTROL_ID=900999000,900999001&CONTROL_TEL_NUM=0102223333,01033334444";
    st_PARSE stParse[SIZE];
    
    int size = strlen(szBODY);

    ret = parse(szBODY, size, stParse);
    if(ret != 0) {
		printf("parse error\n");
		return -1;
    }
	for(j=0;j<cnt;j++)
	{
		k=0;
		while(stParse[j].body[k])
		{
			printf("%s  %s\n", stParse[j].key, stParse[j].body[k]);
			k++;
		}
	}
	printf("get data count = %d\n", cnt);

	ret = getParam(stParse, "CONTROL_ID", &data);
	if(ret > 0) printf("data = %s\ndata lenth = %d\n", data, ret);

	ret = getParamListElement(stParse, "CONTROL_ID", 1, &data);
	if(ret > 0) printf("data = %s\ndata lenth = %d\n", data, ret);
	
    return 0;
}

int parse(char *text, int len, st_PARSE *p) 
{
    char *token, *token1;
	int i;

	while(1) 
	{
		i = 0;

		token = strtok(text, "&");
		text = strtok(NULL, "");
		p[cnt].key=token;

		p[cnt].key = strtok(p[cnt].key, "=");
		token1 = strtok(NULL, "");
		while(1)
		{
			p[cnt].body[i] = strtok(token1,",");
			if(token1 == NULL) break;
			token1 = strtok(NULL, "");
			i++;
		}

		if(token == NULL) break;
		cnt++;
	}
    return 0;
}

int getParam(st_PARSE *p, char *key, char **data)
{
	int i;
	i=0;

	while(1)
	{
		if(p[i].key){
			if(!strcmp(p[i].key, key))
			{
				*data = p[i].body[0];
				break;
			}
			i++;
		} else {
			printf("key name is %s\n", key);
			printf("but found failed\n");
			return -1;
		}
	}

	return strlen(*data);;
}

int getParamListElement(st_PARSE *p, char *key, int idx, char **data)
{
	int i;
	i=0;

	while(1)
	{
		if(p[i].key){
			if(!strcmp(p[i].key, key))
			{
				if(p[i].body[idx]) *data = p[i].body[idx];
				else 
				{
					printf("not exist data\n");
					return -1;
				}
				break;
			}
			i++;
		} else {
			printf("key name is %s\n", key);
			printf("but found failed\n");
			return -2;
		}
	}

	return strlen(*data);;
}
/*
int getParamList(st_PARSE *p, char *key, int listcnt, char *data)
{
	listcnt--;
	if(listcnt > 0)	getParamList(p, key, listcnt, data);
	
*/
