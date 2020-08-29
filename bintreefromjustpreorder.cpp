void constructBinaryTree(Node* root,int pre[], 
						 int size) {
  
  	int h = log2(size+1), c = 1;
  cout<<h<<endl;
	Node* tt = root;
	stack<pair<Node*, int>> s;
  	root->data = pre[0];
  Node* temp = root;
  	s.push({root, 1});
  int i = 1;
  	while(!s.empty()){
    	if(c==h || (temp->left && temp->right)){
          
      		temp = s.top().first;
          	int l = s.top().second;
      		s.pop();
          	c = l;
          cout<<"popped\t:\t"<<temp->data<<endl;
          
        }
      
      if(temp->left == NULL){
        	while(c<h){
          cout<<"if\t:\t"<<pre[i]<<endl;
          c++;
       		 Node* n = new Node(pre[i++]);
        
        	temp->left = n;
        
        	if(c<h){
        s.push({n,c});
      temp = temp->left;
      }
        }
      }
    
      
    else if(!temp->right){
      cout<<"else\t:\t"<<pre[i]<<endl;
     	Node* n = new Node(pre[i++]);
        c++;
      
        temp->right = n;
         if(c<h){
        s.push({n, c});
      temp = temp->right;
      }
      }
      
      
     //if(root->left && root->right) s.pop();
     
}
  cout<<c<<endl;
 printInorder(tt);
  
  return ;
}
  
  