# Manejo de señales
int sigaction( int signum, const struct sigaction *act, struct sigaction *oldact );


Método sigaction(): The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.






struct sigaction {


    void     (*sa_handler)(int);   address of a signal handler or action for NON-queued signals.
    
    void     (*sa_sigaction)(int, siginfo_t *, void *);  address of a signal handler or action for queued signals.
    
    sigset_t   sa_mask; An additional set of signals to be masked (blocked) during execution of the signal-catching function

    
    int        sa_flags;
    
    void     (*sa_restorer)(void);
    
    
           };
