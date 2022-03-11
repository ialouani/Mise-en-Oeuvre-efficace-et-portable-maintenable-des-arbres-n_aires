/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "node.h"
#include "ntree.h"

/* struct ntree_t { */
/*   struct node_t * _root; */
/* }; */

/* enum direction_t { */
/*                   FIRST_CHILD=0,   // premier fils */
/*                   NEXT_SIBLING,    // frère suivant */
/* }; */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/**
 * RETURN an empty n-tree
 */
struct ntree_t * ntree__empty(){
  struct ntree_t* ntr=(struct ntree_t*)malloc(sizeof(struct ntree_t));
  ntr->_root=node_empty();
  return ntr;
}

/**
 * PARAM t : a n-tree
 * PRECOND t is not NULL
 * POSTCOND the memory allocated for the tree t and all its subtree
 * has been freed but for the empty nodes
 */


void free2(struct ntree_t* ntree){
  void free2(struct node_t* nodesT){//sans faire un free de la racine
    //qui est nodesT au juste(prise en charge apres).
    if(node__is_empty(nodesT)) return;
    struct children childs=ntree__children(nodesT);
    struct node_t* current=children__current(&childs);
    struct node_t* current2=current;
    free2(current);
    children__next(current2);
    free2(current2);
  }
  free2(ntree__root(ntree));
  free(ntree__root(ntree));
  free(ntree);
  return;
}
  
    
