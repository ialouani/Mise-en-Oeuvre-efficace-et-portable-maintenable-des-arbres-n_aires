#include <assert.h>

#include "ntree.h"

//rappel: struct ntree_t privee fixé via un code client de representation
//adaptee dans le fichier no

int children__is_empty(struct children_t const * children)
{
  assert(children != NULL);
  return (node__is_empty(children->_current));
}


struct node_t * children__current(struct children_t const * children)
{
  assert(children != NULL);
  assert( ! children__is_empty(children) );
  return children->_current;
}

