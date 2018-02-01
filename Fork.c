#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* waitpid */
#include <sys/types.h> /* pid_t */

void process(int number, int time) {
  printf("Prosess %d kjører\n", number);
  sleep(time);
  printf("Prosess %d kjørte i %d sekunder\n", number, time);
}

int main(void) {
  int p0,p1,p2,p3,p4,p5;

  p0 = fork();
  if (!p0) {
    process(0,1);
    exit(0);
  }
  p2 = fork();
  if (!p2) {
   process(2,3);
   exit(0);
  }
    waitpid(p0,NULL,0);         /*Venter på prosess #0*/
  p1 = fork();
  if (!p1) {
   process(1,2);
   exit(0);
  }
  p4=fork();
  if(!p4) {
   process(4,3);
   exit(0);
  }
    waitpid(p2,NULL,0);         /*Venter på prosess #2*/
  p3 = fork();
  if(!p3) {
   process(3,2);
   exit(0);
  }
    waitpid(p4,NULL,0);         /*Venter på prosess #4*/
  p5 = fork();
  if(!p5) {
   process(5,3);
   exit(0);
  }
    waitpid(p5,NULL,0);         /*Venter på prosess #5*/
}
