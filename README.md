# dijkstra-cpp

## Running the program
The easiest way to run the program is using CLion:
- Open the project with CLion
- Load the CMake project
- Run the program

## Graph data
Each line in the data file represents one edge of a graph. Each edge has a weight and direction. The structure of a line is as follows:

`source node` `weight` `target node`

The elements of a line  are separated by `\t`.

IMPORTANT: If there is a node that is not a source of any edges, it should be added to the file on a separate line, e.g.:

`node_name`

There is also an `example_data.tsv` file that includes an example graph. The source node of the graph will be the source node of the first line in the data file.