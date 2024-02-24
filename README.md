# Open _Hell's Kitchen_!

On the cooking competition show _Hell's Kitchen_, Gordon Ramsay, celebrity chef, yells at people in the kitchen who want to be the head chef in some restaurant with his name on it. Ramsay is mean and gets very angry a lot which no doubt does something for the ratings of the show, but it also makes me sure that I would never want to work for him in that capacity. 

In this exercise, fortunately, you are not going to be in the kitchen. Instead, you will be managing the front-of-house rather than the back-of-house (kitchen). The front-of-house is the part where the guests sit and in this case we are going to be managing reservations for tonight's dinner service. For simplicity we'll say there's only one seating rather than two or more. We will also imagine that the tables are rectangular and modular and work in units of two guests. 

When a guest calls in a reservation, the host must to consider whether or not there are enough seats available. If there are not, the request cannot be accommodated. If there are enough seats available together, then you can assign the seats to the reservation and mark them as busy. If there are enough seats available but they are not together, then the request cannot be accommodated. 

Because of the nature of the tables, a request for seats must always be rounded up to the nearest even number. Thus, if the request for a table for one, that reservation is assigned a table for two. If the request is for five seats, that reservation is assigned a table for six. 

Sometimes, though, someone will call and ask to cancel a reservation. This could be for any number of reasons, but it does free up the previously-reserved seats. We won't explicitly implement something for modifying a reservation since this is effectively the same as a sequential deallocation and new allocation of seats. 

In this exercise, you will use the first-fit algorithm to allocate diners to seats.

### Primary Objective 
The primary objective of this exercise is to practice implementing some memory allocation algorithms.

### Secondary Objective(s)
You will also get some more experience with C programming. You may also improve your ability to work with version control (git) and gitlab.

### Description of Behaviour
 The goal is to implement the function `handle_request()` so that the following behaviour occurs:
 
- You have a dining room that seats 100 people maximum, represented as `int* seats` of capacity `TOTAL_SEATS`.

- Reservations are assigned a sequential number so they can be referred to later: so if the first request comes in and it is a table for 4, allocate four seats to reservation 1. Using the first-fit algorithm, that would be the first four seats in the dining room. As there are sufficient seats available, create the reservation (see next point) and return `true`.

- The seats are represented by an array of integers. A 0 in a seat means that this seat is currently not assigned to a reservation. If a nonzero number `n` is present, it means that the seat is allocated to reservation `n`.

- Remember that reservations are always even numbers.

- If it is not possible to satisfy a request because there are insufficient available seats or insufficient seats together, return `false`.

- A cancellation request will have the reservation number in it, so you can identify the reservation to cancel. A reservation is cancelled by just removing the allocation of seats. Reservation numbers are not re-used.

### Sample Output
```
./hk < night1.txt
Received a request to reserve a table for 1.
Reservation 1 created successfully.
Current seating chart:
1 1 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Received a request to reserve a table for 2.
Reservation 2 created successfully.
Current seating chart:
1 1 
2 2 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Received a request to reserve a table for 3.
Reservation 3 created successfully.
Current seating chart:
1 1 
2 2 
3 3 3 3 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Received a request to cancel reservation 1.
Reservation 4 created successfully.
Current seating chart:
0 0 
2 2 
3 3 3 3 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Received a request to reserve a table for 100.
Unable to create reservation; sorry!
Current seating chart:
0 0 
2 2 
3 3 3 3 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Received a request to reserve a table for 2.
Reservation 5 created successfully.
Current seating chart:
5 5 
2 2 
3 3 3 3 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Final seating chart:
5 5 
2 2 
3 3 3 3 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
In total, 8 seats out of 100 filled!
```

### Test Cases 

There are two provided test cases, `night1.txt` and `night2.txt`. They follow the format `[R|C] [0..100]`. A line in the file that looks like `R 4` is a request to create a reservation for 4 people. A line in the file that looks like `C 2` is a request to cancel reservation number 2.  Using this, you can design your own test cases beyond what's provided.