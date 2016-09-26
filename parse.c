#include"myparse.h"

int parse(char *text, int len, st_PARSE *p) 
{
    char *token, *token1;
	int i,j;
	j=0;

	while(1) 
	{
		i = 0;

		token = strtok(text, "&");
		text = strtok(NULL, "");
		p[j].key=token;

		p[j].key = strtok(p[j].key, "=");
		token1 = strtok(NULL, "");
		while(1)
		{
			p[j].body[i] = strtok(token1,",");
			token1 = strtok(NULL, "");
			if(token1 == NULL) break;
			i++;
		}
		if(token == NULL) break;
		j++;
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

	return strlen(*data);
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
			printf("input key name is %s\n", key);
			printf("but found failed\n");
			return -2;
		}
	}

	return strlen(*data);
}

int getParamList(st_PARSE *p, char *key, int listcnt, char **data)
{
	int i;
	i=0;
	
	if(listcnt < 0) return -1;

	while(1)
	{
		if(p[i].key){
			if(!strcmp(p[i].key, key))
			{
				if(p[i].body[listcnt]) *data = p[i].body[listcnt];
				else{
					printf("not exist data\n");
					return -2;
				}
				break;
			}
			i++;
		} else{
			printf("input key name is %s\n", key);
			printf("but found failed\n");
			return -3;
		}
	}
	return strlen(*data);
}
