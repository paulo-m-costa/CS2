Caltech CS2 Assignment 5: Graphs

See [assignment5.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/spanning_tree/blob/master/assignment5.html)

0) DFS Debugging
This algorithm could be problematic. It may loop forever on a undirected graph,
or on a cyclical data structure. To avoid these issues, we should track the 
nodes that have already been traversed so that they are not visited again.
There is also a typo in the code. There should be a semi-colon after 
"edges.begin()" in the for loop rather than a comma.

1) Minimum Spanning Trees
1.1) Essentials
The three most essential properties of a MST are: (1) that it contains all 
vertices, (2) that it is connected with a subset of E(G), or the edges of the
graph, and (3) that the sum of its edge weights is minimal.

1.2) First Step
The first step should be to pick the adjacent node that costs the minimum 
amount to get to to work towards minimizing the weight of all the edges.

1.3) Next Steps
For each subsequent step, we should pick one of the nodes adjacent to the ones
we have already reached that has the lowest cost. This minimizes the cost of
spanning the tree. This is just like the first step except we now factor in the
previous nodes that have already been reached when choosing the next node. We
are finsihed when all nodes have been reached since all minimum paths are
chosen by this point.

1.4) Different Algorithm
At each step, we should pick the edge with the least weight. This allows the
weight of our final tree to be minimized. We stop when there is only one tree
left since this will be the remaining tree that spans all nodes.

1.5) Programming - Prim's Algorithm (Stepwise Outline)
Note that this algorithm respects the existing edges.
(1) Pick the starting star. (ID 30000142)
(2) Pick the edge with the minimum distance that has one star in the tree and
the other outside it.
(3) Add this edge to the mst_edges member of the star from which the new star
was reached.
(4) Add this new star to the list of stars in the tree.
(5) Repeat steps 2 through 4 until all stars are in the tree.

2) Single-Source Shortest-Path 
2.1) The Source Node
It is logical to investigate the neighbor with the lowest cost to get to first.

2.2) Multiple Nodes
At each further step, it is logical to investigate the cheapest neighbor that
can be reached from any of the already visited nodes. At each step, we should
mark each node's previous neighbor i.e. the node from which it became marked
from. This ends up yielding a shortest path to another node because it is 
possible to reconstruct the shortest path using the previous pointers.

2.3) When We Are Done
We are finsihed when we reach the destination node. Once this happens, we can
derive the path we want via backtracking.

2.4) Programming - Dijkstra's Algorithm (Stepwise Outline)
(1) Initialize dist = INFINITY (dist = 0 for source only) and prev = NULL,
marking all vertices as unvisited.
(2) Set current vertex v = source
(3) For every unvisited neighbor u of v:
  (3.1) Calculate new_cost = v.cost + w(E(v, u)), accounting for cost specs.
  (3.2) If newcost < u.cost, we have found a cheaper path to u
  (3.3) Set u.cost = new_cost and u.prev = v
(4) Mark v as a visited node.
(5) Set v = unvisited vertex with the smallest tentative cost.
(6) Go back to step 3 until all vertices are visited OR v is the destination.

X) Miscellaneous Items
X.1) Jita
A trade hub like Jita might arise simply because it happens to be a prime
location that makes it readily accesible for nearby mission hubs and other
facilities. The New Eden graph could allow Jita to become the 'center of the
universe' by making getting to Jita extremely cheap thanks to the lack of
security. A historical factor that allows Jita to remain economically relevant
is that fact that it used to be a dinosaur haven, meaning that it is abundant
in fossil fuels and thus is guaranteed to be a place of interest.

X.2) Feedback
I consider myself fairly experienced. I took Java and C++ courses starting my
sophomore year in high school, and while I never wrote anything particularly
complicated, I certainly learned the fundamentals. While I found CS 1 pretty
straightforward for the msot part, I have to admit that this class has thrown
me some curveballs.

Well, now that I've gotten used to other languages, I find debugging in C++ to 
be a lot more time-consuming that it is in Python, not that that's supposed to
be surprising or anything. You guys could double-check that all the packages
needed to do the assignments are available on all the machines in the lab since
the one I initially chose didn't have freeglut3-dev installed.

I spent roughly 9 hours on this assignment in particular, most of which was
needed to digest the basic concepts rather than learning obscure C++ things.

I found assignment 4 to be the easiest, probably because it was actually the
shortest one thus far and I didn't need much time to figure out the concepts.
I believe assignment 2 took me the most time simply because there were so many
concepts to learn and functions to write. Assignment 1 was simple but lengthy,
and assignment 3 was kind of doing the same thing twice, which made it easier.

It certainly helped me to write out outlines for some of the functions I've
implemented as it gave me tangible frameworks to work with. I typically wrote
the outlines before starting to code and certainly before finishing coding. I
think that outlines are beneficial and awarding points for them is a great
incentive to encourage us to write them.

I found this assignment reasonably enjoyable and interesting and also not too
difficult. Enough background was provided to cover the concepts adequatey and
I really liked learning about the motives behind the algorithms. I certainly
have become a better programmer by doing this as I coded novel things (for me,
at least). I'd have appreciated it if you guys covered more algorithms and in
more depth during recitation.

I did go to the most recent recitation. While it undeniably helped me with this
assignment, I'd have appreciated it if you guys covered more algorithms and in
more depth. I found the amount of material reviewed to be a little lacking.

While I did not attend the lecture covering the conceptual material in this
assignment, I have reviewed all the lecture slides in my own time and have
found them quite useful. Unfortunately I cannot give any advice for this
lecture in particular, but the lectures I have attended were clear enough
and perhaps even a little slow in moving through the slides.

This course is definitely meeting my expectations. I like the convenience of
pulling assignments and uploading them via Moodle. The lecture slides are easy
to understand and the assignments are not overly time-consuming. Some things
are the slides are quite dated and may need to be updated, but other than that
I don't think any other adjustments need to be made.