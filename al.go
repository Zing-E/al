// al - simply prints the alphabet

package main 

import (
	"flag"
	"fmt"
	"os"
	"sort"
	"unicode"
)

type Al struct {
	letter rune
	num int
}

const version = 0.2

var nflag bool

var alphabet = []Al{
	{'a', 1},
	{'b', 2},
	{'c', 3},
	{'d', 4},
	{'e', 5},
	{'f', 6},
	{'g', 7},
	{'h', 8},
	{'i', 9},
	{'j', 10},
	{'k', 11},
	{'l', 12},
	{'m', 13},
	{'n', 14},
	{'o', 15},
	{'p', 16},
	{'q', 17},
	{'r', 18},
	{'s', 19},
	{'t', 20},
	{'u', 21},
	{'v', 22},
	{'w', 23},
	{'x', 24},
	{'y', 25},
	{'z', 26},
}

func printAl(a Al) {

	if !nflag {
		if a.num < 10 {
			fmt.Printf("0%d. %c\n", a.num, a.letter)
		} else {
			fmt.Printf("%d. %c\n", a.num, a.letter)
		}
	} else {
			fmt.Printf("%c\n", a.letter)
	}
}

func main() {

	hflag := flag.Bool("h", false, "Prints this menu.")
	sflag := flag.Bool("s", false, "Prints specific letter(s).")
	vflag := flag.Bool("v", false, "Prints the al version number.")
	flag.BoolVar(&nflag, "n", false, "Prints alphabet with no numbers.")

	flag.Parse()

	if *hflag {
		fmt.Println(`usage: 
  al [option] [letter(s)]
  al     - Prints the alphabet.
  al -h  - Prints this menu.
  al -n  - Prints the alphabet with no numbers
  al -s  - Prints specific letter(s)
  al -v  - Prints the al version number.`)
	
		return
	}

	if *vflag {
		fmt.Printf("al: version: %v\n", version)
		return
	}

	if *sflag {
		items := flag.Args()

		if len(items) == 0 {
			fmt.Fprintf(os.Stderr, "error: al -s must be followed by a single letter(s).\n")
			return
		}

		sort.Strings(items)

		for _, str := range items {
			if unicode.IsLetter(rune(str[0])) && len(str) == 1 {
				for _, al := range alphabet {
					if rune(str[0]) == al.letter {
						printAl(al)
						break
					}
				}
			} else {
				fmt.Fprintf(os.Stderr, "error: al -s must be followed by a single letter(s).\n")
				return
			}
		}
	} else {
		for _, al := range alphabet {
			printAl(al)
		}
	}
}
