# Longest Path in a Directed Acyclic Graph
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a Weighted&nbsp;<strong>D</strong>irected&nbsp;<strong>A</strong>cyclic&nbsp;<strong>G</strong>raph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=3
M=2
SRC=0
edges[]={{0,2,1},{0,1,1}}
<strong>Output:</strong>
distance[]={0,1,1}
<strong>Explanation:</strong>
the shortest distance of vertex 1 from 0 is 1 and that of two is also 1.</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=6
M=10
SRC=1
edges[]={{0,1,5},{0,2,3},{1,3,6},{1,2,2},{2,4,4},{2,5,2},{2,3,7},{3,5,1},{3,4,-1},{4,5,-2}}
<strong>Output:</strong>
distance[]={INF,0,2,9,8,10}
<strong>Explanation:</strong>
The vertex zero is not reachable from vertex 1 so its distance is INF, for 2 it is 2, for 3 it is 9, the same goes for 4 and 5.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>maximumDistance()</strong>&nbsp;which takes the edge list edges[] </span><span style="font-size:18px">where edges[0] , edges[1] and edges[2] represent u,v and weight, its size M<strong>&nbsp;</strong>and the&nbsp;number of nodes N<strong>&nbsp;</strong>as input parameters&nbsp;and returns the distance array in the distance array instead of passing INF you need to have INT_MIN driver will automatically update it to INF.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(V+E)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(V)</span><br>
<br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10</span><sup><span style="font-size:15px">3</span></sup><br>
<span style="font-size:18px">1&lt;=M&lt;=N*(N-1)/2</span><br>
<span style="font-size:18px">0&lt;=edges[i][0],edges[i][1]<br>
-100&lt;=edges[i][2]&lt;=100.</span><br>
<span style="font-size:18px">&nbsp;</span></p>
</div>