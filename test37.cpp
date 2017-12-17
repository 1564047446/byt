/*************************************************************************
	> File Name: test37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月13日 星期三 18时26分53秒
 ************************************************************************/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main( void )
{
    pid_t childpid;
    int status;
    childpid = fork();
if ( childpid < 0 )
{
    perror( "fork()" );
    exit( EXIT_FAILURE );
}
else if ( childpid == 0 )
{
    puts( "In child process" );
    //sleep( 3 );//让子进程睡眠3秒，看看父进程的行为
    printf("\tchild pid = %d\n", getpid());
    printf("\tchild ppid = %d\n", getppid());
    exit(EXIT_SUCCESS);
}
else
{
    waitpid( childpid, &status, 0 );
    puts( "in parent" );
    printf( "\tparent pid = %d\n", getpid() );
    printf( "\tparent ppid = %d\n", getppid() );
    printf( "\tchild process exited with status %d \n", status );
}
exit(EXIT_SUCCESS);
}
