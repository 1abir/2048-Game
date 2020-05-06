#include "iGraphics.h"
int a4[4][4]= {{0,0,0,2},{0,0,0,0},{0,0,0,0},{4,0,0,0}}, b4[4][4];
int a[3][3]= {{0,0,4},{0,0,0},{2,0,0}};
int b[3][3],undo_a[3][3],undo_a4[4][4];
int p,q;
int gameOver=0,win=0,level=3,start=1,undo_var=1;




/*/int randomInt()
{
    time_t t;
    srand((unsigned)time(&t));
    return rand();

}/*/
void savefile()
{
	int i,j;
	if(level==3)
	{
		FILE *fp;
		fp=fopen("file3.txt","w");
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				fprintf(fp,"%d\n",a[i][j]);

			}
		}
		fclose(fp);

	}
	else if(level==4)
	{
		FILE *fp4;
		fp4=fopen("file4.txt","w");
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				fprintf(fp4,"%d\n",a4[i][j]);

			}
		}
		fclose(fp4);

	}
}
void print_file()
{
	int i,j,temp;
	if(level==3)
	{
		FILE *fp;
		fp=fopen("file3.txt","r");
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				fscanf(fp,"%d",&temp);
				a[i][j]=temp;

			}
		}
		fclose(fp);

	}
	else if(level==4)
	{
		FILE *fp4;
		fp4=fopen("file4.txt","r");
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				fscanf(fp4,"%d",&temp);
				a4[i][j]=temp;

			}
		}
		fclose(fp4);

	}
}



void undoArray4()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            undo_a4[i][j]=a4[i][j];
}
void undoArray()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        undo_a[i][j]=a[i][j];
}
void undo(){
	if(level==3)
	{
		int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
          a[i][j]=undo_a[i][j];
	}
	else if(level==4)
	{
		int i,j;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				a4[i][j]=undo_a4[i][j];
	}
		



	
}
int taim()
{
    //time_t t = time(NULL);
   // struct tm tm = *localtime(&t);
    //if(((tm.tm_sec)%50)>=35)
	if(((rand())%50)>=35)
    {
        return 4;
    }
    else
    {
        return 2;
    }
}
void copyArray()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        b[i][j]=a[i][j];
}
int checkArray()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        if(b[i][j]!=a[i][j])
            return 1;
            return 0;
}

void addnum()
{
    int i,j,c,d=0,k=0;
	int flag = 0;
    for(i=0; i<3; i++)
    {

        for(j=0; j<3; j++)
        {
            if(a[i][j]==0)
            {
			d++;
			}
		
        }
	

    }
	 if(d!=0)
    {
    int adarray_x[9],adarray_y[9];
     for(i=0; i<3; i++)
    {

        for(j=0; j<3; j++)
        {
            if(a[i][j]==0)
            {

                adarray_x[k]=i;
                adarray_y[k]=j;
                k++;

            }
        }

    }
	 c=rand()%d;
    a[adarray_x[c]][adarray_y[c]]=taim();
    }


}
void check_rightrotate()
{
    int t;
    t=b[0][0],b[0][0]=b[0][2],b[0][2]=t;
    t=b[0][0],b[0][0]=b[2][2],b[2][2]=t;
    t=b[0][0],b[0][0]=b[2][0],b[2][0]=t;
    t=b[0][1],b[0][1]=b[1][2],b[1][2]=t;
    t=b[0][1],b[0][1]=b[2][1],b[2][1]=t;
    t=b[0][1],b[0][1]=b[1][0],b[1][0]=t;

}

void rightrotate()
{
    int t;
    t=a[0][0],a[0][0]=a[0][2],a[0][2]=t;
    t=a[0][0],a[0][0]=a[2][2],a[2][2]=t;
    t=a[0][0],a[0][0]=a[2][0],a[2][0]=t;
    t=a[0][1],a[0][1]=a[1][2],a[1][2]=t;
    t=a[0][1],a[0][1]=a[2][1],a[2][1]=t;
    t=a[0][1],a[0][1]=a[1][0],a[1][0]=t;

}
void check_leftslide()
{
    int i;

    for(i=0; i<3; i++)
    {
        if(b[i][0]==0)
        {
            b[i][0]=b[i][1];
            b[i][1]=b[i][2];
            b[i][2]=0;
            if(b[i][0]==0)
            {
                b[i][0]=b[i][1];
                b[i][1]=0;
            }
            else if(b[i][0]==b[i][1])
            {
                b[i][0]=b[i][0]+b[i][0];
                b[i][1]=0;
            }
        }
        else if(b[i][1]==0)
        {
            if(b[i][0]==b[i][2])
            {
                b[i][0]=b[i][0]+b[i][0];
                b[i][2]=0;

            }
			else
			{
				b[i][1]=b[i][2];
				b[i][2]=0;
			}


        }
        else if(b[i][0]==b[i][1])
        {
            b[i][0]=b[i][0]+b[i][0];
            b[i][1]=b[i][2];
            b[i][2]=0;
        }
        else if(b[i][1]==b[i][2])
        {
            b[i][1]=b[i][1]+b[i][1];
            b[i][2]=0;
        }
    }
}

void leftslide()
{
    int i;

    for(i=0; i<3; i++)
    {
        if(a[i][0]==0)
        {
            a[i][0]=a[i][1];
            a[i][1]=a[i][2];
            a[i][2]=0;
            if(a[i][0]==0)
            {
                a[i][0]=a[i][1];
                a[i][1]=0;
            }
            else if(a[i][0]==a[i][1])
            {
                a[i][0]=a[i][0]+a[i][0];
                a[i][1]=0;
            }
        }
        else if(a[i][1]==0)
        {
            if(a[i][0]==a[i][2])
            {
                a[i][0]=a[i][0]+a[i][0];
                a[i][2]=0;

            }
			else
			{
				a[i][1]=a[i][2];
				a[i][2]=0;
			}


        }
        else if(a[i][0]==a[i][1])
        {
            a[i][0]=a[i][0]+a[i][0];
            a[i][1]=a[i][2];
            a[i][2]=0;
        }
        else if(a[i][1]==a[i][2])
        {
            a[i][1]=a[i][1]+a[i][1];
            a[i][2]=0;
        }
    }
}
void check_gameover()
{
	int c=0;
	copyArray();
	check_rightrotate();
	check_rightrotate();
	check_rightrotate();
	check_leftslide();
	check_rightrotate();
	if(checkArray()==0)
		c+=1;




	copyArray();
	check_rightrotate();
	check_rightrotate();
	check_leftslide();
	check_rightrotate();
	check_rightrotate();
	if(checkArray()==0)
		c+=1;



	copyArray();
	check_rightrotate();
	check_leftslide();
	check_rightrotate();
	check_rightrotate();
	check_rightrotate();
	if(checkArray()==0)
		c+=1;



	copyArray();
	check_leftslide();
	if(checkArray()==0)
		c+=1;
	if(c==4)
		gameOver=1;


}
void print_bmp()
{
	int i,x,y,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            switch(i)
            {



            case 0:
                y=517;
                break;

            case 1:
                y=261;
                break;


            case 2:
                y=5;
                break;

            }

            switch(j)
            {
            case 0:
                x=300 ;
                break;


            case 1:
                x=556;
                break;


            case 2:
                x=812;
                break;


            }
            switch(a[i][j])
            {
            case 0:
                iShowBMP(x, y, "0.2.bmp");
                break;
            case 2:
                iShowBMP(x, y, "2.2.bmp");
                break;
            case 4:
                iShowBMP(x, y, "4.2.bmp");
                break;
            case 8:
                iShowBMP(x, y, "8.2.bmp");
                break;
            case 16:
                iShowBMP(x, y, "16.2.bmp");
                break;
            case 32:
                iShowBMP(x, y, "32.2.bmp");
                break;
            case 64:
                iShowBMP(x, y, "64.2.bmp");
                break;
            case 128:
                iShowBMP(x, y, "128.2.bmp");
                break;
            case 256:
                iShowBMP(x, y, "256.2.bmp");
                break;
            case 512:
                iShowBMP(x, y, "512.2.bmp");
                break;
            case 1024:
                iShowBMP(x, y, "1024.2.bmp");
                break;
            case 2048:
                iShowBMP(x, y, "2048.2.bmp");
                break;



            }


            if(a[i][j]==2048)
            {
                win=1;
            }
        }

    }
}

void copyArray4()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            b4[i][j]=a4[i][j];
}
int checkArray4()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(b4[i][j]!=a4[i][j])
                return 1;
    return 0;
}
void check_rightrotate4()
{
    int c_a[4][4];
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            switch (i)
            {
            case 0:
                c_a[j][i+3]=b4[i][j];
                break;
            case 1:
                c_a[j][i+1]=b4[i][j];
                break;
            case 2:

                c_a[j][i-1]=b4[i][j];
                break;
            case 3:
                c_a[j][i-3]=b4[i][j];
                break;
            }
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            b4[i][j]=c_a[i][j];

        }

    }
}
void  check_leftslide4()
{
    int i;

    for(i=0; i<4; i++)
    {
        if(b4[i][0]==0)
        {
            b4[i][0]=b4[i][1];
            b4[i][1]=b4[i][2];
            b4[i][2]=b4[i][3];
            b4[i][3]=0;
            if(b4[i][0]==0)
            {
                b4[i][0]=b4[i][1];
                b4[i][1]=b4[i][2];
                b4[i][2]=0;

                if(b4[i][0]==0)
                {
                    b4[i][0]=b4[i][1];
                    b4[i][1]=0;
                }
            }

            if(b4[i][0]==b4[i][1])
            {
                b4[i][0]=b4[i][0]+b4[i][0];
                b4[i][1]=b4[i][2];
                b4[i][2]=0;
            }
            else if(b4[i][1]==b4[i][2])
            {
                b4[i][1]=b4[i][1]+b4[i][2];
                b4[i][2]=0;
            }
        }
        else if(b4[i][1]==0)
        {
            b4[i][1]=b4[i][2];
            b4[i][2]=b4[i][3];
            b4[i][3]=0;

            if(b4[i][1]==0)
            {
                b4[i][1]=b4[i][2];
                b4[i][2]=0;
            }
            if(b4[i][0]==b4[i][1])
            {
                b4[i][0]=b4[i][0]+b4[i][0];
                b4[i][1]=b4[i][2];
                b4[i][2]=0;
            }
            else if(b4[i][1]==b4[i][2])
            {
                b4[i][1]=b4[i][1]+b4[i][2];
                b4[i][2]=0;
            }




        }
        else if(b4[i][2]==0)
        {
            b4[i][2]=b4[i][3];
            b4[i][3]=0;
            if(b4[i][0]==b4[i][1])
            {
                b4[i][0]=b4[i][0]+b4[i][0];
                b4[i][1]=b4[i][2];
                b4[i][2]=0;
            }
            else if(b4[i][1]==b4[i][2])
            {
                b4[i][1]=b4[i][1]+b4[i][2];
                b4[i][2]=0;
            }

        }
        else if(b4[i][3]==0)
        {
            if(b4[i][0]==b4[i][1])
            {
                b4[i][0]=b4[i][0]+b4[i][0];
                b4[i][1]=b4[i][2];
                b4[i][2]=0;
            }
            else if(b4[i][1]==b4[i][2])
            {
                b4[i][1]=b4[i][1]+b4[i][2];
                b4[i][2]=0;
            }
        }
        else if(b4[i][0]==b4[i][1])
        {
            b4[i][0]=b4[i][0]+b4[i][0];
            b4[i][1]=b4[i][2];
            b4[i][2]=b4[i][3];
            b4[i][3]=0;
            if(b4[i][1]==b4[i][2])
            {
                b4[i][1]=b4[i][1]+b4[i][1];
                b4[i][2]=0;
            }
        }
        else if(b4[i][1]==b4[i][2])
        {
            b4[i][1]=b4[i][1]+b4[i][1];
            b4[i][2]=b4[i][3];
            b4[i][3]=0;
        }
        else if(b4[i][2]==b4[i][3])
        {
            b4[i][2]=b4[i][3];
            b4[i][3]=0;
        }

    }
}
void rightrotate4()
{
    int c_a[4][4];
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            switch (i)
            {
            case 0:
                c_a[j][i+3]=a4[i][j];
                break;
            case 1:
                c_a[j][i+1]=a4[i][j];
                break;
            case 2:

                c_a[j][i-1]=a4[i][j];
                break;
            case 3:
                c_a[j][i-3]=a4[i][j];
                break;
            }
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            a4[i][j]=c_a[i][j];

        }

    }

}
void leftslide4()
{
    int i;

    for(i=0; i<4; i++)
    {
        if(a4[i][0]==0)
        {
            a4[i][0]=a4[i][1];
            a4[i][1]=a4[i][2];
            a4[i][2]=a4[i][3];
            a4[i][3]=0;
            if(a4[i][0]==0)
            {
                a4[i][0]=a4[i][1];
                a4[i][1]=a4[i][2];
                a4[i][2]=0;

                if(a4[i][0]==0)
                {
                    a4[i][0]=a4[i][1];
                    a4[i][1]=0;
                }
            }
			else if(a4[i][1]==0)
            {
                a4[i][1]=a4[i][2];
                a4[i][2]=0;
            }
            if(a4[i][0]==a4[i][1])
            {
                a4[i][0]=a4[i][0]+a4[i][0];
                a4[i][1]=a4[i][2];
                a4[i][2]=0;
            }
            else if(a4[i][1]==a4[i][2])
            {
                a4[i][1]=a4[i][1]+a4[i][2];
                a4[i][2]=0;
            }
        }
        else if(a4[i][1]==0)
        {
            a4[i][1]=a4[i][2];
            a4[i][2]=a4[i][3];
            a4[i][3]=0;

            if(a4[i][1]==0)
            {
                a4[i][1]=a4[i][2];
                a4[i][2]=0;
            }
            if(a4[i][0]==a4[i][1])
            {
                a4[i][0]=a4[i][0]+a4[i][0];
                a4[i][1]=a4[i][2];
                a4[i][2]=0;
            }
            else if(a4[i][1]==a4[i][2])
            {
                a4[i][1]=a4[i][1]+a4[i][2];
                a4[i][2]=0;
            }




        }
        else if(a4[i][2]==0)
        {
            a4[i][2]=a4[i][3];
            a4[i][3]=0;
            if(a4[i][0]==a4[i][1])
            {
                a4[i][0]=a4[i][0]+a4[i][0];
                a4[i][1]=a4[i][2];
                a4[i][2]=0;
            }
            else if(a4[i][1]==a4[i][2])
            {
                a4[i][1]=a4[i][1]+a4[i][2];
                a4[i][2]=0;
            }

        }
        else if(a4[i][3]==0)
        {
            if(a4[i][0]==a4[i][1])
            {
                a4[i][0]=a4[i][0]+a4[i][0];
                a4[i][1]=a4[i][2];
                a4[i][2]=0;
            }
            else if(a4[i][1]==a4[i][2])
            {
                a4[i][1]=a4[i][1]+a4[i][2];
                a4[i][2]=0;
            }
        }
        else if(a4[i][0]==a4[i][1])
        {
            a4[i][0]=a4[i][0]+a4[i][0];
            a4[i][1]=a4[i][2];
            a4[i][2]=a4[i][3];
            a4[i][3]=0;
            if(a4[i][1]==a4[i][2])
            {
                a4[i][1]=a4[i][1]+a4[i][1];
                a4[i][2]=0;
            }
        }
        else if(a4[i][1]==a4[i][2])
        {
            a4[i][1]=a4[i][1]+a4[i][1];
            a4[i][2]=a4[i][3];
            a4[i][3]=0;
        }
        else if(a4[i][2]==a4[i][3])
        {
            a4[i][2]=a4[i][3]+a4[i][2];
            a4[i][3]=0;
        }

    }
}
void check_gameover4()
{
	int c=0;
	copyArray4();
	check_rightrotate4();
	check_rightrotate4();
	check_rightrotate4();
	check_leftslide4();
	check_rightrotate4();
	if(checkArray4()==0)
		c+=1;




	copyArray4();
	check_rightrotate4();
	check_rightrotate4();
	check_leftslide4();
	check_rightrotate4();
	check_rightrotate4();
	if(checkArray4()==0)
		c+=1;



	copyArray4();
	check_rightrotate4();
	check_leftslide4();
	check_rightrotate4();
	check_rightrotate4();
	check_rightrotate4();
	if(checkArray4()==0)
		c+=1;



	copyArray4();
	check_leftslide4();
	if(checkArray4()==0)
		c+=1;
	if(c==4)
		gameOver=1;


}
/*void addnum4()
{
    int i,j,c,d;
	int flag = 0;
    for(i=0; i<4; i++)
    {

        for(j=0; j<4; j++)
        {
            if(a4[i][j]==0)
            {

                    c=rand()%3;
                    d=rand()%3;
                    if(a4[c][d]==0)
                    {

                        a4[c][d]=taim();
                        flag =1;
                        break;

                    }
				while(a4[c][d]!=0)
				{
					c=rand()%3;
                    d=rand()%3;
                    if(a4[c][d]==0)
                    {

                        a4[c][d]=taim();
                        flag =1;
						break;

                    }
				}

            }
			if(flag) break;
        }
		if(flag) break;

    }


}*/
void addnum4()
{
    int i,j,c,ct=0,k=0;
	int flag = 0;
    for(i=0; i<4; i++)
    {

        for(j=0; j<4; j++)
        {
            if(a4[i][j]==0)
            {

                ct++;

            }
        }

    }
	 if(ct!=0)
    {
    int adarray_x4[16],adarray_y4[16];
     for(i=0; i<4; i++)
    {

        for(j=0; j<4; j++)
        {
            if(a4[i][j]==0)
            {

                adarray_x4[k]=i;
                adarray_y4[k]=j;
                k++;

            }
        }

    }
   
    c=rand()%ct;
    a4[adarray_x4[c]][adarray_y4[c]]=taim();
    }



}
void set_arrays(){
	for(p=0;p<3;p++)
					for(q=0;q<3;q++)
						a[p][q]=0;
				a[0][1]=2;
				a[1][0]=4;


				for(p=0;p<4;p++)
					for(q=0;q<4;q++)
						a4[p][q]=0;
				a4[3][0]=2;
				a4[0][1]=4;
				gameOver=0;
}


void print_bmp4()
{
	int i,x,y,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            switch(i)
            {



            case 0:
                y=528;
                break;

            case 1:
                y=400;
                break;


            case 2:
                y=272;
                break;
            case 3:
                y=144;
                break;

            }

            switch(j)
            {
            case 0:
                x=509 ;
                break;


            case 1:
                x=637;
                break;


            case 2:
                x=765;
                break;

            case 3:
                x=893;
                break;


            }
            switch(a4[i][j])
            {
            case 0:
                iShowBMP(x, y, "0.1.bmp");
                break;
            case 2:
                iShowBMP(x, y, "2.1.bmp");
                break;
            case 4:
                iShowBMP(x, y, "4.1.bmp");
                break;
            case 8:
                iShowBMP(x, y, "8.1.bmp");
                break;
            case 16:
                iShowBMP(x, y, "16.1.bmp");
                break;
            case 32:
                iShowBMP(x, y, "32.1.bmp");
                break;
            case 64:
                iShowBMP(x, y, "64.1.bmp");
                break;
            case 128:
                iShowBMP(x, y, "128.1.bmp");
                break;
            case 256:
                iShowBMP(x, y, "256.1.bmp");
                break;
            case 512:
                iShowBMP(x, y, "512.1.bmp");
                break;
            case 1024:
                iShowBMP(x, y, "1024.1.bmp");
                break;
            case 2048:
                iShowBMP(x, y, "2048.1.bmp");
                break;



            }


            if(a4[i][j]==2048)
            {
                win=1;
            }
        }

    }
}
void iDraw() {
	//place your drawing codes here
	//iClear();

	iClear();

    iShowBMP(0, 0, "background.bmp");

	if(level==4)
        print_bmp4();

	else if(level==3)
		print_bmp();

	if(undo_var==1)
	{
		undoArray();
		undoArray4();
		undo_var=0;
	}


    if(gameOver)
    {
        //iSetColor(255, 255, 255);
        //iText(500,450,"GAME OVER",  GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP(1199,499, "gameover.bmp");

		iShowBMP(29,499, "RESTART.bmp");

		iShowBMP(1199,99, "exit.bmp");

    }
	if(gameOver==0)
	{
		iShowBMP(1199,499, "undo1.bmp");
		iShowBMP(99,99, "save&exit.bmp");
	}
    if(win)
    {
        iShowBMP(600,349, "win.bmp");
    }
	if(start==2)
	{
		iShowBMP(0, 0, "background.bmp");
		iShowBMP(299,399,"new_game.bmp");
		iShowBMP(599,399,"saved_game.bmp");
	}

		
	if(start==1)
	{
		
		iShowBMP(0, 0, "background.bmp");
		iShowBMP(299,399,"level.bmp");
		iShowBMP(99,99,"3x3.bmp");
		iShowBMP(599,99,"4x4.bmp");
	}

	//iSetColor(20, 200, 200);
	//iFilledCircle(x, y, r);
	//iFilledRectangle(10, 30, 20, 20);
	//iSetColor(20, 200, 0);
	//iText(40, 40, "Hi, I am iGraphics");
}

void iMouseMove(int mx, int my) {
	//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
	//	x += 10;
	//	y += 10;

		if(mx>=29&&mx<=328&&my>=499&&my<=665){
			if(gameOver){
				
			set_arrays();
			start=1;
				//exit(0);
			}
			
		}
		else if(mx>=1199&&mx<=1397&&my>=99&&my<=198){
			if(gameOver){
				
		//	set_arrays();
				exit(0);
			}
		}
		if(gameOver==0){

		    if(mx<=1199&&mx>=1098&&my>=499&&my<=597){
			
				
		//	set_arrays();
				undo();
			}
			else if(mx>=99&&mx<=248&&my>=99&&my<=198)
			{
				if(start==0)
				{
					savefile();
					exit(0);
				}
			}

		}
		if(start==1)
		{
			if(mx>=99&&mx<=449&&my>=99&&my<=349)
			{
				level=3;
				start=2;
			}
			else if(mx>=599&&mx<=849&&my>=99&&my<=349)
			{
				level=4;
				start=2;
			}
		}
		else if(start==2)
		{
			if(mx>=299&&mx<=648&&my>=399&&my<=549)
			{
				start=0;

			}
			else if(mx>=599&&mx<=948&&my>=399&&my<=549)
			{
				print_file();
				start=0;
			}
		}




		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
	//	x -= 10;
	//	y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {


	if(level==3){
	
		if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        copyArray();
		undoArray();

       leftslide();
        if(checkArray())addnum();

		check_gameover();
    }
    if(key == GLUT_KEY_RIGHT)
    {
        copyArray();
		undoArray();
        rightrotate();
        rightrotate();
        leftslide();
        rightrotate();
        rightrotate();
        if(checkArray())addnum();

		check_gameover();
    }
    if(key == GLUT_KEY_UP)
    {
        copyArray();
		undoArray();
        rightrotate();
        rightrotate();
        rightrotate();
        leftslide();
        rightrotate();
        if(checkArray())addnum();

		check_gameover();
    }
    if(key == GLUT_KEY_DOWN)
    {
        copyArray();
		undoArray();
        rightrotate();
        leftslide();
        rightrotate();
        rightrotate();
        rightrotate();
        if(checkArray())addnum();

		check_gameover();
    }
	
	}

	else{
	if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        copyArray4();
		undoArray4();
       leftslide4();
        if(checkArray4())addnum4();

		check_gameover4();
    }
    if(key == GLUT_KEY_RIGHT)
    {
        copyArray4();
		undoArray4();
        rightrotate4();
        rightrotate4();
        leftslide4();
        rightrotate4();
        rightrotate4();
        if(checkArray4())addnum4();

		check_gameover4();
    }
    if(key == GLUT_KEY_UP)
    {
        copyArray4();
		undoArray4();
        rightrotate4();
        rightrotate4();
        rightrotate4();
        leftslide4();
        rightrotate4();
        if(checkArray4())addnum4();

		check_gameover4();
    }
    if(key == GLUT_KEY_DOWN)
    {
        copyArray4();
		undoArray4();
        rightrotate4();
        leftslide4();
        rightrotate4();
        rightrotate4();
        rightrotate4();
        if(checkArray4())addnum4();

		check_gameover4();
    }
	}
	//place your codes for other keys here
}
int main() {
	//place your own initialization codes here.
	iInitialize(1530, 800, "2048");
	return 0;
}
