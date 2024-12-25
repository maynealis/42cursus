## Next steps
- Recerca debug with vscode
- Documentar functions
- Testejar functions
- Fer els bonus
- check for leaks

## TODO
- TODO: ft_memmove: creo que no gestiono bien el tema de que el destino se sobreescriga con el src.
- TODO: ft_strlen what to do when a NULL is passed? What happens if the string is not NULL-terminated and what happens if the size is bigger than size_t...?
- TODO: ft_bzero quan pooso una n bastant gran, per exemple 128, peta. Suposo que perque estic accedint a posicions de memoria que no tinc permis. Hauria de restringir la funcio suposo? el bzero tambe peta en aquest cas...

## Progress

|Research|Program|Testing|Doc|
|--------|-------|-------|---|
|-|33|||

|date|hours|task|
|----|-----|----|
|18-12-24|3|Prepare structure project and functions ft_isalpha to ft_isprint|
|19-12-24|8|Functions ft_strlen to ft_memmove|
|20-12-24|4.5|Functions ft_strlcpy to ft_strnstr|
|21-12-24|4|Functions ft_atoi to ft_strdup|
|22-12-24|2.5|Functions ft_substr and ft_strjoin|
|23-12-24|9|Functions ft_strtrim to ft_striteri|
|24-12-24|2|Functions ft_putchar_fd to ft_putnbr_fd|

## List of functions
### Part 1
|Function|Done|Test|Doc|Notes|
|--------|----|----|---|-----|
|ft_isalpha|x|x|||
|ft_isdigit|x|x|||
|ft_isalnum|x|x|||
|ft_isascii|x|x|||
|ft_isprint|x|x|||
|ft_strlen|x|x||TODO: what to do when a NULL is passed? What happens if the string is not NULL-terminated and wha    t happens if the size is bigger than size_t...?|
|ft_memset|x|x|||
|ft_bzero|x|x|||
|ft_memcpy|x|-|||
|ft_memmove|x|-|||
|ft_strlcpy|x|-|||
|ft_strlcat|x|-|||
|ft_toupper|x|x|||
|ft_tolower|x|x|||
|ft_strchr|x|-|||
|ft_strncmp|x|-|||
|ft_memchr|x|-|||
|ft_memcmp|x|-|||
|ft_strnstr|x|-|||
|ft_atoi|x|-|||
|ft_calloc|x|-|||
|ft_strndup|x|-|||

### Part 2
|Function|Done|Test|Doc|
|--------|----|----|---|
|ft_substr|x|x||
|ft_strjoin|x|x||
|ft_strtrim|x|x||
|ft_split|x|x||
|ft_itoa|x|x||
|ft_strmapi|x|x||
|ft_striteri|x|x||
|ft_putchar_fd|x|-||
|ft_putstr_fd|x|-||
|ft_putendl_fd|x|-||
|ft_putnbr_fd|x|-||

### Bonus
|Function|Done|Test|Doc|
|--------|----|----|---|
|ft_lstnew||||
|ft_lstadd_front||||
|ft_lstsize||||
|ft_lstlast||||
|ft_lstadd_back||||
|ft_lstdelone||||
|ft_lstclear||||
|ft_lstiter||||
|ft_lstmap||||






