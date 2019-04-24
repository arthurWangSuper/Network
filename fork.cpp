#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 


using namespace std;
int main(int argc,char**argv)
{
	pid_t childpid;
	int stat;

	childpid =fork();
	if(childpid == 0)
	{
		sleep(1);
		cout<<"child ppid: "<<getppid()<<" pid: "<<getpid()<<endl;
		exit(4);
	}
	else if(childpid != -1)
	{
		wait(&stat);
		cout<<"parent ppid: "<< getppid()<<" pid: "<<getpid()<<" err: "<<stat<<endl;
		return 0;
	}
	else{
		return 0;
	}

}
