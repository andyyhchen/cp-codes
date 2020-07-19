mes     db      'Hi, I learn assembly.$'
stack   segment stack
        db      20 dup ('stack123')
stack   ends
pnt_msg segment
        assume  cs:pnt_msg,ds:message
main    proc    far
start:  push    ds
        sub     ax,ax
        push    ax
        mov     ax,message
        mov     ds,ax

        mov     dx,offset mes
        mov     ah,9
        int     21h
        mov     ax,4c00h
        int     21h
main    endp
        end     start
