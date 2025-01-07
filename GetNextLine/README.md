---
description: >-
  This project is about programming a function that returns a line read from a
  file descriptor.
---

# Get Next Line

## Requisits

Write a function that returns a line read from a file descriptor.

{% tabs %}
{% tab title="Prototype" %}
```
char *get_next_line(int fd);
```

Params

<table data-header-hidden><thead><tr><th width="131"></th><th width="571"></th><th data-hidden></th></tr></thead><tbody><tr><td><code>fd</code></td><td><p>The file descriptor to read from. <br><br>Options: </p><ul><li><strong>0</strong>: stdin (standard input)</li><li><strong>1</strong>: stdout (standard output) </li><li><strong>2</strong>: stderr (error standard output)</li></ul><p>Starting from <strong>3</strong> are the files opened. If a file is closed, the file descriptor (fd) can be reassigned, and <code>c</code> will likely do so.</p></td><td></td></tr></tbody></table>

Return

* **Read line**: correct behaviour
* **`NULL`**: there is nothing else to read, or an error ocurred.
{% endtab %}

{% tab title="Structure" %}
* `get_next_line.c` : contains...
* `get_next_line_utils.c` : contains...
* `get_next_line.h` : contains...
{% endtab %}

{% tab title="Functions used" %}
malloc, free, write
{% endtab %}
{% endtabs %}



## Progress

| Research | Program | Test | Doc |
| -------- | ------- | ---- | --- |
| 1.5      | 1.5     |      |     |

| Date       | Hours | Progress |
| ---------- | ----- | -------- |
| 05-01-2025 | 0.5   | Research |
| 06-01-2025 | 2.5   | Starting |

## References

&#x20;
