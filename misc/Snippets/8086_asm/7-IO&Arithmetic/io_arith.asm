TITLE   I/O and Arithmetic Operation
PAGE    60,132
        INCLUDE STDIO.MAC ; display, input
;------------------------------------
STSEG   SEGMENT
        DB 64 DUP(?)
STSEG   ENDS
;------------------------------------
DTSEG   SEGMENT

S_OP1    DB 'First operand: ','$'
S_OP2    DB 'Second operand: ','$'
S_RESULT DB 'The result is: ','$'
S_NOTICE DB ' has been saved to memory.','$'
LINEFEED DB 0DH,0AH,'$'

OP1_BUF      LABEL BYTE
OP1_BUFSIZE  DB    3
OP1_BUFCOUNT DB    ?
OP1_REALDATA DB    2 DUP(' '),'$'

OP2_BUF      LABEL BYTE
OP2_BUFSIZE  DB    3
OP2_BUFCOUNT DB    ?
OP2_REALDATA DB    2 DUP(' '),'$'

RESULT_BUF   DW    2 DUP(0),'$'

DTSEG   ENDS
;------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX
        
        ; Prompt the user to input the first operand
        ; and convert it to num.
        DISPLAY S_OP1
        INPUT   OP1_BUF
        DISPLAY LINEFEED
        DISPLAY OP1_REALDATA
        DISPLAY S_NOTICE
        DISPLAY LINEFEED
        
        ; Prompt the user to input the second operand
        ; and convert it to num.
        DISPLAY S_OP2,1,
        INPUT   OP2_BUF
        DISPLAY LINEFEED
        DISPLAY OP2_REALDATA
        DISPLAY S_NOTICE
        DISPLAY LINEFEED
        
        ; Perform ASCII Addition on two operands
        SUB     AX,AX
        LEA     BX,OP1_REALDATA+1
        LEA     SI,OP2_REALDATA+1
        LEA     DI,RESULT_BUF+1
        MOV     CX,03
BACK:   MOV     AL,BYTE PTR [BX]
        ADD     AL,BYTE PTR [SI]
        AAA                       ; AAA will handle the carry.
        OR      AL,30H
        ADD     [DI],AL
        MOV     [DI-1],AH
        DEC     BX
        DEC     SI
        DEC     DI
        LOOP    BACK
        
        ; Display the result.
        DISPLAY S_RESULT
        DISPLAY RESULT_BUF
        DISPLAY LINEFEED

        MOV AH,4CH
        INT 21H
MAIN    ENDP
CDSEG   ENDS
        END MAIN
