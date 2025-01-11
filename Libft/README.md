# Libft

### Progress

Total hores: 64.5

| Research | Program | Testing | Doc |
| -------- | ------- | ------- | --- |
| 1.5      | 34.5    | 21.5    | 6   |

| date     | hours     | task                                                               |
| -------- | --------- | ------------------------------------------------------------------ |
| 18-12-24 | 3         | Prepare structure project and functions ft\_isalpha to ft\_isprint |
| 19-12-24 | 8         | Functions ft\_strlen to ft\_memmove                                |
| 20-12-24 | 4.5       | Functions ft\_strlcpy to ft\_strnstr                               |
| 21-12-24 | 4         | Functions ft\_atoi to ft\_strdup                                   |
| 22-12-24 | 2.5       | Functions ft\_substr and ft\_strjoin                               |
| 23-12-24 | 9         | Functions ft\_strtrim to ft\_striteri                              |
| 24-12-24 | 2         | Functions ft\_putchar\_fd to ft\_putnbr\_fd                        |
| 25-12-24 | 3.5       | Tests for part1 functions                                          |
| 26-12-24 | 4 + 1.5   | Tests for part1 functions + Bonus functions done                   |
| 27-12-24 | 3.5 + 2   | Tests and docs                                                     |
| 31-12-24 | 1.5       | Research                                                           |
| 02-01-25 | 2.5 + 1.5 | Testing memmove + more docs                                        |
| 03-01-25 | 5         | Testing + more docs                                                |
| 04-01-25 | 2.5 + 2   | Fix ft\_split and ft\_lstmap + doc                                 |
| 05-01-25 | 2         | Revisar fitxers                                                    |

### List of functions

#### Part 1

| Function    | Done | Test | Doc | Notes                                                                                                                                                                           |
| ----------- | ---- | ---- | --- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ft\_isalpha | x    | x    | x   | No he conseguido cambiar el 'C' locale para probar con otros characters. Uso el ft\_isupper i ft\_islower que defino en otros archivos. No tengo claro si lo puedo hacer asi... |
| ft\_isdigit | x    | x    | x   |                                                                                                                                                                                 |
| ft\_isalnum | x    | x    | x   |                                                                                                                                                                                 |
| ft\_isascii | x    | x    | x   |                                                                                                                                                                                 |
| ft\_isprint | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strlen  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_memset  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_bzero   | x    | x    | x   | TODO?: Quedaria millor si utilitzo la funcio memset? Estic escribint el mateix...                                                                                               |
| ft\_memcpy  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_memmove | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strlcpy | x    | /    | x   | TODO: test propio                                                                                                                                                               |
| ft\_strlcat | x    | /    | x   | TODO: test propio                                                                                                                                                               |
| ft\_toupper | x    | x    | x   |                                                                                                                                                                                 |
| ft\_tolower | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strchr  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strrchr | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strncmp | x    | x    | x   |                                                                                                                                                                                 |
| ft\_memchr  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_memcmp  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strnstr | x    | x    | x   |                                                                                                                                                                                 |
| ft\_atoi    | x    | x    | x   |                                                                                                                                                                                 |
| ft\_calloc  | x    | x    | x   |                                                                                                                                                                                 |
| ft\_strdup  | x    | x    | x   |                                                                                                                                                                                 |

#### Part 2

| Function        | Done | Test | Doc | Notes                                             |
| --------------- | ---- | ---- | --- | ------------------------------------------------- |
| ft\_substr      | x    | x    | x   |                                                   |
| ft\_strjoin     | x    | x    | x   |                                                   |
| ft\_strtrim     | x    | x    | x   |                                                   |
| ft\_split       | x    | x    | x   |                                                   |
| ft\_itoa        | x    | x    | /   | Per que he de fer cast al define FT\_INT\_MIN??   |
| ft\_strmapi     | x    | x    | x   |                                                   |
| ft\_striteri    | x    | x    | x   |                                                   |
| ft\_putchar\_fd | x    | -    | x   | OK en salida standar. Pendiente probar en fichero |
| ft\_putstr\_fd  | x    | -    | x   | OK en salida standar. Pendiente probar en fichero |
| ft\_putendl\_fd | x    | -    | x   | OK en salida standar. Pendiente probar en fichero |
| ft\_putnbr\_fd  | x    | -    | x   | OK en salida standar. Pendiente probar en fichero |

#### Bonus

| Function          | Done | Test | Doc |
| ----------------- | ---- | ---- | --- |
| ft\_lstnew        | x    |      | x   |
| ft\_lstadd\_front | x    |      | x   |
| ft\_lstsize       | x    |      | x   |
| ft\_lstlast       | x    |      | x   |
| ft\_lstadd\_back  | x    |      | x   |
| ft\_lstdelone     | x    |      | x   |
| ft\_lstclear      | x    |      | x   |
| ft\_lstiter       | x    |      | x   |
| ft\_lstmap        | x    |      | x   |

### Fonts

* [memmove](https://marmota.medium.com/c-language-making-memmove-def8792bb8d5)
* [static library](https://makori-mildred.medium.com/how-to-create-static-library-in-c-and-how-to-use-it-b8b3e1fde999)
* \[[static library videos](https://www.youtube.com/watch?v=MMecMkU-B94)]
