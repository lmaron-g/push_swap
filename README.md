# push_swap

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

![push_swap](https://user-images.githubusercontent.com/45558274/58187437-6f55c300-7cbf-11e9-9a7f-924f36abd475.gif)

## Installation

This project includes my `libft`. For normal work, I advise you to use:

```
git clone --recurse-submodules git@github.com:lmaron-g/push_swap.git; cd push_swap; make
```

## Run

```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

### Simple usage:

`./push_swap [STACK]` - `OUTPUT`: operation to sort the stack

`./checker [-v (visualize)] [STACK]` - `INPUT`: operation to sort the stack. `OUTPUT`: operation to sort the stack

Also you can test `push_swap` with `sh tester.sh`
