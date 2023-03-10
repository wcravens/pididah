// hello.c
#include <stdio.h>

struct Foo {
  int num;
  char bar;
} foo;


int main() {
  foo.num = 23;
  foo.bar = 'a';
  void * ptr = &foo;

  struct Foo baz = *(struct Foo*) ptr;
  printf( "Hello, world!\n" );
  printf( "%c\n", baz.bar );
  return 0;
}

