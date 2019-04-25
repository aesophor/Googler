TITLE   OUTPUT A STRING OF DATA TO MONITOR
PAGE    60,132
;-----------------------------------------
STSEG   SEGMENT
        DB 32 DUP(?)
STSEG   ENDS
;-----------------------------------------
DTSEG   SEGMENT
STR     DB 'I love assembly :)','$'
DTSEG   ENDS
;-----------------------------------------
CDSEG   SEGMENT
MAIN    PROC FAR
        ASSUME CS:CDSEG,DS:DTSEG,SS:STSEG
        MOV AX,DTSEG
        MOV DS,AX
        
        MOV AH,09H      ;select string output
        LEA DX,STR      ;load offset addr of STR to DX
        INT 21H         ;invoke the interrupt
        
        MOV AH,4CH      ;EXIT
        INT 21H         ;invoke the interrupt
MAIN    ENDP
CDSEG   ENDS
        END MAIN
