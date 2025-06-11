# Find the Index of the First Occurrence in a String

This problem requires finding the starting index of the first occurrence of a substring (needle) within a string (haystack).

## Problem Summary

Given two strings, `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Input:**
- `char* haystack`: The main string to search within.
- `char* needle`: The substring to search for.

**Output:**
- An integer representing the first starting index of `needle` in `haystack`.
- Return `-1` if `needle` is not found.

## Approach and Rationale

The solution leverages the `strstr` function from the C standard library, which finds the first occurrence of a substring within a string. Here’s a brief breakdown:

1. **Using `strstr`**: `strstr(haystack, needle)` returns a pointer to the first occurrence of `needle` in `haystack`, or `NULL` if `needle` is not found.
2. **Index Calculation**: If `needle` is found, the difference between the pointer returned by `strstr` and the original `haystack` pointer gives the starting index.
3. **Handling Not Found**: If `strstr` returns `NULL`, return `-1`.

**Code Snippet:**
```
int strStr(char* haystack, char* needle) {
    char *found = strstr(haystack, needle);
    if (!found) {
        return -1;
    }
    return found - haystack;
}
```

## Time and Space Complexity

- **Time Complexity**: The time complexity is O(n * m), where `n` is the length of `haystack` and `m` is the length of `needle`. This is because in the worst case, `strstr` might need to check every possible starting position in `haystack`.
- **Space Complexity**: The space complexity is O(1) as no additional space is used that scales with the input size.

## Key Test Cases

1. **Basic Case**: `haystack = "hello", needle = "ll"` -> Output: `2`
2. **Not Found**: `haystack = "aaaaaa", needle = "bbb"` -> Output: `-1`
3. **Empty Needle**: `haystack = "aabcde", needle = ""` -> Output: `0` (Most C implementations of strstr treat an empty needle as returning the start of haystack).
4. **Empty Haystack**: `haystack = "", needle = "a"` -> Output: `-1`
5. **Both Empty**: `haystack = "", needle = ""` -> Output: `0`

## Extra Insights or Gotchas

- **Edge Cases**: Handle cases where `needle` is empty. In such cases, the function should ideally return `0` to signify that an empty substring is found at the beginning.
- **Performance**: While `strstr` is efficient for most practical purposes, it may not be optimal for very large strings due to its time complexity. For better performance, consider implementing a more advanced string matching algorithm like Knuth-Morris-Pratt (KMP) or Rabin-Karp.