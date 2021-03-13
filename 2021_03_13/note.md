## 705. 设计哈希集合

不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 `MyHashSet` 类：

- `void add(key)` 向哈希集合中插入值 `key` 。
- `bool contains(key)` 返回哈希集合中是否存在这个值 `key` 。

- `void remove(key)` 将给定值 `key` 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

**示例：*

```
输入：
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
输出：
[null, null, null, true, false, null, true, null, false]

解释：
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）
```

**提示：**

- `0 <= key <= 106`
- 最多调用 `104` 次 `add`、`remove` 和 `contains` 。



### **题解：**

​		首先关于哈希函数的解释：将集合中的任意元素都可以映射到固定范围二等整数值，并将该元素存储到整数值对应的地址上。

​		冲突处理可以采用**链地址法**：

​		哈希函数：$hash(x)=x \quad mod \quad base$

​		所以可以开一个base大小的数组，计算出x的哈希值，插入到对应的链表中即可，将base设置为质数，可以最大可能性的减少冲突。

​		

![image-20210313163237074](E:\Github\Leetcode-\2021_03_13\image-20210313163237074.png)