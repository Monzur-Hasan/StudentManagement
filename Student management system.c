#include<stdio.h>

 void filewrite();
 void avgmarks();
 void fileprint();
 void rollin();

void filewrite()
{
  int roll,ch;
  int mark;
  char nam[50];
  FILE *fp;
  fp = fopen("student.txt","w");
  ch =1;
  while(ch)
  {
   system("cls");
  //system("color 10");
  printf("ENTER NAME: ");
  scanf("%s", nam);
  printf("ENTER ROLL NUMBER: ");
  scanf("%d",&roll);
  printf("ENTER MARK: ");
  scanf("%d",&mark);
  fprintf(fp,"%d %s %d\n",roll,nam,mark);
  printf("\n\n\                \xb1\ press 1 to CONTINUE,0 to MAIN MENU ");
  scanf("%d",&ch);
  }
   fclose(fp) ;
}
void fileprint()
{
  int marks[100],rollno[100],x[100],i;
  char name[100][50];
  FILE *fp;

  fp = fopen("student.txt","r");
   i=0;
  /*printf("ROLLNO       NAME           MARK  \n");*/
   while(!feof(fp))
  {

     //system("color 12");
     fscanf(fp,"%d %s   %d\n",&rollno[i],&name[i],&marks[i]);
     printf("\nNAME: %s\nROLL NO: %d\nMARK: %d\n\n",name[i],rollno[i],marks[i]);
     i=i+1;
   }
   fclose(fp);
   printf("\n\n\n\                \xb1\PRESS ANY KEY\n");
   getch();

  }
void rollin()
{   int i,roll,ch,mark,roll1;
    char nam[50];
    FILE *fm;

    ch=1;
  while(ch)

  {
    system("cls");
    fm = fopen("student.txt","r");
    //system("color 16");
    printf("\n ENTER ROLL NUMBER: ");
    scanf("%d",&roll1);
    i=0;
   while(! feof(fm))
    {
     fscanf(fm,"%d %s %d\n",&roll,nam,&mark);
     if(roll1==roll)
    {
        /*printf("\nROLLNO.     NAME        MARKS\n ");*/
     printf("\nNAME: %s\nROLL NO:%d\nMARK:%d\n",nam,roll,mark);

     }
     else
     i=i+1;
    }
  //printf("\nNAME: %s\nROLL NO:%d\nMARK:%d\n",nam,roll,mark);*/
  printf("\n\n\                \xb1\ press 1 to see STUDENT INFO, 0 to return to MAIN MENU\n");
  scanf("%d",&ch);
  fclose(fm);
  }



 }

void avgmarks()
 {
    int mark,roll,n=0,i;
    float avg=0,x=0;
    char nam[50];
    FILE *fm;
    fm = fopen("student.txt","r");
    i=0;
   while(! feof(fm))
    {
    system("cls");
     fscanf(fm,"%d %s %d\n",&roll,nam,&mark);
     x = x + mark;
     i=i+1;
    }
  n = i;
  avg = x/n;

  printf("AVERAGE MARKS OF %d STUDENTS ARE: %.2f ",n,avg);
  fclose(fm);
  printf("\n\n\n\                \xb1\PRESS ANY KEY");
  getch();

 }
int main()
{
  int marks,mark,rollno,n,i,j,roll,c;
  char nam[100];

  while(c!=5)
  {
      system("color 2");
        system("cls");

      printf("                 \xb1\xb1\xb1\xb1\xb1\ WELCOME TO OUR PROJECT \xb1\xb1\xb1\xb1\xb1");
      printf("\n");
      printf("\n");


     printf("                \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\ GIVE CHOICE \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2   \n\n");
     printf("                1 TO ENTER STUDENT INFO.\n");
     printf("                2 TO SEE STUDENT.TXT FILE\n");
     printf("                3 TO PRINT STUDENT INFO. USING ROLL NO\n");
     printf("                4 TO FIND AVERAGE OF MARKS\n");
     printf("                5 TO EXIT\n\n                \xb2\xb2\xb2\xb2\xb2\Please choice: ");
     scanf("%d",&c);


     switch(c)
     {
         case 1:
              filewrite();
              break;
         case 2:
              fileprint();
              break;
         case 3:  rollin();
              break;
         case 4:  avgmarks();
              break;
         case 5:
              break;
         default:
             break;

     }
  }
  return 0;
}
