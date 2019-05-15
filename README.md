# Caterpillar
Snake-like simulation in which a concept of deque using user-defined Doubly Linked List is implemented.

# How-to
  Caterpillar eats letters (it is also composed of them). When it eats lowercase letter, the caterpillar grows longer from its beginning, if it's an uppercase letter, its tail grows longer. After eating a letter, a new one appears in the same spot (with ascii value lower by 1, so if 'a' or 'A' gets eaten, after that appear void).
  After stepping on void, the caterpillar loses its letter. On the map there are also digits from 1 to 4 giving a caterpillar directions.
## Input
  First three integers (separated with spaces) are: width and height of a map respectively and number of caterpillar moves.
  After hitting Enter key, next three integers are: x and y coordinates of caterpillars head and its length.
  Next, after hitting Enter key again, provide a string of given length that will represent caterpillar.
  Next n-lines should consist of strings that would represent a map (@ - void sign).
## Output
  Output gives us coordinates after all moves, which letters caterpillar contains, and the final state of the map.
  If caterpillar dies before executing all moves, output gives us death coordinates and a hash sign.
  
