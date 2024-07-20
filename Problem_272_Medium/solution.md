### Problem 272:

Write a function, throw_dice(N, faces, total), that determines how many ways it is possible to throw N dice with some number of faces each to get a specific total.

 For example, throw_dice(3, 6, 7) should equal 15.


### Explaination:

Viên xúc xắc có 6 mặt ứng với các số từ 1 đến 6. Khi ném ra cả 3 viên cùng lúc trong 1 lần, để tổng các mặt có giá trị là 7, sẽ có các trường hợp sau:

Các bộ ba khác nhau (không phân biệt thứ tự):

* (1, 1, 5): 3 cách (hoán vị) - 115 : 151 : 511
* (1, 2, 4): 6 cách (hoán vị) - 124 : 142 : 214 : 241 : 412 : 421
* (1, 3, 3): 3 cách (hoán vị) - 133 : 313 : 331
* (2, 2, 3): 3 cách (hoán vị) - 223 : 232 : 322

tổng cộng có: 3 + 6 + 3 + 3 = 15 trường hợp


### Solution:

* Liệt kê thủ công - Brute Force Enumeration
* Lập trình động - Dynamic Programming
* Đệ quy với Ghi nhớ - Recursion with Memoization
* Tổ hợp và Xác suất - Combinatorics and
