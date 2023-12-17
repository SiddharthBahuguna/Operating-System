#include <stdio.h>
#define MAX_FRAMES 3

int main()
{
  int reference_string[] = {0, 1, 2, 3, 2, 4, 5, 3, 4, 1, 6, 7, 8, 7, 8, 4, 9, 7, 8, 1};
  int n = sizeof(reference_string) / sizeof(reference_string[0]);
  int frames[MAX_FRAMES];
  int pageFaults = 0;

  for (int i = 0; i < MAX_FRAMES; i++)
  {
    frames[i] = -1;
  }

  printf("Page Reference String: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", reference_string[i]);
  }
  printf("\n\nFCFS Page Replacement:\n");

  for (int i = 0; i < n; i++)
  {
    int currentPage = reference_string[i];
    int pageFound = 0;

    for (int j = 0; j < MAX_FRAMES; j++)
    {
      if (frames[j] == currentPage)
      {
        pageFound = 1;
        break;
      }
    }

    if (!pageFound)
    {
      // printf("Page %d is loaded into Frame %d\n", currentPage, pageFaults % MAX_FRAMES);
      frames[pageFaults % MAX_FRAMES] = currentPage;
      pageFaults++;
    }

    printf("Current Page Frames: ");
    for (int j = 0; j < MAX_FRAMES; j++)
    {
      printf("%d ", frames[j]);
    }
    printf("\n");
  }

  printf("\nTotal Page Faults: %d\n", pageFaults);
  return 0;
}
