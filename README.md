# PathFinder_CW2
First, run path.c and input 2 nodes' ID to calculate the best path.  
The algorithm will show the shortest path and the length in terminal. In addition, There will be 2 new files generated as 'map.txt' and 'ans.txt'.  
Open GNUPlot, input:   
`<set yrange [53.801600:53.811000]>`        
`<set xrange [-1.564000:-1.543100]>`      
`<plot "D:\map.txt" using 1:2 with linespoints linecolor 3 linewidth 1 pointtype 16 pointsize 0.9,"F:\ans.txt" using 1:2 with linespoints linecolor 7 linewidth 1 pointtype 16 pointsize 0.9>`  
Then user can see the shortest path highlighted with red, and others with light blue.
