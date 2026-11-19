#include<stdio.h>
#include<string.h>
void swap(char a[], char b[]) {
    char temp[11];  
    int i = 0;

   
    while (a[i] != '\0') {
        temp[i] = a[i];
        i++;
    }
    temp[i] = '\0';

 
    i = 0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';


    i = 0;
    while (temp[i] != '\0') {
        b[i] = temp[i];
        i++;
    }
    b[i] = '\0';
}

int main()
{
    int n;
    printf("How many date you want to sort");
    scanf("%d",&n);
    char date[n][11];
    printf("Enter date\n");
    for(int i=0;i<n;i++)
    {
       scanf("%s",&date[i]);
    }
     for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++){
                    if(date[i][6]>date[j][6])
                    {
                        swap(date[i],date[j]);
                    }

                        else if(date[i][6]==date[j][6])
                        {
                            if(date[i][7]>date[j][7])
                        {
                            swap(date[i],date[j]);
                        }
                                        else if(date[i][7]==date[j][7])
                                        {
                                        if(date[i][8]>date[j][8])
                                        {
                                            swap(date[i],date[j]);
                                        }
                                            else if(date[i][8]==date[j][8])
                                            {
                                                if(date[i][9]>date[j][9])
                                            {
                                                swap(date[i],date[j]);
                                            }
                                                else if(date[i][9]==date[j][9])
                                                {
                                                if(date[i][3]>date[j][3])
                                                {
                                                    swap(date[i],date[j]);
                                                }
                                    else if(date[i][3]==date[j][3])
                                    {
                                    if(date[i][4]>date[j][4])
                                    {
                                        swap(date[i],date[j]);
                                    }
                            else if(date[i][4]==date[j][4])
                            {
                                if(date[i][0]>date[j][0])
                            {
                                swap(date[i],date[j]);
                            }
                    else if(date[i][0]==date[j][0])
                    {
                        if(date[i][1]>date[j][1])
                    {
                        swap(date[i],date[j]);
                    }
                    }
                }
              }
            }
           }
         }
        }
    }
 }    

        
     for(int i=0;i<n;i++)
    {
        printf("%s\n",date[i]);
    }
    
}