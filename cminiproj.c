#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50

typedef struct {
    int seatNumber;
    char passengerName[50];
    int isReserved;
} Seat;

Seat bus[MAX_SEATS];
void initializeBus();
void bookSeat();
void cancelReservation();
void displaySeatAvailability();
void generateTicket();

int main() {
    int choice;

    initializeBus();

    while (1) {
        printf("\n--- Bus Reservation System ---\n");
        printf("1. Book a Seat\n");
        printf("2. Cancel a Reservation\n");
        printf("3. Display Seat Availability\n");
        printf("4. Generate a Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                cancelReservation();
                break;
            case 3:
                displaySeatAvailability();
                break;
            case 4:
                generateTicket();
                break;
            case 5:
                printf("Thank you for using the Bus Reservation System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void initializeBus() {
    for (int i = 0; i < MAX_SEATS; i++) {
        bus[i].seatNumber = i + 1;
        bus[i].isReserved = 0;
        strcpy(bus[i].passengerName, "");
    }
}
void bookSeat() {
    int seatNumber;
    char name[50];

    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (bus[seatNumber - 1].isReserved) {
        printf("Seat %d is already reserved.\n", seatNumber);
        return;
    }

    printf("Enter passenger name: ");
    scanf("%s", name);

    bus[seatNumber - 1].isReserved = 1;
    strcpy(bus[seatNumber - 1].passengerName, name);

    printf("Seat %d successfully booked for %s.\n", seatNumber, name);
}
void cancelReservation() {
    int seatNumber;

    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (!bus[seatNumber - 1].isReserved) {
        printf("Seat %d is not reserved.\n", seatNumber);
        return;
    }

    bus[seatNumber - 1].isReserved = 0;
    strcpy(bus[seatNumber - 1].passengerName, "");

    printf("Reservation for seat %d has been canceled.\n", seatNumber);
}
void displaySeatAvailability() {
    printf("\nSeat Availability:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!bus[i].isReserved) {
            printf("Seat %d: Available\n", bus[i].seatNumber);
        } else {
            printf("Seat %d: Reserved by %s\n", bus[i].seatNumber, bus[i].passengerName);
        }
    }
}
void generateTicket() {
    int seatNumber;

    printf("Enter seat number to generate ticket (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (!bus[seatNumber - 1].isReserved) {
        printf("Seat %d is not reserved. Cannot generate ticket.\n", seatNumber);
        return;
    }

    printf("\n--- Ticket ---\n");
    printf("Seat Number: %d\n", bus[seatNumber - 1].seatNumber);
    printf("Passenger Name: %s\n", bus[seatNumber - 1].passengerName);
    printf("Enjoy your journey!\n");
}
