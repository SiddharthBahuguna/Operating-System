#include <stdio.h>
#include <stdlib.h>

void sortRequestSequence(int requestSequence[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (requestSequence[j] > requestSequence[j + 1])
      {

        int temp = requestSequence[j];
        requestSequence[j] = requestSequence[j + 1];
        requestSequence[j + 1] = temp;
      }
    }
  }
}

int findNextRequestIndex(int requestSequence[], int head, int n)
{
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    if (requestSequence[i] >= head)
    {
      index = i;
      break;
    }
  }
  return index;
}

int calculateSeekTime(int requestSequence[], int head, int n, int direction)
{
  int seekCount = 0;
  sortRequestSequence(requestSequence, n);
  int nextRequestIndex = findNextRequestIndex(requestSequence, head, n);
  while (nextRequestIndex != -1)
  {
    seekCount += abs(head - requestSequence[nextRequestIndex]);
    head = requestSequence[nextRequestIndex];
    nextRequestIndex += direction;
    if (nextRequestIndex < 0 || nextRequestIndex >= n)
    {
      break;
    }
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
  int seekTimeLeft = calculateSeekTime(requestSequence, initialHead, n, -1);
  int seekTimeRight = calculateSeekTime(requestSequence, initialHead, n, 1);
  int totalSeekTime = seekTimeLeft + seekTimeRight;
  printf("Total Seek Time using SCAN: %d\n", totalSeekTime);
  return 0;
}
