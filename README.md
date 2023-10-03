# METRO RAIL APP

Let me clarify upfront that this is not an Android app but a straightforward C++ program. Its purpose? To collect details about your starting and ending metro stations on the Delhi Metro and then give you the shortest route and fare information. It's also got a handy metro map to help you find your way.

Here's the scoop on how it works: We're using graphs and heaps as our trusty tools. In our world, graphs consist of nodes (representing the metro stations) and edges (showing how stations are connected). Nodes spill the beans on each station - like their names, which corridors they're on, and the lines they link to. Edges, on the other hand, tell us how far apart stations are.

To find the quickest path from where you start to where you want to go, we've got a few tricks up our sleeve like Dijkstra's algorithm, BFS (breadth-first search), and DFS (depth-first search). These whiz-bang methods help us find the shortest route and calculate the fare based on the total distance you'll travel. Once we've figured that out, we lay it all out for you - the metro route and the total fare.

For the nitty-gritty, check out **Main.cpp** where all the action happens, and don't forget **Heap.cpp**, which is where our heap magic lives.

## REQUIREMENTS

- You can run this project in pretty much any C++ development environment, whether it's Code::Blocks, Visual Studio, or even an online tool like ideone.com.
- You don't need to be a C++ whiz, but some basic knowledge of the language will come in handy.
- If you're familiar with stuff like graphs and heaps and algorithms like Dijkstra's, BFS, and DFS, that's a bonus, but don't sweat it if you're not.
- Oh, and if you've heard of the C++ Standard Template Library (STL), it might make things easier (you can learn about it here: [cplusplus.com/reference/stl](http://www.cplusplus.com/reference/stl/)).

You're all set! Just take the structure and ideas from the Java version, translate them into C++, and you're good to go. Happy coding!