# Czech Wordle Solver

C++ program to quickly find matching words for the game Wordle. This works for the Czech version of the game (czech uses characters from UTF-8), could be used also for the english version, after replacing the dictionary with an english one with exact format.

Play the game [here](https://hadejslova.cz/ "Hadej Slova")

## How to build

Inside wordle_solver_CZ/ do:
```bash
mkdir build
cd build
cmake ..
make
```

## How to run

After building just run this command inside the build folder:
```bash
./wordle_solver
```

## Usage
This program will help you if you have any type of information already (green or orange characters, known letters that are not in the word).

At first write a 5-letter word only with known letters at fixed positions (green letters) and unknown letters write like '?'.

Then behind it write all known (orange letters) seperated by empty spaces.

Then write '!' and behind it all letters that you know are not there.

The command has to contain the first part with the '?', second or third part can be left out. If you want to left out just the second one, you still have to write '!' behind the first part divided by empty spaces.

### Example
#### 1.
Lets say that you are at this stage of game:

[![Example](https://pbs.twimg.com/media/FKiM8WyXsAsPtzV.png)](https://pbs.twimg.com/media/FKiM8WyXsAsPtzV.png)

You will write and press enter:
```
??l?? e ! s m ů a o d í v ý t
```

#### 2.
Another example:
```
????? l a
```
Will find all words containing letter l and a.

#### 3.
Last example:
```
????? ! l a
```
Will find all words that do not contain letter l and a.
