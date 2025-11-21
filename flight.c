#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FLIGHTS 50
#define MAX_BOOKINGS 100

// Flight structure
struct Flight {
    int flightID;
    char source[50];
    char destination[50];
    int seats;
};

// Booking structure
struct Booking {
    int bookingID;
    int flightID;
    char passengerName[50];
};

struct Flight flights[MAX_FLIGHTS];
struct Booking bookings[MAX_BOOKINGS];

int flightCount = 0;
int bookingCount = 0;

// Utility: safe integer input
int readInt() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Invalid input! Enter a valid number: ");
        while (getchar() != '\n'); // clear buffer
    }
    getchar(); // consume leftover newline
    return x;
}

// Find flight index by ID
int findFlight(int id) {
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightID == id)
            return i;
    }
    return -1;
}

// Add a new flight
void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
        printf("Flight list is full!\n");
        return;
    }

    int id;
    printf("\nEnter Flight ID: ");
    id = readInt();

    if (findFlight(id) != -1) {
        printf("Error: Flight ID already exists!\n");
        return;
    }

    struct Flight f;
    f.flightID = id;

    printf("Enter Source: ");
    fgets(f.source, sizeof(f.source), stdin);
    f.source[strcspn(f.source, "\n")] = 0;

    printf("Enter Destination: ");
    fgets(f.destination, sizeof(f.destination), stdin);
    f.destination[strcspn(f.destination, "\n")] = 0;

    printf("Enter Available Seats: ");
    f.seats = readInt();

    flights[flightCount++] = f;
    printf("Flight added successfully!\n");
}

// View all flights
void viewFlights() {
    printf("\n------ Available Flights ------\n");

    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }

    for (int i = 0; i < flightCount; i++) {
        printf("Flight ID: %d | %s -> %s | Seats: %d\n",
               flights[i].flightID,
               flights[i].source,
               flights[i].destination,
               flights[i].seats);
    }
}

// Book a ticket
void bookTicket() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking list full!\n");
        return;
    }

    printf("\nEnter Flight ID to book: ");
    int flightID = readInt();

    int index = findFlight(flightID);
    if (index == -1) {
        printf("Flight not found!\n");
        return;
    }

    if (flights[index].seats <= 0) {
        printf("No seats available!\n");
        return;
    }

    struct Booking b;
    b.bookingID = bookingCount + 1;
    b.flightID = flightID;

    printf("Enter Passenger Name: ");
    fgets(b.passengerName, sizeof(b.passengerName), stdin);
    b.passengerName[strcspn(b.passengerName, "\n")] = 0;

    if (strlen(b.passengerName) == 0) {
        printf("Passenger name cannot be empty!\n");
        return;
    }

    bookings[bookingCount++] = b;
    flights[index].seats--;

    printf("Ticket booked successfully! Booking ID: %d\n", b.bookingID);
}

// View all bookings
void viewBookings() {
    printf("\n------ All Bookings ------\n");

    if (bookingCount == 0) {
        printf("No bookings available.\n");
        return;
    }

    for (int i = 0; i < bookingCount; i++) {
        printf("Booking ID: %d | Flight ID: %d | Passenger: %s\n",
               bookings[i].bookingID,
               bookings[i].flightID,
               bookings[i].passengerName);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=========== Flight Booking Management System ===========\n");
        printf("1. Add Flight\n");
        printf("2. View All Flights\n");
        printf("3. Book Ticket\n");
        printf("4. View Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice) {
            case 1: addFlight(); break;
            case 2: viewFlights(); break;
            case 3: bookTicket(); break;
            case 4: viewBookings(); break;
            case 5:
                printf("Exiting system... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
