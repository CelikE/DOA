#pragma once

#include"GraphNode.h"
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;


template<class Item>
class GraphToolkit
{
public:
	// These typedef's allow us to define nodes and graphs easily.
	// Note that everything in this toolkit could be done without these typedef's
	// - they only exist to make life a little easier for us
	typedef vector<GraphNode<Item>*> Graph;	// Vector is used to hold the complete Graph
	typedef typename Graph::iterator GraphIter;			// Iterator for a Graph
	typedef GraphNode<Item> Node;				// Node in a graph

	typedef vector<Edge<Item>*> EdgeList;
	typedef typename vector<Edge<Item>*>::iterator EdgeListIter;

	static void addEdge(Node*& from, Node*& to, size_t weight=1)
	{
		from->neighbors.push_back(new Edge<Item>(from, to, weight));
	}

	static bool compareEdge(Edge<Item>* a, Edge<Item>* b) { return ((*a).weight > (*b).weight); }

	static void removeEdge(Node*& from, Node*& to)
	{
		EdgeListIter ix = from->neighbors.begin();

		for(;ix != from->neighbors.end(); ++ix)
		{
			if((*ix)->to==to)
			{
				from->neighbors.erase(ix);
				return;
			}
		}
	}


	static void dumpGraph(Graph g)
	{
		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			cout << "Node " << (*curNode)->data << " (" << (*curNode)->marked << ", " << (*curNode)->cost << ", " << (*curNode)->stp << "): neighbors: ";
			
			for(EdgeListIter ix =(*curNode)->neighbors.begin(); ix != (*curNode)->neighbors.end(); ++ix)
			{
				cout << (*ix)->to->data << " (" << (*ix)->weight << "), ";
			}
			cout << endl;
			//printRoute(*curNode);
		}
	}

	static bool detectCirc(Graph g, Node* from, Node* to)
	{
		queue<GraphNode<Item>*> q;
		Node* n;

		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			(*curNode)->circ_marked = false;
		}

		q.push(from);
		while(!q.empty()) {
			n = q.front();
			q.pop();
			n->circ_marked = true;
			for(auto it = n->neighbors.begin(); it != n->neighbors.end(); ++it) {
				if ((*it)->to == to)
					return true;

				if (!(*it)->to->circ_marked) {
					q.push((*it)->to);
				}
			}
		}
		return false;
	}

	static void Kruskalv2(Graph g)
	{
		EdgeList edges;
		Edge<Item>* edge;
		size_t stp_runner = 1;
		size_t stp_min, stp_max;
		
		/*
		 * Run through all nodes and set then
		 * to marked = false and remove all
		 * edges to have a clean slate,
		 * saving the edges in a seperate 
		 * vector
		 */
		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			//Set all nodes to marked false
			(*curNode)->stp = 0;

			//Remove all edges and add them to a vector
			while(!(*curNode)->neighbors.empty()) {
				edge = (*curNode)->neighbors.back();
				(*curNode)->neighbors.pop_back();
				edges.push_back(edge);
			}
		}

		//Sort al edges to cost (lowest is last)
		std::sort(edges.begin(), edges.end(), compareEdge);

		/*
		 * Run through all edges 
		 * If one or zero of the nodes is marked = false
		 * its safe to add that edge to the graph and
		 * changes both nodes marked = true
		 * if both has marked = true, we detect if we
		 * already can go from a to b with the edges
		 * already added. If we can drop the edge, 
		 * if not add it.
		 *
		 * Optimizing 
		 * If edges = (nodes-1) * 2    - We have twice the edges due to twoway connections
		 * 
		 */
		while(!edges.empty()) {
			edge = edges.back();
			edges.pop_back();

			if (edges.size() != (g.size()-1)*2) {
				//One is not marked and thereby safe to insert
				if (edge->to->stp == 0 and edge->from->stp == 0) {
					addEdge(edge->from, edge->to, edge->weight);
					addEdge(edge->to, edge->from, edge->weight);
					edge->from->stp = stp_runner;
					edge->to->stp = stp_runner;
					++stp_runner;
				} else if (edge->to->stp == 0 or edge->from->stp == 0) {
					addEdge(edge->from, edge->to, edge->weight);
					addEdge(edge->to, edge->from, edge->weight);

					if (edge->to->stp == 0)
						edge->to->stp = edge->from->stp;
					else
						edge->from->stp = edge->to->stp;
						
				} else if (edge->to->stp != edge->from->stp) {
					addEdge(edge->from, edge->to, edge->weight);
					addEdge(edge->to, edge->from, edge->weight);

					stp_max = max(edge->from->stp, edge->to->stp);
					stp_min = min(edge->from->stp, edge->to->stp);

					for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
					{
						if ((*curNode)->stp == stp_min)
							(*curNode)->stp = stp_max;
					}
				}
			}
			delete edge;
		}

	}

	static void Kruskal(Graph g)
	{
		EdgeList edges;
		Edge<Item>* edge;
		
		/*
		 * Run through all nodes and set then
		 * to marked = false and remove all
		 * edges to have a clean slate,
		 * saving the edges in a seperate 
		 * vector
		 */
		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			//Set all nodes to marked false
			(*curNode)->marked = false;

			//Remove all edges and add them to a vector
			while(!(*curNode)->neighbors.empty()) {
				edge = (*curNode)->neighbors.back();
				(*curNode)->neighbors.pop_back();
				edges.push_back(edge);
			}
		}

		//Sort al edges to cost (lowest is last)
		std::sort(edges.begin(), edges.end(), compareEdge);

		/*
		 * Run through all edges 
		 * If one or zero of the nodes is marked = false
		 * its safe to add that edge to the graph and
		 * changes both nodes marked = true
		 * if both has marked = true, we detect if we
		 * already can go from a to b with the edges
		 * already added. If we can drop the edge, 
		 * if not add it.
		 *
		 * Optimizing 
		 * If edges = (nodes-1) * 2    - We have twice the edges due to twoway connections
		 * 
		 */
		while(!edges.empty()) {
			edge = edges.back();
			edges.pop_back();

			if (edges.size() != (g.size()-1)*2) {
				//One is not marked and thereby safe to insert
				if (!edge->to->marked or !edge->from->marked) {
					addEdge(edge->from, edge->to, edge->weight);
					addEdge(edge->to, edge->from, edge->weight);
					edge->from->marked = true;
					edge->to->marked = true;
				} else {
					if (!detectCirc(g, edge->from, edge->to)) {
						addEdge(edge->from, edge->to, edge->weight);
						addEdge(edge->to, edge->from, edge->weight);
						edge->from->marked = true;
						edge->to->marked = true;
					}
				}
			}
			delete edge;
		}

	}

	static void Dijkstra(Graph g, Node* node)
	{
		
		queue<GraphNode<Item>*> q;
		Node* n;

		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			(*curNode)->prev = (*curNode);
			(*curNode)->cost = SIZE_MAX;
		}

		node->cost = 0;
		node->prev = node;
		q.push(node);
		while (! q.empty())
		{
			n = q.front();
			q.pop();
			for(auto it = n->neighbors.begin(); it != n->neighbors.end(); ++it) {
				if (n->cost + (*it)->weight < (*it)->to->cost) {
					(*it)->to->cost = n->cost + (*it)->weight;
					(*it)->to->prev = n;
					q.push((*it)->to);
				}
			}
		}
	}

	static void printRoute(Node* node) 
	{
		Node* n = node;
		while (n->prev != n) {
			cout << n->data << " -> ";
			n = n->prev;
		}
		cout << n->data << endl;
	}

};
