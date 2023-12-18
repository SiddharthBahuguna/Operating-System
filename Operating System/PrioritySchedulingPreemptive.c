#include <stdio.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int main()
{
  int n;
  printf("Enter Number of Processes: ");
  scanf("%d", &n);

  int b[n], p[n], index[n], remaining_time[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
    scanf("%d %d", &b[i], &p[i]);
    index[i] = i + 1;
    remaining_time[i] = b[i];
  }
  int t = 0;
  printf("Order of process Execution is\n");
  while (1)
  {
    int selected_process = -1;
    int highest_priority = -1;
    for (int i = 0; i < n; i++)
    {
      if (remaining_time[i] > 0 && p[i] > highest_priority)
      {
        highest_priority = p[i];
        selected_process = i;
      }
    }
    if (selected_process == -1)
    {
      break;
    }
    printf("P%d is executed from %d to %d\n", index[selected_process], t, t + 1);
    remaining_time[selected_process]--;
    if (remaining_time[selected_process] == 0)
    {
    }
    t++;
  }

  printf("\n");
  printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
  int wait_time = 0;
  int turnaround_time;
  for (int i = 0; i < n; i++)
  {
    turnaround_time = wait_time + b[i];
    printf("P%d          %d          %d          %d\n", index[i], b[i], wait_time, turnaround_time);
    wait_time += b[i];
  }
  return 0;
}
