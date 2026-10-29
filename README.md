# Primitive Recursive Functions

This academic project implements the **power function over natural numbers** as a **primitive recursive function (FPR)** in C++23, following the definitions of the Computational Complexity course at the University of La Laguna. The program accepts a base and an exponent on the command line and prints both the result and the number of calls to primitive recursive functions used to calculate it.

The program does not use `std::pow` or built-in addition/multiplication operators to implement the arithmetic of the power function. It constructs addition using successor, multiplication using addition and power using multiplication, through composition and primitive recursion.

## Author

Javier Acosta Portocarrero

## Structure

The source code is organized into the following classes:

- **FPR**: abstract base class defining `virtual Evaluate(const std::vector<unsigned>&)` and the interface for obtaining and resetting call counts. Every object has its own (non-static) call counter, inherited from `FPR`.
- **Zero**: initial function $Z(x) = 0$.
- **Successor**: initial function $S(x) = x + 1$.
- **Projection**: initial function $P_i^n(x_1, \ldots, x_n) = x_i$, with a one-based index `i` specified at construction.
- **Addition**: obtains addition from primitive recursion, using private objects of `Projection` and `Successor`.
- **Multiplication**: obtains multiplication from primitive recursion, using private objects of `Zero`, `Projection` and `Addition`.
- **Power**: obtains exponentiation from primitive recursion, using private objects of `Zero`, `Successor`, `Projection` and `Multiplication`.
- **InputException** and **FPRException**: custom exceptions derived from `std::runtime_error` for invalid arguments and invalid FPR evaluations.

Each higher-level function owns the same lower-level function objects. Their counters are not static and are not shared between independent `Power` instances. When querying a `Power` object, the counters of all its contained objects are combined, including different instances of the same function (for example, the `Successor` in `Power` and in its nested `Addition`).

Composition is implemented through explicit calls to projections and lower-level primitive recursive functions. Unlike implementations using a separate Composition class, composition operations themselves are not counted as function calls.

## Definition as primitive recursive functions

The basic PRF used are the following:

- **Zero:** $Z(x) = 0$.
- **Successor:** $S(x) = x + 1$.
- **Projection:** $P_i^n(x_1, \ldots, x_n) = x_i$.

Using composition and primitive recursion over the second argument, the program defines:

**Addition**

Limit equation:

$$
A(x,0) = g(x) = P_1^1(x) = x
$$

Recursion equation:

$$
\begin{aligned}
A(x,S(y)) &= h(x,y,A(x,y))\\
&= (S \circ P_3^3)(x,y,A(x,y))
\end{aligned}
$$

**Multiplication**

Limit equation:

$$
M(x,0) = g(x) = Z(x) = 0
$$

Recursion equation:

$$
\begin{aligned}
M(x,S(y)) &= h(x,y,M(x,y))\\
&= (A \circ (P_3^1 \times P_3^3))(x,y,M(x,y))
\end{aligned}
$$

**Power**

Limit equation:

$$
P(x,0) = g(x) = (S \circ Z)(x) = 1
$$

Recursion equation:

$$
\begin{aligned}
P(x,S(y)) &= h(x,y,P(x,y))\\
&= (M \circ (P_1^3 \times P_3^3))(x,y,P(x,y))
\end{aligned}
$$

The convention is **$0^0 = 1$**, because $P(x,0) = 1$ for every natural base $x$.

## Compilation and execution

Install `g++` (C++23 support) and `make`. From the root of the project:

```bash
make
```

The executable is generated at `build/primitive_recursive_functions`. Run it with `-x` (base) and `-y` (exponent) options in any order:

```bash
./build/primitive_recursive_functions -x 2 -y 3
```

Output example:

```text
Result: 8
Function calls: 95
Calls by function:
  Addition: 21
  Multiplication: 10
  Power: 4
  Projection: 41
  Successor: 15
  Zero: 4
```

Non-natural numbers, arguments outside the range of `unsigned`, unknown flags, repeated flags and missing options are rejected with an error message and usage information. A mathematical result exceeding the range of `unsigned` throws `FPRException` as soon as the overflow is reached by `Successor`.

To remove compiled files:

```bash
make clean
```
