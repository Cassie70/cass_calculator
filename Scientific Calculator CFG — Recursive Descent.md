<expression> ::= <term> <expression-tail>

<expression-tail> ::= "+" <term> <expression-tail>
                    | "-" <term> <expression-tail>
                    | <epsilon>


<term> ::= <factor> <term-tail>

<term-tail> ::= <multiplication-operator> <factor> <term-tail>
              | <division-operator> <factor> <term-tail>
              | <implicit-multiplication> <factor> <term-tail>
              | <epsilon>


<multiplication-operator> ::= "\cdot"
                            | "\times"
                            | "*"


<division-operator> ::= "\div"
                       | "/"


<implicit-multiplication> ::= <epsilon>


<factor> ::= <unary> <factor-tail>

<factor-tail> ::= "^" <factor>
                | <epsilon>


<unary> ::= "+" <unary>
          | "-" <unary>
          | <postfix>


<postfix> ::= <atom> <postfix-tail>

<postfix-tail> ::= "!" <postfix-tail>
                 | <epsilon>


<atom> ::= <number>
         | <constant>
         | <variable>
         | <function>
         | <fraction>
         | <square-root>
         | <group>


<function> ::= <function-name> <function-argument>


<function-name> ::= "\sin"
                  | "\cos"
                  | "\tan"
                  | "\sec"
                  | "\csc"
                  | "\cot"
                  | "\arcsin"
                  | "\arccos"
                  | "\arctan"
                  | "\log"
                  | "\ln"
                  | "\exp"
                  | "\abs"


<function-argument> ::= <atom>
                      | "(" <expression> ")"
                      | "{" <expression> "}"


<fraction> ::= "\frac"
               "{"
               <expression>
               "}"
               "{"
               <expression>
               "}"


<square-root> ::= "\sqrt" <root-argument>


<root-argument> ::= <atom>
                  | "{"
                    <expression>
                    "}"


<group> ::= "(" <expression> ")"
          | "\left" "(" <expression> "\right)"
          | "{"
             <expression>
            "}"


<constant> ::= "\pi"
             | "\mathrm{e}"
             | "\phi"


<variable> ::= <letter> <identifier-tail>


<identifier-tail> ::= <letter> <identifier-tail>
                    | <digit> <identifier-tail>
                    | <epsilon>


<number> ::= <integer>
           | <decimal>


<integer> ::= <digit> <integer-tail>


<integer-tail> ::= <digit> <integer-tail>
                 | <epsilon>


<decimal> ::= <integer> "." <integer>


<letter> ::= "a" | "b" | "c" | "d" | "e" | "f" | "g"
           | "h" | "i" | "j" | "k" | "l" | "m" | "n"
           | "o" | "p" | "q" | "r" | "s" | "t" | "u"
           | "v" | "w" | "x" | "y" | "z"


<digit> ::= "0" | "1" | "2" | "3" | "4"
          | "5" | "6" | "7" | "8" | "9"


<epsilon> ::= ""
