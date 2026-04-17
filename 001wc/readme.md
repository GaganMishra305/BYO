# wc
Simple word counter.

```bash
make                            # builds the binary ccwc

ccwc -c filename.txt            # gives character count
ccwc -l filename.txt            # gives line count
ccwc -w filename.txt            # gives word count
cat filename.txt | ccwc -flag   # reads from standard input and follows the above flags

make clean                      # cleans the executables
```
