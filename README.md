# Multithreading Bridge Crossing Problem

## About this Project

In this project there is bridge with people from either side want to cross. The people on the bridge are either crossing from the north or from the south. However on this bridge only people from one side can cross at any given point and time and there is a capacity to how many people can be on the bridge at the same time. 

## Background for this Project

I got this question in a class I was taking, but it was a scaled down version of the question I am solving here. The question it was actually asking in the class was just to make it so only one person could cross the bridge at any given point in time. When they were in the critical section of semaphore they would then print out that they were crossing the bridge. Instead of coding it this way I instead coded it so that multiple people from one side could cross at the same time if they were all queued together. This increased efficiency as multiple people were able to cross at once instead of just once. Instead of just deleting this code I thought I would share the way I implemented my version of the bridge crossing problem so anyone can see my thought process. 

There are two variations of the code present. One is solution is closer to the problem's actual solution and doesn't take input for how many people can cross at the same tim. The other takes input for how many can cross at any one point in time. 

## Comments about the code

I'd like to note that I utilize a few different ways to increase randomness in this project so that the concurrency baked into this project can really shine. 
For example I try to make sure that each person is "arriving" at the bridge at random intervals. Also I try to make sure that each person that crosses the bridge takes a different amount of time to cross. This ulitmately leads to the concurrency being shown off in the most effective way possible. 

Also a few more notes about functionality. When prompted to tell the machine how many people should cross the bridge keep the number at 300 or below. Also the "number of people to cross" refers to the number of people from each side so keep that in mind. 

## Requirements

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

This program is primarily made with C. You are going to want to make sure that you have C compiler on your machine that can compile to c11. 

## Build Instructions

if you are using the gcc compiler you can build this project with the following commands!

```bash
gcc -std=c11 -pthread bridge_problem_var1.c -o simple
gcc -std=c11 -pthread bridge_problem_var2.c -o advanced
```

then you can run these files like you would any c file. Navigate to your directory with the output file and then run it. 

```bash
./simple

or 

./advanced
```


## Message to People Seeing this Page

Please feel free to fork this code and adopt it to your own use! I would love to see what other people may be able to create with this code! I will note that this code should not be used to cheat in any computer science class that has related a related problem or problems. 
