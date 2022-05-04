#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

//Sturcture of maessage queue
struct message_buffer{
    long message_type;
    char message_text[100];
}message;

int main(){
    //key_t --> Defined in sys/types.h required by unix system for requesting resources -- Length is system-dependent
    key_t key;
    int message_id;

    //It is used to generate unique IPC key -- Present in sys/ipc.h -- returns a key based on path (progfile) and id(65) -- path could be the name of any file that is available in system and id could be in range of 1 - 255 -- returns -1 on failure
    key=ftok("progfile",65);
    //msgget get message queue it can either create or access an existing queue -- present in sys/msg.h -- returns message queue identifier associated with key
    message_id=msgget(key,0666 | IPC_CREAT);
    //could be any value 
    message.message_type=1;
    printf("Write data: ");
    fgets(message.message_text,sizeof(message.message_text),stdin);

    //msgsnd to send message -- msgid -- address of message -- size of message -- msgflag if 1 then no messsage send 
    msgsnd(message_id,&message,sizeof(message),0);
    
    //Printing of message from queue
    printf("Data send is: %s \n",message.message_text);
}
