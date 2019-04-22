 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N sizeof(struct BOOK)
 
struct BOOK        //ͼ����Ϣ 
{
	char number[10];   //��¼�� 
	char name[10];     //���� 
	float price;       //�۸� 
	int num;         //���� 
	int x;
	struct BOOK *next;   //ָ���� 
};
typedef struct BOOK Book;
typedef Book *book;	 

struct STUDENT       
{
	char number[10];   //ѧ�� 
	char name[10];     //���� 
	char student_name[10];
	char username[10];
	char scert[10];
	int x; 
	struct STUDENT *next;
}; 
typedef struct STUDENT Student;
typedef Student *student;

struct REGISTSTU
{
	char registname[10];
	char password[10];
	struct REGISTSTU *next;
};
typedef struct REGISTSTU Registstu;
typedef Registstu *registstu;


void menu();           //�˵� 
void input_book();     //ͼ����� 
void input_student();  //xue sheng xin xi 
void save_book(book p);//��ͼ����Ϣ�����ļ� 
void save_student(student p);
void find_book();      //��ѯ 
void print_book();    //ͼ������ 
void del_book();     //ɾ��ͼ�� 
book ss();
student aa();
void print_student();
void stulogin();
void sturegist();
void returm_book(); 

void menu()    
{   
	system("cls");  
	int t;
	printf("    LIBARRY MANAGEMENT SYSTEM   \n");	
	printf("|     ��1��Student login       |\n");
	printf("|     ��2��Student registe     |\n");	
	printf("|     ��3��manager access      |\n");	
	scanf("%d",&t); 
	if(t==1) stulogin();
	if(t==2) sturegist();
	if(t==3){
		printf("[1]input book\n");
		printf("[2]delete book\n");
		printf("[3]print book\n");
		printf("[4]print student\n");
		scanf("%d",&t);
		if(t==1) input_book();
	    if(t==2)  del_book();
	    if(t==3) print_book();
	    if(t==4) print_student(); 
	}
}
book ss()      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 
{
	FILE *fp;       //�ļ�ָ�� 
	int n=0;
	book head=NULL;
	book p2,p,pr=NULL;
	fp=fopen("mybook","ab+");     //��ֻ���ķ�ʽ���ļ� 
	while(!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
	   n++;
	   p=(book)malloc(N); //���ڴ�����һ�οռ� 
	   fread(p,N,1,fp);     //��fp��ָ����ļ��е����ݸ���p 
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //�������� 
	    {
	    	pr=p2;
	    	p2->next=p;//β���ֻ����һ���½ڵ� 
	    	p2=p;
		}
    }
    if(pr!=NULL) pr->next=NULL;
    else head=NULL;
    fclose(fp);    //�ر��ļ� 
    return head;   //����ͷָ�� 
}

student aa()      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 
{
	FILE *fp;       //�ļ�ָ�� 
	int n=0;
	student head=NULL;
	student p2,p,pr=NULL;
	fp=fopen("Sinformation","ab+");     //��ֻ���ķ�ʽ���ļ� 
	while(!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
	   n++;
	   	p=(student)malloc(N); //���ڴ�����һ�οռ� 
	   fread(p,N,1,fp);     //��fp��ָ����ļ��е����ݸ���p 
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //�������� 
	    {
	    	pr=p2;
	    	p2->next=p;
	    	p2=p;
		}
    }
    if(pr!=NULL) pr->next=NULL;
    else head=NULL;
    fclose(fp);    //�ر��ļ� 
    return head;   //����ͷָ�� 
}
registstu bb()      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 
{
	FILE *fp;       //�ļ�ָ�� 
	int n=0;
	registstu head=NULL;
	registstu p2,p,pr=NULL;
	fp=fopen("registstu","ab+");     //��ֻ���ķ�ʽ���ļ� 
	while(!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
	   n++;
		p=(registstu)malloc(N); //���ڴ�����һ�οռ� 
	   fread(p,N,1,fp);     //��fp��ָ����ļ��е����ݸ���p 
	   if(n==1)
	   {
	      head=p;
	      p2=p;
	    }
	    else             //�������� 
	    {
	    	pr=p2;
	    	p2->next=p;//β���ֻ����һ���½ڵ� 
	    	p2=p;
		}
    }
    if(pr!=NULL) pr->next=NULL;
    else head=NULL;
    fclose(fp);    //�ر��ļ� 
    return head;  //����ͷָ�� 
}
void input_book()    //ͼ��¼�� 
{
	system("cls");
	char t;
	book p;
	p=(book)malloc(N);     //����ռ� 
	printf("������ͼ���¼��(С��10λ��)��\n");    
	scanf("%s",&p->number);
	printf("Please input the name of the book��\n");
	scanf("%s",&p->name);
	printf("Please input the price of the book��\n");
	scanf("%f",&p->price);
	printf("Please input the number of the book��\n");
	scanf("%d",&p->num);
	save_book(p);
	system("cls");
	printf("| ����ɹ����Ƿ������  |\n");	
	printf("| 1.��             2.�� |\n");
	t=getch();
	if(t=='1')input_book();
	if(t=='2')menu();		 
} 

void input_student()    //ѧ����Ϣ¼�� 
{
	system("cls");
	student p;
	p=(student)malloc(N);     //����ռ� 
	printf("please input your ID number\n");    
	scanf("%s",&p->number);
	printf("the book name you want to borrow��\n");
	scanf("%s",&p->name);
	printf("Input your name��\n");
	scanf("%s",&p->student_name);
	save_student(p);
	menu();		 
} 
void del_book()   //ɾ����Ϣ 
{
	do
	{
		system("cls");
		FILE *fp;
		book head,p,pre=NULL; 
		int j=0,x; 
		char name[10];
		char t,c,ch;
		head=ss();    //���ú��������ر�ͷ��ַ 
		printf("��������Ҫɾ����ͼ���������");
		scanf("%s",name);
		p=head;
		while(p!=NULL)
		{
			p->x=0;
			p=p->next;
		}
		p=head;
		printf("**************ͼ����Ϣ*********************\n");
		printf("------------------------------------------\n");
		printf("��¼��        ����          �۸�       ����\n");
		printf("---------------------------------------\n");
		while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->name,name)==0)          //P->name=name ��ʱ�򷵻�0 
			{
				j++;
				printf("%d:%s%14s      %.2f%12d\n",j,p->number,p->name,p->price,p->num);
				p->x=j;
			}
			p=p->next;
		}
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
			{
				ch=getch();
				if(ch=='0')
				{
					menu();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			printf("��������Ҫɾ����ͼ��ı�ţ�");
			scanf("%d",&x);getchar();
			if(x>j||x==0)
			{
				printf("�����������������!");
			}
			else
			{
				break;
			}
		}
		printf("|     �Ƿ�ȷ��ɾ���� ");
		printf("| 1.��             2.�� |");
		printf("-------------------------");
		while(1)
		{
			t=getch();
			if(t=='1')
			{
				break;
			} 
			else if(t=='2')
			{
				menu();
			}
		}
		p=head;
		while(p!=NULL&&p->x!=x)
		{
			pre=p;
			p=p->next;
		}
		if(p!=NULL)
		{
			if(pre==NULL)
			{
				head=head->next;
			}
			else
			{
				pre->next=p->next;
			}
		}
		free(p);
		fp=fopen("mybook","wb");
		if(fp==NULL)
		{
			printf("cannot open file"); 
		}
		if(fwrite(head,N,1,fp)!=1)
		{
			printf("write error!"); 
		}
		fclose(fp);
		if(head!=NULL)
		{
			p=head->next;
			fp=fopen("mybook","ab");
			if(fp==NULL)
			{
				printf("cannot open file");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)
				{
					printf("write error!");
				}
				p=p->next;
			}
			fclose(fp);
		}
		system("cls");
		printf("|  ɾ���ɹ����Ƿ������ |\n");
		printf("| 1.��             2.�� |\n");
		while(1)
		{
			c=getch();
			if(c=='1')
			{
				break;
			}
			else if(c=='2')
			{
				menu();
			}
		}
	}while(1);
}


void print_book()   //ͼ������ 
{
	system("cls");
	book head,p;
	int i=11;
	int sum=0;
	head=ss();
	printf("*********************ͼ������*****************\n");
	printf("----------------------------------------------\n");
	printf("��¼��        ����             �۸�        ����\n");
	printf("----------------------------------------------\n");
	p=head;
	while(p!=NULL)
	{
		printf("%s %14s             %.2f%   12d\n",p->number,p->name,p->price,p->num);
		i++;
		sum+=p->num;//����ͼ������ 
		p=p->next;
	}
	printf("ͼ������Ϊ��%d\n",sum);
	printf("�����������");
	getch();//�����Ժ���
	menu(); 
}
void print_student()   //ѧ��������Ϣ 
{
	system("cls");
	student head,p;
	head=aa();
	printf("---------------------------------\n");
	printf("ѧ��        ����          ����\n");
	printf("----------------------------------\n");
	p=head;
	while(p!=NULL)
	{
		printf("%s %14s             %s\n",p->number,p->name,p->student_name); 
		p=p->next;
	}
	printf("�����������");
	getch();//�����Ժ���
	menu(); 
}
 
void find_book()  //��ѯͼ�� 
{	
		system("cls");  //���� 
		char t;
		printf(" ��1��ͼ���ѯ\n");
		printf(" ��0������\n");
		t=getch();
		if(t=='0') menu();
	    if(t=='1')
	    {
	    	system("cls");
	  		book head,p;
			int i=11;
			head=ss();
			char name[10];
			
			printf("��������Ҫ��ѯͼ���������\n");
			gets(name);
			p=head;	
			printf("��¼��        ����          �۸�      ����\n");
			printf("----------------------------------------\n");
			while(p!=NULL)
			{
				if(p!=NULL&&strcmp(p->name,name)==0)
				{
			
					printf("%s%14s             %.2f%12d\n",p->number,p->name,p->price,p->num);
					i++;
				}
				p=p->next;
			}
			printf("����������أ�");
			getch();
			find_book();	
		}
}

void save_book(book p)   //��p������д���ļ� 
{
	FILE *fp;    //�ļ�ָ�� 
	fp=fopen("mybook","ab");   //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ� 
	if(fp==NULL)
	{
		printf("cannot open file");
	}
	if(fwrite(p,N,1,fp)!=1)   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ��� 
	{
		printf("write error");
	}
	fclose(fp);    //�ر��ļ�  
 } 
void save_student(student p)   //��p������д���ļ� 
{
	FILE *fp;    //�ļ�ָ�� 
	fp=fopen("Sinformation","ab");   //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ� 
	if(fp==NULL)
	{
		printf("cannot open file");
	}
	if(fwrite(p,N,1,fp)!=1)   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ��� 
	{
		printf("write error");
	}
	fclose(fp);    //�ر��ļ�  
 }
void sturegist()
{
	registstu p;
	char c;
	int t;
	int flag=1;
	p=(registstu)malloc(sizeof(N));     //����ռ�
	system("cls");
	printf("please input your user name\n");    
	scanf("%s",&p->registname);
	char studentname;
	studentname=*p->registname;
	printf("please input your password\n");
	scanf("%s",&p->password);
	FILE *fp;    //�ļ�ָ�� 
	fp=fopen("registstu","ab");   //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ� 
	if(fp==NULL)
	{
		printf("cannot open file");
	}
	if(fwrite(p,N,1,fp)!=1)   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ��� 
	{
		printf("write error");
	}
	fclose(fp);
	fp = fopen("registstu","r"); // ���ļ� .txt
	while(fscanf(fp,"%c",&c)!=EOF){
	if (c==studentname){
	flag=0;
	printf("This name has been used\n");
	printf("please change another one\n");
	fclose(fp);
	printf("[1]regist again\n");
	scanf("%d",&t); 
	if(t==1) sturegist();
	}	
}
    if(flag==1){
	printf("| successflly regist��  |\n");
	printf("�����������");
	getch();
	menu();}
}	
void stulogin()
{
	int flag=0;
	int c=0;
	char t; 
	char password[10]; 
	FILE *fp;
	registstu head,p,pre=NULL;
	char name[10];
	head=bb();
	system("cls");
	printf("please input your user name\n");
	scanf("%s",name);
	printf("please input your password\n");
	scanf("%s",password);
	p=head;
	while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->registname,name)==0&&strcmp(p->password,password)==0)   //P->name=name ��ʱ�򷵻�0 
			{
				flag=1;
			}
			p=p->next;
		}
	if(flag==1){
		system("cls");
		printf("   Successfully log in \n ");
		printf("LIBARRY MANAGEMENT SYSTEM\n");	
		printf("|  ��1��Borrow Book  |\n");
		printf("|  ��2��Return Book  |\n");	
		printf("|  ��3��Find   Book  |\n");
		printf("|  ��4��Print  Book  |\n");
		printf("|  ��5��Print Student|\n");
		t=getch();
		if(t=='1')input_student() ;
		if(t=='2')returm_book();
		if(t=='3')find_book(); 
		if(t=='4')print_book();
		if(t=='5')print_student();
	}
	if(flag==0){
		printf(" The password is error\n ");
		printf("[1] relogiin\n");
		scanf("%d",&c);
		if(c==1)
		stulogin();	
	}
}
void returm_book()
{
		while(1){
		system("cls");
		FILE *fp;
		student head,p,pre=NULL; 
		int j=0,x; 
		char name[10];
		char t,c,ch;
		head=aa();    //���ú��������ر�ͷ��ַ 
		printf("Name of the book u want to return\n");
		scanf("%s",&name);
		p=head;
		while(p!=NULL)
		{
			p->x=0;
			p=p->next;
		}
		p=head;
		printf("**************ͼ����Ϣ*********************\n");
		printf("------------------------------------------\n");
		printf("xuehao        ����          ����\n");
		printf("---------------------------------------\n");
		while(p!=NULL)
		{
			if(p!=NULL&&strcmp(p->name,name)==0)          //P->name=name ��ʱ�򷵻�0 
			{
				j++;
				printf("%s %14s             %s\n",p->number,p->name,p->student_name);
				p->x=j;
			}
			p=p->next;
		}
		if(j==0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{ 
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while(1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
			{
				ch=getch();
				if(ch=='0')
				{
					menu();break;
				}
				else if(ch=='1')
				{
					break;
				}
			}
			if(ch=='1')     //��������ch����1�����������ѭ�� 
			   continue;
		}
		while(1)
		{
			printf("��������Ҫ�����ţ�");
			scanf("%d",&x);getchar();
			if(x>j||x==0)
			{
				printf("�����������������!");
			}
			else
			{
				break;
			}
		}
		printf("|     �Ƿ�ȷ��ɾ���� ");
		printf("| 1.��             2.�� |");
		printf("-------------------------");
		while(1)
		{
			t=getch();
			if(t=='1')
			{
				break;
			} 
			else if(t=='2')
			{
				menu();
			}
		}
		p=head;
		while(p!=NULL&&p->x!=x)
		{
			pre=p;
			p=p->next;
		}
		if(p!=NULL)
		{
			if(pre==NULL)
			{
				head=head->next;
			}
			else
			{
				pre->next=p->next;
			}
		}
		free(p);
		fp=fopen("Sinformation","wb");
		if(fp==NULL)
		{
			printf("cannot open file"); 
		}
		if(fwrite(head,N,1,fp)!=1)
		{
			printf("write error!"); 
		}
		fclose(fp);
		if(head!=NULL)
		{
			p=head->next;
			fp=fopen("Sinformation","ab");
			if(fp==NULL)
			{
				printf("cannot open file");
			}
			while(p!=NULL)
			{
				if(fwrite(p,N,1,fp)!=1)
				{
					printf("write error!");
				}
				p=p->next;
			}
			fclose(fp);
		}
		system("cls");
		printf("|  ����ɹ����Ƿ������ |\n");
		printf("| 1.��             2.�� |\n");
		while(1)
		{
			c=getch();
			if(c=='1')
			{
				break;
			}
			else if(c=='2')
			{
				menu();
			}
		}
 }
}
main()  
{
	menu();
}  
