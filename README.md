State Machine Framework in C
============================

The purpose of this code is to obscure the low-level operation of finite state machines in C, freeing designers to implement event driven systems without worrying about the details. 


### Version
0.0.1

### Getting the repo

You need Git installed first. Please look up a tutorial on how to install Git on your particular OS if you have not already done so. When git is installed, you can do:

```sh
$ git clone [git-repo-url] stateFramework
```

I would highly reccomend not running this command just anywhere. Change your working directory to be someplace you plan on keeping all of your code (at least for now.)

For example, do:
```sh
$ cd ~/Documents
$ mkdir GitHub; cd GitHub
$ git clone [git-repo-url] stateFramework
```

Now you should have a directory called 'GitHub' in your Documents folder with a clone of this repository.

### Understanding the Code
I will admit that this code is pretty dense. If you do not have a lot of programming background, don't worry if it doesnt make sense - it will probably not make sense if you have A LOT of programming experience! 

I'm using some nice tricks that the C language has to offer, and most of them do not get taught to beginners. To begin the process of understanding, look at 
*fsm.h* in the main directory of the repo. Try to answer these questions:

- What is a struct?
- What are the /#defines at the bottom of the file? What do they do?

If you get stumped on the second question, don't worry.

Now, open the playground directory, then take a look at hBridgeFSM.c. Try to answer these questions:

- What is an FSM? (not a programming question)
- What is an H-bridge (not a programming question)
- What is a 'Switch' in C? What are they used for? How do they work?
- Take a look at the function implementations at the top of the files (the ones with 'switches'). Look at the functions they call, use some context and try to explain what they are doing.
- Look at the transition function near the bottom. What do you think it is doing?
- Now look at the main function at the very bottom, can you give a high-level explanation of what is happening? (I don't expect a complete answer here, the idea is to struggle with it a bit)

Now the fun part let's try and run it. If you have the gcc toolchain installed, and you're on mac, you can open a terminal and do the following:

```sh
$ cd ~/Documents/GitHub/stateFramework/playground
$ gcc hBridgeFSM.c -o main.out
$ ./main.out
```

After this string of commands, your terminal will be executing the program, and will wait for input from your keyboard. Enter a '+', then press enter. 
Now enter a '-' and press enter. Now '0' and enter. Try to understand what is happening given what you see in the transition function. Now give the program a '.' and press enter to quit, or continue to play around. Does anything happen if you try to enter a character other than the ones I listed?

### Excercises

Now that I've (probably) thoroughly confused you, here's a bit of a creative excercise. Do some google searches on finite state machines and state diagrams. Now, draw your own state diagram that described the bahavior of a stoplight. The stoplight should take as input a timer (you decide how long it stays red, green, etc.) and a sensor that can tell it how many cars are coming in either direction. Assume this is a typical intersection with (+) with cars moving in both directions on the X and Y axes. Keep it simple at first and assume there are no extra indicators for cars turning left.

### Readings 
Lee and Seshia, Introduction to Embedded Systems
Start out with Chapter 1, then move on to Chapter 3. Do not feel rushed, but make sure you internalize as much of this as possible. I would reccomend taking a look at Chapter 2 as well, though it is a little heavy on the calculus.

The PDF is available [here](http://leeseshia.org)

Next
## Development

### Todo's


License
----

MIT

**Free Software, Hell Yeah!**
