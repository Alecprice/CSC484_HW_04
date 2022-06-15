#include <stdio.h>
#include <pthread.h>


int  factorial;  // Globle varialbe
void *Factorial(void *param);


int main(int argc, char *argv [])
{
  // Thread id
  pthread_t thread_id;   
  // Thread attributes9       
  pthread_attr_t thread_attribute;      

  //The error checking is performed to ensure that the number of arguments is 2
  if (argc !=  2)
  {
    fprintf(stderr, "usage: Factorial <integer value>\n");
    return -1;
  }

  //The error checking is performed to ensure that the given number is a non-negative integer
  if (atoi(argv[1]) < 0)
  {
    fprintf(stderr, "Usage: Please enter a non-negative integer.\n Example: 1, 2, 3, 4... \n");
    return -1;
  }

  //Create a new thread and have it run the Factorial function
  pthread_create(&thread_id, NULL, Factorial, argv[1]);

  //Wait until the thread finishes

  pthread_join(thread_id, NULL);

  printf("Factorial = %d\n", factorial);
}

 //The function to be run by the new  thread
void *Factorial(void *param)
 {
   int i, upper = atoi(param);
   factorial = 1;

   for (i = 1; i <= upper; i++)
     factorial *= i;

   return NULL;
 }