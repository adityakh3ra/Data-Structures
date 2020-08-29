struct Node{
	int val;
	vector<int> adj;
};


int main(){

	vector<Node> g;

	Node n;

	
	n.val = 0;
	n.adj.push_back(3);
	g.push_back(n);

	n.val = 1;
	n.adj.clear();
	n.adj.push_back(0);
	n.adj.push_back(2);
	n.adj.push_back(4);
	g.push_back(n);	

	n.val = 2;
	n.adj.clear();
	n.adj.push_back(7);
	g.push_back(n);

	n.val = 3;
	n.adj.clear();
	n.adj.push_back(5);
	n.adj.push_back(4);
	g.push_back(n);

	n.val = 4;
	n.adj.clear();
	n.adj.push_back(3);
	n.adj.push_back(6);
	g.push_back(n);

	n.val = 5;
	n.adj.clear();
	n.adj.push_back(6);
	g.push_back(n);

	n.val = 6;
	n.adj.clear();
	n.adj.push_back(7);
	g.push_back(n);

	n.val = 7;
	n.adj.clear();
	g.push_back(n);


}