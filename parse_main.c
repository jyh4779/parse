#include"myparse.h"

#define KEYNAMESIZE 20

int main(){
    int ret, idx;
	char *data;
	char keyname[KEYNAMESIZE];
    char szBODY[]="MOBILE_NUM=123456789012&MODIFY_FLAG=1&CONTROL_COUNT=2&CONTROL_NM=관제탑이름1,관제탑이름2&CONTROL_ID=900999000,900999001&CONTROL_TEL_NUM=0102223333,01033334444";
    st_PARSE stParse[SIZE];
    
    int size = strlen(szBODY);
	printf("input data = \n");
	printf("%s\n", szBODY);
	printf("\n");

    ret = parse(szBODY, size, stParse);
    if(ret != 0) {
		printf("parse error\n");
		return -1;
    }

	printf("########################getParam() test##########################\n");
	printf("input key you want to see = ");
	fgets(keyname, KEYNAMESIZE, stdin);
	keyname[strlen(keyname)-1] = '\0';

	ret = getParam(stParse, keyname, &data);
	if(ret > 0) printf("data = %s\ndata lenth = %d\n", data, ret);
	printf("\n");

	printf("###################getParamListElemant() test####################\n");
	printf("input key you want to see = ");
	fgets(keyname, KEYNAMESIZE, stdin);
	keyname[strlen(keyname)-1] = '\0';
	printf("input %s[idx] you want to see\n", keyname);
	scanf("%d", &idx);
	__fpurge(stdin);

	ret = getParamListElement(stParse, keyname, idx, &data);
	if(ret > 0) printf("data = %s\ndata lenth = %d\n", data, ret);

	printf("#######################getParamList() test#######################\n");
	printf("input key you want to see = ");
	fgets(keyname, KEYNAMESIZE, stdin);
	keyname[strlen(keyname)-1] = '\0';
	printf("what last index of %s?\n", keyname);
	scanf("%d", &idx);

	while(ret=getParamList(stParse, keyname, idx, &data)>=0){
		printf("%s ", data);
		idx--;
	}
	printf("\n");

	
    return 0;
}
