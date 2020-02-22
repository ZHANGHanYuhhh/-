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

### 5.最长回文子串

给定一个字符串 s，找到s中最长的回文子串。你可以假设s的最大长度为 1000。

<table><td>
示例 1：

输入: "babad"

输出: "bab"

注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"

输出: "bb"

</td></table>

分析：原本试图使用暴力解法，一个个子串去判断，两个指针，一个从前往后，一个从后往前，后面的找到与前面指针相同的字母，然后判断两指针之间的字符串是不是回文子串，时间复杂度O(n^3)，没有逃出测试样例的制裁，后来采取一次遍历，以一点或者两点为中心（该子串有可能奇数，有可能偶数），向两边展开，然后判断是否为回文子串。

时间复杂度O(n^3)，空间复杂度O(m)（最长回文子串长度）。

### 6.Z字形变换

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

![Image text](https://github.com/ZHANGHanYuhhh/-/blob/master/6-1.png)

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

<table><td>
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3

输出: "LCIRETOESIIGEDHN"

示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4

输出: "LDREOEIIECIHNTSG"

解释:

![Image text](https://github.com/ZHANGHanYuhhh/-/blob/master/6-2.png)

</td></table>

分析：简单的找规律问题：以上图4行为例，假设从上到下从左到右的字母顺序分别为从0开始递增（也即字母在字符串中的位置），可以发现该Z字以7个字母为一组，然后重复，以只要找到第几行字母下一个字母对应位置的计算方法，就很容易算出，以第二行为E和O为例，E在0~5中是1，O是5，两个相加正好是一组的长度，依次为据就很容易计算出下一个第二行字母位置。

时间复杂度O(nxm),空间复杂度O(s)(m为列数，s为字符串长度）。

### 7.整数反转

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

<table><td>

示例 1:

输入: 123

输出: 321

示例 2:

输入: -123

输出: -321

示例 3:

输入: 120

输出: 21

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

</td></table>

分析：这一题比较简单，如果是正数，直接通过模10除10操作来进行反转操作，操作完的数存入long long。如果是负数，先换成正数，再处理，只要注意-2147483648这个特殊数字即可。

时间复杂度O(log(x))，x中大约有 log10(x)位数字,空间复杂度O(1)。

### 8.字符串转换整数（atoi）

请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，qing返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

<table><td>
示例 1:

输入: "42"

输出: 42

示例 2:

输入: "   -42"

输出: -42

解释: 第一个非空白字符为 '-', 它是一个负号。我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:

输入: "4193 with words"

输出: 4193

解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

示例 4:

输入: "words and 987"

输出: 0

解释: 第一个非空字符是 'w', 但它不是数字或正、负号。因此无法执行有效的转换。

示例 5:

输入: "-91283472332"

输出: -2147483648

解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 因此返回 INT_MIN (−2^31) 。 
</td></table>

分析：一开始做的时候没有看清题，以为有的测试样例会没有“ " ”号，后来看清楚题后发现非常简单，先把“ " ”找到，然后向后遍历字符串，直到找到第一个非空字符，然后看看这个字符是不是数字、“+”、“-”三者之一，不是就返回0，是的话判断“+”、“-”后面跟的是不是数字，如果是数字然后将字符串转为整数即可，注意在转换的过程中如果越过int的界就要返回，不然会报错。

时间复杂度O(n),空间复杂度O(1)。

### 9.回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

<table><td>
示例 1:

输入: 121

输出: true

示例 2:

输入: -121

输出: false

解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:

输入: 10

输出: false

解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:

你能不将整数转为字符串来解决这个问题吗？  
</td></table>

分析：转换为字符串做非常简单，但是要耗费一定的资源，主要考虑非字符串做法。转化一半数字，然后判断二者是否相等。首先所有负数，能被10整除的数都不是回文数，首先返回false，接着所有小于10的整数都是回文数，返回true，之后剩下的数就可以通过除10模10运算来转化，如何判断已经转化了一半的数呢，可以判断二者大小，如果转化的数大于等于剩下的数的时候，就说明已经转化了一半，最后比较就可以了（注意像121这样的数，转化完为1和12，需要把前半部分x10+2处理，也即还原一次，进行比较）。

时间复杂度O(log2(n)),空间复杂度O(1)。

### 11.盛最多水的容器

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

![Image text](https://github.com/ZHANGHanYuhhh/-/blob/master/11.jpg)

<table><td>
  
示例：

输入: [1,8,6,2,5,4,8,3,7]

输出: 49
</table></td>
分析：如果一个个求面积，时间复杂度可能会相当的大，这样我们可以从两头遍历（此时的底边是最大值），我们要考虑什么情况下，矩形的面积会增加，我们知道矩形的高是由相对较短的那一侧决定，那么我们不断的移动较短的那一侧，然后计算出来的面积才有可能增加，直到两条边相遇为止。
时间复杂度O(n)，空间复杂度O(1)。


### 994.腐烂的橘子

在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；

值 1 代表新鲜橘子；

值 2 代表腐烂的橘子。

每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

<table><td>

示例 1：

![Image text](https://github.com/ZHANGHanYuhhh/-/blob/master/994.png) 

输入：[[2,1,1],[1,1,0],[0,1,1]]

输出：4

示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]

输出：-1

解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。

示例 3：

输入：[[0,2]]

输出：0

解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

提示：

1 <= grid.length <= 10

1 <= grid[0].length <= 10

grid[i][j] 仅为 0、1 或 2

</table></td>

分析：可以从提示中看到，题目的规模并不大，可以通过模拟时间，来进行解答，首先通过行列循环储存下坏了的橘子，之后取出这些橘子，改变周围橘子的状态，然后循环执行，直到没有橘子状态需要改变，然后判断有没有新鲜的橘子。

时间复杂度O(nxm)(时间复杂度跟网格大小有关)，空间复杂度O(t)(空间复杂度跟总共的橘子数有关)。
