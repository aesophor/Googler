## LeetCode Report
Total:  80
* Avg Runtime is 92.843375000000009% faster than other submissions
* Avg Memory is 61.494749999999996% less than other submissions



## 算法整理

| No | 題型 | Optimal Solution | 時間 | 空間 |
| -- | --- | --- | --- | --- |
| 001 | Two Sum (unsorted) | HashTable; One pass | O(n) | O(n) |
| 167 | Two Sum (sorted) | 雙指針; One pass | O(n) | O(1) |
| 015 | Three Sum | ? | ? | ? |
| 011 | 最大水容器 | 雙指針; One pass | O(n) | O(1) |
| 042 | 雨水搜集 | DP記錄各點左邊最高高度; 回來時min(左最高,右最高)並扣除該位置地板高度，得該處積水高度; Two pass | O(n) | O(n) |
| 238 | Array自己以外乘積 | DP; Two pass | O(n) | O(n) |
| 189 | Rotate Array | 轉左轉右再全轉 | O(n) | O(1) |
| 003 | 最長沒重復字substr | HashTable; Dynamic Sliding Window; One pass | O(n) | O(n) |
| 020 | 驗證刮號 | PDA 左push右pop; 結束stack必須空; One pass | O(n) | O(n) |
| 046 | 產生排列 | 1. Aj<Aj+1 2. Aj右邊大於Aj且最小 3. swap 4. 排序Aj+1之後  | sort O(n^2) | O(1) |
| 204 | Primes | Sieve; 已知01非質數; 質數倍數刪除; 到sqrt(n)可停 | [link](https://stackoverflow.com/questions/48428006/efficiency-of-sieve-of-eratosthenes-algorithm) | O(n) |
| 705 | toLower | 大小寫offset = 'a'-'A' = 0x20 = 32 | O(n) | O(1) |


## Writeups
### 1. Two Sum
給定一個array和target，從中找兩個元素a,b s.t. a+b=target，找到回傳a和b的index
* Bruteforce: 兩個for-loops掃過，若 nums.at(i) + nums.at(j) == target 即回傳 {i,j}
    * Time complexity: O(n^2)
    * Space complexity: O(1)，沒有額外分配記憶體
    
* One-Pass HashTable: 用unordered_map<int, int>，以complement爲key, 自己的index爲value
    ```
    arr=[1,2,3,4,5], target=6
    一開始看到1, 6-1=5, 我們把5當key放入。之後scan到5的時候，用5查找可得知index=1的element與之相加等於target
    +-----+-----+
    | key | val |
    +-----+-----+
    | 5   | 0   |
    | ... | ... |
    +-----+-----+
    ```
    * Time complexity: O(n)，HashTable 查找每次花費O(1)，n個元素總共花O(n)
    * Space complexity: O(n)，n個元素


### 2. Add Two Numbers
給兩個LinkedList, 假設分別是\[2->3->4\], \[3->5->8\]，代表432+853=1285，自己建一個新的LinkedList [5->8->2->1] 並回傳5這個Node的address

注意進位即可（迴圈內每次先檢測上次是否有進位，如果要進位記得額外+1,清除carry flag，做下一次相加。如果>=10，設定carry flag，如此循環直到兩個List都到底了）。

最後回傳 result_head，需注意迴圈內第一次要檢查 result_head 是否爲nullptr，如果是，代表一個node都還沒計算，見[27行](https://github.com/aesophor/future-googler/blob/master/leetcode/002_add_two_numbers.cc#L27)


### 3. Longest Substring without Repeating Characters
這題難度是不是寫錯了...==# 應該是 hard

abcabcbb -> 3 ("abc")

bbbbb -> 1 ("b")

pwwkew -> 3 ("wke")

* Bruteforce Sliding Window: 假設給的字串長度爲n，把1~n的substrings全部列舉出來，逐個檢查是否有重復char，如果沒有就可以更新最大長度。
    * Time complexity: O(n^3) = 1~n長度substrings × sliding window × 檢測substring是否有重復char = n * n * n
    * Space complexity: O(min(n,m))，n爲給定字串長度，m爲alphabet大小
    這個方法會Time Limit Exceed，無法通過
    
* One-Pass Sliding Window: 原本的Sliding Window是列舉所有可能字串長度，注意檢測每一種可能。而這個方法我們的Window size可彈性改變
    ```
    設一 unordered_map<char,int> 記錄遇到的每個char最後出現的index
    設兩變數 win_left=0, win_right=0，還有第三個變數max_len=0
    
    迴圈內每次win_right遇到一個char，就檢測是否在雜湊表內，不在代表現在window內字串還沒發生重復，可直接把此char加入雜湊表
    如果遇到的char已在雜湊表內，分兩種情況，
    如果不在當前window內（最後出現index < win_left），則沒關系，可直接把此char加入雜湊表（即更新它最後出現的index）
    如果此char在當前window內，代表window內有char發生重復了！計算當前window size並和max_size比較大小，比較大就更新max_size
    我們讓 win_left = 它上次出現的index + 1，也就是設定win_left爲還沒重復的char的index
    迴圈每次最後win_right++
    ```
    * Time complexity: O(n)，win_right固定每次都++，一次到底
    * Space complexity: O(min(n,m))，n爲給定字串長度，m爲alphabet大小
    
    
### 4. Median of Two Sorted Arrays
這題應該只有 easy~medium 吧....@_@

和Merge Sort裏的merging很相似，具體作法參考
* https://github.com/aesophor/future-googler/blob/master/algorithms/sort.cpp#L58
* https://www.geeksforgeeks.org/merge-sort/

中位數概念 https://en.wikipedia.org/wiki/Median
* \[0,1,2,3,4\] odd: **5/2** = 2
* \[0,1,2,3,4,5\] even: **(6/2)-1** = 2, **6/2** = 3 

先找中位數index，然後用一個迴圈處理即可，每次都從l1,l2挑最小的element，找到之後讓該list的ptr=ptr->next。
l1 l2 兩個pointer都到底時結束，另外記得設一個counter記錄現在總共找到了多少element，counter=中位數index時代表這就次的中位數，
如果array長度是odd，中位數只有一個。如果是even，會有兩個，把兩個相加除以2傳即可

* Time complexity: O(n)，只scan一次，甚至只scan到一半，(1/2)\*n，但coefficient拿掉還是n 
* Space complexity: O(1)，使用到的variables數量固定


### 7. Reverse Integer
給一個 int n 並反轉。每次用 mod 可以取得個位數，用 /=10 可以shift right
1. reversed \*= 10
2. reversed += n % 10，
3. n /= 10
反復直到n=0爲止

每次 reversed \*= 10 之前記得檢測 reversed 會不會 overflow，會的話馬上回傳0（題目的要求）
reversed * 10 > INT_MAX 和 reversed * 10 < INT_MIN 做一下移項，會得到下列式子
```
if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
    return 0;
}
```
* Time complexity: O(log(n)) digits大約有log(n)個，因爲 log(n) 即 10^x = n，假設除以三次10,就代表有三個digit
* Space complexity: O(1)

> logarithmic running-time function are that:
> 1. the choice of the next element on which to perform some action is one of several possibilities, and
> 2. only one will need to be chosen, or
> 3. the elements on which the action is performed are digits of n

Additional Reading: [What does O(log(n)) really means?](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly)


剩下的之後補 @_@
