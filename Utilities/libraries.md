# Libraries

## Static libraries

A static library contains object code. It’s like a compressed file (`library.a`) that contains functions that you can use.

### How to create a static library

To compile (create object code from source code) without linking:

```bash
cc -c file.c #creates file.o
```

To create the static library (the compressed file), you use `ar`:

```bash
ar rcs library.a file1.o file2.o
```

Explanation of the flags:

* **\[ r ]**: Replaces existing files or inserts new files into the archive.
* **\[ c ]**: Ensures no error occurs if the library needs to be created.
* **\[ s ]**: Creates an index file (a [symbol table](https://en.m.wikipedia.org/wiki/Symbol_table) is required).

Other useful flags for the command `ar`:

* **\[ t ]**: List the specified files in the order in which they appear in the archive, each on a separate line.
* **\[ u ]:** Update files. When used with the -r option, files in the archive will be replaced only if the disk file has a newer modification time than the file in the archive.

[Manual for ar](https://man7.org/linux/man-pages/man1/ar.1.html)

## References

[Static library](https://makori-mildred.medium.com/how-to-create-static-library-in-c-and-how-to-use-it-b8b3e1fde999)

[Static library](https://www.youtube.com/watch?v=MMecMkU-B94) (video in Spanish)

[Dinamic libraries ](https://www.youtube.com/watch?v=DmbwkVvAmew)(video in Spanish)
