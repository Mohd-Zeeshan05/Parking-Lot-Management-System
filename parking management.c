#include <stdio.h>
#include <string.h>

#define MAX_SLOTS 10

typedef struct {
    char plate[20];
    int slotNumber;
    int isOccupied;
} Vehicle;

Vehicle parkingSlots[MAX_SLOTS];

// Initialize all slots as empty
void initializeParking() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        parkingSlots[i].isOccupied = 0;
        parkingSlots[i].slotNumber = i + 1;
        strcpy(parkingSlots[i].plate, "");
    }
}

// Park a vehicle
void parkVehicle() {
    char plate[20];
    printf("Enter vehicle number: ");
    scanf("%s", plate);

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (!parkingSlots[i].isOccupied) {
            strcpy(parkingSlots[i].plate, plate);
            parkingSlots[i].isOccupied = 1;
            printf("Vehicle parked at slot %d\n", parkingSlots[i].slotNumber);
            return;
        }
    }
    printf("Parking full! No available slots.\n");
}

// Remove a vehicle
void removeVehicle() {
    char plate[20];
    printf("Enter vehicle number to remove: ");
    scanf("%s", plate);

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parkingSlots[i].isOccupied && strcmp(parkingSlots[i].plate, plate) == 0) {
            parkingSlots[i].isOccupied = 0;
            printf("Vehicle %s removed from slot %d\n", plate, parkingSlots[i].slotNumber);
            return;
        }
    }
    printf("Vehicle not found!\n");
}

// Show all parked vehicles
void displayStatus() {
    printf("\n--- Parking Lot Status ---\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parkingSlots[i].isOccupied)
            printf("Slot %d: %s\n", parkingSlots[i].slotNumber, parkingSlots[i].plate);
        else
            printf("Slot %d: [Empty]\n", parkingSlots[i].slotNumber);
    }
}

// Menu
void menu() {
    int choice;
    while (1) {
        printf("\n--- Parking Lot Menu ---\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Show Parking Status\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: parkVehicle(); break;
            case 2: removeVehicle(); break;
            case 3: displayStatus(); break;
            case 4: printf("Exiting...\n"); return;
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    initializeParking();
    menu();
    return 0;
}
