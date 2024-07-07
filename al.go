// al - simply prints the alphabet

package main 

import (
	"flag"
	"fmt"
	"os"
	"sort"
	"unicode"
)

const version = 0.2

var nflag bool

var alphabet = map[rune]int{
	'a': 1,
	'b': 2,
	'c': 3,
	'd': 4,
	'e': 5,
	'f': 6,
	'g': 7,
	'h': 8,
	'i': 9,
	'j': 10,
	'k': 11,
	'l': 12,
	'm': 13,
	'n': 14,
	'o': 15,
	'p': 16,
	'q': 17,
	'r': 18,
	's': 19,
	't': 20,
	'u': 21,
	'v': 22,
	'w': 23,
	'x': 24,
	'y': 25,
	'z': 26,
}

func printAl(letter rune, num int) {
	if nflag {
		fmt.Printf("%c\n", letter)
	} else {
		if num < 10 {
			fmt.Printf("0%d. %c\n", num, letter)
		} else {
			fmt.Printf("%d. %c\n", num, letter)
		}
	}
}

func specificError() {
	fmt.Fprintf(os.Stderr, "error: al -s must be followed by a single letter(s).\n")
	os.Exit(1)
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
			specificError()
		}

		sort.Strings(items)

		for _, letter := range items {
			if len(letter) == 1 && unicode.IsLetter(letter[0]) {
				printAl(letter[0], alphabet[letter[0]])
			} else {
				specificError()
			}
		}
	} else {
		for curLet := 'a'; curLet <= 'z'; curLet++ {
			printAl(curLet, alphabet[curLet])
		}
	}
}
