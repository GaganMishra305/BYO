# Compressor Tool

```No matter the data-structure IK the array will beat it. (coz of caching)```

## 1. Caching importance:
1. Data-cache, Instruction-cache, TLB-cache
2. If we optimize the D$, I$ we already have a good usage of TLB-cache
3. size:  l1  <  l2  <  l3

## 2. Compressing strategy: (generic idea)
- STEPS
    1. aaabbc  ->  6bytes
    2. ENCODE: a = 00, b = 10, c = 01
    3. 000000101001 -> 12bits -> 1.5bytes
    4. DECODE: get the value back
- CORE-IDEA: use smaller codes for more frequent characters

## 3. Usage:
```bash
make                                            # builds and runs the target code for the given "./tests/book.txt"
./build/huffman <file.txt>                      # runs the target on custom .txt file

make test                                       # runs the unit tests
make clean                                      # cleans the binaries
```
