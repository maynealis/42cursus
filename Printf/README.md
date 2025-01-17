## Requisits

|Conversion|Auxiliar function|
|----------|-----------------|
|c         |write_char       |
|s         |write_str        |
|p         |write\_hexa or write_str|
|d         |write_int (uses write\_str)|
|i         |write_int (uses write\_str)|
|u         |write_uint (uses wite\_str)|
|x         |write_hexa       |
|X         |write_hexa       |
|%         |write_char       | 


### Bonus requisits

|flag|with|manual|
|----|----|------|
|-  ||The  converted  value  is  to  be left adjusted on the field boundary.  (The default is right justification.)  The converted value is padded on the right with  blanks,  rather than on the left with blanks or zeros.|
|0  ||The value should be zero padded.  For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the converted value is padded on the left with zeros rather than blanks. If the  0  and - flags both appear, the 0 flag is ignored.  If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0 flag is ignored.   For  other  conversions, the behavior is undefined.|
|.  |||
|#   |x X |The value should be converted to an "alternate form". For x and X conversions, a nonzero result has the string "0x" (or "0X"  for  X conversions)  prepended  to it. For other conversions, the result is undefined.|
|' '||A blank should be left before a positive number (or empty string) produced by a signed conversion.|
|+  ||A sign (+ or -) should always be placed before a number produced by  a  signed  conversion.   By default, a sign is used only for negative numbers.  A + overrides a space if both are used.|
      
      
-ddddddc
.ddddddc
0ddddddc




## Things I learned

### Argument Promotion
In C, the va_arg macro is designed to work with the type of argument that is passed to the variadic function, and it uses the promoted types of the arguments as part of its implementation. When you use va_arg with a char type, it will not work directly due to how argument promotion works in C.

In C, when you pass a char (or short) to a variadic function, it is **promoted to int** before being passed. This promotion rule is part of the C standard and is necessary because char and short types are usually too small to be reliably passed across function boundaries. The promotion to int ensures the correct handling of values and is consistent with the calling convention of most platforms.

Here’s how argument promotion works for char and short types in variadic functions:

    1. char and short values are promoted to int when passed to a function with ... (variadic function).
    2. float values are promoted to double.
    3. For types like int, long, double, etc., no promotion happens.

When you call va_arg to extract a char from the argument list, the argument has been promoted to int. Therefore, when you request va_arg to give you a char, you're essentially trying to fetch a promoted int as a char, which could lead to undefined behavior or an incorrect value.

To correctly retrieve a char from a variadic function, you should cast the result of va_arg to char. This is because va_arg always retrieves the type in its promoted form (which will be int), but you can explicitly cast it back to a char after retrieving it.



## References
[variadic functions](https://onepunchcoder.medium.com/variadic-functions-explained-fd3b4ab6fd84)
[printf](https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_en.html)
[IBM documentation printf](https://www.ibm.com/docs/en/i/7.5?topic=functions-printf-print-formatted-characters)
