# 2073. Time Needed to Buy Tickets
-----------------------------------

## Idea
- After one loop through the entire vector, we've simulated the functionality of each ticket purchaser going to the "back" of the line.
- So the idea is to keep looping through, keeping track of the time and returning the value once we sell the last ticket for the k-th person.