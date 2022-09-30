#include <stdio.h>

int duzlem[8][8];

void Yazdir(void);

void MuhtemelMahal(int , int);

main()
{
    int i, j, k, sira;
    int x,y;
    int durum=0;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++) duzlem[i][j]=10;

    duzlem[0][0]=2; duzlem[0][7]=2; duzlem[7][0]=12; duzlem[7][7]=12;
    duzlem[0][1]=3; duzlem[0][6]=3; duzlem[7][1]=13; duzlem[7][6]=13;
    duzlem[0][2]=4; duzlem[0][5]=4; duzlem[7][2]=14; duzlem[7][5]=14;
    duzlem[0][3]=5;                 duzlem[7][3]=15;
    duzlem[0][4]=6;                 duzlem[7][4]=16;

    for(i=0;i<8;i++) duzlem[1][i]=1;

    for(i=0;i<8;i++) duzlem[6][i]=11;

    Yazdir();

    sira=1;
    //1 ise beyaz
    //2 ise siyah


    while(durum==0)
    {
        k=0;
        while(k==0)
        {
            if(sira==1)printf("Sira beyazlarin \n");
            else printf("Sira siyahlarin \n");

            i=8;
            while(i<0 || i>7)
            {printf("Satir(0-7) : "); scanf("%d",&i);}

            j=8;
            while(j<0 || j>7)
            {printf("Sutun (0-7) : "); scanf("%d",&j);}

            if(sira==1)
            {
                if(duzlem[i][j]<=10)
                {printf("Gecerli bir tas secmediniz! \n"); i=0; }

                else { k=1; sira=2; }
            }

            else
            {
                if(duzlem[i][j]>=10)
                {printf("Gecerli bir tas secmediniz! \n"); i=0; }

                else { k=1; sira=1; }
            }

        }

    MuhtemelMahal(i,j);

    Yazdir();

    printf("Hareket edeceginiz : \n");

    x=8;
    while(x<0 || x>7)
    {printf("Satir(0-7) : "); scanf("%d",&x); }

    y=8;
    while(y<0 || y>7)
    {printf("Sutun (0-7) : "); scanf("%d",&y);}

    if(sira==1)//siyahlarinmis; beyazlara hareket et
    {
        if(duzlem[x][y]<0)
        {
            duzlem[x][y]=duzlem[i][j];
            duzlem[i][j]=10;
        }


        else
        {printf("Hareket Gecersiz! \n"); sira=2;}

    }

    else//beyazlarinmis; siyahlara hareket et
    {
        if(duzlem[x][y]<0)
        {
            duzlem[x][y]=duzlem[i][j];
            duzlem[i][j]=10;
        }

        else
        { printf("Hareket gecersiz! \n"); sira=1; }

    }

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
        {
            if(duzlem[i][j]<0) duzlem[i][j]=0-duzlem[i][j];
        }

    Yazdir();

    getchar();

    }
    
}

void Yazdir()
{
    int i, j;

    printf("   ");
    for(i=0;i<8;i++)
    {
        printf("%c[%d;%dm  %d  %c[%dm",27,4,35,i,27,0);
    }

    printf("\n");
    for(i=0;i<8;i++)
    {
        printf("%c[%d;%dm %d %c[%dm",27,3,35,i,27,0);

        for(j=0;j<8;j++)
        {
           

            switch(duzlem[i][j])
            {
                //SIYAHLAR - YUKARI
                case 1: { printf("%c[%d;%d;%dm  p  %c[%dm",27, 1, 31, 40,27,0); break; }

                case 2: { printf("%c[%d;%d;%dm  k  %c[%dm",27, 1, 31, 40,27,0); break; }

                case 3: { printf("%c[%d;%d;%dm  a  %c[%dm",27, 1, 31, 40,27,0); break; }

                case 4: { printf("%c[%d;%d;%dm  f  %c[%dm",27, 1, 31, 40,27,0); break; }

                case 5: { printf("%c[%d;%d;%dm  V  %c[%dm",27, 1, 31, 40,27,0); break; }

                case 6: { printf("%c[%d;%d;%dm  S  %c[%dm",27, 1, 31, 40,27,0); break; }

                //NOKTALAR
                case 10:{ printf("%c[%d;%d;%dm  .  %c[%dm",27, 1, 29, 48,27,0); break; }

                // BEYAZLAR -  ASAGI
                case 11: { printf("%c[%d;%d;%dm  p  %c[%dm",27, 1, 31, 47,27,0);  break; }

                case 12: { printf("%c[%d;%d;%dm  k  %c[%dm",27, 1, 31, 47,27,0); break; }

                case 13: { printf("%c[%d;%d;%dm  a  %c[%dm",27, 1, 31, 47,27,0); break; }

                case 14: { printf("%c[%d;%d;%dm  f  %c[%dm",27, 1, 31, 47,27,0); break; }

                case 15: { printf("%c[%d;%d;%dm  V  %c[%dm",27, 1, 31, 47,27,0); break; }

                case 16: { printf("%c[%d;%d;%dm  S  %c[%dm",27, 1, 31, 47,27,0); break; }

                //MUHTEMEL SIYAHLAR - YUKARI
                case -1: { printf("%c[%d;%d;%dm  p  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -2: { printf("%c[%d;%d;%dm  k  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -3: { printf("%c[%d;%d;%dm  a  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -4: { printf("%c[%d;%d;%dm  f  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -5: { printf("%c[%d;%d;%dm  V  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -6: { printf("%c[%d;%d;%dm  S  %c[%dm",27, 1, 31, 42,27,0); break; }

                //MUHTEMEL NOKTALAR
                case -10:{ printf("%c[%d;%d;%dm  .  %c[%dm",27, 1, 29, 42,27,0); break; }

                // MUHTEMEL BEYAZLAR -  ASAGI
                case -11: { printf("%c[%d;%d;%dm  p  %c[%dm",27, 1, 31, 42,27,0);  break; }

                case -12: { printf("%c[%d;%d;%dm  k  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -13: { printf("%c[%d;%d;%dm  a  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -14: { printf("%c[%d;%d;%dm  f  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -15: { printf("%c[%d;%d;%dm  V  %c[%dm",27, 1, 31, 42,27,0); break; }

                case -16: { printf("%c[%d;%d;%dm  S  %c[%dm",27, 1, 31, 42,27,0); break; }

            }

        }

    printf("\n\n");
    }

}

void MuhtemelMahal(int konum_x,int konum_y)
{
    int i, j;

    switch(duzlem[konum_x][konum_y])
    {
        case 1: //piyon
        {
            if(konum_x<8)  duzlem[konum_x+1][konum_y]=0-duzlem[konum_x+1][konum_y];

            if(konum_x==1) duzlem[konum_x+2][konum_y]=0-duzlem[konum_x+2][konum_y];

            if(duzlem[konum_x+1][konum_y+1]>10) duzlem[konum_x+1][konum_y+1]=0-duzlem[konum_x+1][konum_y+1];
            if(duzlem[konum_x+1][konum_y-1]>10) duzlem[konum_x+1][konum_y-1]=0-duzlem[konum_x+1][konum_y-1];

        break;
        }

        case 2: //kale
        {
            i=konum_x+1;
            while( (duzlem[i][konum_y]==10) && (i<8) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i++;
            }
            if(i<8)
            if(duzlem[i][konum_y]>10) duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_x-1;
            while( (duzlem[i][konum_y]==10) && (i>=0) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i--;
            }
            if(i>=0)
            if(duzlem[i][konum_y]>10)duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_y+1;
            while( (duzlem[konum_x][i]==10) && (i<8) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i++;
            }
            if(i<8)
            if(duzlem[konum_x][i]>10)duzlem[konum_x][i]=0-duzlem[konum_x][i];


            i=konum_y-1;
            while( (duzlem[konum_x][i]==10) && (i>=0) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i--;
            }
            if(i>=0)
            if(duzlem[konum_x][i]>10)duzlem[konum_x][i]=0-duzlem[konum_x][i];

        break;
        }

        case 3: //at
        {
            if( ( konum_x-1>=0 && konum_x-1<8 ) && ( konum_y+2>=0 && konum_y+2<8 ) )
            if( duzlem[konum_x-1][konum_y+2]>=10 ) duzlem[konum_x-1][konum_y+2]=0-duzlem[konum_x-1][konum_y+2];//0

            if( ( konum_x-2>=0 && konum_x-2<8 ) && ( konum_y+1>=0 && konum_y+1<8 ) )
            if( duzlem[konum_x-2][konum_y+1]>=10 ) duzlem[konum_x-2][konum_y+1]=0-duzlem[konum_x-2][konum_y+1];//1

            if( ( konum_x-2>=0 && konum_x-2<8 ) && ( konum_y-1>=0 && konum_y-1<8 ) )
            if( duzlem[konum_x-2][konum_y-1]>=10 ) duzlem[konum_x-2][konum_y-1]=0-duzlem[konum_x-2][konum_y-1];//2

            if( ( konum_x-1>=0 && konum_x-1<8 ) && ( konum_y-2>=0 && konum_y-2<8 ) )
            if( duzlem[konum_x-1][konum_y-2]>=10 ) duzlem[konum_x-1][konum_y-2]=0-duzlem[konum_x-1][konum_y-2];//3

            if( ( konum_x+1>=0 && konum_x+1<8 ) && ( konum_y-2>=0 && konum_y-2<8 ) )
            if( duzlem[konum_x+1][konum_y-2]>=10 ) duzlem[konum_x+1][konum_y-2]=0-duzlem[konum_x+1][konum_y-2];//4

            if( ( konum_x+2>=0 && konum_x+2<8 ) && ( konum_y-1>=0 && konum_y-1<8 ) )
            if( duzlem[konum_x+2][konum_y-1]>=10 ) duzlem[konum_x+2][konum_y-1]=0-duzlem[konum_x+2][konum_y-1];//5

            if( ( konum_x+2>=0 && konum_x+2<8 ) && ( konum_y+1>=0 && konum_y+1<8 ) )
            if( duzlem[konum_x+2][konum_y+1]>=10 ) duzlem[konum_x+2][konum_y+1]=0-duzlem[konum_x+2][konum_y+1];//6

            if( ( konum_x+1>=0 && konum_x+1<8 ) && ( konum_y+2>=0 && konum_y+2<8 ) )
            if( duzlem[konum_x+1][konum_y+2]>=10 ) duzlem[konum_x+1][konum_y+2]=0-duzlem[konum_x+1][konum_y+2];//7

        break;
        }

        case 4://fil
        {
            i=konum_x+1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i<8 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j++;
            }
            if( i<8 && j<8 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i>=0 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j++;
            }
            if( i>=0 && j<8 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y-1;
            while( (duzlem[i][j]==10) && ( i>=0 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j--;
            }
            if( i>=0 && j>=0 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x+1; j=konum_y-1;
            while( ( duzlem[i][j]==10 ) && ( i<8 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j--;
            };
            if( i<8 && j>=0 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];

        break;
        }

        case 5://vezir
        {
            i=konum_x+1;
            while( (duzlem[i][konum_y]==10) && (i<8) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i++;
            }
            if(i<8)
            if(duzlem[i][konum_y]>10) duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_x-1;
            while( (duzlem[i][konum_y]==10) && (i>=0) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i--;
            }
            if(i>=0)
            if(duzlem[i][konum_y]>10)duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_y+1;
            while( (duzlem[konum_x][i]==10) && (i<8) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i++;
            }
            if(i<8)
            if(duzlem[konum_x][i]>10)duzlem[konum_x][i]=0-duzlem[konum_x][i];


            i=konum_y-1;
            while( (duzlem[konum_x][i]==10) && (i>=0) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i--;
            }
            if(i>=0)
            if(duzlem[konum_x][i]>10)duzlem[konum_x][i]=0-duzlem[konum_x][i];

             i=konum_x+1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i<8 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j++;
            }
            if( i<8 && j<8 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i>=0 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j++;
            }
            if( i>=0 && j<8 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y-1;
            while( (duzlem[i][j]==10) && ( i>=0 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j--;
            }
            if( i>=0 && j>=0 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x+1; j=konum_y-1;
            while( ( duzlem[i][j]==10 ) && ( i<8 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j--;
            };
            if( i<8 && j>=0 )
            if(duzlem[i][j]>10) duzlem[i][j]=0-duzlem[i][j];

        break;
        }

        case 6://sah
        {
            if( duzlem[konum_x-1][konum_y-1]>=10 ) duzlem[konum_x-1][konum_y-1]=0-duzlem[konum_x-1][konum_y-1];

            if( duzlem[konum_x-1][konum_y]>=10 ) duzlem[konum_x-1][konum_y]=0-duzlem[konum_x-1][konum_y];

            if( duzlem[konum_x-1][konum_y+1]>=10 ) duzlem[konum_x-1][konum_y+1]=0-duzlem[konum_x-1][konum_y+1];

            if( duzlem[konum_x][konum_y-1]>=10 ) duzlem[konum_x][konum_y-1]=0-duzlem[konum_x][konum_y-1];

            if( duzlem[konum_x][konum_y+1]>=10 ) duzlem[konum_x][konum_y+1]=0-duzlem[konum_x][konum_y+1];

            if( duzlem[konum_x+1][konum_y-1]>=10 ) duzlem[konum_x+1][konum_y-1]=0-duzlem[konum_x+1][konum_y-1];

            if( duzlem[konum_x+1][konum_y]>=10 ) duzlem[konum_x+1][konum_y]=0-duzlem[konum_x+1][konum_y];

            if( duzlem[konum_x+1][konum_y+1]>=10 ) duzlem[konum_x+1][konum_y+1]=0-duzlem[konum_x+1][konum_y+1];

        break;
        }

        case 11: //piyon
        {
            if(konum_x>=0)  duzlem[konum_x-1][konum_y]=0-duzlem[konum_x-1][konum_y];

            if(konum_x==6) duzlem[konum_x-2][konum_y]=0-duzlem[konum_x-2][konum_y];

            if(duzlem[konum_x-1][konum_y+1]<10) duzlem[konum_x-1][konum_y+1]=0-duzlem[konum_x-1][konum_y+1];
            if(duzlem[konum_x-1][konum_y-1]<10) duzlem[konum_x-1][konum_y-1]=0-duzlem[konum_x-1][konum_y-1];

        break;
        }

        case 12: //kale
        {
            i=konum_x+1;
            while( (duzlem[i][konum_y]==10) && (i<8) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i++;
            }
            if(i<8)
            if(duzlem[i][konum_y]<10) duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_x-1;
            while( (duzlem[i][konum_y]==10) && (i>=0) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i--;
            }
            if(i>=0)
            if(duzlem[i][konum_y]<10)duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_y+1;
            while( (duzlem[konum_x][i]==10) && (i<8) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i++;
            }
            if(i<8)
            if(duzlem[konum_x][i]<10)duzlem[konum_x][i]=0-duzlem[konum_x][i];


            i=konum_y-1;
            while( (duzlem[konum_x][i]==10) && (i>=0) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i--;
            }
            if(i>=0)
            if(duzlem[konum_x][i]<10)duzlem[konum_x][i]=0-duzlem[konum_x][i];

        break;
        }

        case 13: //at
        {
            if( ( konum_x-1>=0 && konum_x-1<8 ) && ( konum_y+2>=0 && konum_y+2<8 ) )
            if( duzlem[konum_x-1][konum_y+2]<=10 ) { //printf("bir\n");
            duzlem[konum_x-1][konum_y+2]=0-duzlem[konum_x-1][konum_y+2]; }//0

            if( ( konum_x-2>=0 && konum_x-2<8 ) && ( konum_y+1>=0 && konum_y+1<8 ) )
            if( duzlem[konum_x-2][konum_y+1]<=10 ) { //printf("iki\n");
            duzlem[konum_x-2][konum_y+1]=0-duzlem[konum_x-2][konum_y+1]; }//1

            if( ( konum_x-2>=0 && konum_x-2<8 ) && ( konum_y-1>=0 && konum_y-1<8 ) )
            if( duzlem[konum_x-2][konum_y-1]<=10 ) { //printf("uc\n");
            duzlem[konum_x-2][konum_y-1]=0-duzlem[konum_x-2][konum_y-1]; }//2

            if( ( konum_x-1>=0 && konum_x-1<8 ) && ( konum_y-2>=0 && konum_y-2<8 ) )
            if( duzlem[konum_x-1][konum_y-2]<=10 ) { //printf("dort\n");
            duzlem[konum_x-1][konum_y-2]=0-duzlem[konum_x-1][konum_y-2]; }//3

            if( ( konum_x+1>=0 && konum_x+1<8 ) && ( konum_y-2>=0 && konum_y-2<8 ) )
            if( duzlem[konum_x+1][konum_y-2]<=10 ) { //printf("bes\n");
            duzlem[konum_x+1][konum_y-2]=0-duzlem[konum_x+1][konum_y-2]; }//4

            if( ( konum_x+2>=0 && konum_x+2<8 ) && ( konum_y-1>=0 && konum_y-1<8 ) )
            if( duzlem[konum_x+2][konum_y-1]<=10 ) { //printf("alti\n");
            duzlem[konum_x+2][konum_y-1]=0-duzlem[konum_x+2][konum_y-1]; }//5

            if( ( konum_x+2>=0 && konum_x+2<8 ) && ( konum_y+1>=0 && konum_y+1<8 ) )
            if( duzlem[konum_x+2][konum_y+1]<=10 ) { //printf("yedi\n");
            duzlem[konum_x+2][konum_y+1]=0-duzlem[konum_x+2][konum_y+1]; }//6

            if( ( konum_x+1>=0 && konum_x+1<8 ) && ( konum_y+2>=0 && konum_y+2<8 ) )
            if( duzlem[konum_x+1][konum_y+2]<=10 ) { //printf("sekiz\n");
            duzlem[konum_x+1][konum_y+2]=0-duzlem[konum_x+1][konum_y+2]; }//7

        break;
        }

        case 14://fil
        {
            i=konum_x+1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i<8 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j++;
            }
            if( i<8 && j<8 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i>=0 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j++;
            }
            if( i>=0 && j<8 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y-1;
            while( (duzlem[i][j]==10) && ( i>=0 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j--;
            }
            if( i>=0 && j>=0 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x+1; j=konum_y-1;
            while( ( duzlem[i][j]==10 ) && ( i<8 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j--;
            };
            if( i<8 && j>=0 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];

        break;
        }

        case 15:
        {
            i=konum_x+1;
            while( (duzlem[i][konum_y]==10) && (i<8) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i++;
            }
            if(i<8)
            if(duzlem[i][konum_y]<10) duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_x-1;
            while( (duzlem[i][konum_y]==10) && (i>=0) )
            {
                duzlem[i][konum_y]=0-duzlem[i][konum_y];
                i--;
            }
            if(i>=0)
            if(duzlem[i][konum_y]<10)duzlem[i][konum_y]=0-duzlem[i][konum_y];


            i=konum_y+1;
            while( (duzlem[konum_x][i]==10) && (i<8) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i++;
            }
            if(i<8)
            if(duzlem[konum_x][i]<10)duzlem[konum_x][i]=0-duzlem[konum_x][i];


            i=konum_y-1;
            while( (duzlem[konum_x][i]==10) && (i>=0) )
            {
                duzlem[konum_x][i]=0-duzlem[konum_x][i];
                i--;
            }
            if(i>=0)
            if(duzlem[konum_x][i]<10)duzlem[konum_x][i]=0-duzlem[konum_x][i];


            i=konum_x+1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i<8 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j++;
            }
            if( i<8 && j<8 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y+1;
            while( (duzlem[i][j]==10) && ( i>=0 && j<8 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j++;
            }
            if( i>=0 && j<8 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x-1; j=konum_y-1;
            while( (duzlem[i][j]==10) && ( i>=0 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i--;j--;
            }
            if( i>=0 && j>=0 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];


            i=konum_x+1; j=konum_y-1;
            while( ( duzlem[i][j]==10 ) && ( i<8 && j>=0 ) )
            {
                duzlem[i][j]=0-duzlem[i][j];
                i++;j--;
            };
            if( i<8 && j>=0 )
            if(duzlem[i][j]<10) duzlem[i][j]=0-duzlem[i][j];

        break;
        }

        case 16://sah
        {
            if( duzlem[konum_x-1][konum_y-1]<=10 ) duzlem[konum_x-1][konum_y-1]=0-duzlem[konum_x-1][konum_y-1];

            if( duzlem[konum_x-1][konum_y]<=10 ) duzlem[konum_x-1][konum_y]=0-duzlem[konum_x-1][konum_y];

            if( duzlem[konum_x-1][konum_y+1]<=10 ) duzlem[konum_x-1][konum_y+1]=0-duzlem[konum_x-1][konum_y+1];

            if( duzlem[konum_x][konum_y-1]<=10 ) duzlem[konum_x][konum_y-1]=0-duzlem[konum_x][konum_y-1];

            if( duzlem[konum_x][konum_y+1]<=10 ) duzlem[konum_x][konum_y+1]=0-duzlem[konum_x][konum_y+1];

            if( duzlem[konum_x+1][konum_y-1]<=10 ) duzlem[konum_x+1][konum_y-1]=0-duzlem[konum_x+1][konum_y-1];

            if( duzlem[konum_x+1][konum_y]<=10 ) duzlem[konum_x+1][konum_y]=0-duzlem[konum_x+1][konum_y];

            if( duzlem[konum_x+1][konum_y+1]<=10 ) duzlem[konum_x+1][konum_y+1]=0-duzlem[konum_x+1][konum_y+1];

        break;
        }
    }

}

