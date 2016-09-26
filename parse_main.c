#include"myparse.h"

int main(){
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

	ret = getParam(stParse, "CONTROL_ID", &data);
	if(ret > 0) printf("data = %s\ndata lenth = %d\n", data, ret);

	ret = getParamListElement(stParse, "CONTROL_ID", 1, &data);
	if(ret > 0) printf("data = %s\ndata lenth = %d\n", data, ret);
	
    return 0;
}
