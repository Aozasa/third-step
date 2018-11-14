#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp( const void *p, const void *q ) {
    if( *(double*)p < *(double*)q ) return 1;
    if( *(double*)p > *(double*)q ) return -1;
    return 0;
}

int main()
{
	double sci[20] = {65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70};
	double eng[20] = {44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84};
	double sci_d[20];
	double eng_d[20];
	double ave1,ave2;
	double sum1 = 0.0;
	double sum2 = 0.0;
	double sd1 = 0.0;
	double sd2 = 0.0;
	int i;
	
	for (i=0; i<20; i++){
		sum1 += sci[i];
		sum2 += eng[i];
	}
	ave1 = sum1 / 20.0;
	ave2 = sum2 / 20.0;

	for (i=0; i<20; i++){
		sd1 += pow((sci[i] - ave1),2) / 20.0;
		sd2 += pow((eng[i] - ave2),2) / 20.0;
		sci_d[i] = 50.0 + (sci[i] - ave1) / 2.0;
		eng_d[i] = 50.0 + (eng[i] - ave2) / 2.0;
	}
	
	sd1 = sqrt(sd1);
	sd2 = sqrt(sd2);

	for (i=0; i<20; i++){
		sci_d[i] = 50.0 + ((sci[i] - ave1) / sd1) * 10;
		eng_d[i] = 50.0 + ((eng[i] - ave2) / sd2) * 10;
	}
	
	qsort(sci,20,sizeof(sci[0]),cmp);
	qsort(eng,20,sizeof(eng[0]),cmp);	
	
	printf("理科の合計点：%.1f　英語の合計点：%.1f\n",sum1 ,sum2);
	printf("理科の平均点：%.1f　英語の平均点：%.1f\n",ave1 ,ave2);
	printf("理科の標準偏差：%.1f　英語の標準偏差：%.1f\n",sd1 ,sd2);
	printf("理科の偏差値\n");
	for (i=0; i<20; i++){
		printf("%.1f\n",sci_d[i]);
	}
	printf("\n");
	printf("英語の偏差値\n");
	for (i=0; i<20; i++){
		printf("%.1f\n",eng_d[i]);
	}
	printf("\n");
	
	printf("理科の成績(昇順)\n");
	for (i=0; i<20; i++){
		printf("%.1f\n",sci[i]);
	}
	printf("\n");
	printf("英語の成績(昇順)\n");
	for (i=0; i<20; i++){
		printf("%.1f\n",eng[i]);
	}
	printf("\n");
	

}
	 
	
	
	