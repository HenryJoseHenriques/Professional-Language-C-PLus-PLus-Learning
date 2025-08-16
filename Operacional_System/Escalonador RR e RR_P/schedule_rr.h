#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
//#define QUANTUM 3

void iniciarlizarFilas();

struct Task* taskCreate(const char *name, int burst);

// add a task to the list 
void add(char *name, int burst);

// invoke the scheduler
void schedule();

