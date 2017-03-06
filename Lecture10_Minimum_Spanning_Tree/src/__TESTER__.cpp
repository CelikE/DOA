#include "GraphToolkit.h"


int main()
{

	// Define graph nodes
	GraphToolkit<char>::Graph graph;
	GraphNode<char>* a = new GraphNode<char>('a');
	GraphNode<char>* b = new GraphNode<char>('b');
	GraphNode<char>* c = new GraphNode<char>('c');
	GraphNode<char>* d = new GraphNode<char>('d');
	GraphNode<char>* e = new GraphNode<char>('e');
	GraphNode<char>* f = new GraphNode<char>('f');
	GraphNode<char>* g = new GraphNode<char>('g');
	GraphNode<char>* h = new GraphNode<char>('h');

	// Connect the nodes with edges
	GraphToolkit<char>::addEdge(a, b, 2);
	GraphToolkit<char>::addEdge(a, d, 1);

	GraphToolkit<char>::addEdge(b, c, 1);
	GraphToolkit<char>::addEdge(b, d, 2);
	GraphToolkit<char>::addEdge(b, e, 7);

	GraphToolkit<char>::addEdge(c, e, 2);
	GraphToolkit<char>::addEdge(c, g, 9);

	GraphToolkit<char>::addEdge(d, e, 2);

	GraphToolkit<char>::addEdge(e, f, 1);
	GraphToolkit<char>::addEdge(h, e, 2);

	// Add the nodes to a Graph object
	graph.push_back(a);
	graph.push_back(b);
	graph.push_back(c);
	graph.push_back(d);
	graph.push_back(e);
	graph.push_back(f);
	graph.push_back(g);
	graph.push_back(h);

	//GraphToolkit<char>::Dijkstra(graph, a);
	GraphToolkit<char>::Kruskalv2(graph);
	GraphToolkit<char>::dumpGraph(graph);

	// Dump the graph
	//GraphToolkit<char>::dumpGraph(graph);

	cout << endl << endl << endl;
	{

	GraphToolkit<char>::Graph ga;
	GraphNode<char>* a = new GraphNode<char>('a');
	GraphNode<char>* b = new GraphNode<char>('b');
	GraphNode<char>* c = new GraphNode<char>('c');
	GraphNode<char>* d = new GraphNode<char>('d');
	GraphNode<char>* e = new GraphNode<char>('e');
	GraphNode<char>* f = new GraphNode<char>('f');
	GraphNode<char>* g = new GraphNode<char>('g');
	GraphNode<char>* h = new GraphNode<char>('h');

	GraphToolkit<char>::addEdge(a, b, 4);
	GraphToolkit<char>::addEdge(a, d, 7);

	GraphToolkit<char>::addEdge(b, c, 1);
	GraphToolkit<char>::addEdge(b, e, 7);
	GraphToolkit<char>::addEdge(b, d, 2);

	GraphToolkit<char>::addEdge(c, g, 9);
	GraphToolkit<char>::addEdge(c, e, 6);

	GraphToolkit<char>::addEdge(e, f, 2);

	GraphToolkit<char>::addEdge(f, e, 1);

	GraphToolkit<char>::addEdge(h, e, 3);

	ga.push_back(a);
	ga.push_back(b);
	ga.push_back(c);
	ga.push_back(d);
	ga.push_back(e);
	ga.push_back(f);
	ga.push_back(g);
	ga.push_back(h);
	//GraphToolkit<char>::Dijkstra(ga, a);
	GraphToolkit<char>::Kruskalv2(ga);
	GraphToolkit<char>::dumpGraph(ga);
	}
	return 0;
}
