# Remove minimum elements
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an unsorted array <strong>Arr</strong>&nbsp;of size <strong>N</strong>. Find the minimum number of removals required such that twice of minimum element in the array is greater than or equal to the maximum in the array.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 9
Arr[] = {4,5,100,9,10,11,12,15,200}
<strong>Output:</strong> 4
<strong>Explanation:</strong> In the given array 4 elements 
<strong>4, 5, 200</strong> and <strong>100</strong> are removed from the
array to make the array such that
2*minimum &gt;= max (2*9 &gt; 15).
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
Arr[] = {4,7,5,6}
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;We don't need to remove any
element as  4*2 &gt; 7 (Note that min = 4,
max = 7).</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>minRemoval()</strong>&nbsp;which takes the&nbsp;array of integers&nbsp;<strong>arr</strong>&nbsp;and&nbsp;<strong>n&nbsp;</strong>as parameters and returns an integer&nbsp;denoting the answer.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*logN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>7</sup><br>
1 ≤ Arr<sub>i</sub> ≤ 10<sup>9</sup></span></p>
</div>