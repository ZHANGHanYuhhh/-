# LeetCode
### 1.两数之和

给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

<table><td>
示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
</td></table>

分析：由于题目中数组没有顺序，直接暴力解决。从第一个数开始，与之后的数比较相加，等于target就返回。

时间复杂度O(n^2)，空间复杂度O(1)。

### 2.两数相加

给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字0之外，这两个数都不会以0开头。
<table><td>
示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)

输出：7 -> 0 -> 8

原因：342 + 465 = 807
</td></table>

分析：两个非负逆序链表相加，其实符合加法运算规则，实际上考察链表的合并操作，将两个链表从最低位开始逐位相加，计算本位和和进位
和，得到的本位结果作为新链表该位的值，进位送去下一节点计算，只要注意两个链表可能不一样长，以及最高位是进位得到的即可。

时间复杂度O(n+m)，空间复杂度O(max(n,m))。

### 3.无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
<table><td>
示例 1:

输入: "abcabcbb"

输出: 3

解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"

输出: 1

解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"

输出: 3

解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

  请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
</td></table>

分析：暴力解法，使用一个temp子串，初始化为空，从第一位开始通过ifHas函数（返回值为子串中该字符的位置，若不存在，返回-1）依次判断原输入字符串的字符是否在temp内，不在则添加进temp，在的话比较现在子串长度是否为最大长度，然后将子串替换为除去之前存在字符之后并添加了新字符的子串，如原子串为abcd，新插入字符为b，则新子串变为cdb，依次下去直到遍历完字符串，返回最大长度。

时间复杂度O(n^3)，空间复杂度O(m)其中m为最长子串。

### 4. 寻找两个有序数组的中位数

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

<table><td>
示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
</td></table>

分析：因为两个数组有序，实际上这是一个数组合并问题，只要比较两个数组的值的大小，然后插入新的数组中，使新数组有序，最后找出中位数即可。注意可能有一个数组为空即可。

时间复杂度O(n+m)，空间复杂度O(m+n)。

