# Team 001-09 Homework4: Payment System
---
**Kayla Hartman hartm700**
**Jenna Bailey bail0416**

### Drone Transportation Simulation System

This project is a drone transportation simulation system, similar to Uber, where robots are
customers who schedule trips to be transported from a starting to end point by a drone. 


### How to run simulation:

To run the simulation:
1. Navigate to project home directory
2. Compile project: type 'make -j' in terminal
3. Build the project: type './build/bin/transit_service 8081 apps/transit_service/web/' in terminal
4. Navigate to http://127.0.0.1:8081 to see a visualization of the simulation
5. Navigate to http://127.0.0.1:8081/schedule.html to schedule trips
6. Schedule trips by selecting a start and end point on the map, select a strategy from the drop down menu, and a name for your robot
7. Watch visualization in webpage. Use drop down menu to select which entity to follow. See output in terminal for more information.


### Project Overview

There are 3 different strategies that can be used for the trip paths: AStar, Depth-First Search, or Dijkstra's algorithm. We also implemented a payment system.

## New Feature: Payment System

Trips scheduled by robots now have a cost. Robots are created with a random amount of money, and when the drone arives to begin their trip, the robot must pay the drone. If the robot does not have enough money, they can call an ATM Drone to go to a payment system for them to pick up some emergency cash and save the day. When transportation drone's have accumulated too fat of a stack of cash in their own wallet, they take a break from transporting robots and go make a deposit at a payment station. The payment stations have a 5% fee for use, which is put into the National Bank account as tax. The transportation drones' wages also eventually go into the National Bank account because this is not a chill economic system. There is more potential for additional bank accounts to be added to the payment stations, but the government doesn't want this to be utilized, so drones and robots just get the illusion of economic freedom.

Why is it significantly interesting, you ask? Money makes the world go around. This system is very unrealistic without money involved. Drones need to be paid for their service, and if a company is running this business, they're probably not going to offer it for free.

This extension adds to the existing work by considering how payment for the transportation service could be handled.

We chose to implement this with the decorator design pattern. Drones, robots, and bank accounts require wallets, so those classes are decorated with a wallet decorator which provides extra functionality.

This feature is not user interactive since trip costs are fixed based on distance, drones automatically go to payment systems, and robots are created with a random amount of money in their wallet. However, you can see updates on the financial status of these entities in the terminal while the simulation is being run.


### Sprint retrospective
We started off with dividing tasks into two sprints. The first sprint was centered around the actual implementation of the extension, and our original plan was to finish this sprint on April 23rd. The second sprint included all non-coding sections of the extension, such as documentation, code style, docker deployment, and others. This sprint was planned to start upon the completion of the first sprint on April 23rd, and continue for 1 week, with the goal to finish both sprints a comfortable amount of time before the deadline.

The timeline of the first sprint was pushed back by around a week to a week and a half, since both group members were busier than expected the week of the sprint. We did eventually start the sprint, and worked on it bit by bit until a large push shortly before the deadline. Sprint two turned out to take much less time than anticipated, and was completed in one day.

Overall, the sprints were instrumental in planning work division, and how individual parts could come together. We could have done better on sticking to the timeline, but in the end both sprints were completed.

### YouTube Video Link - Project Explanation
https://youtu.be/tV7TdBGVoJc

### UML Diagram Link 
https://lucid.app/lucidchart/c230460a-c1d6-4129-b048-8b316e78cdab/edit?viewport_loc=-1104%2C-325%2C4818%2C2216%2C0_0&invitationId=inv_c36ac896-8c27-4984-91da-4f0c5f543d28

