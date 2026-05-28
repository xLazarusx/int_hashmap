# Hashmaps

## Hashing positive Integers

### Modular Hashing

- Simple and commonly used hashing method for positive integer keys
- Array Size M, is often choosen to be a prime number, to reduce clustering and improve distribution
- positive Integer key k
- Hash function: h(k) = k mod M => index of the bucket


### Modern Hashing of positive Integer

- Hashing the key with a hashfunction of choice
- H(k) computes the hash value
- M is typically chosen as a power of two
- Bucket-Index: h(k) = H(k) & (M-1) => index of the bucket
- This function calculates the index of the bucket


## Hashing floating-point numbers

- Modular Hashing with the Bits of the floating-point number
- bits(k) = Copy the Bits of the float into a integer Variable, NOT CONVERT.
- h(k) = bits(k) mod M => index of the bucket

## Hashing Strings

- using Horner's method
- for perfect collision using a R-value bigger than any character value
    - String is treated as an N-Digit Based-R computing the hash with modulo M
    - Cons:
        - Overflow can occur easily
        - computing is slower
    - Pros:
        - nearly no collision
- using a primenumber as the R-value
    - good balance between overflow risk and collision chance
    - normaly used to hash Strings
- Code Example(Java):
``` Java
int hash = 0;
for (int i = 0; i < s.length(); i++){
    hash = (R * hash + s.charAt(i)) % M;
}
```

## Hashing Compound Keys

- Compound Keys, are one Key with more the one Value, like date(day,month,year)
- using Horner's method to calculate hash
- just like in Strings described we combine every part of the Key to one hash
- If the R-value is sufficiently small, that no Integer overflow occurs we can skip the inner modulo steps
- one example of a sufficiently used R-value is a low primenumber, like 31
- In this example, a date gets hashed.
``` Java
int hash = (((day * R + month) % M) * R + year) %M;
```


