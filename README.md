ExtendedBlip
============

An interpreter for a "fake" programming language called Blip (defined by Dr. Craig Chase). Blip is a simple language with only one type (signed int), if/while loops (using C conventions for converting integers to booleans), and functions (with local variables and parameters). Expressions in blip use prefix notation, so the expression:

    (x + 1) || (~x)

would be written as the following expression in blip:

    || + x 1 ~ x

This interpreter aims to also extend and change the syntax and style of the original language. The goal is to make ExtendedBlip look a little more like C and not be as difficult to type.

The interpreter takes code from stdin, so you can run tests like so:

    cat tests/test1.blip | ./blip

Or simply run Blip and use it as an interactive shell. You can see the tests to get a better idea of how Blip works. The following are the basic statements of Blip:

* output &lt;expression&gt;
* text &lt;single_word_string | "multiple word string"&gt;
* var &lt;var_name&gt; &lt;expression&gt;
* set &lt;var_name&gt; &lt;expression&gt;
* return &lt;expression&gt;

Blip uses a single space to separate all statement/operators/expressions, past that all whitespace is ignored. The C convention for // commenting is used.