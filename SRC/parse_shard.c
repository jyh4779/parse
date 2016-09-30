#include"myparse.h"

st_PARSE *p;

int getShared()
{
	int shmid;

	shmid = shmget((key_t)SHKEY, sizeof(st_PARSE)*10, IPC_CREAT|0666);
	if(shmid == -1) 
	{
		printf("shared memory getting failed\n");
		return -1;
	}

	p = (st_PARSE*)shmat(shmid, NULL, 0);
	if(p == (st_PARSE*)-1) printf("shared memory attach failed\n");

//	p[0].key = "aa";
	printf("%c\n", p[0].key);


	return shmid;
}

int main()
{
	int a;

	while(1){
		printf("1 : attach\n2 : detach\n3 : bye\n");
		scanf("%d", &a);

		if(a == 1) getShared();
		else if(a == 2) shmdt(p);
		else if(a == 3) 
		{
			printf("bye\n");
			break;
		}
	}

	return 0;
}

