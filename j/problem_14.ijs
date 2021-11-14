NB. Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB. Project Euler: Problem 14
NB. Longest Collatz sequence

NB. Mostly copied from:
NB. https://code.jsoftware.com/wiki/Essays/Collatz_Conjecture#A_Vector_Approach

NB. Computes the next Collatz number.
collatz =: 3 : 0
    NB. Calculate y/2 and 3y + 1 at the same time, and choose based on parity.
    <. (2 | y) } 0 1 + 0.5 3 */ y
)

NB. Computes the lengths of Collatz sequences starting at i. y.
lengths =: 3 : 0
    NB. Calculate exponents (m) for all powers of two (f) less than y.
    f =. 2 ^ m =. i. <. @ (2 & ^.) &. <: y
    m =. >: m
    NB. Produce a list of length y of the form _1 0 0 ... (y {. _1), and replace
    NB. items after the _1 with powers of two. Finally, append a zero.
    C =. 0 ,~ m f } y {. _1
    NB. Set j and i to the odd numbers 3 5 7 ... less than y.
    j =. i =. 3 + i. @ <. &. -: y - 2
    while. # i do.
        NB. Advance values in j to the next Collatz number.
        j =. collatz j
        NB. Identify j values whose place in C is positive.
        b =. 0 < (j <. y) { C
        NB. The rest is magic.
        p =. , f */ b # i
        q =. , m +/ (b # j) { C
        m =. >:m
        i =. (-. b) # i
        j =. (-. b) # j
        b =. y > p
        C =. (b # q) (b # p) } C
    end.
    }: C
)

(i. >./) lengths 1e6

NB. Get the Collatz sequence lengths starting from integers under one million.
NB.
NB.     lengths 1e6
NB.
NB. Get the index of the maximum.
NB.
NB.     (i. >./)
NB.
