## Wat?
Basically a auto-completion system that gives an average number of inputs given to obtain a word, from a dataset file.
## File structure
- `etc` is for external resources (images, video, audio, etc.). The dataset files are on `etc`
- `src` is for source code
- `doc` is for documentation
- `lib` is for putting libraries. ex: lib/foo/[*.c,*.h]
- `README.md` is a general README file
- `CONTRIBUTING.md` is basically a FAQ for contributors
- `Makefile` is for use with `make`
## Possible Solution
So, the way that I need to do things is to find a way to create a graph structure in wich the nodes have values asssociated with them.
Based on the number of outgoing connections of the current node we determine if and where we are going next.

### Graph 1
So, this input here:

``` sh
hello
hell
heaven
goodbye
```

Would create something like this:

```
he -> aven
|
v
ll -> o

goodbye
```

Which would give a result of `2.0`

### Graph 2

Input:

``` sh
structure
structures
ride
riders
stress
solstice
ridiculous
```

Graph:

```
s -> tr -> ucture -> s
|     |
|     v
v    ess
olstice

rid -> e -> rs
|
v
iculous
```
