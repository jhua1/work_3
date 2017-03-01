#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = 223;
  c.green = 151;
  c.blue = 51;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  printf("adding edges\n");
  add_edge(edges,0,0,0,250,500,0);
  add_edge(edges,250,500,0,500,0,0);
  add_edge(edges,250,250,0,0,0,0);
  add_edge(edges,250,250,0,500,0,0);
  add_edge(edges,0,500,0,250,0,0);
  add_edge(edges,250,0,0,500,500,0);
  add_edge(edges,0,500,0,250,250,0);
  add_edge(edges,250,250,0,500,500,0);
  add_edge(edges,0,500,0,500,250,0);
  add_edge(edges,500,250,0,0,0,0);
  add_edge(edges,0,250,0,500,500,0);
  add_edge(edges,0,250,0,500,0,0);
  add_edge(edges,250,0,0,250,500,0);
  add_edge(edges,0,250,0,500,250,0);
  
  print_matrix(edges);
  printf("drawing picture\n");
  draw_lines(edges,s,c);
  
  printf("matrix operations below\n");

  struct matrix *test;
  test = new_matrix( 4,4);
  
  int x,y;
  for( x = 0;x < test->rows; x++){
    for ( y = 0; y<test->cols;y++){
      test->m[x][y] = 2;
    }
  }

  printf("printing out test\n");
  print_matrix(test);
  printf("Applying Identity Matrix\n");
  ident(test);
  print_matrix(test);
  printf("Applying Scalar Mult by 5\n");
  scalar_mult(5,test);
  print_matrix(test);
  printf("Doing Matrix Multiplication\n");
  printf("Matrix 1:\n");
  
  struct matrix *test1;
  struct matrix *test2;
  test1 = new_matrix(2,3);
  test2 = new_matrix(3,2);

  test1->m[0][0] = 1;
  test1->m[0][1] = 2;
  test1->m[0][2] = 3;
  test1->m[1][0] = 4;
  test1->m[1][1] = 5;
  test1->m[1][2] = 6;

  print_matrix(test1);

  printf("Matrix 2:\n");

  test2->m[0][0] = 1;
  test2->m[0][1] = 2;
  test2->m[1][0] = 3;
  test2->m[1][1] = 4;
  test2->m[2][0] = 5;
  test2->m[2][1] = 6;

  print_matrix(test2);

  printf("Multiplying Matrix 1 by Matrix 2\n");

  matrix_mult(test1,test2);

  print_matrix(test2);

  display(s);
  free_matrix( edges );
  free_matrix(test);
  free_matrix(test1);
  free_matrix(test2);
  //save_extension(s,"matrix.png");
}  
