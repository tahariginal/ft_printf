#                                                                                         ft_printf

A lightweight reimplementation of the standard C `printf` function supporting a subset of the most common format specifiers. The project builds a static library `libftprintf.a` that you can link against in other C projects.

## Supported Conversions
The following format specifiers are handled:

| Specifier | Meaning                        | Argument Type            |
|-----------|--------------------------------|--------------------------|
| `%c`      | Single character               | `int` (promoted char)    |
| `%s`      | C-string (null-terminated)     | `char *`                 |
| `%p`      | Pointer address (0x... or nil) | `void *` (printed as hex)|
| `%d` / `%i` | Signed decimal integer       | `int`                    |
| `%u`      | Unsigned decimal integer       | `unsigned int`           |
| `%x`      | Hexadecimal (lowercase)        | `unsigned int`           |
| `%X`      | Hexadecimal (uppercase)        | `unsigned int`           |
| `%%`      | Literal percent sign           | (no argument consumed)   |

Behavioral notes:
- `NULL` strings print as `(null)`.
- Null pointer (`%p` with argument 0) prints `(nil)`.
- Return value matches the total number of characters written, or `-1` on malformed final `%`.

## Project Structure
```
.
├── Makefile
├── ft_printf.c        # Core parser / dispatcher
├── ft_print_type.c    # Maps specifier -> print helper
├── ft_printf.h        # Public header
├── tools/             # Helper functions
│   ├── ft_putchar.c
│   ├── ft_putnbr.c
│   ├── ft_putstr.c
│   ├── ft_putunsigned.c
│   ├── ft_puthex.c
│   ├── ft_putadd.c
│   ├── ft_strlen.c
│   └── ft_strchr.c
└── main.c             # Example / ad‑hoc test (not part of lib)
```

## Building
Build the static library:
```
make
```
This produces `libftprintf.a`.

Clean object files:
```
make clean
```
Remove objects and library:
```
make fclean
```
Rebuild from scratch:
```
make re
```

## Using the Library
1. Include the header:
```c
#include "ft_printf.h"
```
2. Link the library when compiling your program:
```
cc your_program.c libftprintf.a -o your_program
```
(Ensure the library path is in the compile command, e.g. add `-L.` if needed.)

### Minimal Example
```c
#include "ft_printf.h"

int main(void) {
    int n = 42;
    ft_printf("Value: %d, Hex: %x, Ptr: %p, Str: %s\\n", n, n, &n, "hello");
    return 0;
}
```

## Variadic Function Explanation
`ft_printf` is a variadic function: it accepts a fixed first parameter (`const char *format`) followed by a variable number of additional arguments whose types are determined at runtime by parsing the format string.

Core mechanisms from `<stdarg.h>`:
1. `va_list ap;` declares a handle to traverse the unnamed arguments.
2. `va_start(ap, format);` initializes traversal; the second argument is the last named parameter.
3. `va_arg(ap, T)` fetches the next argument, casting / promoting as necessary (default argument promotions apply: `char` and `short` become `int`, `float` becomes `double`). You must request the correct type that matches the specifier.
4. `va_end(ap);` cleans up at the end.

In this project:
- `ft_printf` scans the format string. When it finds `%`, it looks at the next character (specifier) and dispatches to `ft_print_type`.
- `ft_print_type` receives the ongoing `va_list` by value (C passes this structure internally so copying is fine for single forward iteration) and calls `va_arg` with the appropriate expected type for each specifier.
- Each helper (e.g. `ft_putnbr`) prints the value and returns the number of characters written; these are summed for the overall return value.

### Why Pass `va_list` Instead of Individual Arguments?
Because the number and types of arguments are unknown at compile time. The `va_list` abstracts the stack (or register) layout so the function can sequentially consume each argument exactly once.

### Safety Considerations
- Mismatching the type in `va_arg` is undefined behavior (e.g., reading an `int` as `char *`). Always maintain the specifier/type mapping.
- You cannot "rewind" a `va_list` (unless you use `va_copy` beforehand); arguments are consumed in order.
- Always call `va_end` before returning from a variadic function to allow any platform-specific cleanup.

### Extending with New Specifiers
To add `%o` (octal) for example:
1. Implement `ft_putoctal(unsigned int n)`.
2. Declare it in `tools.h` and add its source to the Makefile list.
3. Extend the `if` chain in `ft_print_type` to handle `'o'` by calling your new helper.
4. Add `'o'` to the allowed characters in `ft_printf`'s `ft_strchr` test.

## Testing Ideas
- Compare outputs vs. system `printf` for each specifier.
- Edge cases: `NULL` string, zero pointer, INT_MIN, very large unsigned, consecutive percent signs like `%%`. 
- Measure return values to ensure character counts match expectations.

## License
Add your preferred license here (MIT, etc.).

## Author
Original author: tkoulal (1337 School). Adapted README generated by AI assistant.
