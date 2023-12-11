#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 30

int findLRU(int time[], int n) {
    int i, minIndex = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < time[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int frames[MAX_FRAMES], time[MAX_FRAMES];
    int no_of_frames, no_of_pages, pages[MAX_PAGES], faults = 0, counter = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter reference string: ");
    for (int i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nF1\tF2\tF3");

    for (int i = 0; i < no_of_pages; ++i) {
        int pageFound = 0;

        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                pageFound = 1;
                time[j] = ++counter;
                break;
            }
        }

        if (!pageFound) {
            int replaceIndex = findLRU(time, no_of_frames);
            frames[replaceIndex] = pages[i];
            time[replaceIndex] = ++counter;
            faults++;
        }

        printf("\n");
        for (int j = 0; j < no_of_frames; ++j) {
            printf("%d\t", frames[j]);
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
