#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t key,in;
pthread_mutex_t lock1;

int count=0, n ;

void *search(void *title)
{
    sem_wait(&in);
    printf("\nProcess %d reached\n",pthread_self());
  _sleep(1);

  printf("\n");
    pthread_mutex_lock(&lock1);

    if(count>=5)
        {
        printf("\nProcess %d is waiting to search\n",pthread_self());
    }
    count++;
    pthread_mutex_unlock(&lock1);

    sem_wait(&key);

 printf("\nProcess %d has started searching\n",pthread_self());
  _sleep(1);

    printf("\nProcess %d searching for %s\n",pthread_self(),title);

    info(title,pthread_self());

    printf("\nProcess%d finished it's search\n\n",pthread_self());

    sem_post(&key);
}

int main()
{
        int choice ;
        while(1)
        {
                printf("\n\t\t\t\t............Menu..............\n");
                printf("\n1.Choose number of searching process \n2.Exit\n");
                printf("\nEnter choice: ");
                scanf("%d",&choice);

                if(choice==1)
                {
       printf("\nEnter the number of searching process : ");
    scanf("%d",&n);

    printf("\n");
    int i,j,c=0;

    sem_init(&key,0,5);
    sem_init(&in,0,0);
    pthread_mutex_init(&lock1,0);

    pthread_t movie[n];
     char m[n][100];

       printf("Enter Keyword -> \n");

    for(i=1; i<=n; i++)
        {
        printf("%d: ",i);
        scanf("%s",m[i]);
        pthread_create(&movie[i],NULL,search,(void*)&m[i]);
        getchar();

    if(i==n)
        {
        for(j=0; j<n; j++)
        sem_post(&in);
    }
    }

    printf("\n");

    for(i=0; i<n; i++)
        {
        pthread_join(movie[i],NULL);
    }
    printf("All threads finished its' searching \n");
}
        else
        {
                exit(0);
        }
}
}

void info(char ch[],int no)
{
       if(ch[0]=='s' && ch[1]=='t' && ch[2]=='a' && ch[3]=='r') //Star
       {
        printf("\n3 match found for Process : %d , keyword : %s\n",no,ch);

        printf("\nName: My love from another star (2015)\n");
        printf("Director: Yoon Hye Jin \n");
        printf("Rating:  8.9\n\n");

        printf("\nName: Where stars land (2018)\n");
        printf("Director: Kim Soobin \n");
        printf("Rating:  8.0\n\n");

        printf("\nName: Falling like the stars (2019)\n");
        printf("Director: Patrick Mason \n");
        printf("Rating:  5.0\n\n");

        printf("................\n");
}

    else if(ch[0]=='m' && ch[1]=='o' && ch[2]=='n' && ch[3]=='e' && ch[4]=='y')  //money
        {
               printf("\n2 match found for Process : %d , keyword : %s\n",no,ch);

        printf("\nName: Money Heist (2019) \n");
        printf("Director:  Jesús Colmenar \n");
        printf("Rating:  8.3\n\n");

        printf("Name: Money monster (2016)\n");
        printf("Director: Jodie Foster \n");
        printf("Rating:  6.5\n");

        printf("................\n");
    }

else if(ch[0]=='g' && ch[1]=='u' && ch[2]=='a' && ch[3]=='r' && ch[4]=='d' && ch[5]=='i' && ch[6]=='a' && ch[7]=='n') //Guardian
        {
                printf("\n3 match found for Process : %d , keyword : %s\n",no,ch);

        printf("\nName: Guardian: The Lonely and Great God (2016)\n");
        printf("Director:  Lee Eung-bok  \n");
        printf("Rating:  8.6n\n");

        printf("\nName: Guardians of the Galaxy (2014)\n");
        printf("Director:  James Gunn \n");
        printf("Rating:  8.0n\n");

        printf("\nName: The invisible guardian (2017)\n");
        printf("Director:  Fernando González Molina  \n");
        printf("Rating:  6.0\n");

        printf("................\n");
    }

    else if (ch[0]=='d' && ch[1]=='a' && ch[2]=='r' && ch[3]=='k' ) //dark
    {
        printf("\n4 match found for Process : %d , keyword : %s\n",no,ch);

        printf("\nName: The Dark Knight (2008)\n");
        printf("Director:  Christopher Nolan\n");
        printf("Rating:  9\n\n");

        printf("\nName: Dark(2017)\n");
        printf("Director:  Baran bo Odar, Jantje Friese\n");
        printf("Rating:  8.8\n\n");

        printf("\nName: The Dark Knight Rises (2012)\n");
        printf("Director:  Christopher Nolan\n");
        printf("Rating:  8.4\n\n");

        printf("\nName: The dark (2018)\n");
        printf("Director: Justin P. Lange \n");
        printf("Rating:  5.4\n\n");

        printf("................\n");
    }

        else if (ch[0]=='w' && ch[1]=='a' && ch[2]=='t' && ch[3]=='e' && ch[4]== 'r') //water
    {

              printf("\n1 match found for Process : %d , keyword : %s\n",no,ch);

        printf("\nName: Under Water (2020)\n");
        printf("Director:  William Eubank\n");
        printf("Rating:  5.8\n\n");

        printf("................\n");
    }

           else if (ch[0]=='m' && ch[1]=='a' && ch[2]=='n') //man
    {
           printf("\n2 match found for Process : %d , keyword : %s\n",no,ch);

              printf("\nName: Spider-Man (2002)\n");
        printf("Director: Sam Raimi\n");
        printf("Rating:  7.3\n\n");

        printf("\nName: The invisible man (2020)\n");
        printf("Director: Leigh Whannell\n");
        printf("Rating:  7.1\n\n");

        printf("................\n");
    }

    else
        {
          printf("\nNo match found for Process : %d , keyword : %s\n",no,ch);
    }
}
