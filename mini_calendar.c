#include <stdio.h>
#include <stdbool.h>
int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year);
void add_days_to_date(int* dd, int* mm, int* yy, int days_left_to_add );


int main(void)
{
  //testing if leap year works
  /*int year;
  printf("please insert a number between 1800 and 10000\n ");


  scanf("%d", &year );

  if (is_leap_year(year))
  {
    printf("Leap Year\n");
  }
  else
  {
    printf("Not Leap Year\n");
  }*/

  int mm;
  int dd;
  int yy;
  int days_left_to_add;

  printf("Please enter a date between the years 1800 and 10000 in the format dd
  mm yyyy and provide the number of days to add to this date:\n");
  scanf("%d %d %d %d",&dd, &mm, &yy, &days_left_to_add);

  add_days_to_date(&dd, &mm, &yy, days_left_to_add);

  printf("%02d / %02d / %04d\n", dd, mm, yy);

}
bool is_leap_year(int year)
{
  // a leap year can be devided by four but not by 100 except if it
  //can be devided by 400
  if (year % 4 == 0)
  {
    if (year %400 == 0)
    {
      return true;
    }
    else if (year % 100 != 0)
    {
      return true;
    }
  }
  else
  {
    return false;
  }
}
void add_days_to_date(int* dd, int* mm, int* yy, int days_left_to_add )
{
  //calculate days left this month
  int days_left_in_month;

  //loop of days left
  while(days_left_to_add > 0)
  {
    // [*mm -1] because first months index is 0
    days_left_in_month = days_in_month[(*mm - 1)] - *dd;
    if (*mm == 2 && is_leap_year(*yy))
    {
      days_left_in_month +=1;
    }
    if (days_left_to_add > days_left_in_month)
    {
      days_left_to_add = days_left_to_add - days_left_in_month -1;
      *dd = 1;
      if (*mm == 12)
      {
        *mm = 1;
        *yy += 1;
      }
      else
      {
        *mm += 1;
      }
    }
    else
    {
      *dd += days_left_to_add;
      days_left_to_add = 0;
    }
  }
}
