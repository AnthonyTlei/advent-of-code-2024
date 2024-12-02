
# Advent Of Code 2024

This repository contains my solutions to the daily coding challenges, implemented in C++.





## Project Structure

The project is organized as follows:

```
./data/
├── day-1/
│   └── (input files for day 1)
├── day-2/
│   └── (input files for day 2)
...

./exercises/
├── day-1/
│   ├── part-1.cpp
│   └── part-2.cpp
├── day-2/
│   ├── part-1.cpp
│   └── part-2.cpp
...

./builds/
├── (compiled binaries are saved here)
├── day_1_part_1
├── day_1_part_2
...

builder.sh (wraps clang++ with std=C++20)
```
## Usage/Examples

```bash
./builder.sh exercises/day-1/part-1.cpp
./builds/day_1_part_1 > output/day_1_part_1.txt
```

