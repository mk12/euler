NB. Copyright 2020 Mitchell Kember. Subject to the MIT License.
NB. Project Euler: Problem 13
NB. Large sum

numbers =: , ". ;. _2 (0 : 0)
37107287533902102798797998220837590246510135740250x
46376937677490009712648124896970078050417018260538x
74324986199524741059474233309513058123726617309629x
91942213363574161572522430563301811072406154908250x
23067588207539346171171980310421047513778063246676x
89261670696623633820136378418383684178734361726757x
28112879812849979408065481931592621691275889832738x
44274228917432520321923589422876796487670272189318x
47451445736001306439091167216856844588711603153276x
70386486105843025439939619828917593665686757934951x
62176457141856560629502157223196586755079324193331x
64906352462741904929101432445813822663347944758178x
92575867718337217661963751590579239728245598838407x
58203565325359399008402633568948830189458628227828x
80181199384826282014278194139940567587151170094390x
35398664372827112653829987240784473053190104293586x
86515506006295864861532075273371959191420517255829x
71693888707715466499115593487603532921714970056938x
54370070576826684624621495650076471787294438377604x
53282654108756828443191190634694037855217779295145x
36123272525000296071075082563815656710885258350721x
45876576172410976447339110607218265236877223636045x
17423706905851860660448207621209813287860733969412x
81142660418086830619328460811191061556940512689692x
51934325451728388641918047049293215058642563049483x
62467221648435076201727918039944693004732956340691x
15732444386908125794514089057706229429197107928209x
55037687525678773091862540744969844508330393682126x
18336384825330154686196124348767681297534375946515x
80386287592878490201521685554828717201219257766954x
78182833757993103614740356856449095527097864797581x
16726320100436897842553539920931837441497806860984x
48403098129077791799088218795327364475675590848030x
87086987551392711854517078544161852424320693150332x
59959406895756536782107074926966537676326235447210x
69793950679652694742597709739166693763042633987085x
41052684708299085211399427365734116182760315001271x
65378607361501080857009149939512557028198746004375x
35829035317434717326932123578154982629742552737307x
94953759765105305946966067683156574377167401875275x
88902802571733229619176668713819931811048770190271x
25267680276078003013678680992525463401061632866526x
36270218540497705585629946580636237993140746255962x
24074486908231174977792365466257246923322810917141x
91430288197103288597806669760892938638285025333403x
34413065578016127815921815005561868836468420090470x
23053081172816430487623791969842487255036638784583x
11487696932154902810424020138335124462181441773470x
63783299490636259666498587618221225225512486764533x
67720186971698544312419572409913959008952310058822x
95548255300263520781532296796249481641953868218774x
76085327132285723110424803456124867697064507995236x
37774242535411291684276865538926205024910326572967x
23701913275725675285653248258265463092207058596522x
29798860272258331913126375147341994889534765745501x
18495701454879288984856827726077713721403798879715x
38298203783031473527721580348144513491373226651381x
34829543829199918180278916522431027392251122869539x
40957953066405232632538044100059654939159879593635x
29746152185502371307642255121183693803580388584903x
41698116222072977186158236678424689157993532961922x
62467957194401269043877107275048102390895523597457x
23189706772547915061505504953922979530901129967519x
86188088225875314529584099251203829009407770775672x
11306739708304724483816533873502340845647058077308x
82959174767140363198008187129011875491310547126581x
97623331044818386269515456334926366572897563400500x
42846280183517070527831839425882145521227251250327x
55121603546981200581762165212827652751691296897789x
32238195734329339946437501907836945765883352399886x
75506164965184775180738168837861091527357929701337x
62177842752192623401942399639168044983993173312731x
32924185707147349566916674687634660915035914677504x
99518671430235219628894890102423325116913619626622x
73267460800591547471830798392868535206946944540724x
76841822524674417161514036427982273348055556214818x
97142617910342598647204516893989422179826088076852x
87783646182799346313767754307809363333018982642090x
10848802521674670883215120185883543223812876952786x
71329612474782464538636993009049310363619763878039x
62184073572399794223406235393808339651327408011116x
66627891981488087797941876876144230030984490851411x
60661826293682836764744779239180335110989069790714x
85786944089552990653640447425576083659976645795096x
66024396409905389607120198219976047599490197230297x
64913982680032973156037120041377903785566085089252x
16730939319872750275468906903707539413042652315011x
94809377245048795150954100921645863754710598436791x
78639167021187492431995700641917969777599028300699x
15368713711936614952811305876380278410754449733078x
40789923115535562561142322423255033685442488917353x
44889911501440648020369068063960672322193204149535x
41503128880339536053299340368006977710650566631954x
81234880673210146739058568557934581403627822703280x
82616570773948327592232845941706525094512325230608x
22918802058777319719839450180888072429661980811197x
77158542502016545090413245809786882778948721859617x
72107838435069186155435662884062257473692284509516x
20849603980134001723930671666823555245252804609722x
53503534226472524250874054075591789781264330331690x
)

10 {. ": +/ numbers

NB. Parse numbers as a multiline string (0 : 0) broken into lines (;. _2),
NB. execute it as J syntax (".), and flatten into a list (,). Use the 'x' suffix
NB. on numbers for arbitrary precision integers.
NB.
NB.     , ". ;. _2 (0 : 0)
NB.
NB. Calculate the sum of the numbers.
NB.
NB.     +/ numbers
NB.
NB. Convert to text (":) and take the first 10 digits (10 {.).
NB.
NB.     10 {. ":
NB.
