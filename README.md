Absract

This project presents a simple console-based Flight Booking Management System implemented in the C programming language. 
The system allows users to efficiently manage flight information and passenger bookings through a menu-driven interface.
Key functionalities include adding new flights, viewing available flights, booking tickets, and displaying all confirmed bookings.
The program uses structures to store flight and booking data, while arrays maintain a fixed number of records. Input validation is incorporated to ensure safe and reliable user interactions.
This system demonstrates the use of structured programming, data handling, and user-interface design in C, making it suitable for educational purposes and small-scale management tasks.

FEATURES OF THE PROGRAM

.Add Flights: Enter flight ID, source, destination, and number of seats.
.View Flights: Display all available flights with their details.
.Book Tickets: Book a seat on a selected flight and generate a booking ID.
.View Bookings: Show all ticket bookings with passenger names.
.Seat Management: Seats automatically decrease when a booking is made.
.Input Validation: Ensures users enter valid numbers and non-empty names.
.Menu System: Easy-to-use menu to access all functions.

TECHNICAL REQUIREMENTS

.OS: Windows, Linux, or macOS
.Software: Any C compiler (GCC, MinGW, etc.)
.Editor/IDE: VS Code, Code::Blocks, Dev-C++, or any text editor
.Libraries Needed: stdio.h, string.h, ctype.h
.Hardware: Basic computer with ~1 GB RAM
.Memory: Supports up to 50 flights and 100 bookings

FUNCTIONAL REQUIREMENT

.The system must allow adding new flights.
.The system must display all available flights.
.The system must allow booking tickets for a selected flight.
.The system must store and display all bookings.
.The system must update seat count after each booking.
.The system must validate user inputs and prevent invalid entries.
.The system must provide a menu for easy navigation.

HOW TO RUN PROGRAM

1. Save the Code

Save your program as:
flight_booking.c

2. Compile the Program

Open a terminal or command prompt and run:

On Windows (MinGW / GCC):
gcc flight_booking.c -o flight_booking

On Linux / macOS:
gcc flight_booking.c -o flight_booking

3. Run the Program

After successful compilation:

Windows:
flight_booking

Linux / macOS:
./flight_booking

SCREENSHOT
<img width="512" height="157" alt="Screenshot 2025-11-21 225844" src="https://github.com/user-attachments/assets/347a78ee-cacb-4c58-b2e4-c577ad0037b6" />

