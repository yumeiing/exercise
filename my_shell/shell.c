#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int a;

void standardCommand(char *,char **);
int handlePipe(char **);

int main(int argc,char *argv[])
{
	if(argc > 1)
	{
		if(freopen(argv[1],"r",stdin) == NULL)
		{
			fprintf(stderr,"Can't read from script file %s\n",argv[1]);
			fputs("Exiting.\n",stderr);

			exit(1);
		}
		a = 1;
	}
	while(1)
	{
		char buf[1024];
		if(!a) fputs("$ ",stdout);
		if(fgets(buf,1024,stdin) == NULL) break;

		char **args;
		standardCommand(buf,args);

		if(args[0] == NULL) continue;
		if(strcmp(args[0],"exit") == 0) exit(0);

		pid_t pid = fork();

		if(pid > 0)
		{
			wait(NULL);
		}
		else
		{
			if(handlePipe(args) == -1)
			{
				fputs("Could not redirect\n",stderr);
				exit(1);
			}
			execvp(args[0],args);
			fprintf(stderr,"Could not exec %s\n",buf);
		}
	}
}

void standardCommand(char *buf,char **args)
{
		char *nl = strchr(buf,'\n');
		if(nl) *nl = '\0';

		char *hash = strchr(buf,'#');
		if(hash) *hash = '\0';

		int nargs = 0;
		args[nargs] = strtok(buf," ");

		while(args[nargs] != NULL)
		{
			args[++nargs] = strtok(NULL," ");
		}
}

int handlePipe(char **args)
{
	for(int i = 0; args[i] != NULL; ++i)
	{
		if(strcmp(args[i],">") == 0)
		{
			if(freopen(args[i+1],"w",stdout) == NULL) return -1;

			args[i] = NULL;
			return 1;
		}
	}
	return 0;
}
