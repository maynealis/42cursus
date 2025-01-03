## Next steps
- Recerca debug with vscode
- Documentar functions
- Testejar functions
- Fer els bonus
- check for leaks

## TODO
- TODO: ft_memmove: creo que no gestiono bien el tema de que el destino se sobreescriga con el src. CASI TE DIRIA QUE LO REPITAS!!
- ft_memcpy: [crash]: your memcpy does not behave well with NULL as both params with size.

## Progress

|Research|Program|Testing|Doc|
|--------|-------|-------|---|
|1.5     |34.5   |14     |2  |

|date|hours|task|
|----|-----|----|
|18-12-24|3|Prepare structure project and functions ft_isalpha to ft_isprint|
|19-12-24|8|Functions ft_strlen to ft_memmove|
|20-12-24|4.5|Functions ft_strlcpy to ft_strnstr|
|21-12-24|4|Functions ft_atoi to ft_strdup|
|22-12-24|2.5|Functions ft_substr and ft_strjoin|
|23-12-24|9|Functions ft_strtrim to ft_striteri|
|24-12-24|2|Functions ft_putchar_fd to ft_putnbr_fd|
|25-12-24|3.5|Tests for part1 functions|
|26-12-24|4 + 1.5|Tests for part1 functions + Bonus functions done|
|27-12-24|3.5 + 2|Tests and docs|
|31-12-24|1.5|Research|
|02-01-25|2.5 + 1.5|Testing memmove + more docs|

## List of functions
### Part 1
|Function|Done|Test|Doc|Notes|
|--------|----|----|---|-----|
|ft_isalpha|x|x|x|No he conseguido cambiar el 'C' locale para probar con otros characters. Uso el ft_isupper i ft_islower que defino en otros archivos. No tengo claro si lo puedo hacer asi...|
|ft_isdigit|x|x|x||
|ft_isalnum|x|x|x||
|ft_isascii|x|x|x||
|ft_isprint|x|x|x||
|ft_strlen |x|x|x||
|ft_memset |x|x|x||
|ft_bzero  |x|x|x|Quedaria millor si utilitzo la funcio memset? Estic escribint el mateix...|
|ft_memcpy |x|x|x||
|ft_memmove|x|x|x|TODO: en la docu poner bien ejemplos de overlap.|
|ft_strlcpy|x|/|x|TODO: test propio|
|ft_strlcat|x|/|x|TODO: test propio|
|ft_toupper|x|x|x||
|ft_tolower|x|x|x||
|ft_strchr |x|x|x||
|ft_strrchr|x|x|x||
|ft_strncmp|x|x|x||
|ft_memchr |x|x|x||
|ft_memcmp |x|x|x||
|ft_strnstr|x|x|x||
|ft_atoi   |x|x|x||
|ft_calloc |x|x|||
|ft_strdup |x|x||Tengo que comprobar que no le pase NULL? Creo que la original no lo hace...|

### Part 2
|Function|Done|Test|Doc|Notes|
|--------|----|----|---|-----|
|ft_substr |x|x|||
|ft_strjoin|x|x|||
|ft_strtrim|x|x|||
|ft_split  |x|x|||
|ft_itoa   |x|x|||
|ft_strmapi|x|x|||
|ft_striteri|x|x|||
|ft_putchar_fd|x|-||OK en salida standar. Pendiente probar en fichero|
|ft_putstr_fd|x|-||OK en salida standar. Pendiente probar en fichero|
|ft_putendl_fd|x|-||OK en salida standar. Pendiente probar en fichero|
|ft_putnbr_fd|x|-||OK en salida standar. Pendiente probar en fichero|

### Bonus
|Function|Done|Test|Doc|
|--------|----|----|---|
|ft_lstnew|x|||
|ft_lstadd_front|x|||
|ft_lstsize|x|||
|ft_lstlast|x|||
|ft_lstadd_back|x|||
|ft_lstdelone|x|||
|ft_lstclear|x|||
|ft_lstiter|x|||
|ft_lstmap|x|||

## Fonts
- [memmove](https://marmota.medium.com/c-language-making-memmove-def8792bb8d5)






