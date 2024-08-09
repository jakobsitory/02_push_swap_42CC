# Push Swap
The **Push Swap** project is a challenge within the 42 School curriculum aimed at deepening students' understanding of sorting algorithms, data structures, and algorithmic complexity in C. The goal is to sort a stack of integers using a minimal number of operations, with the constraints of using only two stacks and a limited set of operations.

## **Task**

The task was to implement a program that sorts a stack of integers using a set of predefined operations. The program needs to handle various tasks such as:

- Sorting a stack (`stack_a`) using an auxiliary stack (`stack_b`) with a limited set of operations.
- Implementing efficient algorithms to sort stacks of varying sizes with the fewest possible operations.
- Handling edge cases such as empty input, duplicated numbers, and large sets of numbers.

**Key objectives included:**
- Designing algorithms that efficiently sort small and large sets of integers with minimal operations.
- Implementing operations such as `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr` to manipulate the stacks.
- Ensuring the program handles various edge cases, including invalid input and edge cases in sorting.

## **Key Achievements**
- Optimized Sorting Algorithms: Successfully implemented sorting algorithms tailored to handle small sets (3-5 elements) and larger sets (up to 500 elements) with minimal operations.
- Efficient Stack Manipulation: Developed a robust set of operations to manipulate the stacks, ensuring accurate and efficient sorting with minimal moves.
- Comprehensive Edge Case Handling: Integrated thorough error checking and handling to manage edge cases, ensuring the program's reliability and correctness in various scenarios.

## Installation

To install the Project, follow these steps:
1. Clone the repository: **`git clone git@github.com:jakobsitory/02_push_swap_42CC.git`**
2. Navigate to the project directory: **`cd 02_push_swap_42CC`**
3. Build the project: **`make`**

## **Usage**

The `push_swap` program is used to generate a list of operations that will sort the stack of integers provided as arguments. It should be executed as follows:

```bash
./push_swap [list_of_integers]
```

**Visualizing the algorithm:**

To visualize the sorting process using the [push_swap_visualizer]((https://github.com/o-reo/push_swap_visualizer)). To use the visualizer:
1. Clone the visualizer repository and follow the installation instructions provided.
2. Run your push_swap program with the list of integers and pipe the output to the visualizer.
