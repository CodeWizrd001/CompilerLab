
tnode* createTree(int val,int op,int type,int t,char* c,tnode *l,tnode *r)
{
  tnode *Temp = (YYSTYPE) calloc(1,sizeof(tnode)) ;
  Temp->val = val ;
  Temp->op = op ;
  Temp->type = t ;
  Temp->nodeType = type ;
  Temp->varName = c ;
  Temp->left = l ;
  Temp->right = r ;
  Temp->sTable = NULL ;
  return Temp ;
}