NB.  Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB.  Project Euler: Problem 17
NB.  Number letter counts

f =: [: +/ [: #"1 ;. _1 ' ' , ]
and =: f 'and'
hundred =: f 'hundred'
one_thousand =: f 'one thousand'
a =: f 'one two three four five six seven eight nine'
b =: f 'ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen'
c =: f 'twenty thirty forty fifty sixty seventy eighty ninety'
s99 =: (10 * c) + (9 * a) + b
(10 * s99) + (100 * a) + (9 * 100 * hundred) + (9 * 99 * and) + one_thousand

NB. Prepend a space (' ' , ]), split on the first character (;. _1), count
NB. characters in each word (#"1), and take the sum (+/).
NB.
NB.     [: +/ [: #"1 ;. _1 ' ' , ]
NB.
