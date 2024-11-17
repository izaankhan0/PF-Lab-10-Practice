#include <stdio.h>
#include <string.h>
typedef struct {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[10];
    char arrivalTime[10];
    int availableSeats;
} Flight;
void bookSeat(Flight *flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--;
        printf("Seat booked successfully!\n");
    } else {
        printf("No seats available.\n");
    }
}
void displayFlights(Flight flights[], int numFlights, char *fromCity, char *toCity) {
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].departureCity, fromCity) == 0 && strcmp(flights[i].arrivalCity, toCity) == 0) {
            printf("Flight %s: %s to %s (%s - %s), Seats: %d\n", flights[i].flightNumber,
                   flights[i].departureCity, flights[i].arrivalCity,
                   flights[i].departureTime, flights[i].arrivalTime, flights[i].availableSeats);
        }
    }
}
void updateFlightDetails(Flight *flight, char *newDepartureTime, char *newArrivalTime) {
    strcpy(flight->departureTime, newDepartureTime);
    strcpy(flight->arrivalTime, newArrivalTime);
    printf("Flight details updated.\n");
}
int main() {
    Flight flights[100];
    int numFlights = 0;
    Flight newFlight = {"Karachi", "DHA", "Fast Uni", "08:00", "11:00", 100};
    flights[numFlights++] = newFlight;
    bookSeat(&flights[0]);
    displayFlights(flights, numFlights, "DHA", "Fast Uni");
    updateFlightDetails(&flights[0], "09:00", "12:00");
    return 0;
}

