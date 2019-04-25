TITLE    INPUT A STRING OF DATA, WITH ECHO
PAGE     60,132
;-----------------------------------------
STSEG    SEGMENT
         DB 32 DUP(?)
STSEG    ENDS
;-----------------------------------------
DTSEG    SEGMENT
;BUFFER   LABEL   BYTE
;MAX_SIZE DB      06
;B_COUNT  DB      ?
;B_DATA   DB      6 DUP(' ')
;B_TRAIL  DB      '$'
BUFFER   DB     6,?,6 DUP(0FFH),'$'
DTSEG    ENDS
;-----------------------------------------
CDSEG    SEGMENT
MAIN     PROC FAR
         ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
         MOV AX,DTSEG
         MOV DS,AX
        
         MOV AH,0AH      ;select string input
         MOV DX,OFFSET BUFFER   ;DX points to BUFFER
         MOV CX,DX
         INT 21H         ;invoke the interrupt

         MOV AH,09H      ;select string output
         MOV DX,CX   ;load actual data section
         INT 21H         ;invoke the interrupt
        
         MOV AH,4CH      ;EXIT
         INT 21H         ;invoke the interrupt
MAIN     ENDP
CDSEG    ENDS
         END MAIN
