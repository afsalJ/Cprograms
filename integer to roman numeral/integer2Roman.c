#include<stdio.h>

int considerations(int number,int integer)
{
    int considered_numbers[]={1,10,100};
    int considers[3][2]={{5,10},{50,100},{500,1000}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(considers[i][j]==number)
            {
                if(number-integer<=considered_numbers[i] && number-integer>0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void roman_identifier(int integer)
{
    int temp=integer;
    int considered_numbers[]={1,10,100};
    char considered_numbers_numerals[]={'I','X','C'};
    int numbers[]={5,10,50,100,500,1000};
    char numerals[]={'V','X','L','C','D','M'};
    // int integer;
    char roman[100];
    for(int j=0;j<100;j++)
    {
        roman[j]=' ';
    }
    int iRoman=0;
    int main_choice_maker;
    // printf("ENTER THE NUMBER:(<1899)");
    // scanf("%d", &integer);
    for(int i=5;integer>9;i--)
    {
        main_choice_maker=considerations(numbers[i],integer);
        // printf("%d\n", main_choice_maker);
        if(i<5 && considerations(numbers[i+1],integer) && (!main_choice_maker))
        {
            roman[iRoman++]=considered_numbers_numerals[i/2];
            roman[iRoman++]=numerals[i+1];
            integer=((integer+considered_numbers[i/2])%numbers[i+1]);
            i-=1;
        }
        else if(main_choice_maker)
        {
            roman[iRoman++]=considered_numbers_numerals[i/2];
            roman[iRoman++]=numerals[i];
            integer=((integer+considered_numbers[i/2])%numbers[i]);
        }
        else
        {
            int n_of_times=integer/numbers[i];
            for(int j=0;j<n_of_times;j++)
            {
                roman[iRoman++]=numerals[i];
            }
            integer=(integer%numbers[i]);
        }
    }
    if(integer==9)
    {
        roman[iRoman++]='I';
        roman[iRoman++]='X';
    }
    else if(integer==4)
    {
        roman[iRoman++]='I';
        roman[iRoman++]='V';
    }
    else 
    {
        int n_of_times=integer/5;
        for(int j=0;j<n_of_times;j++)
        {
            roman[iRoman++]='V';
        }
        integer=integer%5;
        for(int j=0;j<integer;j++)
        {
            roman[iRoman++]='I';
        }
    }
    printf("%d==",temp);
    for(int i=0;i<iRoman;i++)
    {   
        printf("%c", roman[i]);
    }
    printf("\n");
    return;
}
/*
991
1000,1559->cosideration
            1000-991=9<100 && 9>0 ->1
        
*/
int main()
{
    int integer;
    printf("ENTER THE NUMBER(<5000):");
    scanf("%d", &integer);
    roman_identifier(integer);
    return 0;
}