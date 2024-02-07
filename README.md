# Plane-Ticket-System

PROG2400 Data Structures Class | Group Airline Reservation System on Brightspace.

Program requirements:

    DO NOT USE GLOBAL VARIABLES
    Use good programming practices:
        Block Comment and appropriate Comments as needed
        Proper meaningful variable names
    Modular code
    Simple class
    Array(s)and/or Pointers
    File 1/0 and Exception handling

 
(Airline Reservations System) 
A small airline has just purchased a computer for its new automated reservations system. You've been asked to program the new system. 
You are to write a program to assign seats on each flight of the airline's only plane (capacity: 10 seats).

 
Your program should display the following menu of alternatives-Please type 1 for "First Class" and Please type 2 for "Economy".
If the person types 1, your program should assign a seat in the first class section (seats 1-5).
If the person types 2, your program should assign a seat in the economy section (seats 6-10).
Then get the person's full name and birthdate.
Your program should print a boarding pass indicating the person's Name, Seat Number, and whether it's in the First Class or Economy Section of the plane.
This information should also be written to the BoardingPass.txt file.


Your program should, of course, never assign a seat that has already been assigned.

Nathan, Justin & John
When the First Class section is full, your program should ask the person if it's acceptable to be placed in the Economy Section (and vice versa).
If yes, then make the appropriate seat assignment.
If no, then ask if the person wants to be put on the waiting list for the next flight, if yes add the person to the waitlist.txt file (full name, birthdate, and seating type) and print the message "Next flight leaves in 3 hours."

Note: If there is a waiting list (waitlist.txt) then assign those seats first, print boarding passes, and update the BoardingPass.txt file.
