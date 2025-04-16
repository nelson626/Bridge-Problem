# Bridge-Problem

Multithreading Problem in C

## About this Project

In this project there is bridge with people that want to cross from the north and the south. However on this bridge only people from one side can cross at any given point and time and there is a capacity to how many people can be on the bridge at the same time. 

I'd like to note that I utilize a few different ways to increase randomness in this project so that the concurrency baked into this project can really shine. 

## Background for this Project

I got this question in a class I was taking, but it was a scaled down version of the question I am solving here. I coded this solution for a problem I thought I was solving and thought it would be a wasted to delete it and never see it again when I spent so much time figuring this problem out. 

There are two variations of the code present. One is closer to the orignal problem I got in class, and doesn't take input for how many people can cross at the same time, because for the class this was an not needed variable. The other takes input for how many can cross at any one point in time. 

## Build Instructions

if you are using the gcc compiler you can build this project with the following commands!

```bash
gcc -pthread bridge_problem_var1 -o v1.out;
gcc -pthread bridge_problem_var2 -o v2.out
```

then you can run these files like you would any c file. Navigate to your directory with the output file and then run it. 

```bash
./v1.out
```


## Message to People Seeing this Page

Please feel free to fork this code and adopt it to your own use! I would love to see what other people may be able to create with this code!
