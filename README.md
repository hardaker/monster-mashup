# Monster Mash Code Arena

This simple [monster code](./monster-mashup.cpp) code base exists only
to tinker with and learn to create objects in C++ using pointers and
to serve as a place to tinker with function overloading.

# Task ideas

1. READ THE CODE!
   - Before doing anything else, make sure you can understand every
     line.  If you can't understand every line, reach out to me and
     ask (6178 folk: find me in the room or on slack).  One rule of
     thumb I apply to learning new things (be it code, math, physics,
     whatever) is to break apart each line to the pieces I do
     understand.  Many times a single line of code or a single
     equation only looks daunting when you think about it as a whole,
     but less so after you concentrate on each piece.

2. Add a new monster to the potential battles
   - Give it new powers (hp and attack damage)
   - Maybe over-ride one of the functions to do new things

3. Add more monsters!  Why should just 2 battle?
   - ask the user for the number of monsters to put into the arena
   - add that many monsters and have them go for it
   - you might want to add a monster #N counter to the battle print
     out too.
	 
4. Easier to read output
   - the output is quite ugly at the moment.  Maybe a formatted
     closing score card display would be nice?
	 
5. Team battles
   - What if you had two teams with multiple monsters each?
   - What if you had more than two teams?
   
6. Special Attacks
   - What if a monster did two attacks at once (one claw, and one bite
     maybe)?

7. Find and fix the bug!
   - There is a bug in the program.  See if you can spot it (hint: you
     actually can be studying the code and reading the output)
   - Find and fix the *other* bug.  ha ha.
   
8. What can you come up with?  Be creative!!

	 
# Example Output

```
The Robot attacks the Robot dealing 5 damage
   The Robot has 49 hit-points left
The Unicorn attacks the Robot with death-rainbows and deals 17 pink heart damage
   The Robot has 32 hit-points left

The Robot attacks the Robot dealing 2 damage
   The Robot has 30 hit-points left
The Unicorn attacks the Unicorn with death-rainbows and deals 4 pink heart damage
   The Unicorn has 18 hit-points left

The Robot attacks the Robot dealing 4 damage
   The Robot has 26 hit-points left
The Unicorn attacks the Robot with death-rainbows and deals 4 pink heart damage
   The Robot has 22 hit-points left

The Robot attacks the Unicorn dealing 3 damage
   The Unicorn has 15 hit-points left
The Unicorn attacks the Unicorn with death-rainbows and deals 18 pink heart damage
   The Unicorn killed the Unicorn!!!
The Unicorn died!

The Robot wins the battle!
```
