#include <iostream>
#include <cstdio>

using namespace std;

class calender{

public :
    calender(int year)
    {
        int i=0;
        for(i=1;i<=12;i++)
        {
            showCalender(i, year);
            printf("\n");
        }
    }
    calender(int month, int year)
    {
        showCalender(month,year);
    }

    int getDay(int date, int month, int year)
    {
        int monthc, yearc, centuryc,centuryx, lyearc,day;
        if(month==1)
        {
            monthc=0;
        }
        else if(month==2)
        {
            monthc=3;
        }
        else if(month==3)
        {
            monthc=3;
        }
        else if(month==4)
        {
            monthc=6;
        }
        else if(month==5)
        {
            monthc=1;
        }
        else if(month==6)
        {
            monthc=4;
        }
        else if(month==7)
        {
            monthc=6;
        }
        else if(month==8)
        {
            monthc=2;
        }
        else if(month==9)
        {
            monthc=5;
        }
        else if(month==10)
        {
            monthc=0;
        }
        else if(month==11)
        {
            monthc=3;
        }
        else if(month==12)
        {
            monthc=5;
        }

        yearc=(year+(year/4))%7;
     
        centuryx=(year-(year%100));
     
        if(centuryx==1700)
        {
            centuryc=4;
        }
        else if(centuryx==1800)
        {
            centuryc=2;
        }
        else if(centuryx==1900)
        {
            centuryc=0;
        }
        else if(centuryx==2000)
        {
            centuryc=6;
        }
        else if(centuryx==2100)
        {
            centuryc=4;
        }
        else if(centuryx==2200)
        {
            centuryc=8;
        }
        else if(centuryx==2300)
        {
            centuryc=0;
        }

        lyearc=0;

        if((year%4==0&&year%100!=0)||(year%4==0&&year%100==0&&year%400==0))
        {
            if(month==1||month==2)
            {
                lyearc=1;
            }
        }
        
        day=(yearc-lyearc+date+monthc+centuryc)%7;
        
        return day;
    }

    int showCalender(int month, int year)
    {
        int iday=getDay(1,month, year);
        int calender[6][6]={0};
        int lday=1,i,j,flag=0;;
        
        printf("\nCalculator Of Month : %d / %d\n", month, year);
        printf("\n____________________________________________________________________________________");
        printf("\n|   Sunday  |  Monday   |  Tuesday  | Wednesday | Thursday  |  Friday   | Saturday  |");
        printf("\n|___________|___________|___________|___________|___________|___________|___________|\n");
        
        int k;
        
        for(i=0;i<=6;i++)
        {
            for(k=0;k<=2;k++)
            {
                for(j=1;j<=7;j++)
                {
                    int l=1;
                    
                    if(iday==0&&i==0&&j<7)
                    {
                        printf("|___________");
                    }

                    else if(j<iday&&i==0&&iday!=0)
                    {
                        printf("|___________");
                    }
                    else
                    {
                      calender[i][j-l]=lday;
                      if(k==1)
                      {
                        if(calender[i][j-l]%10==calender[i][j-l])
                        {
                            if(j==7)
                            {
                                printf("|     %d     |", calender[i][j-l]);
                            }
                            else 
                            {
                                printf("|     %d     ", calender[i][j-l]);
                            }
                        }
                        else
                        {
                        if(j==7)
                        {
                            printf("|     %d    |", calender[i][j-l]);
                        }
                        else
                        {
                            printf("|     %d    ", calender[i][j-l]);
                        }
                        }
                lday++;

            if(lday>30&&(month==4||month==6||month==9||month==11))
            {
                flag=1;
                break;
            }
            if(lday>31&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
            {
                flag=1;break;
            }
            else if(lday>28&&month==2)
            {
                flag=1;break;
            }
            }
            
            else if(k==2)
            {
                if(j==7)
                {
                    printf("|___________|");
                }
                    else {
                        printf("|___________");
                        }
            }
                else 
                {
                    if(j==7)
                    {
                        printf("|           |");
                    }
                    else printf("|           ");
                }
            }
            }
            printf("\n");
            }
            if(flag==1)
            {
                break;
            }
        }
    return 0;
}
};


int main(void)
{

int date, month, year;

cout <<  endl << "Enter Month(0 to show All) : ";
cin >> month;

cout << endl << "Enter Year : ";
cin >> year;

if(month==0)
{
    calender obj(year);
}
else
{
    calender obj(month,year);
}

return 0;
}