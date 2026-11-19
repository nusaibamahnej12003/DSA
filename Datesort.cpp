#include<iostream>
using namespace std;


int main()
{
    char date[10][11];
    printf("Enter date\n");
    for(int i=0;i<10;i++)
    {
        cin>>date[i];
    }
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++){
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
         else if(date[i][6]==date[j][6])
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

        
     for(int i=0;i<10;i++)
    {
        cout<<date[i]<<endl;
    }
    
}