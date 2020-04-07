#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct station
{
    char name[50];
    int number;

    struct station *next;
    struct station *right;

};

struct station *head[8],*temp;

char base[32][50]={"vaishali","kaushambi","anand vihar","karkuduma","preet vihar","nirman preet","laxmi nagar","yamuna bank","indraprastha","pragati maidan","mandi house","janpath","central secretariat","patel chowk","rajiv chowk","new-delhi","chawri bazar","chandni chowk","kashmere gate","tis hazari","pulbangash","pratap nagar","shastri nagar","inderlok","kanhaiya nagar","keshav puram","netaji subhash place","kohat enclave","pitampura","rohini east","rohini west","rithala"};//main line
char blue1[10][50]={"akshardham","mayur vihar","mayur vihar extn.","new-ashok nagar","noida sector 15","noida sector 16","noida sector 18","botanical garden","golf course","city center"};
char violet[24][50]={"khan market","jln stadium","jangpura","lajpat nagar","moolchand","kailash colony","nehru palace","kalkaji mandir","govind puri","okhla","jasola-apollo","sarita vihar","mohan estate","tughalkabad","badarpur border","sarai","n.h.p.c chowk","mewala maharajapur","sector 28","badkal mor","old faridabad","neelam chowk ajronda","bata chowk","escorts mujesar" };
char yellow1[19][50]={"udyog bhawan","lok kalyan marg","jor bhagh","ina","aiims","green park","hauz khas","malviya nagar","saket","qutab minar","chhattarpur","sultanpur","ghitorni","arjangarh","guru dronacharya","sikanderpur","mg road","iffco chowk","huda city centre"};
char blue2[26][50]={"ramakrishna ashram marg","jhandewalan","karol bagh","rajendra place","patel nagar","shadipur","kirti nagar","moti nagar","ramesh nagar","rajouri garden","tagore garden","subhash nagar","tilak nagar","janakpuri east","janakpuri west","uttam nagar east","uttam nagr west","nawada","dwarka mor","dwarka","dwarka sector 14","dwarka sector 12","dwarka sector 11"," dwarka sector 10"," dwarka sector 9","dwarka sector 8"};
char airport_line[5][50]={"shivaji stadium","dhaula kaun","delhi aero city","igi airport","dwarka sector 21"};
char yellow2[11][50]={"civil lines","vidhan sabha","vishwavidyalay","gtb nagar","model town","azadpur","adarsh nagar"," jahangirpuri","hiderpur badli mor","rohini sector 18","samaypur badli"};
char green[13][50]={"punjabi bagh","ashok park main","shivaji park","madipur","paschim vihar east","paschim vihar west","peeragarhi","udyog nagar","surajmal stadium","nagloi","nangloi railway station","rajdhani park","mundka"};

int size[8]={32,10,24,19,26,5,11,13};
int junction[7]={7,10,12,14,15,18,23};
int top=-1;
char list_[75][50];
char start[50];
char end[50];

void creation(int j,char name1[][50])
{
    head[j]=NULL;
    int i=0;
    for(i=0;i<size[j];i++)
    {
        struct station *new;
        new=(struct station*)malloc(sizeof(struct station));
        strcpy(new->name,name1[i]);
        new->number=i;
        new->next=NULL;
        new->right=NULL;

        if(head[j]==NULL)
        {
            head[j]=new;
        }
        else
        {
            temp=head[j];
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=new;
        }
    }
}

void creation1(int j,char name1[][50])
{

    head[j]=NULL;
    int i=0;
    for(i=0;i<size[j];i++)
    {
        struct station *new;
        new=(struct station*)malloc(sizeof(struct station));
        int k=strlen(name1[i]);
        strncpy(new->name,name1[i],k);
        new->number=i;
        new->next=NULL;
        new->right=NULL;

        if(head[j]==NULL)
        {
            head[j]=new;
        }
        else
        {
            temp=head[j];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new;
        }
    }
}

void insert()
{//printf("flag=3\n");
    creation1(0,base);//creation of main line
    creation(1,blue1);//creation of blue1 line
    creation(2,violet);//creation of violet line
    creation(3,yellow1);//creation of yellow1 line
    creation(4,blue2); //creation of blue2 line
    creation(5,airport_line);//creation of airport line
    creation(6,yellow2);//creation of yellow2 line
    creation(7,green);//creation of green line
}

void mergelist()
{
   // printf("flag=m\n");
temp=head[0];
int i=0;
while(temp->next!=NULL)
    {
        if(temp->number==junction[i])
        {
            temp->right=head[i+1];

             i++;
        }

        temp=temp->next;
    }

}

int count,x,find,flag,flag0,flag3,flag4,i,flag2,d,z,as,ay,ris,sop;
void initials()
{
    count=0;x=0;find=0;
    flag=0; flag0=0;i=0;sop;
    flag2=0;ris=0;flag3=0;flag4=0;
    d=0;z=0;as=0;ay=0;
}

int  traversal(struct station *temp)
{
   // printf("flag=t\n");
    if(temp!=NULL)
    {
        int endh,starth;
        endh=strcmp(temp->name,end);
        starth=strcmp(temp->name,start);

        if(starth==0)
        {
            flag=1;
            flag4=1;
        }

        if(endh==0)
        flag0=1;

        if(find==0)
        {
            if(starth==0)
                find=1;
            else if(endh==0)
                find=2;
        }

        if(flag==1&&flag0==0)
        {
            if(temp->right!=NULL && temp->next!=NULL)
            as=1;
            push(temp->name);
       //printf("flag1\n");
        }

        if(flag0==1)
            return 0;
        else
        {//printf("7\n");
            if(temp->right==NULL)
            {
                flag3=1;
                for(i=0;i<count;i++)
                {
         //           printf("pop\n");
                    pop();
                   // printf("%s",temp->name);
                }
                count=0;

            }
            else
            {
                if(flag0==0)
                {
                    if(flag==1)
                    {
                    count++;
//                     printf("5\n");
                    }

                    traversal(temp->right);
                }
                /*  if(temp->next==NULL)
                        {
                            printf("5\n");
                            flag3=1;
                        }*/
                if(starth==0 && temp->next==NULL)
                {
                    flag2=1;

                }
     //printf("4\n");
                if(temp->right!=NULL && temp->next!=NULL)
                 {
                   //  printf("3\n");
                    if(flag2!=0)
                    {
                       if(as==0)
                       x=1;
                    }
                 }
     /*if(flag3==0)
{
         if(flag==1 && temp->right==NULL)
            {flag3=1;
     }*/
                 if(flag0==1)
                 {
                     flag2=0;
                 }

                 if(flag2==1 || x==1)
                 {
            //if(flag3==0)
                      push(temp->name);
                      printf("push2\n");
                      x=0;
                      d++;
                      if(ris==0)
                      {
                         pop();
                         ris=1;
                      }
                  }
                 if(temp->right!=NULL && temp->next!=NULL)
                 {
                       printf("************\n");
                       if(flag0==0)
                       {
                            if(flag2==0|| sop>0)
                            {
                                for(i=0;i<d;i++)
                                {
                                    printf("4\n");
                                    pop();

                                }
                                d=0;flag3=0;
                            }
                            else
                            {
                                sop++;
                            }
                        }
                  }
              }

              traversal(temp->next);
        }
    }
}





int pop()
{
    top--;
    printf("%d aftter pop\n",top);
    return 0;
}
int push(char stat[])
{
    int k=strlen(&stat[0]);
    top++;

    strncpy(list_[top],&stat[0],k+10);
    printf("%s push\n",list_[top]);
    return 0;
}

void display()
{
    for(i=0;i<=top;i++)
    {
        printf("%s\n",list_[i]);
    }
}

void display1()
{
    for(i=top;i>=0;i--)
    {
        printf("%s\n",list_[i]);
    }
}

void mainlayout()
{

    system("COLOR 47");

    printf("\n");
    //printf("\n");
    //printf("\n");
    //printf("\n");
    //printf("\n");
    //printf("            _________________________________________________________\n");
    //printf("           |                 DELHI METRO ROUTE                       |\n");
    //printf("           |_________________________________________________________|\n");
    //printf("           |                                                         |\n");
    //printf("           | ENTER START STATION :                                   |\n");
    //printf("           | ENTER DESTINATION   :                                   |\n");
    //printf("           |_________________________________________________________|\n");
//return 0;
}
void lowercase(char l[])
{
    int c=strlen(l);
    int i;

    for(i=0;i<c;i++)
    {
        if(l[i]>=65&& l[i]<=90)
        {
            l[i]=l[i]+32;
        }
        if(l[i]==95||l[i]==46)
        {
            l[i]=32;
        }
        if(l[i]>=97&&l[i]<=122)
        {
            l[i]=l[i];
        }

    } // printf("%s",l);
}

int main()
{
// mainlayout();
    //fflush(stdin);
    gets(start);
    //fflush(stdin);
    gets(end);
    //fflush(stdin);
    lowercase(start);
    lowercase(end);
    int k=strlen(start);
    int j=strlen(end);

    char sanchi[50];
    insert();
    mergelist();
    initials();
    traversal(head[0]);

    if(find==1)
    {//printf("flag=2\n");
        display();
        printf("%s",end);
    }

    if(find==2)
    {//printf("flag3\n");
        strncpy(sanchi,start,k+10);
        strncpy(start,end,j+10);
        strncpy(end,sanchi,50);
    //puts(start);
    //puts(end);
        top=-1;
        initials();
        traversal(head[0]);
        printf("%s\n",end);
        display1();

    }

    return 0;
}
