#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10 // Number of frames in the page table

// Function to check if a page is already in the memory frames
int isPageInMemory(int page, int frames[], int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Function to display the current state of the memory frames
void displayFrames(int frames[], int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    // int referenceString[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int referenceString[50]={},n=0,framescount=0;
    
    printf("Enter the number of elements in reference string and no. of frames \t");
    scanf("%d %d",&n,&framescount);
    printf("\nEnter the reference string \t");
    for(int i=0;i<n;i++)
    	scanf("%d",&referenceString[i]);
    int frames[MAX_FRAMES]; // Memory frames
    int frameSize = 0; // Number of frames currently in use
    int pageFaults = 0; // Counter for page faults

    for (int i = 0; i < framescount-1; i++) {
        frames[i] = -1; // Initialize frames as empty
    }

    for (int i = 0; i < n; i++) {
        int page = referenceString[i];

        if (!isPageInMemory(page, frames, frameSize)) {
            if (frameSize < framescount) {
                frames[frameSize] = page;
                frameSize++;
            } else {
                // Replace the oldest page in the frames
                int replaceIndex = 0;
                for (int j = 1; j < frameSize; j++) {
                    if (referenceString[i - frameSize + j] < referenceString[i - frameSize + replaceIndex]) {
                        replaceIndex = j;
                    }
                }
                frames[replaceIndex] = page;
            }
            pageFaults++;
        }

        printf("Page %d -> ", page);
        displayFrames(frames, frameSize);
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}

