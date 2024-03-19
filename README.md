# FiniteFields

C library for working with elements of finite fields.

## Main Features

- `ff_get_zero`: Returns the zero element of the finite field.
- `ff_get_identity`: Returns the identity element of the finite field.
- `ff_inv_add`: Calculates the inverse element under addition.
- `ff_inv_mult`: Calculates the inverse element under multiplication.

Operations under elements of the same finite field:

- `ff_add`: Performs addition of two elements.
- `ff_sub`: Calculates the difference between two elements.
- `ff_mult`: Multiplies two elements.
- `ff_div`: Divides one element of the finite field by another.

Other helpful features:

- `ff_2_8_init_elem` `ff_2_16_init_elem` `ff_2_32_init_elem`: Initializes an element of the finite field of the order 2^N from uintN_t.

## Building

To build the FiniteFields library, follow these steps:

1. Clone the repository:

    ```
    git clone https://github.com/PolinaSavelyeva/FiniteFields.git
    ```

2. Navigate to the FiniteFields directory:

    ```
    cd FiniteFields
    ```

3. Build the library using CMake:

    ```
    cmake .
    make
    ```

## Build Requirements

- CMake (version 3.10 or higher)
- clang compiler supporting C11 standard
- valgrind
