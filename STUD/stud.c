/*
 * stud.c
 *
 *  Created on: 30-May-2022
 *      Author: arin_dhimar
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define si 2
struct password
{
	char pas[50];
}p;


struct stud
{
	int rno;
	char name[20];
	double marks[si],total;
};


int chk(int n)
{

	FILE *fp;
	struct stud s;
	fp=fopen("student.txt","r");
	while(fread(&s,sizeof(s),1,fp))
	{
		if(n==s.rno)
			return 1;
	}
	return 0;
}


void menu(void)
{
	printf("\n\t|---------------------------|\n");
	printf("\n\t\t1-ADD  STUDENT\n");
	printf("\n\t\t2-MODIFY  STUDENT\n");
	printf("\n\t\t3-SHOW ALL  STUDENT\n");
	printf("\n\t\t4-REMOVE  STUDENT\n");
	printf("\n\t\t5-RANK  STUDENT\n");
	printf("\n\t\t6-CHANGE PASSWORD\n");
	printf("\n\t\t7-EXIT\n");
	printf("\n\t|--------------------------|\n");
}


void smenu(void)
{
	printf("\n\t\t|-----------------|\n");
	printf("\n\t\t1-UPDATE NAME\n");
	printf("\n\t\t2-UPDATE MARKS\n");
	printf("\n\t\t|-----------------|\n");
}


void add(FILE *fp)
{
	struct stud s;
	int i,ck;
	do
	{
		printf("\n\t\tENTER STUDENT ROLL NO				");
		scanf("%d",&s.rno);
		ck=chk(s.rno);
		if(ck==1)
		{
			printf("\n\tRNO ALREADY EXIST\n");
		}
	}while(ck==1);

	printf("\n\t\tENTER STUDENT ROLL NAME				");
	scanf("%s",s.name);
	s.total=0;
	for(i=0;i<si;i++)
	{
		printf("\n\t\tENTER STUDENT MARKS FOR SUB %d				",i+1);
		scanf("%lf",&s.marks[i]);
		s.total=s.marks[i]+s.total;
	}
	fwrite(&s,sizeof(s),1,fp);
}


void disp(FILE *fp)
{
	int i;
	struct stud s;
	while(fread(&s,sizeof(s),1,fp))
	{
		printf("-----------------------------------------\n");
		printf("|\tSID=	%d			|\n",s.rno);
		printf("|\tSTUDENT NAME=%s		|\n",s.name);
		for(i=0;i<si;i++)
		{
			printf("|\tMARKS %d=%lf		|\n",i+1,s.marks[i]);
		}
		printf("|\tTOTAL=%lf		|\n",s.total);
		printf("-----------------------------------------\n");
	}
}


void change(FILE *fp)
{
	char pa[50],npa1[50],npa2[50];
	printf("\n\tENTER OLD PASSWORD			");
	scanf("%s",pa);
	//printf("%s",p.pas);
	if(strcmp(pa,p.pas)==0)
		{
			printf("\n\tENTER NEW PASSWORD		");
			scanf("%s",npa1);
			printf("\n\tCONFIRM NEW PASSWORD		");
			scanf("%s",npa2);
			if(strcmp(npa1,npa2)==0)
			{
				fputs(npa2,fp);
				printf("\n\tPASSWORD CHANGED SUCCESFULLY\t\n");


			}
			else
			{
				printf("\n|--------------------|\n");
				printf("\n\tPASSWORDS DONT MATCH\n");
				printf("\n|--------------------|\n");
			}

		}
		else
		{
			printf("\n\t|-----------------|\n");
			printf("\n\tINVALID PASSWORD");
			printf("\n\t|-----------------|\n");
		}


}


void rank(FILE *fp)
{
	printf("\n\t|-----------------|\n");
	printf("\n\tRANKS\t\n");
	printf("\n\t|-----------------|\n");
	struct stud *s,stemp,st;
	int ct=0,i,j;
	/*while(fread(&st,sizeof(st),1,fp))
	{
		ct++;
	}*/
	//printf("\nct=%d",ct);
	fseek(fp,1,SEEK_END);
	ct=ftell(fp)/sizeof(struct stud);
	rewind(fp);
	s=(struct stud*)calloc(ct,sizeof(s));
	for(i=0;i<ct;i++)
	{
		fread(&s[i],sizeof(st),ct,fp);
	}

	for(i=0;i<ct;i++)
	{
		for(j=i+1;j<ct;j++)
		{
			if(s[i].total<s[j].total)
			{
				stemp=s[i];
				s[i]=s[j];
				s[j]=stemp;
			}
		}
	}
	for(i=0;i<ct;i++)
	{
		printf("-----------------------------------------\n");
		printf("|\tSID=	%d			|\n",s[i].rno);
		printf("|\tSTUDENT NAME=%s		|\n",s[i].name);
		for(j=0;j<si;j++)
		{
			printf("|\tMARKS %d=%lf		|\n",j+1,s[i].marks[j]);
		}
		printf("|\tTOTAL=%lf		|\n",s[i].total);
		printf("-----------------------------------------\n");
	}
}


void del(FILE *fp)
{
	int n,ck;
	FILE *fp1;
	struct stud s;
	printf("\n\tENTER ROLL NO TO DELETE			");
	scanf("%d",&n);
	ck=chk(n);
	if(ck==1)
	{
		fp1=fopen("temp.txt","w");
		while(fread(&s,sizeof(s),1,fp))
		{
			if(s.rno!=n)
			{
				fwrite(&s,sizeof(s),1,fp1);
			}
		}
		fclose(fp1);
		fclose(fp);
		fp=fopen("student.txt","w");
		fp1=fopen("temp.txt","r");
		while(fread(&s,sizeof(s),1,fp1))
		{
			fwrite(&s,sizeof(s),1,fp);
		}
		fclose(fp1);
		fclose(fp);
		printf("\n\t|------------------|\n");
		printf("\n\tDELETE SUCCESSFULL\n");
		printf("\n\t|------------------|\n");
	}
	else
	{
		printf("\n\t|---------------------|\n");
		printf("\n\tROLL NUMBER NOT FOUND\n");
		printf("\n\t|---------------------|\n");
	}

}


void upt(FILE *fp)
{
	int n,ck=0,opt,i;
	FILE *fp1;
	struct stud s;
	printf("\n\tENTER ROLL NO TO UPDATE	--------------->>>>>>>>>		");
	scanf("%d",&n);
	ck=chk(n);
	if(ck==1)
	{
		smenu();
		printf("\n\tSELECT OPTION 				");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				fp1=fopen("temp.txt","w");
				while(fread(&s,sizeof(s),1,fp))
				{
					if(s.rno!=n)
					{
						fwrite(&s,sizeof(s),1,fp1);
					}
					else
					{
						printf("\n\tENTER NEW NAME		");
						scanf("%s",s.name);
						fwrite(&s,sizeof(s),1,fp1);
					}
				}
				fclose(fp1);
				fclose(fp);
				fp=fopen("student.txt","w");
				fp1=fopen("temp.txt","r");
				while(fread(&s,sizeof(s),1,fp1))
				{
					fwrite(&s,sizeof(s),1,fp);
				}
				fclose(fp1);
				fclose(fp);
				break;
			case 2:
				fp1=fopen("temp.txt","w");
				while(fread(&s,sizeof(s),1,fp))
				{
					if(s.rno!=n)
					{
						fwrite(&s,sizeof(s),1,fp1);
					}
					else
					{
						s.total=0;
						for(i=0;i<si;i++)
						{
							printf("\n\tENTER MARKS %d",i+1);
							scanf("%lf",&s.marks[i]);
							s.total=s.marks[i]+s.total;
						}
						fwrite(&s,sizeof(s),1,fp1);
					}
				}
				fclose(fp1);
				fclose(fp);
				fp=fopen("student.txt","w");
				fp1=fopen("temp.txt","r");
				while(fread(&s,sizeof(s),1,fp1))
				{
					fwrite(&s,sizeof(s),1,fp);
				}
				fclose(fp1);
				fclose(fp);
				break;
			default:
				printf("\n\t|-----------------------|\n");
				printf("\n\tINVALID SUBMENU OPTION\t\n");
				printf("\n\t|-----------------------|\n");
		}
	}
	else
	{
		printf("\n\t|-------------------|\n");
		printf("\n\tROLL NUMBER NOT FOUND");
		printf("\n\t|-------------------|\n");
	}

}


int main(int argc,char *argv[])
{

	FILE *fp;
	fp=fopen("pass.txt","r");
	fgets(p.pas,50,fp);
	//int n=strlen(p.pas);
	//p.pas[n-1]='\0';
	//printf("\n%s\n",argv[1]);
	//printf("\n%s\n",p.pas);
	if(strcmp(p.pas,argv[1])!=0)
	{
		printf("\n|-----------------|\n");
		printf("\nINVALID PASSWORD\n");
		printf("\n|-----------------|\n");
		return -1;
	}
	else
	{
		printf("\n\t\t|------------|\n");
		printf("\n\t\tLOGIN SUCCESS\n");
		printf("\n\t\t|------------|\n");
	}

	/*int n1,n2;
	n1=strlen(argv[1]);
	printf("\nN1=%d",n1);
	n2=strlen(p.pas);
	printf("\nN1=%d",n2);*/


	FILE *fp1;
	int opt;
	do{
		menu();
		printf("\n\t\tSELECT OPTION --------------->>>>>>>>>       ");
		scanf("%d",&opt);
		switch(opt)
		{
		case 1:
			fp1=fopen("student.txt","a");
			if(fp1==NULL)
			{
				printf("\nCANT OPEN DATABASE\n");
				return -2;
			}
			add(fp1);
			fclose(fp1);
			break;
		case 2:
			fp1=fopen("student.txt","r");
			upt(fp1);
			break;
		case 3:
			fp1=fopen("student.txt","r");
			if(fp==NULL)
			{
				printf("\nCANT OPEN DATABASE\n");
				return -2;
			}
			disp(fp1);
			fclose(fp1);
			break;
		case 4:
			fp1=fopen("student.txt","r");
			del(fp1);
			break;
		case 5:
			fp1=fopen("student.txt","r");
			rank(fp1);
			break;
		case 6:
			fp1=fopen("pass.txt","w");
			change(fp1);
			fclose(fp1);
			break;
		case 7:
			printf("\n|-----------------|\n");
			printf("\n\tEXIT SUCCESSFULL\t\n");
			printf("\n|-----------------|\n");
			return 0;

		default:
			printf("\n\t\tSELECT VALID OPTION\n");
		}
	}while(opt!=7);


	return 0;
}

