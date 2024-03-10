#include "defs.h"

#define NCOMMANDS 4

typedef struct cmd_struct {
  char* name;
  char* msg;
  int (*func)(char**);
} cmd_struct;

int help(char**);
int hello(char**);
int timestamp(char**);
int reboot(char**);

// TODO: argv for each commands
char* argv[10];

cmd_struct cmds[NCOMMANDS] = {
  {
    .name = "help",
    .msg = "print available commands",
    .func = help
  },
  {
    .name = "hello",
    .msg = "print hello world",
    .func = hello
  },
  {
    .name = "timestamp",
    .msg = "get current timestamp",
    .func = timestamp
  },
  {
    .name = "reboot",
    .msg = "restart the computer",
    .func = reboot
  }
};

int
execute(char* cmd)
{
  for(int i=0; i < NCOMMANDS; i++){
    if(strncmp(cmd, cmds[i].name, 100) == 0){
      return cmds[i].func(argv);
    }
  }
  printk("sh.c: unknown command\n");
  return -1;
}

void
runsh(void)
{
  uartflush();
  static char buf[100];

  while(1){
    printk("$ ");
    
    // Read command
    int i = 0;
    char c;
    memset(buf, 0, sizeof(buf));
    buf[0] = '\0';

    while((c = uartgetc()) != '\n'){
      buf[i++] = c;
      uartputc(c);
    }
    buf[i] = '\0';
    uartputc('\n');
    execute(buf);
  }
}

int
help(char**)
{
  for(int i=0; i<NCOMMANDS; i++){
    printk(cmds[i].name);
    printk(": ");
    printk(cmds[i].msg);
    printk("\n");
  }
  return 0;
}

int
hello(char**)
{
  printk("Hello world\n");
  return 0;
}

int
timestamp(char**)
{
  return 0;
}

int
reboot(char**)
{
  return 0;
}
