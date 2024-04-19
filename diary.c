#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANS 100
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_DETAILS_LENGTH 200

typedef struct {
    char date[11];
    char description[MAX_DESCRIPTION_LENGTH];
    char details[MAX_DETAILS_LENGTH];
} Plan;

void addPlan(Plan *plans, int *numPlans);
void viewPlans(Plan *plans, int numPlans, char *date);
void checkReminders(Plan *plans, int numPlans, char *date);
int validateDate(const char *date);
void cancelPlan(Plan *plans, int *numPlans, char *date, char *description);
void savePlan(Plan *plans, int *numPlans, char *date, char *description, char *details);
void listAllPlans(Plan *plans, int numPlans);
void printCentered(const char *text) {
    // Calculate the number of spaces needed to center the text
    int padding = (80 - strlen(text)) / 2; // Assuming a terminal width of 80 characters

    // Print leading spaces followed by the text
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", text);
}


int main() {
    Plan plans[MAX_PLANS];
    int numPlans = 0;
    char date[11];

    printf("\033[0;39m");

    printf("     Welcome to Your Personal Dairy!     \n");

   int choice;
    do {
printf("+------------------------------------------------+\n");
printf("|      1. Add Plan                               |\n");
printf("+------------------------------------------------+\n");
printf("+------------------------------------------------+\n");
printf("|      2. View  Plans for a Date                 |\n");
printf("+------------------------------------------------+\n");
printf("+------------------------------------------------+\n");
printf("|      3. Check Reminders for today              |\n");
printf("+------------------------------------------------+\n");
printf("+------------------------------------------------+\n");
printf("|      4. Cancel Plan                            |\n");
printf("+------------------------------------------------+\n");
printf("+------------------------------------------------+\n");
printf("|      5. List All Plans                         |\n");
printf("+------------------------------------------------+\n");
printf("+------------------------------------------------+\n");
printf("|      6. Exit                                   |\n");
printf("+------------------------------------------------+\n");
printf("              Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPlan(plans, &numPlans);
                break;
            case 2:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                viewPlans(plans, numPlans, date);
                break;
            case 3: {
                time_t t = time(NULL);
                struct tm *tm = localtime(&t);
                strftime(date, sizeof(date), "%Y-%m-%d", tm);
                checkReminders(plans, numPlans, date);
                break;
            }
            case 4:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter description: ");
                scanf(" %[^\n]", plans[numPlans].description);
                cancelPlan(plans, &numPlans, date, plans[numPlans].description);
                break;
            case 5:
                listAllPlans(plans, numPlans);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void addPlan(Plan *plans, int *numPlans) {
    if (*numPlans >= MAX_PLANS) {
        printf("Plan list is full. Cannot add more plans.\n");
        return;
    }

    char date[11];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    if (!validateDate(date)) {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return;
    }

    printf("Enter description: ");
    scanf(" %[^\n]", plans[*numPlans].description);

    printf("Enter details:\n");
    scanf(" %[^\n]", plans[*numPlans].details);

    savePlan(plans, numPlans, date, plans[*numPlans].description, plans[*numPlans].details);
}

void viewPlans(Plan *plans, int numPlans, char *date) {
    printf("Plans for %s:\n", date);
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    printf("|    Date    |           Description             |             Details               |\n");
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    int found = 0;
    for (int i = 0; i < numPlans; i++) {
        if (strcmp(plans[i].date, date) == 0) {
            printf("| %-10s | %-33s | %-33s |\n", plans[i].date, plans[i].description, plans[i].details);
            found = 1;
        }
    }
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    if (!found) {
        printf("No plans found for %s.\n", date);
    }
}

void checkReminders(Plan *plans, int numPlans, char *date) {
    printf("Reminders for today (%s):\n", date);
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    printf("|    Date    |           Description             |             Details               |\n");
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    int found = 0;
    for (int i = 0; i < numPlans; i++) {
        if (strcmp(plans[i].date, date) == 0) {
            printf("| %-10s | %-33s | %-33s |\n", plans[i].date, plans[i].description, plans[i].details);
            found = 1;
        }
    }
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    if (!found) {
        printf("No reminders for today.\n");
    }
}

int validateDate(const char *date) {
    if (strlen(date) != 10) {
        return 0;
    }

    if (date[4] != '-' || date[7] != '-') {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (date[i] < '0' || date[i] > '9') {
            return 0;
        }
    }

    return 1;
}

void cancelPlan(Plan *plans, int *numPlans, char *date, char *description) {
    int found = 0;
    for (int i = 0; i < *numPlans; i++) {
        if (strcmp(plans[i].date, date) == 0 && strcmp(plans[i].description, description) == 0) {
            for (int j = i; j < *numPlans - 1; j++) {
                strcpy(plans[j].date, plans[j + 1].date);
                strcpy(plans[j].description, plans[j + 1].description);
                strcpy(plans[j].details, plans[j + 1].details);
            }
            (*numPlans)--;
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Plan canceled successfully.\n");
    } else {
        printf("No matching plan found.\n");
    }
}

void savePlan(Plan *plans, int *numPlans, char *date, char *description, char *details) {
    char choice;
    printf("Do you want to save (S) the plan? ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'S':
        case 's':
            strcpy(plans[*numPlans].date, date);
            strcpy(plans[*numPlans].description, description);
            strcpy(plans[*numPlans].details, details);
            (*numPlans)++;
            printf("Plan saved successfully.\n");
            break;
        default:
            printf("Invalid choice. Plan not saved.\n");
    }
}

void listAllPlans(Plan *plans, int numPlans) {
    printf("All Plans:\n");
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    printf("|    Date    |           Description             |             Details               |\n");
    printf("+------------+-----------------------------------+-----------------------------------+\n");
    for (int i = 0; i < numPlans; i++) {
        printf("| %-10s | %-33s | %-33s |\n", plans[i].date, plans[i].description, plans[i].details);
    }
    printf("+------------+-----------------------------------+-----------------------------------+\n");
}
