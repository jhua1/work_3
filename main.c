#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);
  
  int x,y;
  for( x = 0;x < edge->rows; x++){
    for ( y = 0; y<edges->cols;y++){
      edges->m[x][y] = 2;
    }
  }

  printf("printing out edge\n");
  print_matrix(edges);
  printf("Applying Identity Matrix\n");
  ident(edges);
  print_matrix(edges);
  printf("Applying Scalar Mult by 5\n");
  scalar_mult(5,edges);
  print_matrix(edges);

  free_matrix( edges );
}  
