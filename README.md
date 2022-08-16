# runaway_reservations 

## Problem
Imagine an airport with a single runaway. We need to schedule a reservation for future landings.

- When a plane lands, it is removed from the set of pending events 
- reserve requirement specify the requested landing time (t)
- add t ot the set if no otehr landings are scheduled within k minutes before and after t(we don't want any accidents)
- k is at the disretion of the user

## Example
consider the set of times request for landing
$$R = {35-41-49-56} $$ and k =3  and now = 35

- request to land at t = 49 not okay because $49\subset B$
- request to land at t =53 is okay
- request to land at t =20 is not okay because $ t< now$
