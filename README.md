# Czech Wordle Solver

A simple program to quickly find fitting words in the Czech version of the game Wordle.

Play the game [here](https://hadejslova.cz/ "Hadej Slova")

## How to build

Inside wordle_solver_CZ/ do:
```
mkdir build
cd build
cmake ..
make
```

## How to run

After building just run this command inside the build folder:
```
./wordle_solver
```

## Usage
This program will help you if you have any type of information already (green or orange character).

At first write a 5-letter word only with known letters at fixed positions (green letters) and unknown letters write like '?'.

Then behind it write all known (orange letters) seperated by empty spaces.

### Example
#### 1.
Lets say that you are at this stage of game:

[![Example](https://pbs.twimg.com/media/FKiM8WyXsAsPtzV.png)](https://pbs.twimg.com/media/FKiM8WyXsAsPtzV.png)

You will write and press enter:
```
??l?? e
```

#### 2.
Another example:
```
????? l a
```
Will find all words containing letter l and a.