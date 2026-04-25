# Compressor Tool

```No matter the data-structure IK the array will beat it. (coz of caching)```

## 1. Caching importance:
1. Data-cache, Instruction-cache, TLB-cache
2. If we optimize the D$, I$ we already have a good usage of TLB-cache
3. size:  l1  <  l2  <  l3

## 2. Compressing strategy: (generic idea)
- aaabbc  ->  6bytes
- ENCODE: a = 00, b = 10, c = 01
- 000000101001 -> 12bits -> 1.5bytes
- DECODE: get the value back

## 3. Usage:
