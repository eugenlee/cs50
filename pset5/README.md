# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

A lung disease caused by inhaling ash and dust.

## According to its man page, what does `getrusage` do?

It returns resource usage measures for calling the process.

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 members.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Because passing a pointer to a structure is much more efficient (time and memory-wise) than passing its value.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The for loop will keep retrieving next character in file (by fgetc) until EOF. There are three conditions to the loop:
1. Check to see if is alphabetic character or an apostrophe within a letter. If true, add character to word array at index and increment
   the index counter. But if index becomes larger than 45 characters, it is not a 'true' word, thereby skip this word using while
   loop and reset index to 0.
2. If the character is a digit, it will also be ignored in a similar manner as the word larger than 45 characters. Set index = 0.
3. If full word is found, add a NUL (\0) at the end of the word array and update counter of total words found. Then, check the spelling
   of the word and its resource usage by running rusage after and before calling the check function. Afterwards, update the benchmark
   by calling calculate and store output in time_check. If it is mispelled, print it, increase the number of mispelled words and set
   index = 0 to repeat for next words.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

By reading one character at a time, we are able to discern individual items rather than entire words that may incorrectly be
marked as mispelled if included a punctuation.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

We do not want to change our input pointers.
