#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TOTAL_SEATS 100
#define RESERVE 'R'
#define CANCEL 'C'

typedef struct {
    char type;
    int number;
} request;

request *get_next_request();

void print_current_seat_map(int *seats, bool final);

bool handle_request(request *r, int *seats, int reservation_number);

int main(int argc, char **argv) {
    int *seats = calloc(TOTAL_SEATS, sizeof(int));
    int reservation_number = 1;

    request *next = get_next_request();
    while (next != NULL) {
        bool could_handle = handle_request(next, seats, reservation_number);
        if (could_handle) {
            printf("Reservation %d created successfully.\n", reservation_number);
            reservation_number++;
        } else {
            printf("Unable to create reservation; sorry!\n");
        }
        print_current_seat_map(seats, false);
        next = get_next_request();
    }

    print_current_seat_map(seats, true);
    free(seats);
    return 0;
}

bool handle_request(request *r, int *seats, int reservation_number) {

    if(r->type == 'R')
    {
        int i = 0;
        int sum = 0;

        for(int j = 0; j < 100; ++j)
        {
            if(*(seats+j) == 0)
            {
                sum++;
            }
        }

        if(sum < r->number)
        {
            return false;
        }
        
        while(i < ((r->number+1)/2)*2)
        {
            if(*seats == 0)
            {
                *seats = reservation_number;
                i++;
            }
            seats++;
        }
        return true;
    }
    else
    {
        while(*seats <= r->number)
        {
            if(*seats == r->number)
            {
                *seats = 0;
            }
            seats++;
        }
        return true;
    }
    return false;
}

/****** Do not change anything below this line -- Internal Functionality Only ********/

void print_current_seat_map(int *seats, bool final) {
    if (final) {
        printf("Final seating chart:\n");
    } else {
        printf("Current seating chart:\n");
    }
    int filled_seats = 0;
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] != 0) {
            filled_seats++;
        }
        printf("%d ", seats[i]);
        if (i != TOTAL_SEATS - 1 && seats[i] != seats[i + 1]) {
            printf("\n");
        }
    }
    printf("\n");
    if (final) {
        printf("In total, %d seats out of %d filled!\n", filled_seats, TOTAL_SEATS);
    }
}

request *get_next_request() {
    if (feof(stdin)) {
        return NULL;
    }
    request *r = calloc(1, sizeof(request));
    scanf("%1s %d", &(r->type), &(r->number));
    if (r->type == RESERVE) {
        printf("Received a request to reserve a table for %d.\n", r->number);
    } else if (r->type == CANCEL) {
        printf("Received a request to cancel reservation %d.\n", r->number);
    } else {
        printf("Unrecognized request type '%c'!", r->type);
        exit(-1);
    }
    if (r->number <= 0) {
        printf("Invalid request: number %d must be > 0\n", r->number);
        exit(-2);
    }
    return r;
}
