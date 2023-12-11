//C program for LRU replacement algorithm implementation
 
#include <stdio.h>
 
//user-defined function
int findLRU(int time[], int n)
{
   int i, minimum = time[0], pos = 0;
 
   for (i = 1; i < n; ++i)
   {
      if (time[i] < minimum)
      {
         minimum = time[i];
         pos = i;
      }
   }
 
   return pos;
}
 
//main function
int main()
{
   int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, LRUflag2, i, j, pos, faults = 0;
   printf("Enter number of frames: ");
   scanf("%d", &no_of_frames);
 
   printf("Enter number of pages: ");
   scanf("%d", &no_of_pages);
 
   printf("Enter reference string: ");
 
   for (i = 0; i < no_of_pages; ++i)
   {
      scanf("%d", &pages[i]);
   }
 
   for (i = 0; i < no_of_frames; ++i)
   {
      frames[i] = -1;
   }
 	printf("\n F1 \t F2 \tF3");
   for (i = 0; i < no_of_pages; ++i)
   {
      flag1 = LRUflag2 = 0;
 
      for (j = 0; j < no_of_frames; ++j)
      {
         if (frames[j] == pages[i])
         {
            counter++;
            time[j] = counter;
            flag1 = LRUflag2 = 1;
            break;
         }
      }
 
      if (flag1 == 0)
      {
         for (j = 0; j < no_of_frames; ++j)
         {
            if (frames[j] == -1)
            {
               counter++;
               faults++;
               frames[j] = pages[i];
               time[j] = counter;
               LRUflag2 = 1;
               break;
            }
         }
      }
 
      if (LRUflag2 == 0)
      {
         pos = findLRU(time, no_of_frames);
         counter++;
         faults++;
         frames[pos] = pages[i];
         time[pos] = counter;
      }
 
      printf("\n");
	  
      for (j = 0; j < no_of_frames; ++j)
      {
         printf("%d\t", frames[j]);
      }
   }
 
   printf("\nTotal Page Faults = %d", faults);
 
   return 0;
}
