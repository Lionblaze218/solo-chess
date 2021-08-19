# solo-chess

## Project Description
My attempt at replicating solo playable chess using c++.

Best used in visual studios, as the SFML library is super sensitive.
The best video I found for the installation of SFML is [here](https://www.youtube.com/watch?v=neIoDQ71yb0).

Here is an example video showing it off:

[Ruy Lopez Example](https://www.youtube.com/watch?v=r0uIpLdgwQ8)

## Requirements

- SFML Library

## To use

Simply just run the source.cpp file in visual studios to play the game

## Misc
###### Why did I write everything into one file (Source.cpp)? 

For some reason the SFML library only works in visual studios, and I'm not really familiar with it. Adding different files and using more conventional forms of coding (like branching) in visual studios is something that'd take me a while to learn. But it's less frustrating to deal with the janky library all in one file. If I could split it up, I would.

###### Why did I do this? 

I was going on vacation and wanted to practice my openings on the car ride there. We couldnt bring a real chess board, so I just decided to make my own. I also did it just to prove to myself that I could.

###### Is this finished? 

No, definetely not. It lacks the functionality of en passant, promotions, and checkmate. About 90% of the game is complete. I plan on revisiting this in the future to finish those last 3 functions. There is also most likely bugs that I have not encountered yet that are probably game breaking. Again, I plan on revisitng this to fix them.

###### What did I get out of this? 

Software that I can use to play chess, but mostly experience on planning out a project. What ended up happening was I would write a function, implement it, test it out, and then move onto the next function. After the code hit ~ 800 lines of code, I realized half of my functions were fundamentally useless and I could come up with a more efficient solution. So this turned into a self repeating cycle of writting code, then writting more, then changing past code. This would result in really annoying bugs that were hard to find, or just functions overwritting each other on accident because I mistyped the wrong varaible. In the end, I could have saved myself a lot of brainpower by just planning it out better.

I also plan on making the game differ from chess itself. Just adding a bit of flair or new rules to the game to make it more unique (or a chess bot!).
