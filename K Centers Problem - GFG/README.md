# K Centers Problem
## Hard
<div class="problems_problem_content__Xm_eO"><h4><span style="font-size:18px">You have given N cities numbered from 0 to N-1. The distance between each pair of cities is given by N * N matrix MAT where MAT[i][j] denotes the distance between city i and j.</span></h4>

<h4><span style="font-size:18px">The task is to&nbsp;select K (K&lt;= N) ATM servers&nbsp; in such a way that the maximum distance of a city from the ATM Server is minimized.</span></h4>

<h4><span style="font-size:18px"><strong>Example 1:</strong></span></h4>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 4, K = 2,
MAT[][] = {{0, 10, 7, 6},
           {10, 0, 8, 5},
           {7, 8, 0, 12},
           {6, 5, 12, 0}}
<strong>Output:</strong> 6
<strong>Explanation:</strong><code>
<img alt="" src="https://media.geeksforgeeks.org/img-practice/kcenters11-1649711037.png" style="height:250px; width:500px"></code></span>

</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the function <strong>selectKcities() </strong>which takes N, K&nbsp; and MAT[][] as input parameter and returns an integer, indicating the maximum distance of a city from the ATM Server, which is minimized.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N * K * (2 ^ N))<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(K)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= K &lt;= N &lt;= 15<br>
1 &lt;= MAT[i][j] &lt;= 10^9</span></p>
</div>