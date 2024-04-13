#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LENGTH 100

struct DiaryEntry {
    int day;
    int month;
    int year;
    char time[6];
    char description[MAX_DESCRIPTION_LENGTH];
};

struct DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &diary[numEntries].day, &diary[numEntries].month, &diary[numEntries].year);

    printf("Enter time (HH:MM): ");
    scanf("%s", diary[numEntries].time);

    printf("Enter description: ");
    scanf(" %[^\n]", diary[numEntries].description);

    numEntries++;
}

void viewEntries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Date: %02d/%02d/%d, Time: %s, Description: %s\n",
               diary[i].day, diary[i].month, diary[i].year, diary[i].time, diary[i].description);
    }
}

void editEntry() {
    int index;
    printf("Enter index of entry to edit: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= numEntries) {
        printf("Invalid index!\n");
        return;
    }

    printf("Enter new description: ");
    scanf(" %[^\n]", diary[index].description);

    printf("Entry edited successfully!\n");
}

void remind() {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    printf("Reminder:\n");
    for (int i = 0; i < numEntries; i++) {
        if (diary[i].year == tm_now->tm_year + 1900 &&
            diary[i].month == tm_now->tm_mon + 1 &&
            diary[i].day >= tm_now->tm_mday) {
            printf("Upcoming event on %02d/%02d/%d: %s\n",
                   diary[i].day, diary[i].month, diary[i].year, diary[i].description);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nDiary Management System\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Edit Entry\n");
        printf("4. Remind\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                editEntry();
                break;
            case 4:
                remind();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
