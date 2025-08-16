#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

void iniciarlizarFilas();

struct Task* taskCreate(const char *name, int priority, int burst);

// add a task to the list 
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

