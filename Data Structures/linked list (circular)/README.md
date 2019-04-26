# LeetCode #708 - Insert into a Cyclic Sorted List

給定一數據結構，*2 -> 3 -> 4 -> *2 ，其中 *2 代表是同一個節點。

請寫一個class並實現其insert方法。


## 思路
* 我們可以讓head永遠指向list中的最小元素

* Insert element with value X 時：
  1. 若list爲空，則生成一個新node(X)作爲其head
  2. 若list非空，遍歷至最後一個<X的node，並進行插入，如果X比原本head的值更小就更新head

## Resources
https://www.cnblogs.com/grandyang/p/9981163.html
