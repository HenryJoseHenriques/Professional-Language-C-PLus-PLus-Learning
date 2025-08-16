// Tempo global usado no aging e no deadline
extern int tempo;
// Controle da thread
extern int run_thread;

void* thread_timer();
void inicia_timer();
void pausa_thread();
void deleta_timer();