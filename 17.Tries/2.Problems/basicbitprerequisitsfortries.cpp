/*
# Bit Prerequisites for TRIE Problems

Before solving **Bit Trie** problems like:

* Maximum XOR of Two Numbers — LeetCode 421
* Maximum XOR With an Element From Array — LeetCode 1707
* Min XOR / Max XOR
* XOR queries

you should be comfortable with these **bit manipulation concepts**.

---

## 1. Binary Representation

Every integer can be represented using bits.

For example:

```text
5 = 101
10 = 1010
25 = 11001
```

For Trie XOR problems, we usually process bits from:

```cpp
30 → 0
```

because `nums[i] <= 2^31 - 1`.

---

## 2. Get the i-th Bit ⭐⭐⭐

This is the **most important operation**.

```cpp
int bit = (num >> i) & 1;
```

Example:

```text
num = 5

Binary:
101
```

For `i = 2`:

```text
5 >> 2
= 101 >> 2
= 001

001 & 1
= 1
```

So the 2nd bit is `1`.

For `i = 1`:

```text
101 >> 1 = 010

010 & 1 = 0
```

So the 1st bit is `0`.

### Remember:

```cpp
(num >> i) & 1
```

means:

> **Give me the i-th bit of `num`.**

---

## 3. Right Shift `>>`

```cpp
num >> i
```

moves the bits to the right by `i` positions.

Example:

```text
12 = 1100

12 >> 1 = 0110 = 6
12 >> 2 = 0011 = 3
```

---

## 4. Left Shift `<<`

Very important for constructing an answer.

```cpp
1 << i
```

means:

> Put `1` at position `i`.

Example:

```text
1 << 0 = 0001 = 1
1 << 1 = 0010 = 2
1 << 2 = 0100 = 4
1 << 3 = 1000 = 8
```

So when we write:

```cpp
ans = ans | (1 << i);
```

we are setting the `i-th` bit of `ans` to `1`.

---

## 5. XOR `^` ⭐⭐⭐

XOR follows:

```text
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
```

The important rule is:

> **Different bits → 1**
> **Same bits → 0**

Example:

```text
5  = 0101
25 = 11001

For matching lengths:

  00101
  11001
  -----
  11100 = 28
```

Therefore:

```cpp
5 ^ 25 = 28
```

---

# 6. Why Opposite Bit Gives Maximum XOR ⭐⭐⭐

This is the **main idea behind Bit Trie**.

Suppose our current bit is:

```text
num bit = 0
```

We want:

```text
0 XOR 1 = 1
```

So we search for:

```text
opposite = 1
```

If our current bit is:

```text
num bit = 1
```

we want:

```text
1 XOR 0 = 1
```

So we search for:

```text
opposite = 0
```

That's why we write:

```cpp
int opposite = 1 - bit;
```

Then:

```cpp
if(node->contains(opposite))
```

we choose it.

---

# 7. Setting a Bit in Answer

Suppose:

```text
num bit = 0
opposite bit = 1
```

Then XOR gives us `1`.

We need to put that `1` into our answer:

```cpp
ans = ans | (1 << i);
```

Example, if `i = 3`:

```text
1 << 3

0001
 ↓↓↓
1000
```

Then:

```cpp
ans = ans | 8;
```

sets the 3rd bit.

---

# 8. Bit Trie Structure

Unlike normal Trie:

```text
'a' → 'z'
```

Bit Trie has only:

```text
0
1
```

So:

```cpp
Node* links[2];
```

Example:

```text
             root
            /    \
           0      1
          /        \
         0          1
        /            \
       1              0
```

Each level represents one bit.

For 31 bits:

```text
Level 30
   ↓
Level 29
   ↓
Level 28
   ↓
...
   ↓
Level 0
```

---

# 9. Basic Bit Trie Template

You should memorize this:

```cpp
class Node {
public:
    Node* links[2];

    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool contains(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};
```

### Insert

```cpp
void insert(int num) {
    Node* node = root;

    for(int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;

        if(!node->contains(bit)) {
            node->put(bit, new Node());
        }

        node = node->get(bit);
    }
}
```

### Maximum XOR

```cpp
int getMax(int num) {
    Node* node = root;
    int ans = 0;

    for(int i = 30; i >= 0; i--) {

        int bit = (num >> i) & 1;
        int opposite = 1 - bit;

        if(node->contains(opposite)) {
            ans = ans | (1 << i);
            node = node->get(opposite);
        }
        else {
            node = node->get(bit);
        }
    }

    return ans;
}
```

---

# 10. Why We Go From `30 → 0` ⭐⭐⭐

For maximum XOR, **higher bits are more important**.

For example:

```text
10000 = 16
01111 = 15
```

Even though `01111` has four `1`s, the number with the highest bit set is larger.

Therefore we process:

```cpp
for(int i = 30; i >= 0; i--)
```

*/