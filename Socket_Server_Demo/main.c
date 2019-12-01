//
//  main.c
//  Socket_Server_Demo
//
//  Created by zhangtalent on 2019/11/24.
//  Copyright © 2019 zhangtalent. All rights reserved.
// Serverooo

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    pid_t client_pid;
    char buff[1024];
    int clientf = 0;
    struct sockaddr_in saddr,clientaddr;
    socklen_t clilen;
    bzero(&saddr, sizeof(saddr));
    saddr.sin_port = htons(8088);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_family = AF_INET;
    bind(server_socket, (struct sockaddr *)&saddr, sizeof(saddr));
    listen(server_socket, 5);
    for(;;) {
        clilen = sizeof(clientaddr);
        clientf = accept(server_socket, (struct sockaddr*)&clientaddr,&clilen);
        printf("###clienfd = %d\n",clientf);
        printf("###listen = %d\n",server_socket);
        if (clientf>0) {
            if ((client_pid = fork())==0) {
                close(server_socket);
                while (1) {
                    while (read(clientf,buff, sizeof(buff))) {
                        fputs(buff, stdout);
                        if(strlen(buff)<1024)break;
                        bzero(buff,sizeof(buff));
                        
                    }
                    
                    printf("over");
                    char *htmldata = "Nice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet uNice to meet u";
                    //设置缓存
                    char c[1024];
                    
                    snprintf(c, sizeof(c), "HTTP/1.1 200 OK\r\ncontent-type: text/html;\r\nDate: Mon, 27 Jul 2009 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\nLast-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\nContent-Length:%lu\r\n\r\n",strlen(htmldata)+1);
                    
                    int writeoffset = 0;
                    ssize_t writesize = 0;
                    long length  = strlen(c);
                    if (length<1024) {
                        write(clientf, c, length);
                    }else{
                        while(writeoffset<length){
                            if((writesize=write(clientf, c+writeoffset, 1024))>0){
                                writeoffset += writesize;
                                
                                //fputs("Fail",stdout);
                            }
                        }
                    }
                    
                    length  = strlen(htmldata);
                    writeoffset = 0;
                    if (length<1024) {
                        write(clientf, htmldata, length);
                    }else{
                        while(writeoffset<length){
                            if((writesize=write(clientf, htmldata+writeoffset, 1024))>0){
                                writeoffset += writesize;
                                
                                //fputs("Fail",stdout);
                            }
                        }
                    }
                    
                    
                    printf("#child##clienfd = %d\n",clientf);
                    printf("child ---the pid = %d nowpid = %d\n",getpid(),client_pid);
                    printf("###child = %d\n",server_socket);
                }
                //描述符减一
                
                
            }
        }
        printf("parent ---the pid = %d\n",getpid());
        printf("#parent##clienfd = %d\n",clientf);
        printf("----------------\n\n");
        close(clientf);
    }
    
    return 0;
}
