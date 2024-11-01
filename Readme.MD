# Sorting Games Data using various Algorithms

## Table of Contents

- [Overview](#overview)
- [Introdution](#introduction)
- [Project Structure](#project-structure)
- [Tasks](#tasks)
    - [Task 1 - Array Generation](#task-1-array-generation)
    - [Task 2 - Sorting Algorithms](#task-2-sorting-algorithms)
    - [Task 3 - Algorithm Comparisons](#task-3-algorithm-comparisons)
    - [Task 4 - Most Popular Games](#task-4-most-popular-games)
    - [Task 5 - Most Popular Games by Year](#task-5-most-popular-games-by-year)
    - [Task 6 - Faster Most Popular Games](#task-6-faster-most-popular-games)
- [CSV File Format](#csv-file-format)
- [Conclusion](#conclusion)
- [Author](#author)

## Overview

The primary objective of this project is to implement and evaluate various sorting algorithms and then process video game data sourced from a CSV file, `t4_ign.csv`. 

The project revolve around looking at the complexity of each sorting algorithm and comparing them for various tasks.

## Introduction

- This assignment revolved around using sorting algorithms to efficiently sort data.
- The data was a randomly generated using `t1.c` and retrieved form `t4_ign.csv`.
- Then, we used the sorting algorithms from `t2.c` to sort the data and compare the results.
- In part four, we used `t4_ign.csv`, which was a file of various games over last 20 years and their scores.
- This was stored efficiently in an array and in a matrix for `t5.c` and `t6.c`.
- Struct called Game was made to efficiently store the data.

## Project Structure

- **`t1.c`**: Program to generate different types of arrays for testing sorting algorithms.
- **`t2.c`**: Sorting algorithms (Insertion Sort, Selection Sort, and Quick Sort).
- **`t3.c`**: Comparison of sorting algorithms on various data patterns.
- **`t4.c`**: Program to read and sort games from a CSV file and display the top 10 games by score.
- **`t5.c`**: Extended functionality to categorize games by year and display the top 5 games per year.
- **`t6.c`**: It is a more optimised way of doing the task 4 in o(n) time.
- **`t4_ign.csv`**: CSV file containing video game data with columns: Title, Platform, Score, Year.

```
.
├── CMakeLists.txt
├── t1.c          # Array generation implementations
├── t1.h          # Header file for array generation
├── t2.c          # Sorting algorithms implementations
├── t2.h          # Header file for sorting algorithms
├── t3.c          # Testing and performance analysis
├── t4.c          # Read and sort games from a file
├── t5.c          # Categorize games by year sort them
├── t6.c          # Same as task 4 but faster 
├── t4_ign.csv    # File containing video game data
```

## Tasks

### Task 1 - Array Generation

In this task, five functions were implemented in `t1.c` to generate arrays of different types:

1. **Ascending Sorted Array**: Generates an array sorted in ascending order.
2. **Descending Sorted Array**: Generates an array sorted in descending order.
3. **Uniform Array**: Generates an array where all values are the same.
4. **Random Array without Duplicates**: Generates a randomly shuffled array with unique values.
5. **Random Array with Duplicates**: Generates a randomly shuffled array allowing duplicate values.


### Task 2 - Sorting Algorithms

In `t2.c`, three sorting algorithms were implemented:

1. **Insertion Sort**
    - Time Complexity: O(n²)
    - Space Complexity: O(1)
    - Efficient for small data sets
    - **Implementation**: Goes over the entire array, assuming the starting subset is sorted then inserting any next value in its right spot in the "sorted" subset.

2. **Selection Sort**
    - Time Complexity: O(n²)
    - Space Complexity: O(1)
    - In-place sorting algorithm
    - **Implementation**: Goes over the entire array and stores the minimum at the starting position, then goes over the unsorted subset from the next position onwards.


3. **Quick Sort**
    - Time Complexity: O(n log n) average case, O(n²) worst case.
    - Space Complexity: O(log n)
    - **Implementation**: A divide-and-conquer algorithm that recursively partitions the array around a chosen pivot.
    - Due to the recursive calling, we do have some memory overheard despite sorting in place, but it makes the implementation simpler.
    - I chose to pivot at arr[High] as this is the implementaion we looked at in the class & is straightforward.
    - The advantage here is that we can have a simpler implementaion but the drawback is that it performs poorly on sorted arrays. 

### Task 3 - Algorithm Comparisons

In `t3.c`, we evaluated the performance of each sorting algorithm by measuring the number of comparisons and swaps. The following metrics were recorded after sorting various types of arrays:

#### Results:
The result upon running the code is given below.

```commandline

Arrays of size 10000:
  Selection sort
                     TEST |     SORTED |      SWAPS |      COMPS |
sorted
                Ascending |        YES |          0 |   49995000 |
sorted
               Descending |        YES |       5000 |   49995000 |
sorted
                  Uniform |        YES |          0 |   49995000 |
sorted
      Random w duplicates |        YES |       9993 |   49995000 |
sorted
   Random w/o  duplicates |        YES |       8340 |   49995000 |


  Insertion sort
                     TEST |     SORTED |      SWAPS |      COMPS |
sorted
                Ascending |        YES |          0 |       9999 |
sorted
               Descending |        YES |   49995000 |   50004999 |
sorted
                  Uniform |        YES |          0 |       9999 |
sorted
      Random w duplicates |        YES |   24861942 |   24871941 |
sorted
   Random w/o  duplicates |        YES |   22567528 |   22577527 |


  Quick sort
                     TEST |     SORTED |      SWAPS |      COMPS |
sorted
                Ascending |        YES |   50004999 |   49995000 |
sorted
               Descending |        YES |   25004999 |   49995000 |
sorted
                  Uniform |        YES |       9999 |   49995000 |
sorted
      Random w duplicates |        YES |      89307 |     149811 |
sorted
   Random w/o  duplicates |        YES |      80698 |     161796 |


```


#### Performance Results & Comments

##### Selection Sort
- Consistent performance across all input types
- Always performs ~50M comparisons
- Performs ~10K swaps for unsorted arrays
- High comparison count for all cases

##### Insertion Sort
- Best performance on already sorted arrays (ascending)
- Worst performance on reverse sorted arrays (descending)
- Decent performance on uniform arrays

##### Quicksort
- Excellent performance on random arrays
- Reasonable performance on uniform arrays
- Worst case scenario in sorted arrays but that is due to our pivot choice.
- Higher number of comparisons but fewer swaps overall


### Task 4 - Most Popular Games

In `t4.c`, the code was written to read reviews from `t4_ign.csv` and sort them based on scores to identify the top 10 games. 

If two games have the same score, there was no secondary parameter used for comparing them further.

#### Results:
The result upon running the code is given below.

```commandline

Starting
file loaded
looping through data
Game sorting
Game sorted
10: Sonic The Hedgehog: Pocket Adventure : NeoGeo Pocket Color : 1999
10: Rayman Origins : PC : 2012
10: LittleBigPlanet (Game of the Year Edition) : PlayStation 3 : 2009
10: Mega Man 2 : Wii : 2008
10: Syphon Filter : PlayStation : 1999
10: LittleBigPlanet : PlayStation 3 : 2008
10: Rayman Origins : Xbox 360 : 2011
10: Rayman Origins : PlayStation 3 : 2011
10: Mario Golf: Advance Tour : Game Boy Advance : 2004
10: Crashmo : Nintendo 3DS : 2012

```

We can get similiar but different answers with different algorithms as they split the arrays in different ways, so if only one value of the struct is compared, it can result in various answers.
algorithms split the arrays in different ways, so if only one value of the struct is compared, it can result in various answers.

### Task 5 - Most Popular Games By Year


In `t5.c`, further categorization by year was implemented, allowing for the display of the top 5 games per year over the last 20 years.

**Approach for Task 5**: 
- To find the top 5 games for each year, I would maintain a separate array for each year and apply the sorting algorithm to each array after loading the data. 
- This would allow for efficient retrieval and display of top-ranked games by year.
- This was stored in C as a matrix/ an array of arrays.

#### Results:
The result upon running the code is given below.

```commandline

Starting
File loaded
Looping through data
Game sorting
Games sorted
10: Sonic The Hedgehog: Pocket Adventure : NeoGeo Pocket Color : 1999
10: Rayman Origins : PC : 2012
10: LittleBigPlanet (Game of the Year Edition) : PlayStation 3 : 2009
10: Mega Man 2 : Wii : 2008
10: Syphon Filter : PlayStation : 1999
10: LittleBigPlanet : PlayStation 3 : 2008
10: Rayman Origins : Xbox 360 : 2011
10: Rayman Origins : PlayStation 3 : 2011
10: Mario Golf: Advance Tour : Game Boy Advance : 2004
10: Crashmo : Nintendo 3DS : 2012

Games sorted by year:

Year 1996:
10: Wave Race 64 : Nintendo 64 : 1996
10: Super Mario 64 : Nintendo 64 : 1996
9: NHL FaceOff : PlayStation : 1996
9: X-COM: UFO Defense : PlayStation : 1996
9: NBA In the Zone 2 : PlayStation : 1996

Year 1997:
10: GoldenEye 007 : Nintendo 64 : 1997
10: Final Fantasy VII : PlayStation : 1997
9: International Superstar Soccer 64 : Nintendo 64 : 1997
9: Blast Corps : Nintendo 64 : 1997
9: Star Fox 64 : Nintendo 64 : 1997

Year 1998:
10: Metal Gear Solid : PlayStation : 1998
10: Xenogears : PlayStation : 1998
10: Half-Life : PC : 1998
10: Colony Wars: Vengeance : PlayStation : 1998
10: Gran Turismo [1998] : PlayStation : 1998

Year 1999:
10: Soulcalibur : Dreamcast : 1999
10: Checkered Flag : Lynx : 1999
10: Pokemon Blue Version : Game Boy : 1999
10: Unreal Tournament [1999] : PC : 1999
10: Sid Meier's Alpha Centauri : PC : 1999

Year 2000:
10: Jet Grind Radio : Dreamcast : 2000
10: Samba de Amigo : Dreamcast : 2000
10: Pokemon Silver Version : Game Boy Color : 2000
10: Pokemon Gold Version : Game Boy Color : 2000
10: Excitebike 64 : Nintendo 64 : 2000

Year 2001:
10: Dragon Warrior III : Game Boy Color : 2001
10: Super Smash Bros. Melee : GameCube : 2001
10: Samba de Amigo Ver. 2000 : Dreamcast : 2001
10: Golden Sun : Game Boy Advance : 2001
10: Tony Hawk's Pro Skater 2 : Game Boy Advance : 2001

Year 2002:
10: Tony Hawk's Pro Skater 3 : Game Boy Advance : 2002
10: Tom Clancy's Splinter Cell : Xbox : 2002
10: Grand Theft Auto: Vice City : PlayStation 2 : 2002
10: Metroid Prime : GameCube : 2002
10: Dance Dance Revolution Konamix : PlayStation : 2002

Year 2003:
10: Star Wars Knights of the Old Republic : Xbox : 2003
10: Pokemon Sapphire Version : Game Boy Advance : 2003
10: Grand Theft Auto Double Pack: Grand Theft Auto III & Grand Theft Auto: Vice City : PlayStation 2 : 2003
10: Super Mario Advance 4: Super Mario Bros. 3 : Game Boy Advance : 2003
10: Lemonade Tycoon : Wireless : 2003

Year 2004:
10: Sky Force : Wireless : 2004
10: Halo 4 (Game of the Year Edition) : Xbox 360 : 2004
10: Halo 2 (Limited Collector's Edition) : Xbox : 2004
10: Burnout 3: Takedown : Xbox : 2004
10: Prince of Persia: The Sands of Time : Wireless : 2004

Year 2005:
10: Forza Motorsport : Xbox : 2005
10: Grand Theft Auto: San Andreas : Xbox : 2005
10: Devil May Cry 3: Dante's Awakening : PlayStation 2 : 2005
10: Grand Theft Auto: San Andreas (Special Edition) : PlayStation 2 : 2005
10: Shadow of the Colossus : PlayStation 2 : 2005

Year 2006:
10: Mafia Wars: Yakuza : Wireless : 2006
10: Final Fantasy XII (Collector's Edition) : PlayStation 2 : 2006
10: Metal Gear Solid 3: Subsistence (Limited Edition) : PlayStation 2 : 2006
10: The Legend of Zelda: Twilight Princess : GameCube : 2006
10: Brothers in Arms 3D : Wireless : 2006

Year 2007:
10: BioShock (Limited Edition) : PC : 2007
10: Castlevania: Symphony of the Night : PlayStation Portable : 2007
10: God of War II : PlayStation 2 : 2007
10: Halo 3 (Legendary Edition) : Xbox 360 : 2007
10: Halo 3 (Collector's Edition) : Xbox 360 : 2007

Year 2008:
10: Super Mario RPG: Legend of the Seven Stars : Wii : 2008
10: Mega Man 3 : Wii : 2008
10: Mega Man 3 : NES : 2008
10: Gears of War 2 : Xbox 360 : 2008
10: Gears of War 2 (Limited Edition) : Xbox 360 : 2008

Year 2009:
10: Empire: Total War (Special Forces Edition) : PC : 2009
10: Fallout 3 -- Game of the Year Edition : Xbox 360 : 2009
10: Grand Theft Auto: Chinatown Wars : Nintendo DS : 2009
10: Call of Duty: Modern Warfare 2 : Xbox 360 : 2009
10: Call of Duty: Modern Warfare 2 : PlayStation 3 : 2009

Year 2010:
10: Battlefield: Bad Company 2 -- Vietnam : Xbox 360 : 2010
10: NBA 2K11 : PlayStation 3 : 2010
10: NBA 2K11 : Xbox 360 : 2010
10: Metal Gear Solid: Peace Walker : PlayStation Portable : 2010
10: Red Dead Redemption : Xbox 360 : 2010

Year 2011:
10: Super Mario 3D Land : Nintendo 3DS : 2011
10: The Legend of Zelda: Skyward Sword : Wii : 2011
10: The Legend of Zelda: Ocarina of Time 3D : Nintendo 3DS : 2011
10: Infinity Blade II : iPhone : 2011
10: The Legend of Zelda: Link's Awakening DX : Nintendo 3DS : 2011

Year 2012:
10: Halo 4 (Limited Edition) : Xbox 360 : 2012
10: Batman: Arkham City -- Armored Edition : Wii U : 2012
10: Pokemon White Version 2 : Nintendo DS : 2012
10: Diablo III : Macintosh : 2012
10: Zero Escape: Virtue's Last Reward : PlayStation Vita : 2012

Year 2013:
10: SteamWorld Dig : Nintendo 3DS : 2013
10: SteamWorld Dig : PlayStation Vita : 2013
10: SteamWorld Dig : PlayStation 4 : 2013
10: Rayman Legends : PlayStation 4 : 2013
10: Gone Home : Macintosh : 2013

Year 2014:
10: The Walking Dead: Season Two -- Episode 5: No Going Back : PlayStation 3 : 2014
10: FTL: Faster Than Light : PC : 2014
10: The Walking Dead: Season Two -- Episode 5: No Going Back : iPhone : 2014
10: Minecraft : PlayStation 4 : 2014
10: The Walking Dead: Season Two -- Episode 5: No Going Back : PlayStation Vita : 2014

Year 2015:
10: Grand Theft Auto V : PC : 2015
10: Fallout 4 : Xbox One : 2015
10: Pro Evolution Soccer 2016 : PlayStation 4 : 2015
10: Metal Gear Solid V: The Phantom Pain : PlayStation 4 : 2015
10: Metal Gear Solid V: The Phantom Pain : PC : 2015

Year 2016:
10: Inside : Xbox One : 2016
10: Inside : PlayStation 4 : 2016
10: Fire Emblem Fates: Revelation : Nintendo 3DS : 2016
10: Pro Evolution Soccer 2017 : Xbox One : 2016
10: Pro Evolution Soccer 2017 : PlayStation 4 : 2016


```


### Task 6 - Faster Most Popular Games

- In `t6.c`, the code was written to read reviews from `t4_ign.csv` and store them in a Matrix thus eliminating the need to sort them.
- This makes the code faster at the trade-off that it only works on exactly this kind of data (with scores form 0-10). 


#### Results:
The result upon running the code is given below.

```commandline
Starting
file loaded
looping through data
Game sorted
10: Undertale : Macintosh : 2016
10: Undertale : PC : 2016
10: The Witness : Xbox One : 2016
10: The Witness : PC : 2016
10: The Witness : PlayStation 4 : 2016
10: Pro Evolution Soccer 2017 : Xbox One : 2016
10: Pro Evolution Soccer 2017 : PlayStation 4 : 2016
10: Odin Sphere Leifthrasir : PlayStation Vita : 2016
10: Odin Sphere Leifthrasir : PlayStation 4 : 2016
10: Inside : PC : 2016
```

## CSV File Format

The `t4_ign.csv` file contains the following columns:

| Title                 | Platform     | Score | Year |
|-----------------------|--------------|-------|------|
| Game Title 1          | Platform 1   | 9     | 2001 |
| Game Title 2          | Platform 2   | 10    | 2005 |
| ...                   | ...          | ...   | ...  |


## Conclusion

- We looked at various algorithms and compared them for how they perform in various situations.
- Then they were used practically to sort a data set of Games.

## Author
- [DivyumSinghal]