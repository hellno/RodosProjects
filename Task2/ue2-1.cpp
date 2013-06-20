#include "rodos.h"

static Application module01("Uebung2-1", 2000);

volatile long int globalCount = 0;
volatile long int firstCounter = 0;
volatile long int secondCounter = 0;

Semaphore incrementCounter;

class SomeThread: public Thread{
public:
  
  SomeThread(const char * name) : Thread(name, 25) {
  }
  
  void run() {
	while(1){
   
    //incrementCounter.enter();
     if(strcmp(name,"1")){
      firstCounter += 50;
    }else{
      secondCounter += 50;
    }
		globalCount += 50;
    //incrementCounter.leave();
	
		xprintf("Process %s called.\n Sum: %ld, globalCount: %ld, Diff: %ld\n",name,firstCounter + secondCounter,globalCount, firstCounter + secondCounter - globalCount);
		FFLUSH();
	}
  }
};

SomeThread eins("1");
SomeThread zwei("2");
