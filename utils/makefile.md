# Makefile

In a Makefile, there are different rules (targets). The main goal is to have each rule with its dependencies and how it should be executed in a single file. To execute a rule, you simply write `make rule_name`.

```makefile
target: dependencies
    instructions
```

The first rule is the default rule and will be executed if you simply write `make`.

{% hint style="info" %}
To add comments: `#`
{% endhint %}

## Variables

* To define variables: `OBJS = main.o`
* To use variables: `$(OBJS)`

If you want to list multiple files in a variable, separate them with a _single space_. To split the list across multiple lines, use a `\` at the end of each line to escape the newline character. The next line does not need to be indented, but adding a tab can improve readability.

### Types of variables

For **recursively expanded variables**, the expansion will happen at execution time. If we redefine the variable multiple times, it will only be substituted at the end.

{% code fullWidth="false" %}
```makefile
# Recursively expanded variables (default)
VAR1 = value1
```
{% endcode %}

For **simply expanded variables**, the variable is expanded at the moment it is assigned. Therefore, if we later redefine the variable, it will not change what has already been expanded.

```makefile
# Simply expanded variables
VAR1 := value1
```

<details>

<summary>Example on different types of expanded variables</summary>

```makefile
VAR1 = value1
VAR2 = $(VAR1) value2
VAR1 = change1

print:
	@echo $(VAR1)
	@echo $(VAR2)

#output:
change1
change1 value2
```

```makefile
VAR1 = value1
VAR2 := $(VAR1) value2
VAR1 = change1

print:
	@echo $(VAR1)
	@echo $(VAR2)

#output:
change1
value1 value2
```

</details>

{% hint style="info" %}
To print something to the console, you can use `@echo`. The `@` suppresses the command output, so only the text following `@echo` is displayed.
{% endhint %}

## Patterns

* `%` is used to indicate any text.&#x20;

For example this is a rule for anything that ends with `.o`

```makefile
%.o: %.c
```

### Automatic Variables:

* `$<` —  The first prerequisite.
* `$^` — All prerequisites.
* `$?` — All prerequisites that are newer than the target.
* `$@` — The target name.

## Multiple files

You can include other Makefiles using `include`.

## .PHONY

The prerequisites of the special target `.PHONY` are considered to be phony targets. When it is time to consider such a target, `make` will run its recipe unconditionally, regardless of whether a file with that name exists or what its last-modification time is.

```makefile
clean:
        rm -rf $(OBJS)
        
.PHONY: clean
```

## Other things

About relink in libft, I found out that in the bonus part it is difficult to not do relink. Here are some solutions:

{% code title="@ikael in Slack" %}
```mathml
bonus: $(OBJS_BONUS)
	make O_OBJS="$(OBJS_BONUS)"
```
{% endcode %}

> By using `make O_OBJS="$(OBJS_BONUS)" all`, you're invoking `make` recursively while passing in a specific list of object files (`$(OBJS_BONUS)`) as an environment variable (`O_OBJS`).
>
> This allows you to reuse the `$(OBJS_BONUS)` variable for compiling and linking the bonus object files, without having to manually define all the compilation steps for the bonus files within the `bonus` rule. Instead, the `all` rule will handle the compilation and linking, using the newly passed `O_OBJS` variable.

## References

[Manual GNU Make](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents)

List of [videos](https://youtu.be/jI2n8jofuRg?si=dAzjhEb9VHUEL-d4) to understand basics of Make (in Spanish)

List of posts about Makefile that I want to read:

* [Part 1](https://medium.com/@adi.ashour/stuff-i-learned-about-makefiles-part-1-9b85986d7c59)
* [Part 2](https://medium.com/@adi.ashour/stuff-i-learned-about-makefiles-part-2-66d87109b19b)
* [Part 3](https://medium.com/@adi.ashour/stuff-i-learned-about-makefiles-part-3-7eaa1e0b918b)

