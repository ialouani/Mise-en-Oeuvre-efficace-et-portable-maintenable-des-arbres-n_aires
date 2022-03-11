//il faut commenter sinon on se melangera les pinceux;pas un defaut
  //mais mieux commenter des le debut pour eviter
  //les debugs de valgrind qui peuvent nous paraitre
  //anodins a leurs observations..
  //*t  allouée(valeur dans le segment de donnees du TAS) dans le tas
  //ainsi que *((*t)->_root) qui represente le 'debut' de l'arbre n_aire
  //lui aussi dans le tas via une adresse dans un block de 4 octets dans
  //la pile;son adresse bien sur.
  //t->_root de type struct node_t*...=>utiliser la recursivite car
  //ce n'etait pas demander de faire la fct. node__empty
  //=>~structure dans la pile en terme de developpement de chainage dans
  //le tas par deferencement inconnus..
***************

RQ2:
/*

//rappel: je ramene l'implementation de struct node_t
//et dans le fichier ntree.h ou cest icomplet pour declarer
//struct children_t*(ptr tjrs!!!) via: un champ::: struct node_t current;;
//mais si on voit bien: ntree_t n'est pas implementee..///
//=>il faut l'implementer pour connaitre sa taille (pour allocation).

/*enum direction_t{FIRST_CHILD=0,NEXT_SIBLING};
struct ntree_t{
  struct node_t* _root;
  };*/
//a ne pas modifier:il faut faire avec!
//j'ai struct node_t/strut children_t mais pas struct ntree_t.

*/

=>=>=>=>=>=>=>
//structure fonctionnelle non via le cas de abse ci-dessus
    //=>est passee forcement par des add de quelques struct node
    //a 2 sentinelles dans le cas le plus basique par allocation
    //pour faire un link sinon ca serait une racine avec aucun fils.
    
//t->root impossible car struct ntree_t* est comme un void*
  //=>*.. est un type INCOMPLET.
  //il faut liberer a part le t et t->_root(ntree__root(t))
  //:>>tous les sommets en-dessus avec l'astuce de stockage temporaire.

//tableau des struct node_t restants
    //fils de node_tree.

//ptr pas tableau.
//allocation dynamique discrete dans la fonction
 //allocation necessaire par retour d'adresse.
//remarque essentielle: utiliser les fonctions pour creer des expressions suivant la construction proposee dans le sujet. 
 ---------------------
 //node__child:returns the node(struct node_t* --type) of a node n at d.
  //ntree__children(valeur):retourns the sequence of child nodes of a node n.
  //ntree__root:(&):: a struct node* value OF the root node of t.
  //children__current: a struct node* of a children that it's pointed by him.
  //children__is_empty: returns if *children is an empty sequence of nodes.
  //children_next: returns the children points to the next node.
  //il faut passer par une fonction (au pire) qui fait la meme chose pour des
  //node.. mais pensant un peu: seul la struct ntree_t dont les composants
  //sont inaccessibles.(et de pres meme struct node_t que via les fonctions).





 //ca fait un free pour un node normal.
    //node a ete alloue et les encapsulations via le tableau children
    //aussi evidemment.



  //de type struct node_t de meme 'structure' que l'entree(arg.1).
    //struct node_t* en_cours;
    //while(!children__is_empty((struct children*)childs)){
    //ce typecasting nous force a ne pas utiliser de boucle.
    //copie sauvegarde de current






//sequence des noeuds
//1er noeud pointe.(ordre..######).//<.|||
















void ntree__free(struct ntree_t * t){
  void free_liste_node(struct node_t* tab[]){
    int i=0;
    struct node* node_prev=tab[0];
    struct node* node_next;
    while(node_prev!=NULL){
      node_next=tab[i+1];
      tnode__free(node_prev);
      node_prev=node_next;
      i++;
    }
  }
  void tnode__free(struct node_t *node_tree){
    if(node_tree==NULL) return;
    struct node_t* base=node_tree->children[0];
    struct node_t* reste=node_tree->children[1];
    tnode__free(base);
    free_liste_node(reste);
    free(node_tree);
  } 
  
  struct node_t* root=ntre__root(t);
  tnode__free(root);
  free(ntree__root(ntr));
  free(ntr);
}













********************************************
qst3:
//valeur de droite de type struct node_t*.
  //tab->_current[1] represente un strut node_t* de meme
  //qui fait reference a un tableau de struct node_t.
  //tab->current[0] est lui meme que tab->current[1] de type struct node_t*
  //la difference cest que le premier reference une valeur adressee
  //et le deuxieme fait appel a une ecriture dont la classe d'equivalence
  //a comme representant: struct node_t[].




//la deuxieme valeur est de type struct node_t* present non pas une adresse
  //d'une valeur mais l'adresse d'un debut(VALEUR) d'un tableau contenant
  //des struct node_t.
  //retour d'un struct node_t* referencant l'adresse de debut du tableau des
  //struct node_t donc logiquement c'est l'adresse du deuxieme struct node_t*
  //dans la suite des enfant de son pere.


 //children->current a modifier.(pas children sinon au max ss effet de bord)






******************************************
qst4:
si on continue d'appliquer instinctivement des evaluations de tnode__degree a la racine suivant un schema traditionnel ancien ~operationnel tjrs, on aurait l'impression que ca fait le meme travail de ntree_depth.

//nodes[] exprime pour tableau sans commentaire avec ce quon a dit avant ca s'arrage bien: no next_sibling exprimant un tableau par deferencement mais une simple valeur par anti-remontee~~~ referencee.

FIN QUESTIONS de programmation sur machine --comments ()  () de la session1/2018-2019.












