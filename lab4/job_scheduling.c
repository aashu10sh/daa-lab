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
    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    // Handle edge case where no jobs have deadlines
    if (maxDeadline == 0) {
        printf("No jobs can be scheduled (all deadlines are 0)\n");
        return;
    }
    
    // Allocate schedule array dynamically
    int *schedule = (int *)malloc(maxDeadline * sizeof(int));
    if (schedule == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize schedule array
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
    
    // Free allocated memory
    free(schedule);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    // Input validation
    if (n <= 0) {
        printf("Number of jobs must be greater than 0\n");
        return 1;
    }
    
    // Allocate jobs array dynamically
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    if (jobs == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        jobs[i].jobID = i + 1;
        printf("Enter the profit for Job %d: ", i + 1);
        scanf("%d", &jobs[i].profit);
        printf("Enter the deadline for Job %d: ", i + 1);
        scanf("%d", &jobs[i].deadline);
        
        // Input validation for deadline
        if (jobs[i].deadline < 0) {
            printf("Deadline cannot be negative. Setting to 0.\n");
            jobs[i].deadline = 0;
        }
    }
    
    sortJobsByProfit(jobs, n);
    scheduleJobs(jobs, n);
    
    // Free allocated memory
    free(jobs);
    
    return 0;
}