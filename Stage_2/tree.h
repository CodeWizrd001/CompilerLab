
tnode* createTree(int val,int op,int type,char* c,tnode *l,tnode *r)
{
  tnode *Temp = (YYSTYPE) calloc(1,sizeof(tnode)) ;
  Temp->val = val ;
  Temp->op = op ;
  Temp->nodeType = type ;
  Temp->varName = c ;
  Temp->left = l ;
  Temp->right = r ;
  return Temp ;
}