## Requisits

|Conversion|Auxiliar function|
|----------|-----------------|
|c         |write_char       |
|s         |write_str        |
|p         |write_hexa_min|
|d         |write_int
|i         |write_int (uses write\_str)|
|u         |write_int (uses wite\_str)|
|x         |write_hexa_min
|X         |write_hexa_may
|%         |write_char       | 

[x] %c Imprime un solo carácter.
[x] %s Imprime una string (como se define por defecto en C).
[ ] %p El puntero void * dado como argumento se imprime en formato hexadecimal.
[x] %d Imprime un número decimal (base 10). TODO: different in limit negative...
[x] %i Imprime un entero en base 10.
[ ] %u Imprime un número decimal (base 10) sin signo.
[ ] %x Imprime un número hexadecimal (base 16) en minúsculas.
[ ] %X Imprime un número hexadecimal (base 16) en mayúsculas.
[/] %% para imprimir el símbolo del porcentaje.

### Bonus requisits

|flag|with|manual|
|----|----|------|
|-  ||The  converted  value  is  to  be left adjusted on the field boundary.  (The default is right justification.)  The converted value is padded on the right with  blanks,  rather than on the left with blanks or zeros.|
|0  ||The value should be zero padded.  For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the converted value is padded on the left with zeros rather than blanks. If the  0  and - flags both appear, the 0 flag is ignored.  If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0 flag is ignored.   For  other  conversions, the behavior is undefined.|
|.  |||
|#   |x X |The value should be converted to an "alternate form". For x and X conversions, a nonzero result has the string "0x" (or "0X"  for  X conversions)  prepended  to it. For other conversions, the result is undefined.|
|' '||A blank should be left before a positive number (or empty string) produced by a signed conversion.|
|+  ||A sign (+ or -) should always be placed before a number produced by  a  signed  conversion.   By default, a sign is used only for negative numbers.  A + overrides a space if both are used.|
      
      
      



## Implementation

int chars = 0;

while str[i] != '\0'
	
	i++








## References
[variadic functions](https://onepunchcoder.medium.com/variadic-functions-explained-fd3b4ab6fd84)
[printf](https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_en.html)
[IBM documentation printf](https://www.ibm.com/docs/en/i/7.5?topic=functions-printf-print-formatted-characters)
