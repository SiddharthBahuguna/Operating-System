#include <stdio.h>
#include <stdlib.h>

int calculateSeekTime(int requestSequence[], int head, int n)
{
  int seekCount = 0;
  for (int i = 0; i < n; i++)
  {
    seekCount += abs(head - requestSequence[i]);
    head = requestSequence[i];
  }
  return seekCount;
}

int main()
{
  int n;
  printf("Enter the number of disk requests: ");
  scanf("%d", &n);

  int requestSequence[n];
  printf("Enter the disk request sequence:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &requestSequence[i]);
  }

  int initialHead;
  printf("Enter the initial position of the disk head: ");
  scanf("%d", &initialHead);

  int seekTime = calculateSeekTime(requestSequence, initialHead, n);

  printf("Total Seek Time using FCFS: %d\n", seekTime);

  return 0;
}
