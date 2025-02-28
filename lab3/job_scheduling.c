#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int jobID;
  int deadline;
  int profit;
} Job;
void swap(Job *a, Job *b) {
  Job temp = *a;
  *a = *b;
  *b = temp;
}
void sortJobsByProfit(Job jobs[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (jobs[j].profit < jobs[j + 1].profit) {
        swap(&jobs[j], &jobs[j + 1]);
      }
    }
  }
}
void scheduleJobs(Job jobs[], int n) {
  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    if (jobs[i].deadline > maxDeadline) {
      maxDeadline = jobs[i].deadline;
    }
  }
  int schedule[maxDeadline];
  for (int i = 0; i < maxDeadline; i++) {
    schedule[i] = -1; // Unassigned
  }
  int totalProfit = 0;
  for (int i = 0; i < n; i++) {
    for (int j = jobs[i].deadline - 1; j >= 0; j--) {
      if (schedule[j] == -1) {
        schedule[j] = jobs[i].jobID;
        totalProfit += jobs[i].profit;
        break;
      }
    }
  }
  printf("Scheduled jobs with maximum profit:\n");
  for (int i = 0; i < maxDeadline; i++) {
    if (schedule[i] != -1) {
      printf("Job %d\n", schedule[i]);
    }
  }
  printf("Total Profit: %d\n", totalProfit);
}
int main() {
  int n;
  printf("Enter the number of jobs: ");
  scanf("%d", &n);
  Job jobs[n];
  for (int i = 0; i < n; i++) {
    jobs[i].jobID = i + 1;
    printf("Enter the profit for Job %d: ", i + 1);
    scanf("%d", &jobs[i].profit);
    printf("Enter the deadline for Job %d: ", i + 1);
    scanf("%d", &jobs[i].deadline);
  }
  sortJobsByProfit(jobs, n);
  scheduleJobs(jobs, n);
  return 0;
}