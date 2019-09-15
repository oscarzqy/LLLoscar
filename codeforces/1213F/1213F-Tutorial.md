## Official Tutorial

$$

$$

https://codeforces.com/problemset/problem/1213/F

https://codeforces.com/blog/entry/69464

Because if we write down all characters of s in order of both permutations and this string will be sorted, it is obvious that these two strings are equal. Let's try the maximum possible number of distinct characters and then replace extra characters with 'z'. How to find the maximum number of distinct characters?

Let's iterate over all values of p (and q) in order from left to right. If we staying at the position i now, let's add to the set vals1 the value pi and to the set vals2 the value qi. And when these sets become equal the first time, let's say that the block of positions i such that values pi are in the set right now, have the same letter, and then clear both sets. We can see that this segment of positions is the minimum by inclusion set that can contain equal letters. We don't need to compare sets naively and clear them naively, you can see implementation details in author's solution.

If the number of such segments is less than k then the answer is "NO", otherwise the answer is "YES" and we can fill the string s with letters in order of these segments (if the segment is [l;r] then all characters of s with indices pl,pl+1,…,pr has the same letter, the first segment has the letter 'a', the second one has the letter 'b', and so on, all segments after 25-th has the letter 'z').

Time complexity: O(nlogn).

My Idea

In the beginning I want find out the sets of those numbers where the characters are the same. To accomplish it I simply iterate over all values of p, if we are staying at the position i ,then correspondingly position j in the permutation q, and iterate backwards from j, find those numbers which its index is larger than i in the permutation p. It is obvious these characters on these positions we just find out are the same with s[pi]. We can use a DSU to find out how many distinct characters at least. But a big problem is that, time complexity is O(n^2) which I still don't know how to optimize it or is it possible to optimize?     

