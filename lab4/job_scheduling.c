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
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

void scheduleJobs(Job jobs[], int n) {
    int i, j;
    int maxDeadline = 0;

    // Find the maximum deadline
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Allocate memory for the schedule array
    int *schedule = (int *)malloc(maxDeadline * sizeof(int));
    if (schedule == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize the schedule array
    for (i = 0; i < maxDeadline; i++) {
        schedule[i] = -1; // Unassigned
    }

    int totalProfit = 0;

    // Schedule jobs
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].jobID;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print scheduled jobs
    printf("Scheduled jobs with maximum profit:\n");
    for (i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            printf("Job %d\n", schedule[i]);
        }
    }

    printf("Total Profit: %d\n", totalProfit);

    // Free allocated memory
    free(schedule);
}

int main() {
    int n, i;
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Dynamically allocate memory for jobs array
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    if (jobs == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        jobs[i].jobID = i + 1;
        printf("Enter the profit for Job %d: ", i + 1);
        scanf("%d", &jobs[i].profit);
        printf("Enter the deadline for Job %d: ", i + 1);
        scanf("%d", &jobs[i].deadline);
    }

    sortJobsByProfit(jobs, n);
    scheduleJobs(jobs, n);

    // Free allocated memory
    free(jobs);

    puts("Ran by Aashutosh Pudasaini");

    return 0;
}