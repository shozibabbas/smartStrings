<p align="right">Sayyed Shozib Abbas<br>
  BSCS-4A<br>
  35038<br>
  112434<br>
  Assignment 2: Smart Strings</p>
<h1>Github Repo</h1>
<h1>Introduction</h1>
<p>Our task is to provide implementation of Strings using the  following types of smart pointers:</p>
<ol>
  <li>Copied Pointers</li>
  <li>Owned Pointers</li>
  <li>COW with Reference Counting</li>
  <li>COW with Reference Linking</li>
</ol>
<p>Moreover, we need to profile our applications and analyze  the resource utilization for each one of these strategies with relatively  small, medium and very large strings.<br>
  Then with Unit Tests ensure the methods are running  correctly and pointer transfer is not leaking memory or leaving any dangling  pointers.</p>
<h1>Approach</h1>
<p>Let me just write down every inch of detail about this  assignment and how it was done.<br>
  Sorry for the late submission and consuming late days. I  suspect you would be expecting an earlier submission from my side but trust me,  some issues at my end due to which I couldn&rsquo;t do it earlier.<br>
  Firstly, there is no such thing as copied pointers. I tried  searching the internet and it says that the correct term for copied pointers is  &ldquo;deep copy&rdquo;. Obvio I needed help, so I had to search the internet. But telling  you the truth, there isn&rsquo;t anything directly related to the assignment. Even if  there is, I didn&rsquo;t bother looking at it. Though I did find something related to  the &ldquo;copied pointers&rdquo; part but trust me, all I noticed was the dirtiness of the  code and how I couldn&rsquo;t handle it <em>*sighs*</em>.<br>
  Secondly, since I am using Visual Studio with C++, this just  gets better while trying to ensure if there is any memory leak. Instead of  using Unit tests, I used Visual Studio&rsquo;s Performance Analyzer which provides  options for checking memory leaks as well as performance.<br>
  After correcting the initially broken code (removing some  delete statements), I got the program working.<br>
  Copied pointers and COW with reference counting was already  implemented (partially or fully, I don&rsquo;t remember now). The other parts have  been written and are working correctly according to my instincts.</p>
<h1>How to Run</h1>
<p>You may run the solution in visual studio directly. There  are 4 applications attached to a single solution. The solution explorer should  show:</p>
<ol>
  <li>copiedPointers</li>
  <li>COWwithRFC</li>
  <li>COWwithRL</li>
  <li>ownedPointers</li>
</ol>
<p>Load each project and compile a single project to see its  output.</p>
<h1>Profiling</h1>
<h2>Resource Utilization</h2>
<p>Profiling each application with small (5), medium (25) and  large (125) strings. The sampling number tells us which part of the application  utilizes what number of resources.<br>
  The strings used are:<br>
  nIciq<br>
  chWvvzgI0uDn9yHDnrRrpL9O7<br>
  aX42bWW2Bv7Je69IKzUMGQJFgAgkGUVN7wGPsCT4m0t0YHTkPbr7XxurscpzSAuWRUGXsaIPgz3sc8txUGuB4PpoMFAt0sActpvXBreqPYnUNSi5KDDKV9iLiPkAv</p>
<h2>Memory Leaks</h2>
<p>I placed pauses on each step of the main function and took a  snapshot every time the program stopped. This means there is a memory snapshot  taken on every new variable created, copied, edited and destroyed.<br>
  Taking a closer look, you will see snapshots showing memory  increases. <br>
  Ultimately, this memory being occupied should be freed to  its fullest right after the applications ends. If you see the number of  allocations being less in the end than the number of allocations done between  execution, that means there is no memory loss.<br>
  Moreover, the size of data that increases during execution  must reduce to its fullest at the end which will prove there are no memory  leaks in the application as well.</p>
